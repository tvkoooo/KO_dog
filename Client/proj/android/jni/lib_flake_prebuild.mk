# prebuild.mk
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libiconv_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/libiconv/proj_android/libs/$(APP_ABI)/libiconv.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libiconv_static
LOCAL_SRC_FILES := $(MM_LIB)/build/libiconv/proj_android/obj/local/$(APP_ABI)/libiconv.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := liblua_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/lua/proj_android/libs/$(APP_ABI)/liblua.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := liblua_static
LOCAL_SRC_FILES := $(MM_LIB)/build/lua/proj_android/obj/local/$(APP_ABI)/liblua.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libOIS_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/OIS/proj_android/libs/$(APP_ABI)/libOIS.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libOIS_static
LOCAL_SRC_FILES := $(MM_LIB)/build/OIS/proj_android/obj/local/$(APP_ABI)/libOIS.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_core_shared
LOCAL_SRC_FILES := $(MM_CORE)/mm/proj/android/libs/$(APP_ABI)/libmm_core.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_core_static
LOCAL_SRC_FILES := $(MM_CORE)/mm/proj/android/obj/local/$(APP_ABI)/libmm_core.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_net_shared
LOCAL_SRC_FILES := $(MM_CORE)/mm/proj/android/libs/$(APP_ABI)/libmm_net.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_net_static
LOCAL_SRC_FILES := $(MM_CORE)/mm/proj/android/obj/local/$(APP_ABI)/libmm_net.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_dish_shared
LOCAL_SRC_FILES := $(MM_CORE)/dish/proj/android/libs/$(APP_ABI)/libmm_dish.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libmm_dish_static
LOCAL_SRC_FILES := $(MM_CORE)/dish/proj/android/obj/local/$(APP_ABI)/libmm_dish.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libfreetype_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/freetype/proj_android/libs/$(APP_ABI)/libfreetype.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libfreetype_static
LOCAL_SRC_FILES := $(MM_LIB)/build/freetype/proj_android/obj/local/$(APP_ABI)/libfreetype.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libFreeImage_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/FreeImage/proj_android/libs/$(APP_ABI)/libFreeImage.so
include $(PREBUILT_SHARED_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libzzip_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/zziplib/proj_android/libs/$(APP_ABI)/libzzip.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libzzip_static
LOCAL_SRC_FILES := $(MM_LIB)/build/zziplib/proj_android/obj/local/$(APP_ABI)/libzzip.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libOgreMain_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libOgreMain.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libOgreMain_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libOgreMain.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_BSPSceneManager_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libPlugin_BSPSceneManager.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_BSPSceneManager_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libPlugin_BSPSceneManager.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_OctreeSceneManager_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libPlugin_OctreeSceneManager.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_OctreeSceneManager_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libPlugin_OctreeSceneManager.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_PCZSceneManager_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libPlugin_PCZSceneManager.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_PCZSceneManager_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libPlugin_PCZSceneManager.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_OctreeZone_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libPlugin_OctreeZone.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_OctreeZone_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libPlugin_OctreeZone.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_ParticleFX_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libPlugin_ParticleFX.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_ParticleFX_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libPlugin_ParticleFX.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libRenderSystem_GLES2_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libRenderSystem_GLES2.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libRenderSystem_GLES2_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libRenderSystem_GLES2.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_RTShaderSystem_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libComponents_RTShaderSystem.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_RTShaderSystem_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libComponents_RTShaderSystem.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Overlay_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libComponents_Overlay.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Overlay_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libComponents_Overlay.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Paging_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libComponents_Paging.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Paging_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libComponents_Paging.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Terrain_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libComponents_Terrain.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Terrain_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libComponents_Terrain.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Volume_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libComponents_Volume.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libComponents_Volume_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libComponents_Volume.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libOgreComponents_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/libs/$(APP_ABI)/libOgreComponents.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libOgreComponents_static
LOCAL_SRC_FILES := $(MM_LIB)/build/Ogre/proj_android/obj/local/$(APP_ABI)/libOgreComponents.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libOpenAL_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/OpenAL/proj_android/libs/$(APP_ABI)/libOpenAL.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libOpenAL_static
LOCAL_SRC_FILES := $(MM_LIB)/build/OpenAL/proj_android/obj/local/$(APP_ABI)/libOpenAL.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libogg_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/libogg/proj_android/libs/$(APP_ABI)/libogg.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libogg_static
LOCAL_SRC_FILES := $(MM_LIB)/build/libogg/proj_android/obj/local/$(APP_ABI)/libogg.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libvorbis_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/libvorbis/proj_android/libs/$(APP_ABI)/libvorbis.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libvorbis_static
LOCAL_SRC_FILES := $(MM_LIB)/build/libvorbis/proj_android/obj/local/$(APP_ABI)/libvorbis.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libOgreAL_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/OgreAL/proj_android/libs/$(APP_ABI)/libOgreAL.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libOgreAL_static
LOCAL_SRC_FILES := $(MM_LIB)/build/OgreAL/proj_android/obj/local/$(APP_ABI)/libOgreAL.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libogre-oggsound_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/ogre-oggsound/proj_android/libs/$(APP_ABI)/libogre-oggsound.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libogre-oggsound_static
LOCAL_SRC_FILES := $(MM_LIB)/build/ogre-oggsound/proj_android/obj/local/$(APP_ABI)/libogre-oggsound.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_ParticleUniverse_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/ParticleUniverse/proj_android/libs/$(APP_ABI)/libPlugin_ParticleUniverse.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libPlugin_ParticleUniverse_static
LOCAL_SRC_FILES := $(MM_LIB)/build/ParticleUniverse/proj_android/obj/local/$(APP_ABI)/libPlugin_ParticleUniverse.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libLinearMath_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libLinearMath.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libLinearMath_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libLinearMath.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Common_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBullet3Common.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Common_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBullet3Common.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Collision_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBullet3Collision.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Collision_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBullet3Collision.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Dynamics_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBullet3Dynamics.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Dynamics_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBullet3Dynamics.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Geometry_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBullet3Geometry.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3Geometry_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBullet3Geometry.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3OpenCL_clew_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBullet3OpenCL_clew.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet3OpenCL_clew_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBullet3OpenCL_clew.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletCollision_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletCollision.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletCollision_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletCollision.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletDynamics_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletDynamics.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletDynamics_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletDynamics.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletSoftBody_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletSoftBody.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletSoftBody_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletSoftBody.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletInverseDynamics_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletInverseDynamics.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletInverseDynamics_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletInverseDynamics.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libConvexDecomposition_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libConvexDecomposition.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libConvexDecomposition_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libConvexDecomposition.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBlenderSerialize_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBlenderSerialize.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBlenderSerialize_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBlenderSerialize.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet2FileLoader_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBullet2FileLoader.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBullet2FileLoader_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBullet2FileLoader.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletFileLoader_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletFileLoader.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletFileLoader_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletFileLoader.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletInverseDynamicsUtils_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletInverseDynamicsUtils.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletInverseDynamicsUtils_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletInverseDynamicsUtils.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletWorldImporter_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletWorldImporter.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletWorldImporter_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletWorldImporter.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletXmlWorldImporter_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libBulletXmlWorldImporter.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libBulletXmlWorldImporter_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libBulletXmlWorldImporter.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libGIMPACTUtils_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libGIMPACTUtils.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libGIMPACTUtils_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libGIMPACTUtils.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libHACD_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/libs/$(APP_ABI)/libHACD.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libHACD_static
LOCAL_SRC_FILES := $(MM_LIB)/build/bullet3/proj_android/obj/local/$(APP_ABI)/libHACD.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libtinyxml_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/tinyxml/proj_android/libs/$(APP_ABI)/libtinyxml.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libtinyxml_static
LOCAL_SRC_FILES := $(MM_LIB)/build/tinyxml/proj_android/obj/local/$(APP_ABI)/libtinyxml.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libpcre_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/pcre/proj_android/libs/$(APP_ABI)/libpcre.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libpcre_static
LOCAL_SRC_FILES := $(MM_LIB)/build/pcre/proj_android/obj/local/$(APP_ABI)/libpcre.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################

################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIMain_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUIMain.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIMain_static
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/obj/local/$(APP_ABI)/libCEGUIMain.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUICommonDialogs_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUICommonDialogs.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUICommonDialogs_static
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/obj/local/$(APP_ABI)/libCEGUICommonDialogs.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUICoreWindowRendererSet_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUICoreWindowRendererSet.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUICoreWindowRendererSet_static
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/obj/local/$(APP_ABI)/libCEGUICoreWindowRendererSet.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIImageCodecFreeImage_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUIImageCodecFreeImage.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIImageCodecFreeImage_static
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/obj/local/$(APP_ABI)/libCEGUIImageCodecFreeImage.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIRendererOgre_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUIRendererOgre.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIRendererOgre_static
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/obj/local/$(APP_ABI)/libCEGUIRendererOgre.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIXMLParserTinyXML_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUIXMLParserTinyXML.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUIXMLParserTinyXML_static
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/obj/local/$(APP_ABI)/libCEGUIXMLParserTinyXML.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUI_shared
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/libs/$(APP_ABI)/libCEGUI.so
include $(PREBUILT_SHARED_LIBRARY)
include $(CLEAR_VARS)  
LOCAL_MODULE := libCEGUI_static
LOCAL_SRC_FILES := $(MM_LIB)/build/cegui/proj_android/obj/local/$(APP_ABI)/libCEGUI.a
include $(PREBUILT_STATIC_LIBRARY)
################################################################################
