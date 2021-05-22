#include "JavaArrayList.h"
#include <iostream>

JavaArrayList::JavaArrayList(JNIEnv* env) : env{env}
{
	arrayListClass = env->FindClass("java/util/ArrayList");
	static jmethodID constructor = env->GetMethodID(arrayListClass, "<init>", "()V");
	instance = env->NewObject(arrayListClass, constructor);
}

bool JavaArrayList::Add(jobject obj)
{
	static jmethodID mId = env->GetMethodID(arrayListClass, "add", "(Ljava/lang/Object;)Z");
	return env->CallBooleanMethod(instance, mId, obj);
}

int JavaArrayList::Size()
{
	static jmethodID mId = env->GetMethodID(arrayListClass, "size", "()I");
	return env->CallIntMethod(instance, mId);
}
