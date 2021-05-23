#include "JavaEnv.h"

#include <windows.h>
typedef UINT(CALLBACK* JVMDLLFunction)(JavaVM**, void**, JavaVMInitArgs*);

#include <vector>
#include <tuple>
#include <functional>
#include <sstream>
#include <iostream>
#include "BedrockMod.h"

DCCallVM* callVM = dcNewCallVM(4096);

void InitCallVM()
{
	dcReset(callVM);
	dcMode(callVM, DC_CALL_C_X86_WIN32_THIS_MS);
	std::cout << dcGetError(callVM) << std::endl;
}

jobject JFunctionPointerInvoke(JNIEnv* jenv, jobject instance, jclass clazz, jobjectArray args)
{
	std::cout << clazz << std::endl;
	return g_BedrockMod->javaEnv->JavaFunctionPointerInvoke(instance, clazz, args);
}

JavaEnv::JavaEnv(std::string classPath)
{
	this->env = nullptr;
	this->vm = nullptr;

	InitCallVM();

	char inputJdkDll[] = "%JAVA_HOME%\\jre\\bin\\server\\jvm.dll";
	TCHAR outputJdkDll[32000];
	DWORD jdkResult = ExpandEnvironmentStrings((LPCTSTR)inputJdkDll, outputJdkDll, sizeof(outputJdkDll) / sizeof(*outputJdkDll));
	char inputJreDll[] = "%JAVA_HOME%\\bin\\server\\jvm.dll";
	TCHAR outputJreDll[32000];
	DWORD jreResult = ExpandEnvironmentStrings((LPCTSTR)inputJreDll, outputJreDll, sizeof(outputJreDll) / sizeof(*outputJreDll));
	if (!jdkResult && !jreResult) {
		std::cout << "Failed to find JDK/JRE jvm.dll, please ensure Java 8 is installed." << std::endl;
		return;
	}
	HINSTANCE jvmDLL = LoadLibrary(outputJdkDll);
	if (!jvmDLL) {
		jvmDLL = LoadLibrary(outputJreDll);

		if (!jvmDLL) {
			std::cout << "Failed to find JDK/JRE jvm.dll, please ensure Java 8 is installed." << std::endl;
			return;
		}
	}
	JVMDLLFunction createJavaVMFunction = (JVMDLLFunction)GetProcAddress(jvmDLL, "JNI_CreateJavaVM");
	if (!createJavaVMFunction) {
		std::cout << "Failed to find JDK/JRE jvm.dll, please ensure Java 8 is installed." << std::endl;
		return;
	}

	static std::stringstream optionString;
	optionString << "-Djava.class.path=" << classPath;

	JavaVMInitArgs vm_args;
	auto* options = new JavaVMOption[1];
	char cpoptionString[200] = "";
	std::strcpy(cpoptionString, optionString.str().c_str());

	options[0].optionString = cpoptionString;
	vm_args.version = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false;

	int res = createJavaVMFunction(&this->vm, (void**)&this->env, &vm_args);
	std::cout << "Created JVM!" << std::endl;

	this->loaderClass = this->env->FindClass("bedrock/Loader");
	this->pointerClass = this->env->FindClass("bedrock/Pointer");
	this->functionPointerClass = this->env->FindClass("bedrock/FunctionPointer");
	if (this->functionPointerClass != NULL && this->pointerClass != NULL) {
		JNINativeMethod methods[] = {
			{(char*) "invoke", (char*) "(Ljava/lang/Class;[Ljava/lang/Object;)Ljava/lang/Object;", (void*)JFunctionPointerInvoke}
		};
		this->env->RegisterNatives(this->functionPointerClass, methods, 1);

		jmethodID mainMethod = this->env->GetStaticMethodID(this->loaderClass, "main", "([Ljava/lang/String;)V");
		this->env->CallStaticVoidMethod(this->loaderClass, mainMethod);
	}
}

void JavaEnv::PushValueToCallVM(jobject object) 
{
	JNIEnv* jenv = this->GetEnv();
	jclass jcls = jenv->GetObjectClass(object);

	jclass stringClass = jenv->FindClass("java/lang/String");
	jclass integerClass = jenv->FindClass("java/lang/Integer");
	jclass doubleClass = jenv->FindClass("java/lang/Double");
	jclass floatClass = jenv->FindClass("java/lang/Float");
	jclass longClass = jenv->FindClass("java/lang/Long");
	jclass booleanClass = jenv->FindClass("java/lang/Boolean");

	if (jenv->IsInstanceOf(object, pointerClass)) {
		jfieldID aField = this->env->GetFieldID(this->pointerClass, "address", "J");
		__int64 address = this->env->GetLongField(object, aField);
		dcArgPointer(callVM, (DCpointer)address);
	} else if (jenv->IsInstanceOf(object, longClass)) {
		jmethodID longValueMethod = jenv->GetMethodID(jcls, "longValue", "()J");
		jlong result = jenv->CallLongMethod(object, longValueMethod);
		dcArgLong(callVM, (DClong)result);
	} else if (jenv->IsInstanceOf(object, stringClass)) {
		jstring element = (jstring)object;
		const char* pchars = jenv->GetStringUTFChars(element, nullptr);
		dcArgPointer(callVM, (DCpointer)pchars);
		jenv->ReleaseStringUTFChars(element, pchars);
	} else if (jenv->IsInstanceOf(object, integerClass)) {
		jmethodID intValueMethod = jenv->GetMethodID(jcls, "intValue", "()I");
		jint result = jenv->CallIntMethod(object, intValueMethod);
		dcArgInt(callVM, (DCint)result);
	}
	else if (jenv->IsInstanceOf(object, doubleClass)) {
		jmethodID doubleValueMethod = jenv->GetMethodID(jcls, "doubleValue", "()D");
		jdouble result = jenv->CallDoubleMethod(object, doubleValueMethod);
		dcArgDouble(callVM, (DCdouble)result);
	}
	else if (jenv->IsInstanceOf(object, floatClass)) {
		jmethodID floatValueMethod = jenv->GetMethodID(jcls, "floatValue", "()F");
		jfloat result = jenv->CallFloatMethod(object, floatValueMethod);
		dcArgFloat(callVM, (DCfloat)result);
	}
	else if (jenv->IsInstanceOf(object, booleanClass)) {
		jmethodID boolValueMethod = jenv->GetMethodID(jcls, "booleanValue", "()Z");
		jboolean result = jenv->CallBooleanMethod(object, boolValueMethod);
		dcArgBool(callVM, (DCbool)result);
	}

	jenv->DeleteGlobalRef(object);
	jenv->DeleteGlobalRef(jcls);
	jenv->DeleteGlobalRef(stringClass);
	jenv->DeleteGlobalRef(integerClass);
	jenv->DeleteGlobalRef(doubleClass);
	jenv->DeleteGlobalRef(floatClass);
	jenv->DeleteGlobalRef(longClass);
	jenv->DeleteGlobalRef(booleanClass);
}

jobject JavaEnv::ValueToJVM(jobject retType, DCpointer address)
{
	jclass jcls = env->GetObjectClass(retType);

	jclass stringClass = env->FindClass("java/lang/String");
	jclass integerClass = env->FindClass("java/lang/Integer");
	jclass doubleClass = env->FindClass("java/lang/Double");
	jclass floatClass = env->FindClass("java/lang/Float");
	jclass longClass = env->FindClass("java/lang/Long");
	jclass booleanClass = env->FindClass("java/lang/Boolean");

	jmethodID equals = env->GetMethodID(jcls, "equals", "(Ljava/lang/Object;)Z");
	
	auto cleanup = [&]()
	{
		env->DeleteGlobalRef(jcls);
		env->DeleteGlobalRef(stringClass);
		env->DeleteGlobalRef(integerClass);
		env->DeleteGlobalRef(doubleClass);
		env->DeleteGlobalRef(floatClass);
		env->DeleteGlobalRef(longClass);
		env->DeleteGlobalRef(booleanClass);
	};

	if (env->CallBooleanMethod(retType, equals, stringClass)) {
		cleanup();
		return (jobject)env->NewStringUTF((char*)dcCallPointer(callVM, address));
	}
	else if (env->CallBooleanMethod(retType, equals, integerClass)) {
		jobject obj = env->NewObject(integerClass, env->GetMethodID(integerClass, "<init>", "(I)V"), dcCallInt(callVM, address));
		cleanup();
		return obj;
	}
	else if (env->CallBooleanMethod(retType, equals, doubleClass)) {
		jobject obj = env->NewObject(doubleClass, env->GetMethodID(doubleClass, "<init>", "(D)V"), dcCallDouble(callVM, address));
		cleanup();
		return obj;
	}
	else if (env->CallBooleanMethod(retType, equals, booleanClass)) {
		jobject obj = env->NewObject(booleanClass, env->GetMethodID(booleanClass, "<init>", "(Z)V"), dcCallBool(callVM, address));
		cleanup();
		return obj;
	}
	else if (env->CallBooleanMethod(retType, equals, floatClass)) {
		jobject obj = env->NewObject(floatClass, env->GetMethodID(floatClass, "<init>", "(F)V"), dcCallFloat(callVM, address));
		cleanup();
		return obj;
	}
	else if (env->CallBooleanMethod(retType, equals, longClass)) {
		jobject obj = env->NewObject(longClass, env->GetMethodID(longClass, "<init>", "(J)V"), dcCallLong(callVM, address));
		cleanup();
		return obj;
	}
	else if (env->CallBooleanMethod(retType, equals, pointerClass)) {
		std::cout << "Making pointer of result calling " << address << std::endl;
		void* res = dcCallPointer(callVM, address);
		std::cout << "Got pointer" << std::endl;
		jobject obj = CreatePointer(res);
		std::cout << "Made object!" << std::endl;
		cleanup();
		return obj;
	}

	return jobject();
}

jobject JavaEnv::JavaFunctionPointerInvoke(jobject instance, jclass clazz, jobjectArray args)
{
	jfieldID aField = this->env->GetFieldID(this->pointerClass, "address", "J");
	__int64 address = (__int64) GetModuleHandle(0) + this->env->GetLongField(instance, aField);
	int argsLength = this->env->GetArrayLength(args);
	dcReset(callVM);
	for (jsize i = 1; i < argsLength; i++)
		PushValueToCallVM(this->env->GetObjectArrayElement(args, i));
	return this->ValueToJVM(clazz, (DCpointer) address);
}

void JavaEnv::FireEvent(static std::string name, JavaArrayList list)
{
	jmethodID fireEventMethod = this->env->GetStaticMethodID(this->loaderClass, "fireEvent", "(Ljava/lang/String;Ljava/util/List;)V");
	jstring jName = this->env->NewStringUTF(name.c_str());
	this->env->CallStaticVoidMethod(this->loaderClass, fireEventMethod, jName, list.GetInstance());
}

void JavaEnv::FireEvent(std::string name)
{
	JavaArrayList emptyList(env);
	FireEvent(name, emptyList);
}

jobject JavaEnv::CreatePointer(void* address)
{
	static jmethodID constructor = env->GetMethodID(this->pointerClass, "<init>", "(J)V");
	return env->NewObject(this->pointerClass, constructor, (int64_t) address);
}
