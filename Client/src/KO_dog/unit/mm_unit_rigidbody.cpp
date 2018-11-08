#include "mm_unit_rigidbody.h"

#include "core/mm_logger.h"
#include "core/mm_alloc.h"

#include "dish/mm_file_context.h"

#include "physical/mm_bullet_ogre_conver.h"

namespace mm
{	
	mm_unit_rigidbody::mm_unit_rigidbody()
		: d_shape_manager(NULL)
		, d_shape_data(NULL)
		, d_rigidbody(NULL)
		, d_scene_node(NULL)
		, d_world_transform_is_dirty(false)
	{
		this->d_world_transform.setIdentity();
		this->d_rigidbody = new btRigidBody(1.0f, NULL, NULL, btVector3(0, 0, 0));
	}

	mm_unit_rigidbody::~mm_unit_rigidbody()
	{
		delete this->d_rigidbody;
		this->d_rigidbody = NULL;
	}
	void mm_unit_rigidbody::shape_create(const std::string& type, const std::string& parameter)
	{
		this->shape_delete();
		this->d_shape_data = this->d_shape_manager->produce(type, parameter);
		this->d_rigidbody->setCollisionShape(this->d_shape_data->d_collision_shape);
	}
	void mm_unit_rigidbody::shape_delete()
	{
		if (NULL != this->d_shape_data)
		{
			this->d_shape_manager->recycle(this->d_shape_data);
			this->d_shape_data = NULL;
			this->d_rigidbody->setCollisionShape(NULL);
		}
	}
	void mm_unit_rigidbody::set_collision_shape(const std::string& type, const std::string& parameter)
	{
		this->shape_create(type, parameter);
	}
	btCollisionShape* mm_unit_rigidbody::get_collision_shape()
	{
		return this->d_rigidbody->getCollisionShape();
	}

	void mm_unit_rigidbody::set_scene_node(Ogre::SceneNode* node)
	{
		this->d_scene_node = node;
	}
	Ogre::SceneNode* mm_unit_rigidbody::get_scene_node()
	{
		return this->d_scene_node;
	}

	void mm_unit_rigidbody::update(float _offset)
	{
		if (this->d_world_transform_is_dirty)
		{
			this->d_scene_node->setPosition(mm_vec3_bt_to_og(d_world_transform.getOrigin()));
			this->d_scene_node->setOrientation(mm_quat_bt_to_og(d_world_transform.getRotation()));
			this->d_world_transform_is_dirty = false;
		}
	}
	//btMotionState
	void mm_unit_rigidbody::getWorldTransform(btTransform& worldTrans ) const
	{
		worldTrans = this->d_world_transform;
	}
	void mm_unit_rigidbody::setWorldTransform(const btTransform& worldTrans)
	{
		this->d_world_transform = worldTrans;
		this->d_world_transform_is_dirty = true;
	}
}

