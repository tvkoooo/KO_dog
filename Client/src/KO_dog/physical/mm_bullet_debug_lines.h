#ifndef __mm_bullet_debug_lines_h__
#define __mm_bullet_debug_lines_h__
#include "LinearMath/btIDebugDraw.h"
#include "OgreSimpleRenderable.h"
//////////////////////////////////////////////////////////////////////////
class mm_bullet_debug_lines : public Ogre::SimpleRenderable
{
public:
	typedef std::vector<Ogre::Vector3> Vector3Array;
public:
	Ogre::HardwareVertexBufferSharedPtr d_vertex_buffer;
	Vector3Array d_points;
public:
	mm_bullet_debug_lines();
	virtual ~mm_bullet_debug_lines();
public:
	Ogre::Real getSquaredViewDepth(const Ogre::Camera *cam) const;
	Ogre::Real getBoundingRadius(void) const;
public:
	// make sure at gl thread.
	virtual void drawGeometry();
public:
	void clear();
public:
	void addLine(const Ogre::Vector3 &start,const Ogre::Vector3 &end);
	void addLine(Ogre::Real start_x, Ogre::Real start_y, Ogre::Real start_z, 
		Ogre::Real end_x, Ogre::Real end_y, Ogre::Real end_z);
	void addPoint(const Ogre::Vector3 &pt);
	void addPoint(Ogre::Real x, Ogre::Real y, Ogre::Real z);
};
//////////////////////////////////////////////////////////////////////////
#endif//__mm_bullet_debug_lines_h__