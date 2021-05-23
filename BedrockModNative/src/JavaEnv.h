#pragma once

#include <jni.h>
#include <cstring>
#include <string>
#include <memory>
#include <dyncall.h>
#include "JavaArrayList.h"

class JavaEnv
{
private:
	JavaVM* vm;
	JNIEnv* env;
	jclass functionPointerClass;
	jclass pointerClass;
	jclass loaderClass;
	void PushValueToCallVM(jobject object);
	jobject ValueToJVM(jobject retType, DCpointer address);
public:
	JavaEnv(std::string classPath);
	void Destroy() {
		this->vm->DestroyJavaVM();
	}
	JavaVM* GetVM() {
		return this->vm;
	}
	JNIEnv* GetEnv() {
		return this->env;
	}
	jobject JavaFunctionPointerInvoke(jobject instance, jclass clazz, jobjectArray args);
	void FireEvent(static std::string name, JavaArrayList list);
	void FireEvent(static std::string name);
	jobject CreatePointer(void* address);
};