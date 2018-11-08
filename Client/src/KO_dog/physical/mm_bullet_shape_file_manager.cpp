#include "mm_bullet_shape_file_manager.h"

#include "core/mm_logger.h"

#include "BulletCollision/CollisionDispatch/btCollisionObject.h"

namespace mm
{
	mm_bullet_shape_file_data::mm_bullet_shape_file_data()
		: d_manager(NULL)
		, d_asset("")
		, d_collision_shape(NULL)
		, d_reference(0)
	{

	}
	mm_bullet_shape_file_data::~mm_bullet_shape_file_data()
	{
		this->d_importer.deleteAllData();
	}

	mm_bullet_shape_file_manager::mm_bullet_shape_file_manager()
		: d_file_context(NULL)
	{

	}
	mm_bullet_shape_file_manager::~mm_bullet_shape_file_manager()
	{
		this->clear();
	}
	void mm_bullet_shape_file_manager::set_file_context(struct mm_file_context* file_context)
	{
		this->d_file_context = file_context;
	}
	struct mm_file_context* mm_bullet_shape_file_manager::get_file_context()
	{
		return this->d_file_context;
	}
	mm_bullet_shape_file_data* mm_bullet_shape_file_manager::produce(const std::string& fullname)
	{
		mm_bullet_shape_file_data* data = this->get_instance(fullname);
		data->d_reference++;
		return data;
	}
	void mm_bullet_shape_file_manager::recycle(const std::string& fullname)
	{
		mm_bullet_shape_file_data* data = this->get(fullname);
		if (NULL != data)
		{
			data->d_reference--;
			if (0 == data->d_reference)
			{
				this->rmv(fullname);
			}
		}
	}

	mm_bullet_shape_file_data* mm_bullet_shape_file_manager::add(const std::string& fullname)
	{
		mm_bullet_shape_file_data* data = this->get(fullname);
		if (NULL == data)
		{
			data = new mm_bullet_shape_file_data;
			data->d_manager = this;
			data->d_asset = fullname;

			struct mm_byte_buffer byte_buffer;
			mm_byte_buffer_init(&byte_buffer);

			mm_file_context_acquire_file_byte_buffer(this->d_file_context, fullname.c_str(), &byte_buffer);

			if (NULL != byte_buffer.buffer && 0 != byte_buffer.length)
			{
				int index_cs_0 = data->d_importer.getNumCollisionShapes();
				int index_rb_0 = data->d_importer.getNumRigidBodies();
				data->d_importer.loadFileFromMemory((char*)(byte_buffer.buffer + byte_buffer.offset), (int)byte_buffer.length);
				int index_cs_1 = data->d_importer.getNumCollisionShapes();
				int index_rb_1 = data->d_importer.getNumRigidBodies();

				if (index_cs_1 == index_cs_0 + 1)
				{
					data->d_collision_shape = data->d_importer.getCollisionShapeByIndex(index_cs_0);
				}
				if (index_rb_1 == index_rb_0 + 1)
				{
					btCollisionObject* r = data->d_importer.getRigidBodyByIndex(index_rb_0);
					data->d_collision_shape = r->getCollisionShape();
				}
				this->d_collision_shape_map.insert(collision_shape_map_type::value_type(fullname, data));
			}
			else
			{
				struct mm_logger* g_logger = mm_logger_instance();
				mm_logger_log_E(g_logger, "mm_bullet_shape_factory::%s %d the shape parameter fullname:%s is invalid.", __FUNCTION__, __LINE__, fullname.c_str());
			}

			mm_file_context_release_file_byte_buffer(this->d_file_context, &byte_buffer);

			mm_byte_buffer_destroy(&byte_buffer);
		}
		return data;
	}
	mm_bullet_shape_file_data* mm_bullet_shape_file_manager::get(const std::string& fullname)
	{
		mm_bullet_shape_file_data* data = NULL;
		collision_shape_map_type::iterator it = this->d_collision_shape_map.find(fullname);
		if (it != this->d_collision_shape_map.end())
		{
			data = it->second;
		}
		return data;
	}
	mm_bullet_shape_file_data* mm_bullet_shape_file_manager::get_instance(const std::string& fullname)
	{
		mm_bullet_shape_file_data* data = this->get(fullname);
		if (NULL == data)
		{
			data = this->add(fullname);
		}
		return data;
	}
	void mm_bullet_shape_file_manager::rmv(const std::string& fullname)
	{
		mm_bullet_shape_file_data* data = NULL;
		collision_shape_map_type::iterator it = this->d_collision_shape_map.find(fullname);
		if (it != this->d_collision_shape_map.end())
		{
			data = it->second;
			this->d_collision_shape_map.erase(it);
			delete data;
		}
	}
	void mm_bullet_shape_file_manager::clear()
	{
		mm_bullet_shape_file_data* data = NULL;
		collision_shape_map_type::iterator it = this->d_collision_shape_map.begin();
		while (it != this->d_collision_shape_map.end())
		{
			data = it->second;
			this->d_collision_shape_map.erase(it++);
			delete data;
		}
	}
}

