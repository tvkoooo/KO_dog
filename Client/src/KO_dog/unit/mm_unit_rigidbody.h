#ifndef __mm_unit_rigidbody_h__
#define __mm_unit_rigidbody_h__

#include "physical/mm_bullet_shape_manager.h"

#include "LinearMath/btMotionState.h"
#include "LinearMath/btTransform.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"
#include "OgreSceneNode.h"

namespace mm
{
	class mm_unit_rigidbody	: public btMotionState
	{
	public:
		mm_bullet_shape_manager* d_shape_manager;
		mm_bullet_shape_data* d_shape_data;
		btRigidBody* d_rigidbody;//strong ref. 
		Ogre::SceneNode* d_scene_node;// weak ref.
		btTransform d_world_transform;
		bool d_world_transform_is_dirty; 
	public:
		mm_unit_rigidbody();
		virtual ~mm_unit_rigidbody();
	public:
		void set_collision_shape(const std::string& type, const std::string& parameter);
		btCollisionShape* get_collision_shape();

		void set_scene_node(Ogre::SceneNode* node);
		Ogre::SceneNode* get_scene_node();
	public:
		void shape_create(const std::string& type, const std::string& parameter);
		void shape_delete();
	public:
		void update(float _offset);
	private:
		//btMotionState
		virtual void getWorldTransform(btTransform& worldTrans ) const;
		virtual void setWorldTransform(const btTransform& worldTrans);
	};
}
#endif//__mm_unit_rigidbody_h__