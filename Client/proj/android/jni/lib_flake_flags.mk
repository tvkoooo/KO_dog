LOCAL_LDLIBS    += -lz
LOCAL_LDLIBS 	+= -lOpenSLES 
LOCAL_LDLIBS	+= -lEGL -lGLESv2
##########################################################################
LOCAL_SHARED_LIBRARIES += gnustl_shared

LOCAL_SHARED_LIBRARIES += libzzip_shared
LOCAL_SHARED_LIBRARIES += libtinyxml_shared

LOCAL_SHARED_LIBRARIES += libmm_core_shared
LOCAL_SHARED_LIBRARIES += libmm_dish_shared

LOCAL_SHARED_LIBRARIES += libfreetype_shared
LOCAL_SHARED_LIBRARIES += libFreeImage_shared

LOCAL_SHARED_LIBRARIES += libOgreMain_shared
LOCAL_SHARED_LIBRARIES += libRenderSystem_GLES2_shared
LOCAL_SHARED_LIBRARIES += libOgreComponents_shared

LOCAL_SHARED_LIBRARIES += libpcre_shared
LOCAL_SHARED_LIBRARIES += libiconv_shared

LOCAL_SHARED_LIBRARIES += libCEGUI_shared
## not must be.
LOCAL_SHARED_LIBRARIES += libOpenAL_shared

LOCAL_SHARED_LIBRARIES += libogg_shared
LOCAL_SHARED_LIBRARIES += libvorbis_shared

LOCAL_SHARED_LIBRARIES += libOgreAL_shared
LOCAL_SHARED_LIBRARIES += libogre-oggsound_shared

LOCAL_SHARED_LIBRARIES += libPlugin_ParticleUniverse_shared
##########################################################################
LOCAL_STATIC_LIBRARIES += libOIS_static

LOCAL_STATIC_LIBRARIES += cpufeatures
LOCAL_STATIC_LIBRARIES += android_native_app_glue
##########################################################################
LOCAL_C_INCLUDES += $(ANDROID_NDK)/sources/cpufeatures 

LOCAL_C_INCLUDES += $(MM_CORE)/mm/src
LOCAL_C_INCLUDES += $(MM_CORE)/mm/src/os/android
LOCAL_C_INCLUDES += $(MM_CORE)/dish/src
LOCAL_C_INCLUDES += $(MM_CORE)/dish/src/os/android
LOCAL_C_INCLUDES += $(MM_CORE)/flake/src
LOCAL_C_INCLUDES += $(MM_CORE)/flake/src/os/android

LOCAL_C_INCLUDES += $(MM_LIB)/src/lua/src
LOCAL_C_INCLUDES += $(MM_LIB)/build/libiconv/include/android
LOCAL_C_INCLUDES += $(MM_LIB)/src/libiconv/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/ois/includes

LOCAL_C_INCLUDES += $(MM_LIB)/build/Ogre/include/android
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/OgreMain/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/RenderSystems/GLES2
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/RenderSystems/GLES2/EGL
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/Components/Overlay/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/Components/Paging/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/Components/RTShaderSystem/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/Components/Terrain/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/Components/Volume/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/PlugIns/BSPSceneManager/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/PlugIns/OctreeSceneManager/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/PlugIns/OctreeZone/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/PlugIns/ParticleFX/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/Ogre/PlugIns/PCZSceneManager/include

LOCAL_C_INCLUDES += $(MM_LIB)/build/cegui/include/android
LOCAL_C_INCLUDES += $(MM_LIB)/src/cegui/cegui/include

LOCAL_C_INCLUDES += $(MM_LIB)/src/freetype/include

LOCAL_C_INCLUDES += $(MM_LIB)/src/FreeImage/Source

LOCAL_C_INCLUDES += $(MM_LIB)/src/bullet3
LOCAL_C_INCLUDES += $(MM_LIB)/src/bullet3/src

LOCAL_C_INCLUDES += $(MM_LIB)/src/OpenAL/include

LOCAL_C_INCLUDES += $(MM_LIB)/build/libogg/include/android
LOCAL_C_INCLUDES += $(MM_LIB)/src/libogg/include

LOCAL_C_INCLUDES += $(MM_LIB)/src/libvorbis/include

LOCAL_C_INCLUDES += $(MM_LIB)/src/OgreAL/include
LOCAL_C_INCLUDES += $(MM_LIB)/src/ogre-oggsound/include

LOCAL_C_INCLUDES += $(MM_LIB)/src/ParticleUniverse/Plugins/ParticleUniverse/include

LOCAL_C_INCLUDES += $(MM_LIB)/src/zziplib

LOCAL_C_INCLUDES += $(MM_LIB)/src/tinyxml

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../src
##########################################################################