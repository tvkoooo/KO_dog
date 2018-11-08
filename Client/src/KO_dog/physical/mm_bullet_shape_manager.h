#ifndef __mm_bullet_shape_manager_h__
#define __mm_bullet_shape_manager_h__

#include "dish/mm_file_context.h"

#include "physical/mm_bullet_shape_file_manager.h"

namespace mm
{
	class mm_bullet_shape_manager;

	class mm_bullet_shape_data
	{
	public:
		mm_bullet_shape_manager* d_manager;
		std::string d_name;
		std::string d_asset;
		btCollisionShape* d_collision_shape;
		int d_create_type;
		mm_uint32_t d_reference;
	public:
		mm_bullet_shape_data();
		~mm_bullet_shape_data();
	};

	class mm_bullet_shape_manager
	{
	public:
		enum mm_create_type
		{
			none,
			bullet_file,
			box,
			capsule_x,
			capsule_y,
			capsule_z,
			cone_x,
			cone_y,
			cone_z,
			cylinder_x,
			cylinder_y,
			cylinder_z,
			sphere,
			static_plane,
		};
	public:
		typedef btCollisionShape* (mm_bullet_shape_manager::*shape_create_function)(mm_bullet_shape_data* shape_data, const std::string& parameter);
		typedef std::map<std::string, shape_create_function> shape_create_function_map_type;

		typedef std::map<std::string, mm_bullet_shape_data*> collision_shape_data_map_type;
	public:
		mm_bullet_shape_file_manager* d_shape_file_manager;
		shape_create_function_map_type d_create;
		collision_shape_data_map_type d_collision_shape_data_map;
	public:
		mm_bullet_shape_manager();
		virtual ~mm_bullet_shape_manager();
	public:
		void set_shape_file_manager(mm_bullet_shape_file_manager* manager);
		mm_bullet_shape_file_manager* get_shape_file_manager();
	public:
		mm_bullet_shape_data* add(const std::string& fullname, const std::string& type, const std::string& parameter);
		mm_bullet_shape_data* get(const std::string& fullname);
		mm_bullet_shape_data* get_instance(const std::string& fullname, const std::string& type, const std::string& parameter);
		void rmv(const std::string& fullname);
		void clear();
	public:
		mm_bullet_shape_data* produce(const std::string& type, const std::string& parameter);
		void recycle(mm_bullet_shape_data* shape_data);
	public:
		// (std::string(filename), std::string(pathname))
		// "{%s,%s,}"
		// {file.bullet,physical/shape}
		btCollisionShape* shape_create_bullet_file(mm_bullet_shape_data* shape_data, const std::string& parameter);
	public:
		// (btVector3(x, y, z))
		// {%f,%f,%f,}
		// {1.0, 1.0, 1.0,}
		btCollisionShape* shape_create_box(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btScalar radius,btScalar height)
		// {%f,%f,}
		// {1.0, 1.0,}
		btCollisionShape* shape_create_capsule_x(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btScalar radius,btScalar height)
		// {%f,%f,}
		// {1.0, 1.0,}
		btCollisionShape* shape_create_capsule_y(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btScalar radius,btScalar height)
		// {%f,%f,}
		// {1.0, 1.0,}
		btCollisionShape* shape_create_capsule_z(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btScalar radius,btScalar height)
		// {%f,%f,}
		// {1.0, 1.0,}
		btCollisionShape* shape_create_cone_x(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btScalar radius,btScalar height)
		// {%f,%f,}
		// {1.0, 1.0,}
		btCollisionShape* shape_create_cone_y(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btScalar radius,btScalar height)
		// {%f,%f,}
		// {1.0, 1.0,}
		btCollisionShape* shape_create_cone_z(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btVector3(x, y, z))
		// {%f,%f,%f,}
		// {1.0, 1.0, 1.0,}
		btCollisionShape* shape_create_cylinder_x(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btVector3(x, y, z))
		// {%f,%f,%f,}
		// {1.0, 1.0, 1.0,}
		btCollisionShape* shape_create_cylinder_y(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btVector3(x, y, z))
		// {%f,%f,%f,}
		// {1.0, 1.0, 1.0,}
		btCollisionShape* shape_create_cylinder_z(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (btScalar radius)
		// {%f,}
		// {1.0,}
		btCollisionShape* shape_create_sphere(mm_bullet_shape_data* shape_data, const std::string& parameter);
		// (const btVector3& planeNormal,btScalar planeConstant)
		// {%f,%f,%f,%f,}
		// {1.0, 1.0, 1.0, 1.0,}
		btCollisionShape* shape_create_static_plane(mm_bullet_shape_data* shape_data, const std::string& parameter);
	};
}
#endif//__mm_bullet_shape_manager_h__