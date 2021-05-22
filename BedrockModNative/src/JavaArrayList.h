#pragma once

#include <jni.h>

class JavaArrayList
{
private:
	jclass arrayListClass;
	JNIEnv* env;
	jobject instance;
public:
	JavaArrayList(JNIEnv* env);
	bool Add(jobject obj);
	int Size();
	jobject GetInstance() {
		return instance;
	};
};