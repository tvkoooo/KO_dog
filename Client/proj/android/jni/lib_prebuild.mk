# prebuild.mk
################################################################################
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
include $(LOCAL_PATH)/lib_flake_prebuild.mk
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_data_lua_shared
LOCAL_SRC_FILES := $(MM_CORE)/data/proj/android/libs/$(APP_ABI)/libmm_data_lua.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_data_lua_static
LOCAL_SRC_FILES := $(MM_CORE)/data/proj/android/obj/local/$(APP_ABI)/libmm_data_lua.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_data_openssl_shared
LOCAL_SRC_FILES := $(MM_CORE)/data/proj/android/libs/$(APP_ABI)/libmm_data_openssl.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_data_openssl_static
LOCAL_SRC_FILES := $(MM_CORE)/data/proj/android/obj/local/$(APP_ABI)/libmm_data_openssl.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_data_protobuf_shared
LOCAL_SRC_FILES := $(MM_CORE)/data/proj/android/libs/$(APP_ABI)/libmm_data_protobuf.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_data_protobuf_static
LOCAL_SRC_FILES := $(MM_CORE)/data/proj/android/obj/local/$(APP_ABI)/libmm_data_protobuf.a
include $(PREBUILT_STATIC_LIBRARY)
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
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_emu_shared
LOCAL_SRC_FILES := $(MM_NES)/emu/proj/android/libs/$(APP_ABI)/libmm_emu.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_emu_static
LOCAL_SRC_FILES := $(MM_NES)/emu/proj/android/obj/local/$(APP_ABI)/libmm_emu.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libcrypto_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/openssl/proj_android/libs/$(APP_ABI)/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libcrypto_static
LOCAL_SRC_FILES := $(MM_LIB)/build/openssl/proj_android/obj/local/$(APP_ABI)/libcrypto.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)  
LOCAL_MODULE := libssl_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/openssl/proj_android/libs/$(APP_ABI)/libssl.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libssl_static
LOCAL_SRC_FILES := $(MM_LIB)/build/openssl/proj_android/obj/local/$(APP_ABI)/libssl.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libprotobuf_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/protobuf/proj_android/libs/$(APP_ABI)/libprotobuf.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libprotobuf_static
LOCAL_SRC_FILES := $(MM_LIB)/build/protobuf/proj_android/obj/local/$(APP_ABI)/libprotobuf.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################






