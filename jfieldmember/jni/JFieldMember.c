#include <stdio.h>
#include "JFieldMember.h"

JNIEXPORT void JNICALL Java_JFieldMember_accessField(JNIEnv *jenv, jobject jobj)
{
	jfieldID jfid;
	jstring jstr;
	const char *str;

	jclass jcls = (*jenv)->GetObjectClass(jenv, jobj);
	jfid = (*jenv)->GetFieldID(jenv, jcls, "str", "Ljava/lang/String;");
	if(!jfid)
	{
		printf("Error at %d %s", __LINE__, __func__);
		return;
	}

	jstr = (*jenv)->GetObjectField(jenv, jobj, jfid);
	str = (*jenv)->GetStringUTFChars(jenv, jstr, NULL);
	if(!str)
	{
		printf("Error at %d %s", __LINE__, __func__);
		return ;
	}

	printf("in C fm.str = \"%s\"\n", str);
	(*jenv)->ReleaseStringUTFChars(jenv, jstr, str);

	jstr = (*jenv)->NewStringUTF(jenv, "string field changed in C");
	if(!jstr)
	{
		printf("Error at %d %s", __LINE__, __func__);
		return ;
	}

	(*jenv)->SetObjectField(jenv, jobj, jfid, jstr);
	return ;
}