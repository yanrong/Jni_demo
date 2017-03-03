#include <stdio.h>

#include "JArray.h"

/*
 * Class:     JArray
 * Method:    sumArray
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_JArray_sumArray(JNIEnv *jenv, jobject jobj, jintArray jiarr)
{
	jint buf[10];
	jint i , sum = 0;
	(*jenv)->GetIntArrayRegion(jenv, jiarr, 0, 10, buf);
	for(i = 0; i < 10; i++)
		sum += buf[i];

	jsize* jparr = (*jenv)->GetIntArrayElements(jenv, jiarr, NULL);
	if(!jparr)
	{
		print("LOG: error in get elements");
		return ;
	}

	for( i = 0; i < 10; i++)
	{
		jparr[i] *= i;
	}
	return sum;
}