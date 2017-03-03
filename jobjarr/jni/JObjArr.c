#include "JObjArr.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Class:     JObjArr
 * Method:    init2DArr
 * Signature: (II)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_JObjArr_init2DArr
  (JNIEnv *jenv, jclass jcls, jint jcol, jint jrow)
{
	jobjectArray jobjarr;
	int i;
	jclass jicls = (*jenv)->FindClass(jenv, "[I");
	if(!jicls)
	{
		printf("Error in jicls");
		return NULL;
	}

	jobjarr = (*jenv)->NewObjectArray(jenv, jrow, jicls, NULL);
	if(!jobjarr)
	{
		printf("get object array Error\n");
		return NULL;
	}
	
	srand(time(NULL));
	for(i = 0; i < jrow; i++)
	{
		jint tmp[256];
		int j;
		jintArray iarr = (*jenv)->NewIntArray(jenv, jcol);
		if(!iarr)
		{
			printf("Error in get row int array\n");
			return NULL;
		}

		for(j = 0; j < jcol; j++)
		{
			tmp[j] = rand()%100 + 1;
		}

		(*jenv)->SetIntArrayRegion(jenv, iarr, 0, jcol, tmp);
		(*jenv)->SetObjectArrayElement(jenv, jobjarr, i, iarr);
		(*jenv)->DeleteLocalRef(jenv, iarr);
	}
	return jobjarr;
}