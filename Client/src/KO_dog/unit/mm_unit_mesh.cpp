#include "mm_unit_mesh.h"

#include "OgreSkeletonManager.h"

namespace mm
{	
	mm_unit_mesh::mm_unit_mesh()
		: d_scene_manager(NULL)
		, d_entity(NULL)
		, d_skeleton(NULL)
	{

	}
	mm_unit_mesh::~mm_unit_mesh()
	{

	}
	void mm_unit_mesh::set_ogre_entity(Ogre::Entity* entity)
	{
		this->d_entity = entity;
	}
	Ogre::Entity* mm_unit_mesh::get_ogre_entity()
	{
		return this->d_entity;
	}
	void mm_unit_mesh::set_mesh(const char* _mesh_name, const char* _mesh_file, const char* _mesh_group)
	{
		this->d_entity = this->d_scene_manager->createEntity(_mesh_name, _mesh_file, _mesh_group);
	}
	void mm_unit_mesh::set_skeleton(const char* _skeleton_file, const char* _skeleton_group)
	{
		Ogre::SkeletonManager& _skeleton_mgr = Ogre::SkeletonManager::getSingleton();
		Ogre::ResourcePtr _resource_ptr = _skeleton_mgr.load(_skeleton_file, _skeleton_group);
		this->d_skeleton = (Ogre::Skeleton*)_resource_ptr.get();
	}
	void mm_unit_mesh::add_skeleton_animation(const char* _skeleton_file)
	{

	}
	void mm_unit_mesh::rmv_skeleton_animation(const char* _skeleton_file)
	{

	}
	void mm_unit_mesh::attach_skeleton_animation()
	{

	}
	void mm_unit_mesh::detach_skeleton_animation()
	{

	}
}

