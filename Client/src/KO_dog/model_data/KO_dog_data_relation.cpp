#include "KO_dog_data_relation.h"


namespace mm
{
	//////////////////////////////////////////////////////////////////////////////////////////////
	const std::string data_relation_friendInfo::event_update("event_update");
	const std::string data_relation_friendInfo::event_update_remark("event_update_remark");
	const std::string data_relation_friendInfo::event_update_group("event_update_group");


	data_relation_friendInfo::data_relation_friendInfo()
		: friend_id(0)
		, friend_group_id(0)
		, friend_remark("")
		, build_friend_time(0)
	{

	}
	data_relation_friendInfo::~data_relation_friendInfo()
	{

	}
	void data_relation_friendInfo::update(mm_uint64_t friend_id, mm_uint64_t friend_group_id, const std::string& friend_remark, mm_uint32_t build_friend_time)
	{
		this->friend_id = friend_id;
		this->friend_group_id = friend_group_id;
		this->friend_remark = friend_remark;
		this->build_friend_time = build_friend_time;
		mm_event_obj_ags ags;
		ags.e = this;
		this->d_event_set.fire_event(data_relation_friendInfo::event_update, ags);
	}
	void data_relation_friendInfo::update_remark(const std::string& friend_remark)
	{
		this->friend_remark = friend_remark;
		mm_event_obj_ags ags;
		ags.e = this;
		this->d_event_set.fire_event(data_relation_friendInfo::event_update_remark, ags);

	}
	void data_relation_friendInfo::update_group(mm_uint64_t friend_group_id)
	{
		this->friend_group_id = friend_group_id;
		mm_event_obj_ags ags;
		ags.e = this;
		this->d_event_set.fire_event(data_relation_friendInfo::event_update_group, ags);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	const std::string data_relation_friendId_friendInfo_map::event_add("event_add");
	const std::string data_relation_friendId_friendInfo_map::event_rmv("event_rmv");
	const std::string data_relation_friendId_friendInfo_map::event_meg("event_meg");
	
	data_relation_friendId_friendInfo_map::data_relation_friendId_friendInfo_map()
	{

	}
	data_relation_friendId_friendInfo_map::~data_relation_friendId_friendInfo_map()
	{
		this->clear();
	}
	bool data_relation_friendId_friendInfo_map::add(mm_uint64_t friend_id, mm_uint64_t friend_group_id, const std::string& friend_remark, mm_uint32_t build_friend_time)
	{
		bool flag = false;
		//寻找元素 
		map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
		if (it == this->m_friendId_friendInfo.end())
		{
			//插入一条数据
			data_relation_friendInfo* exp = new data_relation_friendInfo;
			exp->friend_id = friend_id;
			exp->friend_group_id = friend_group_id;
			exp->friend_remark = friend_remark;
			exp->build_friend_time = build_friend_time;
			this->m_friendId_friendInfo.insert(map_friendId_friendInfo::value_type(friend_id, exp));
			//
			mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags ags;
			ags.e = exp;
			ags.id = friend_id;
			ags.m = this;
			this->d_event_set.fire_event(data_relation_friendId_friendInfo_map::event_add, ags);

			flag = true;
		}
		return flag;
	}
	bool data_relation_friendId_friendInfo_map::rmv(mm_uint64_t friend_id)
	{
		bool flag = false;
		//寻找元素 
		map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
		if (it != this->m_friendId_friendInfo.end())
		{
			//
			mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags ags;
			ags.e = it->second;
			ags.id = friend_id;
			ags.m = this;
			this->d_event_set.fire_event(data_relation_friendId_friendInfo_map::event_rmv, ags);
			//
			delete(it->second);
			//删除一条数据
			this->m_friendId_friendInfo.erase(it);
			//
			flag = true;
		}
		return flag;
	}
	data_relation_friendInfo* data_relation_friendId_friendInfo_map::get(mm_uint64_t friend_id)
	{
		data_relation_friendInfo* p = NULL;
		//寻找元素 
		map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
		if (it != this->m_friendId_friendInfo.end())
		{
			p = it->second;
		}
		return p;
	}
	void data_relation_friendId_friendInfo_map::meg(mm_uint64_t friend_group_id_old, mm_uint64_t friend_group_id_new)
	{
		//遍历 map_friendId_friendInfo 
		map_friendId_friendInfo::iterator it;
		for (it = this->m_friendId_friendInfo.begin(); it != this->m_friendId_friendInfo.end(); it++)
		{
			data_relation_friendInfo* exp = it->second;
			if (exp->friend_group_id == friend_group_id_old)
			{
				//换组事件函数在内部已经对事件进行了发布，外表不需要再发布事件
				exp->update_group(friend_group_id_new);
			}
		}		
	}
	void data_relation_friendId_friendInfo_map::clear()
	{
		//遍历 map_friendId_friendInfo 
		map_friendId_friendInfo::iterator it;
		for (it = this->m_friendId_friendInfo.begin(); it != this->m_friendId_friendInfo.end(); it++)
		{
			delete(it->second);
		}
		this->m_friendId_friendInfo.clear();
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	const std::string data_relation_groupInfo::event_update("event_update");
	const std::string data_relation_groupInfo::event_update_name("event_update_name");

	data_relation_groupInfo::data_relation_groupInfo()
		: group_id(0)
		, group_name("")
	{

	}
	data_relation_groupInfo::~data_relation_groupInfo()
	{

	}
	void data_relation_groupInfo::update(mm_uint64_t group_id, const std::string& group_name)
	{
		this->group_id = group_id;
		this->group_name = group_name;
		mm_event_obj_ags ags;
		ags.e = this;
		this->d_event_set.fire_event(data_relation_groupInfo::event_update, ags);
	}
	void data_relation_groupInfo::update_name(const std::string& group_name)
	{
		this->group_name = group_name;
		mm_event_obj_ags ags;
		ags.e = this;
		this->d_event_set.fire_event(data_relation_groupInfo::event_update_name, ags);

	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	const std::string KO_dog_data_relation::event_friendId_friendInfo_map_set_model("event_friendId_friendInfo_map_set_model");
	const std::string KO_dog_data_relation::event_groupId_groupName_map_set_model("event_groupId_groupName_map_set_model");
	const std::string KO_dog_data_relation::event_meg("event_meg");
	const std::string KO_dog_data_relation::event_rmv("event_rmv");
	const std::string KO_dog_data_relation::event_data_relation_talk_friend_send("event_data_relation_talk_friend_send");
	const std::string KO_dog_data_relation::event_data_relation_talk_friend_receive("event_data_relation_talk_friend_receive");
	const std::string KO_dog_data_relation::event_data_relation_server_error("event_data_relation_server_error");

	KO_dog_data_relation::mm_event_args_data::mm_event_args_data()
		: friend_group_id_old(0)
		, friend_group_id_new(0)
	{

	}
	KO_dog_data_relation::mm_event_args_data::~mm_event_args_data()
	{

	}
	KO_dog_data_relation::mm_event_args_model::mm_event_args_model()
		: model_addr(NULL)
	{

	}
	KO_dog_data_relation::mm_event_args_model::~mm_event_args_model()
	{

	}

	KO_dog_data_relation::KO_dog_data_relation()
		: friendId_friendInfo_map()
		, groupId_groupName_map()
	{

	}
	KO_dog_data_relation::~KO_dog_data_relation()
	{

	}
	bool KO_dog_data_relation::meg(mm_uint64_t friend_group_id_old, mm_uint64_t friend_group_id_new)
	{
		bool flag = false;
		if (NULL != this->groupId_groupName_map.get(friend_group_id_old) && NULL != this->groupId_groupName_map.get(friend_group_id_new))
		{
			//函数内部已经做了换组 event_update_group 事件发布
			this->friendId_friendInfo_map.meg(friend_group_id_old, friend_group_id_new);
			//函数内部已经做了换组 event_rmv 事件发布
			this->groupId_groupName_map.rmv(friend_group_id_old);
			flag = true;
		}	
		return flag;
	}
	bool KO_dog_data_relation::rmv(mm_uint64_t friend_group_id)
	{
		//函数内部已经做了换组 meg 事件发布
		return this->meg(friend_group_id,0);
	}




}