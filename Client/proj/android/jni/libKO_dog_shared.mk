LOCAL_PATH := $(call my-dir)
LOCAL_MAKEFILE := $(this-makefile)
########################################################################
include $(CLEAR_VARS)  
########################################################################
LOCAL_MODULE := libKO_dog_shared
LOCAL_MODULE_FILENAME := libKO_dog
########################################################################
LOCAL_CFLAGS += -fPIC
LOCAL_CFLAGS += -D__ANDROID__

LOCAL_CFLAGS += -Wall
LOCAL_CFLAGS += -Wno-undefined-var-template

LOCAL_CFLAGS += -Wno-unused-function
LOCAL_CFLAGS += -Wno-unused-variable
LOCAL_CFLAGS += -Wno-unused-value
LOCAL_CFLAGS += -Wa,-mimplicit-it=thumb

LOCAL_CXXFLAGS += -DMM_STATIC_RAPTORQ

LOCAL_CXXFLAGS += -std=c++11 
LOCAL_CXXFLAGS += -fexceptions 
LOCAL_CXXFLAGS += -frtti
########################################################################
LOCAL_LDLIBS += -fPIC
########################################################################
LOCAL_SHARED_LIBRARIES += libCEGUIOgreRenderer_shared
LOCAL_SHARED_LIBRARIES += libmm_net_shared
LOCAL_SHARED_LIBRARIES += libmm_flake_shared
LOCAL_STATIC_LIBRARIES += libmm_emu_shared
########################################################################
LOCAL_STATIC_LIBRARIES += libmm_data_openssl_static
LOCAL_STATIC_LIBRARIES += libmm_data_lua_static
LOCAL_STATIC_LIBRARIES += libmm_data_protobuf_static

LOCAL_STATIC_LIBRARIES += libcrypto_static
LOCAL_STATIC_LIBRARIES += libprotobuf_static
LOCAL_STATIC_LIBRARIES += liblua_static

LOCAL_STATIC_LIBRARIES += libOgreAL_static

LOCAL_STATIC_LIBRARIES += libBulletWorldImporter_static
LOCAL_STATIC_LIBRARIES += libBulletFileLoader_static
LOCAL_STATIC_LIBRARIES += libGIMPACTUtils_static
LOCAL_STATIC_LIBRARIES += libConvexDecomposition_static
LOCAL_STATIC_LIBRARIES += libBulletDynamics_static
LOCAL_STATIC_LIBRARIES += libBulletCollision_static
LOCAL_STATIC_LIBRARIES += libLinearMath_static
########################################################################
INSTALL_MODEL := mm_core_packet
INSTALL_FILES := $(MM_CORE)/mm/proj/android/bin/mm_core.jar
INSTALL_OPATH := $(NDK_APP_LIBS_OUT)
include $(MM_MAKE_HOME)/compile/prebuilt-install.mk
########################################################################
INSTALL_MODEL := mm_flake_packet
INSTALL_FILES := $(MM_CORE)/flake/proj/android/bin/mm_flake.jar
INSTALL_OPATH := $(NDK_APP_LIBS_OUT)
include $(MM_MAKE_HOME)/compile/prebuilt-install.mk
########################################################################
INSTALL_MODEL := mm_flake_native_lib
INSTALL_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libPlugin_ParticleFX.so
INSTALL_FILES += $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libPlugin_OctreeSceneManager.so
INSTALL_FILES += $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUICoreWindowRendererSet.so
INSTALL_OPATH := $(NDK_APP_LIBS_OUT)/$(APP_ABI)
include $(MM_MAKE_HOME)/compile/prebuilt-install.mk
########################################################################
LOCAL_C_INCLUDES += $(MM_LIB)/src/protobuf/src
LOCAL_C_INCLUDES += $(MM_LIB)/src/openssl/include
LOCAL_C_INCLUDES += $(MM_LIB)/build/openssl/include/android
LOCAL_C_INCLUDES += $(MM_CORE)/data/src
LOCAL_C_INCLUDES += $(MM_NES)/emu/src
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../src/KO_dog
########################################################################
LOCAL_SRC_FILES  += 
########################################################################
include $(LOCAL_PATH)/lib_flake_flags.mk
########################################################################
MY_SOURCES_PATH       := 
MY_SOURCES_FILTER_OUT := 
MY_SOURCES_EXTENSION  := 
#  
# config self source file path ,suffix.
MY_SOURCES_PATH += $(LOCAL_PATH)/../../../src/KO_dog
MY_SOURCES_PATH += $(LOCAL_PATH)/../../../src/protodef/cxx/protodef
MY_SOURCES_PATH += $(LOCAL_PATH)/android

# config filter out file and path.
# MY_SOURCES_FILTER_OUT += ../../filter-out-directory%
# MY_SOURCES_FILTER_OUT += ../../filter-out-source.c

MY_SOURCES_EXTENSION += .cpp .c .cc .S
####
include $(MM_MAKE_HOME)/compile/definitions-sources.mk
include $(MM_MAKE_HOME)/compile/sources-rwildcard.mk
########################################################################
include $(BUILD_SHARED_LIBRARY)
########################################################################