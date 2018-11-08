#include <jni.h>
#include "flake/mm_flake_activity.h"
#include "flake/mm_flake_activity_android.h"

#include "application/KO_dog.h"
//////////////////////////////////////////////////////////////////////////
#include "core/mm_prefix.h"
//////////////////////////////////////////////////////////////////////////
JNIEXPORT jlong JNICALL Java_org_mm_flake_mm_1flake_1activity_native_1alloc(JNIEnv* env, jobject obj)
{
	mm::mm_flake_activity* d_impl = (mm::mm_flake_activity*)mm::mm_flake_activity_native_alloc();
	jobject global_ref = (jobject)env->NewGlobalRef(obj);
	d_impl->set_impl(global_ref);
	return (jlong)d_impl;
}
JNIEXPORT void JNICALL Java_org_mm_flake_mm_1flake_1activity_native_1dealloc(JNIEnv* env, jobject obj)
{
	mm::mm_flake_activity* d_impl = mm_flake_activity_d_impl(env, obj);
	jobject global_ref = (jobject)d_impl->get_impl();
	env->DeleteGlobalRef(global_ref);
	mm::mm_flake_activity_native_dealloc(d_impl);
}

JNIEXPORT void JNICALL Java_org_mm_flake_mm_1flake_1activity_native_1init(JNIEnv* env, jobject obj)
{
	mm::mm_flake_activity* d_impl = mm_flake_activity_d_impl(env, obj);
	d_impl->init();
}
JNIEXPORT void JNICALL Java_org_mm_flake_mm_1flake_1activity_native_1destroy(JNIEnv* env, jobject obj)
{
	mm::mm_flake_activity* d_impl = mm_flake_activity_d_impl(env, obj);
	d_impl->destroy();
}
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"
//////////////////////////////////////////////////////////////////////////
