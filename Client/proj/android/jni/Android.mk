LOCAL_PATH := $(call my-dir)

include $(LOCAL_PATH)/lib_prebuild.mk


include $(LOCAL_PATH)/libKO_dog_shared.mk

$(call import-module,android/cpufeatures) 
$(call import-module,android/native_app_glue)