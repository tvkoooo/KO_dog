#ifndef __mm_unit_mesh_h__
#define __mm_unit_mesh_h__

#include "core/mm_core.h"

#include "OgreEntity.h"
#include "OgreSceneManager.h"

namespace mm
{
	class mm_unit_mesh
	{
	public:
		Ogre::SceneManager* d_scene_manager;
		Ogre::Entity* d_entity;
		Ogre::Skeleton* d_skeleton;

		std::string d_resource_group;
		std::string d_resource_directory;
		std::string d_file_mesh;
		std::string d_file_skeleton;
		std::string d_file_rigidbody;
	public:
		mm_unit_mesh();
		virtual ~mm_unit_mesh();
	public:
		void set_ogre_entity(Ogre::Entity* entity);
		Ogre::Entity* get_ogre_entity();
	public:
		void set_mesh(const char* _mesh_name, const char* _mesh_file, const char* _mesh_group);
		void set_skeleton(const char* _skeleton_file, const char* _skeleton_group);
	public:
		void add_skeleton_animation(const char* _skeleton_file);
		void rmv_skeleton_animation(const char* _skeleton_file);
	public:
		void attach_skeleton_animation();
		void detach_skeleton_animation();
	};
}
#endif//__mm_unit_mesh_h__