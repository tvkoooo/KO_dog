#ifndef __KO_dog_data_relation_h__
#define __KO_dog_data_relation_h__

#include <string>
#include <map>
#include "core/mm_core.h"
#include "dish/mm_event.h"

#include "toolkit/mm_elem_map.h"
namespace mm
{

	class data_relation_friendInfo
	{
	public:
		mm_uint64_t friend_id;
		mm_uint64_t friend_group_id;
		std::string friend_remark;
		mm_uint32_t build_friend_time;

	public:
		static const std::string event_update;
		static const std::string event_update_remark;
		static const std::string event_update_group;
	public:
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		data_relation_friendInfo();
		~data_relation_friendInfo();
	public:

		void update(mm_uint64_t friend_id, mm_uint64_t friend_group_id,const std::string& friend_remark, mm_uint32_t build_friend_time);
		void update_remark(const std::string& friend_remark);
		void update_group(mm_uint64_t friend_group_id);
	};


	class data_relation_friendId_friendInfo_map
	{

	public:
		typedef std::map<mm_uint64_t, data_relation_friendInfo*> map_friendId_friendInfo;

	public:
		map_friendId_friendInfo m_friendId_friendInfo;

	public:
		static const std::string event_add;
		static const std::string event_rmv;
		static const std::string event_meg;
	public:
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		data_relation_friendId_friendInfo_map();
		~data_relation_friendId_friendInfo_map();
	public:
		bool add(mm_uint64_t friend_id, mm_uint64_t friend_group_id, const std::string& friend_remark , mm_uint32_t build_friend_time);
		bool rmv(mm_uint64_t friend_id);
		data_relation_friendInfo* get(mm_uint64_t friend_id);
		void meg(mm_uint64_t friend_group_id_old, mm_uint64_t friend_group_id_new);
		void clear();
	};

	class data_relation_groupInfo
	{
	public:
		mm_uint64_t group_id;
		std::string group_name;

	public:
		static const std::string event_update;
		static const std::string event_update_name;
	public:
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		data_relation_groupInfo();
		~data_relation_groupInfo();
	public:

		void update(mm_uint64_t group_id, const std::string& group_name);
		void update_name(const std::string& group_name);
	};


	class KO_dog_data_relation
	{
	public:
		class mm_event_args_data :public mm_event_args
		{
		public:
			mm_uint64_t friend_group_id_old;
			mm_uint64_t friend_group_id_new;
		public:
			mm_event_args_data();
			~mm_event_args_data();
		};
	public:
		class mm_event_args_model :public mm_event_args
		{
		public:
			void* model_addr;
		public:
			mm_event_args_model();
			~mm_event_args_model();
		};

	public:
		typedef elem_event_map<mm_uint64_t, data_relation_groupInfo> data_relation_groupId_groupName_map;

	public:
		data_relation_friendId_friendInfo_map friendId_friendInfo_map;
		data_relation_groupId_groupName_map groupId_groupName_map;

	public:
		static const std::string event_friendId_friendInfo_map_set_model;
		static const std::string event_groupId_groupName_map_set_model;
		static const std::string event_meg;
		static const std::string event_rmv;
		static const std::string event_data_relation_talk_friend_send;
		static const std::string event_data_relation_talk_friend_receive;

		static const std::string event_data_relation_server_error;


		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		KO_dog_data_relation();
		~KO_dog_data_relation();

	public:
		bool meg(mm_uint64_t friend_group_id_old, mm_uint64_t friend_group_id_new);
		bool rmv(mm_uint64_t friend_group_id_old);
	};

}






#endif//__KO_dog_data_relation_h__