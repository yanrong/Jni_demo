#include <cstdio>
#include "hello.h"

JNIEXPORT void JNICALL Java_hello_print(JNIEnv *jenv, jobject jobj)
{
	printf("Java_hello_print\n");
	return ;
}