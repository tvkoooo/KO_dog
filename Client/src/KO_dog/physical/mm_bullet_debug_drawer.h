#ifndef __mm_bullet_debug_drawer_h__
#define __mm_bullet_debug_drawer_h__
#include "core/mm_spinlock.h"
#include "mm_bullet_debug_lines.h"
#include "LinearMath/btIDebugDraw.h"
#include "OgreSimpleRenderable.h"
#include "OgreSceneNode.h"
//////////////////////////////////////////////////////////////////////////
class mm_bullet_debug_drawer : public btIDebugDraw
{
public:
	static btVector3 d_axis_x_color;//(0.7f,0.0f,0.0f)
	static btVector3 d_axis_y_color;//(0.0f,0.7f,0.0f)
	static btVector3 d_axis_z_color;//(0.0f,0.0f,0.7f)
public:
	Ogre::SceneNode* d_node_debug_draw;// weak ref.
	//
	mm_bullet_debug_lines d_axis_x;
	mm_bullet_debug_lines d_axis_y;
	mm_bullet_debug_lines d_axis_z;
	mm_bullet_debug_lines d_comm_draw;
	//
	int d_debug_mode;
	mm_atomic_t d_locker;
public:
	mm_bullet_debug_drawer();
	virtual ~mm_bullet_debug_drawer();
public:
	virtual void drawLine(const btVector3& from,const btVector3& to,const btVector3& color);
	virtual void drawLine(const btVector3& from,const btVector3& to, const btVector3& fromColor, const btVector3& toColor);
	virtual void drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color);
	virtual void reportErrorWarning(const char* warningString);
	virtual void draw3dText(const btVector3& location,const char* textString);
public:
	virtual void setDebugMode(int debugMode);
	virtual int getDebugMode() const;
public:
	void setSceneNode(Ogre::SceneNode* _node);
	Ogre::SceneNode* getSceneNode() const;
public:
	// make sure at gl thread.
	virtual void drawGeometry();
	// make sure at gl thread.
	virtual void clearGeometry();
};
//////////////////////////////////////////////////////////////////////////
#endif//__mm_bullet_debug_drawer_h__