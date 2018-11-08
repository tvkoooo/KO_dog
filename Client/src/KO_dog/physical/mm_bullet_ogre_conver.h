#ifndef __mm_bullet_ogre_conver_h__
#define __mm_bullet_ogre_conver_h__
#include "LinearMath/btVector3.h"
#include "LinearMath/btQuaternion.h"
#include "OgreVector3.h"
#include "OgreQuaternion.h"
//////////////////////////////////////////////////////////////////////////
static btVector3 mm_vec3_og_to_bt(const Ogre::Vector3 &V)
{
	return btVector3(V.x, V.y, V.z);
};

static btQuaternion mm_quat_og_to_bt(const Ogre::Quaternion &Q)
{
	return btQuaternion(Q.x, Q.y, Q.z, Q.w);
};
static Ogre::Vector3 mm_vec3_bt_to_og(const btVector3 &V)
{
	return Ogre::Vector3(V.x(), V.y(), V.z());
};

static Ogre::Quaternion mm_quat_bt_to_og(const btQuaternion &Q)
{
	return Ogre::Quaternion(Q.w(), Q.x(), Q.y(), Q.z());
};
//////////////////////////////////////////////////////////////////////////
#endif//__mm_bullet_ogre_conver_h__