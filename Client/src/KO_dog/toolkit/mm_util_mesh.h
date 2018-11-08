#ifndef __mm_util_mesh_h__
#define __mm_util_mesh_h__
#include "OgreEntity.h"
#include "OgreResourceGroupManager.h"
//////////////////////////////////////////////////////////////////////////
extern void mm_attach_skeleton(Ogre::Skeleton* _mainSkeleton, const Ogre::String& _skeletonFile,const Ogre::String& _groupName = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
extern void mm_detach_skeleton(Ogre::Skeleton* _mainSkeleton, const Ogre::String& _skeletonName);
//////////////////////////////////////////////////////////////////////////
#endif//__mm_util_mesh_h__