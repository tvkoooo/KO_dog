#ifndef __mm_bullet_shape_file_manager_h__
#define __mm_bullet_shape_file_manager_h__

#include "dish/mm_file_context.h"

#include "BulletCollision/CollisionShapes/btCollisionShape.h"
#include "Extras/Serialize/BulletWorldImporter/btBulletWorldImporter.h"

#include <string>
#include <map>

namespace mm
{
	class mm_bullet_shape_file_manager;

	class mm_bullet_shape_file_data
	{
	public:
		mm_bullet_shape_file_manager* d_manager;
		std::string d_asset;
		btBulletWorldImporter d_importer;
		btCollisionShape* d_collision_shape;
		mm_uint32_t d_reference;
	public:
		mm_bullet_shape_file_data();
		~mm_bullet_shape_file_data();
	};

	// bullet file must have only one btCollisionShape.
	class mm_bullet_shape_file_manager
	{
	public:
		typedef std::map<std::string, mm_bullet_shape_file_data*> collision_shape_map_type;
	public:
		struct mm_file_context* d_file_context;// weak ref.
		collision_shape_map_type d_collision_shape_map;
	public:
		mm_bullet_shape_file_manager();
		virtual ~mm_bullet_shape_file_manager();
	public:
		void set_file_context(struct mm_file_context* file_context);
		struct mm_file_context* get_file_context();
	public:
		mm_bullet_shape_file_data* produce(const std::string& fullname);
		void recycle(const std::string& fullname);
	public:
		mm_bullet_shape_file_data* add(const std::string& fullname);
		mm_bullet_shape_file_data* get(const std::string& fullname);
		mm_bullet_shape_file_data* get_instance(const std::string& fullname);
		void rmv(const std::string& fullname);
		void clear();
	};
}
#endif//__mm_bullet_shape_file_manager_h__