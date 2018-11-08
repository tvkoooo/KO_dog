#include "mm_util_mesh.h"
#include "OgreSkeletonManager.h"
#include "OgreSkeletonInstance.h"
void mm_attach_skeleton(Ogre::Skeleton* _mainSkeleton, const Ogre::String& _skeletonFile,const Ogre::String& _groupName /*= Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME*/)
{
	Ogre::SkeletonManager& _skeleton_manager = Ogre::SkeletonManager::getSingleton();
	Ogre::ResourcePtr _resource_ptr  = _skeleton_manager.load(_skeletonFile, _groupName);
	Ogre::SkeletonPtr _skeleton = Ogre::static_pointer_cast<Ogre::Skeleton>(_resource_ptr);
	Ogre::Skeleton* _skeleton_ptr = _skeleton.get();
	Ogre::Skeleton::BoneHandleMap _boneHandleMap;
	_skeleton_ptr->_buildMapBoneByHandle(_skeleton_ptr,_boneHandleMap);
	_mainSkeleton->_mergeSkeletonAnimations(_skeleton_ptr,_boneHandleMap);
}
void mm_detach_skeleton(Ogre::Skeleton* _mainSkeleton, const Ogre::String& _skeletonName)
{
	_mainSkeleton->removeAnimation(_skeletonName);
}