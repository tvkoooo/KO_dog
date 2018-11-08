#include <jni.h>

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	return JNI_VERSION_1_4;
}
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
{

}
