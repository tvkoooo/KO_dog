#include "mm_bullet_shape_manager.h"

#include "core/mm_logger.h"
#include "core/mm_alloc.h"

#include "dish/mm_file_path.h"

#include "physical/mm_bullet_ogre_conver.h"

#include "BulletCollision/CollisionShapes/btBoxShape.h"
#include "BulletCollision/CollisionShapes/btCapsuleShape.h"
#include "BulletCollision/CollisionShapes/btConeShape.h"
#include "BulletCollision/CollisionShapes/btCylinderShape.h"
#include "BulletCollision/CollisionShapes/btSphereShape.h"
#include "BulletCollision/CollisionShapes/btStaticPlaneShape.h"

#include "Extras/Serialize/BulletWorldImporter/btBulletWorldImporter.h"

namespace mm
{
	static void __static_bullet_shape_factory_parameter_none_symbol(const std::string& parameter, std::string& parameter_none_symbol)
	{
		parameter_none_symbol = parameter;
		size_t len = parameter_none_symbol.size();
		size_t i = 0;
		char* buffer = (char*)parameter_none_symbol.data();

		for (i = 0; i < len; ++i)
		{
			if ('(' == buffer[i] || ')' == buffer[i] || '{' == buffer[i] || '}' == buffer[i] || ',' == buffer[i])
			{
				buffer[i] = ' ';
			}
		}
	}
	static void __static_bullet_shape_factory_name_none_empty(const std::string& name, std::string& name_none_empty)
	{
		name_none_empty = "";
		size_t len = name.size();
		size_t i = 0;
		const char* buffer = (const char*)name.data();

		for (i = 0; i < len; ++i)
		{
			if (' ' != buffer[i])
			{
				name_none_empty.push_back(buffer[i]);
			}
		}
	}

	mm_bullet_shape_data::mm_bullet_shape_data()
		: d_manager(NULL)
		, d_name("")
		, d_asset("")
		, d_collision_shape(NULL)
		, d_create_type(mm_bullet_shape_manager::none)
		, d_reference(0)
	{

	}
	mm_bullet_shape_data::~mm_bullet_shape_data()
	{

	}

	mm_bullet_shape_manager::mm_bullet_shape_manager()
		: d_shape_file_manager(NULL)
	{
		this->d_create["bullet_file"] = &mm_bullet_shape_manager::shape_create_bullet_file;
		this->d_create["box"] = &mm_bullet_shape_manager::shape_create_box;
		this->d_create["capsule_x"] = &mm_bullet_shape_manager::shape_create_capsule_x;
		this->d_create["capsule_y"] = &mm_bullet_shape_manager::shape_create_capsule_y;
		this->d_create["capsule_z"] = &mm_bullet_shape_manager::shape_create_capsule_z;
		this->d_create["cone_x"] = &mm_bullet_shape_manager::shape_create_cone_x;
		this->d_create["cone_y"] = &mm_bullet_shape_manager::shape_create_cone_y;
		this->d_create["cone_z"] = &mm_bullet_shape_manager::shape_create_cone_z;
		this->d_create["cylinder_x"] = &mm_bullet_shape_manager::shape_create_cylinder_x;
		this->d_create["cylinder_y"] = &mm_bullet_shape_manager::shape_create_cylinder_y;
		this->d_create["cylinder_z"] = &mm_bullet_shape_manager::shape_create_cylinder_z;
		this->d_create["sphere"] = &mm_bullet_shape_manager::shape_create_sphere;
		this->d_create["static_plane"] = &mm_bullet_shape_manager::shape_create_static_plane;
	}
	mm_bullet_shape_manager::~mm_bullet_shape_manager()
	{
		this->clear();
	}
	void mm_bullet_shape_manager::set_shape_file_manager(mm_bullet_shape_file_manager* manager)
	{
		this->d_shape_file_manager = manager;
	}
	mm_bullet_shape_file_manager* mm_bullet_shape_manager::get_shape_file_manager()
	{
		return this->d_shape_file_manager;
	}
	mm_bullet_shape_data* mm_bullet_shape_manager::add(const std::string& fullname, const std::string& type, const std::string& parameter)
	{
		mm_bullet_shape_data* shape_data = this->get(fullname);
		if (NULL == shape_data)
		{
			shape_data = new mm_bullet_shape_data;
			shape_data->d_manager = this;
			shape_data->d_name = fullname;

			shape_create_function_map_type::iterator it = this->d_create.find(type);
			if (it != this->d_create.end())
			{
				shape_create_function create_function = it->second;
				shape_data->d_collision_shape = (this->*create_function)(shape_data, parameter);
				this->d_collision_shape_data_map.insert(collision_shape_data_map_type::value_type(fullname, shape_data));
			}
			else
			{
				struct mm_logger* g_logger = mm_logger_instance();
				mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape type:%s create not find.", __FUNCTION__, __LINE__, type.c_str());
				this->d_collision_shape_data_map.insert(collision_shape_data_map_type::value_type(fullname, shape_data));
			}
		}
		return shape_data;
	}
	mm_bullet_shape_data* mm_bullet_shape_manager::get(const std::string& fullname)
	{
		mm_bullet_shape_data* shape_data = NULL;
		collision_shape_data_map_type::iterator it = this->d_collision_shape_data_map.find(fullname);
		if (it != this->d_collision_shape_data_map.end())
		{
			shape_data = it->second;
		}
		return shape_data;
	}
	mm_bullet_shape_data* mm_bullet_shape_manager::get_instance(const std::string& fullname, const std::string& type, const std::string& parameter)
	{
		mm_bullet_shape_data* shape_data = this->get(fullname);
		if (NULL == shape_data)
		{
			shape_data = this->add(fullname, type, parameter);
		}
		return shape_data;
	}
	void mm_bullet_shape_manager::rmv(const std::string& fullname)
	{
		mm_bullet_shape_data* shape_data = NULL;
		collision_shape_data_map_type::iterator it = this->d_collision_shape_data_map.find(fullname);
		if (it != this->d_collision_shape_data_map.end())
		{
			shape_data = it->second;
			this->d_collision_shape_data_map.erase(it);
			delete shape_data;
		}
	}
	void mm_bullet_shape_manager::clear()
	{
		mm_bullet_shape_data* shape_data = NULL;
		collision_shape_data_map_type::iterator it = this->d_collision_shape_data_map.begin();
		while (it != this->d_collision_shape_data_map.end())
		{
			shape_data = it->second;
			this->d_collision_shape_data_map.erase(it++);
			delete shape_data;
		}
	}

	mm_bullet_shape_data* mm_bullet_shape_manager::produce(const std::string& type, const std::string& parameter)
	{
		mm_bullet_shape_data* shape_data = NULL;
		std::string shapename = type + ":" + parameter;
		std::string shapename_none_empty;

		__static_bullet_shape_factory_name_none_empty(shapename, shapename_none_empty);

		shape_data = this->get_instance(shapename_none_empty, type, parameter);
		shape_data->d_reference++;
		return shape_data;
	}
	void mm_bullet_shape_manager::recycle(mm_bullet_shape_data* shape_data)
	{
		shape_data->d_reference--;
		if (bullet_file == shape_data->d_create_type)
		{
			if (0 == shape_data->d_reference)
			{
				this->d_shape_file_manager->recycle(shape_data->d_asset);
				this->rmv(shape_data->d_name);
			}
		}
		else
		{
			if (0 == shape_data->d_reference)
			{
				delete shape_data->d_collision_shape;
				shape_data->d_collision_shape = NULL;
				this->rmv(shape_data->d_name);
			}
		}
	}
	// (std::string(filename), std::string(pathname))
	btCollisionShape* mm_bullet_shape_manager::shape_create_bullet_file(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			struct mm_logger* g_logger = mm_logger_instance();

			std::string parameter_none_symbol;
			__static_bullet_shape_factory_parameter_none_symbol(parameter, parameter_none_symbol);

			struct mm_string pathname;
			struct mm_string filename;
			struct mm_string fullname;

			mm_string_init(&pathname);
			mm_string_init(&filename);
			mm_string_init(&fullname);

			mm_string_resize(&pathname, parameter.size());
			mm_string_resize(&filename, parameter.size());

			mm_sscanf(parameter_none_symbol.data(), "%s %s", (char*)pathname.s, (char*)filename.s);

			mm_directory_have_suffix(&pathname, pathname.s);

			mm_string_assign(&fullname, &pathname);
			mm_string_append(&fullname, filename.s);

			mm_bullet_shape_file_data* data = this->d_shape_file_manager->produce(fullname.s);
			_collision_shape = data->d_collision_shape;
			shape_data->d_asset = fullname.s;
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::bullet_file;

			mm_string_destroy(&pathname);
			mm_string_destroy(&filename);
			mm_string_destroy(&fullname);
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btVector3(x, y, z))
	btCollisionShape* mm_bullet_shape_manager::shape_create_box(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[3] = {0};
			mm_sscanf(parameter.data(), "{%f,%f,%f,}", &data[0], &data[1], &data[2]);
			_collision_shape = new btBoxShape(btVector3(data[0], data[1], data[2]));
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::box;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btScalar radius,btScalar height)
	btCollisionShape* mm_bullet_shape_manager::shape_create_capsule_x(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[2] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,}", &data[0], &data[1]);
			_collision_shape = new btCapsuleShapeX(data[0], data[1]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::capsule_x;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btScalar radius,btScalar height)
	btCollisionShape* mm_bullet_shape_manager::shape_create_capsule_y(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[2] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,}", &data[0], &data[1]);
			_collision_shape = new btCapsuleShape(data[0], data[1]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::capsule_y;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btScalar radius,btScalar height)
	btCollisionShape* mm_bullet_shape_manager::shape_create_capsule_z(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[2] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,}", &data[0], &data[1]);
			_collision_shape = new btCapsuleShapeZ(data[0], data[1]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::capsule_z;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btScalar radius,btScalar height)
	btCollisionShape* mm_bullet_shape_manager::shape_create_cone_x(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[2] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,}", &data[0], &data[1]);
			_collision_shape = new btConeShapeX(data[0], data[1]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::cone_x;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btScalar radius,btScalar height)
	btCollisionShape* mm_bullet_shape_manager::shape_create_cone_y(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[2] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,}", &data[0], &data[1]);
			_collision_shape = new btConeShape(data[0], data[1]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::cone_y;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btScalar radius,btScalar height)
	btCollisionShape* mm_bullet_shape_manager::shape_create_cone_z(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[2] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,}", &data[0], &data[1]);
			_collision_shape = new btConeShapeZ(data[0], data[1]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::cone_z;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btVector3(x, y, z))
	btCollisionShape* mm_bullet_shape_manager::shape_create_cylinder_x(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[3] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,%f,}", &data[0], &data[1], &data[2]);
			_collision_shape = new btCylinderShapeX(btVector3(data[0], data[1], data[2]));
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::cylinder_x;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btVector3(x, y, z))
	btCollisionShape* mm_bullet_shape_manager::shape_create_cylinder_y(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[3] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,%f,}", &data[0], &data[1], &data[2]);
			_collision_shape = new btCylinderShape(btVector3(data[0], data[1], data[2]));
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::cylinder_y;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btVector3(x, y, z))
	btCollisionShape* mm_bullet_shape_manager::shape_create_cylinder_z(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[3] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,%f,}", &data[0], &data[1], &data[2]);
			_collision_shape = new btCylinderShapeZ(btVector3(data[0], data[1], data[2]));
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::cylinder_z;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (btScalar radius)
	btCollisionShape* mm_bullet_shape_manager::shape_create_sphere(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[1] = { 0 };
			mm_sscanf(parameter.data(), "{%f,}", &data[0]);
			_collision_shape = new btSphereShape(data[0]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::sphere;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}
	// (const btVector3& planeNormal,btScalar planeConstant)
	btCollisionShape* mm_bullet_shape_manager::shape_create_static_plane(mm_bullet_shape_data* shape_data, const std::string& parameter)
	{
		btCollisionShape* _collision_shape = NULL;
		if (false == parameter.empty())
		{
			btScalar data[4] = { 0 };
			mm_sscanf(parameter.data(), "{%f,%f,%f,%f,}", &data[0], &data[1], &data[2], &data[3]);
			_collision_shape = new btStaticPlaneShape(btVector3(data[0], data[1], data[2]), data[3]);
			shape_data->d_collision_shape = _collision_shape;
			shape_data->d_create_type = mm_bullet_shape_manager::static_plane;
		}
		else
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger, "mm_bullet_shape_manager::%s %d the shape parameter is invalid.", __FUNCTION__, __LINE__);
		}
		return _collision_shape;
	}	
}

