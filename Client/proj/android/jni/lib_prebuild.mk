# prebuild.mk
################################################################################
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
include $(LOCAL_PATH)/lib_flake_prebuild.mk
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_flake_shared
LOCAL_SRC_FILES := $(MM_CORE)/flake/proj/android/libs/$(APP_ABI)/libmm_flake.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_flake_static
LOCAL_SRC_FILES := $(MM_CORE)/flake/proj/android/obj/local/$(APP_ABI)/libmm_flake.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIOgreRenderer_shared
LOCAL_SRC_FILES := $(MM_CORE)/flake/proj/android/libs/$(APP_ABI)/libCEGUIOgreRenderer.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIOgreRenderer_static
LOCAL_SRC_FILES := $(MM_CORE)/flake/proj/android/obj/local/$(APP_ABI)/libCEGUIOgreRenderer.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
