#include <iostream>
#include <cstdio>
#include "PromptString.h"

/*
 * Class:     PromptString
 * Method:    printStr
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_PromptString_printStr(JNIEnv *jenv, jobject jobj, jstring jstr)
{
	char javastr[256];
	const char *jchar;
	jchar = jenv->GetStringUTFChars(jstr, NULL);
	if(!jchar) 
	{
		std::cout<<"ERROR in get String"<<std::endl;
		return;
	}
	//sprintf(javastr,"%s",jchar);
	int len = jenv->GetStringLength(jstr);
	jenv->GetStringUTFRegion(jstr,0,len,javastr);
	std::cout << javastr << std::endl;
	jenv->ReleaseStringUTFChars(jstr, jchar);
	return ;
}

/*
 * Class:     PromptString
 * Method:    getStr
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_PromptString_getStr(JNIEnv *jenv , jobject jobj)
{
	char buf[256] = "hello, i from C++";
	return jenv->NewStringUTF(buf);
}
