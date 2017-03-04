#include <stdio.h>
#include "JCallBack.h"

JNIEXPORT void JNICALL Java_JCallBack_callMethod(JNIEnv *jenv, jobject jobj)
{
	//get method's class
	jclass jcls = (*jenv)->GetObjectClass(jenv, jobj);
	//ID is neccessary to call method in java
	jmethodID jmid = (*jenv)->GetMethodID(jenv, jcls, "callInJava","()V");
	if(!jmid)
	{
		printf("Error at %d %s", __LINE__, __func__);
		return;
	}

	(*jenv)->CallVoidMethod(jenv, jobj, jmid);
	//call static method
	jmethodID jsmid = (*jenv)->GetStaticMethodID(jenv, jcls, "callStaticMethod","(I)I");
	jint k = (*jenv)->CallStaticIntMethod(jenv, jobj, jsmid, 5);
	printf("In C the value puls 1 = %d\n", k);
/*
	//call construction method
	jclass jStrClzz = (*jenv)->FindClass(jenv, "java/lang/String");
	jmethodID jcmid = (*jenv)->GetMethodID(jenv, jcls, "<init>","([C)V");
	if(!jcmid || !jStrClzz)
	{
		printf("Error at %d %s\n", __LINE__, __func__);
		return;
	}
	jcharArray jch_arr = NewCharArray(jenv, 10);
	if(!jch_arr)
	{
		printf("Error at %d %s\n", __LINE__, __func__);
		return;
	}
	(*jenv)->SetCharArrayRegion(jenv, jch_arr, 0, 10, "C lang");
	jstring jstr = (*jenv)->NewObject(jenv, jStrClzz, jcmid, jch_arr);
	printf("jstr = %s",jstr, __LINE__, __func__);
	(*jenv)->DeleteLocalRef(jenv, jch_arr);
	(*jenv)->DeleteLocalRef(jenv, jStrClzz);*/
}
