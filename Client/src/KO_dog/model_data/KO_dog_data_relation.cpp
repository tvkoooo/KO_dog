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
			mm_event_map_ags ags;
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
			mm_event_map_ags ags;
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





	//void data_relation_groupId_info::clear()
	//{
	//	this->group_name = "";
	//	this->num = 0;
	//	//遍历 map_friendId_friendInfo 
	//	map_friendId_friendInfo::iterator it;
	//	for (it = this->m_friendId_friendInfo.begin(); it != this->m_friendId_friendInfo.end(); it++)
	//	{
	//		free(it->second);
	//	}
	//	this->m_friendId_friendInfo.clear();
	//	this->handle = NULL;
	//}
	//size_t data_relation_groupId_info::member_size()
	//{
	//	return this->num;
	//}
	//bool data_relation_groupId_info::is_member(mm_uint64_t friend_id)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it != this->m_friendId_friendInfo.end())
	//	{
	//		flag = true;
	//	}
	//	return flag;
	//}
	//data_relation_friendId_info* data_relation_groupId_info::move_out_friend(mm_uint64_t friend_id)
	//{
	//	data_relation_friendId_info* handle = NULL;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it != this->m_friendId_friendInfo.end())
	//	{
	//		handle = it->second;
	//		this->num--;
	//	}
	//	return handle;
	//}

	//bool data_relation_groupId_info::add_friend(mm_uint64_t friend_id, const std::string& friend_remark, mm_uint32_t build_friend_time)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it == this->m_friendId_friendInfo.end())
	//	{
	//		//插入一条数据
	//		data_relation_friendId_info* exp = new data_relation_friendId_info;
	//		exp->friend_remark = friend_remark;
	//		exp->build_friend_time = build_friend_time;
	//		this->m_friendId_friendInfo.insert(map_friendId_friendInfo::value_type(friend_id, exp));
	//		this->num++;
	//		flag = true;
	//	}
	//	return flag;
	//}
	//bool data_relation_groupId_info::move_in_friend(mm_uint64_t friend_id, data_relation_friendId_info* exp)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it == this->m_friendId_friendInfo.end())
	//	{
	//		//插入一条数据
	//		this->m_friendId_friendInfo.insert(map_friendId_friendInfo::value_type(friend_id, exp));
	//		this->num++;
	//		flag = true;
	//	}
	//	else
	//	{
	//		//数据出现覆盖现象，需要释放旧存储空间
	//		free(it->second);
	//		it->second = exp;
	//		flag = true;
	//	}
	//	return flag;
	//}
	////If the element exists, the handle is returned. If it does not exist, it returns NULL.
	//void* data_relation_groupId_info::delete_friend(mm_uint64_t friend_id)
	//{
	//	void* handle = NULL;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it != this->m_friendId_friendInfo.end())
	//	{
	//		handle = it->second->handle;
	//		//删除一条数据
	//		this->m_friendId_friendInfo.erase(it);
	//		this->num--;
	//	}
	//	return handle;
	//}
	//bool data_relation_groupId_info::rename_friend_remark(mm_uint64_t friend_id, const std::string& friend_remark)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it != this->m_friendId_friendInfo.end())
	//	{
	//		//修改一条数据
	//		it->second->friend_remark = friend_remark;
	//		flag = true;
	//	}
	//	return flag;
	//}
	//bool data_relation_groupId_info::put_handle(mm_uint64_t friend_id ,void* handle)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it != this->m_friendId_friendInfo.end())
	//	{
	//		//修改一条数据
	//		it->second->handle = handle;
	//		flag = true;
	//	}
	//	return flag;
	//}
	//void* data_relation_groupId_info::get_handle(mm_uint64_t friend_id)
	//{
	//	void* handle = NULL;
	//	//寻找元素 
	//	map_friendId_friendInfo::iterator it = this->m_friendId_friendInfo.find(friend_id);
	//	if (it != this->m_friendId_friendInfo.end())
	//	{
	//		handle = it->second->handle;
	//	}
	//	return handle;
	//}

	////KO_dog_data_relation Event definition
	//const std::string KO_dog_data_relation::event_data_relation_add_friend("event_data_relation_add_friend");
	//const std::string KO_dog_data_relation::event_data_relation_delete_friend("event_data_relation_delete_friend");
	//const std::string KO_dog_data_relation::event_data_relation_rename_friend_remark("event_data_relation_rename_friend_remark");
	//const std::string KO_dog_data_relation::event_data_relation_add_friend_group("event_data_relation_add_friend_group");
	//const std::string KO_dog_data_relation::event_data_relation_delete_group("event_data_relation_delete_group");
	//const std::string KO_dog_data_relation::event_data_relation_rename_group("event_data_relation_rename_group");
	//const std::string KO_dog_data_relation::event_data_relation_change_group("event_data_relation_change_group");
	//const std::string KO_dog_data_relation::event_data_relation_delete_friend_group("event_data_relation_delete_friend_group");
	//const std::string KO_dog_data_relation::event_data_relation_change_friend_group("event_data_relation_change_friend_group");
	//const std::string KO_dog_data_relation::event_data_relation_query_friends("event_data_relation_query_friends");
	//const std::string KO_dog_data_relation::event_data_relation_talk_friend_send("event_data_relation_talk_friend_send");
	//const std::string KO_dog_data_relation::event_data_relation_talk_friend_receive("event_data_relation_talk_friend_receive");

	//const std::string KO_dog_data_relation::event_data_relation_server_error("event_data_relation_server_error");
	////KO_dog_data_relation
	//KO_dog_data_relation::KO_dog_data_relation()
	//{
	//	this->m_groupId_groupInfo.clear();
	//	//备注： 默认情况下，有个默认的组，该组不可删除（其他组删除后会归给这个默认组），id是0 默认名是 friends，不可以重命名该组
	//	this->add_group(0,"friends");
	//}
	//KO_dog_data_relation::~KO_dog_data_relation()
	//{
	//	this->clear();
	//}
	//void KO_dog_data_relation::clear()
	//{
	//	this->num = 0;
	//	//遍历 map_groupId_groupInfo 
	//	map_groupId_groupInfo::iterator it;
	//	for (it = this->m_groupId_groupInfo.begin(); it != this->m_groupId_groupInfo.end(); it++)
	//	{
	//		free(it->second);
	//	}
	//	this->m_groupId_groupInfo.clear();
	//	this->m_friendId_groupId.clear();
	//}
	////operate group
	//data_relation_groupId_info* KO_dog_data_relation::get_group_info(mm_uint64_t group_id)
	//{
	//	data_relation_groupId_info* p = NULL;
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		p = it->second;
	//	}
	//	return p;
	//}

	//bool KO_dog_data_relation::add_group(mm_uint64_t group_id, const std::string& group_name)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it == this->m_groupId_groupInfo.end())
	//	{
	//		//插入一条数据
	//		data_relation_groupId_info* exp = new data_relation_groupId_info;
	//		exp->group_name = group_name;
	//		exp->num = 0;
	//		exp->m_friendId_friendInfo.clear();
	//		exp->handle = NULL;
	//		this->m_groupId_groupInfo.insert(map_groupId_groupInfo::value_type(group_id, exp));
	//		this->num++;
	//		flag = true;
	//	}
	//	return flag;
	//}
	//bool KO_dog_data_relation::rename_group(mm_uint64_t group_id, const std::string& group_name_new)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		//修改一条数据
	//		it->second->group_name = group_name_new;
	//		flag = true;
	//	}
	//	return flag;
	//}
	//bool KO_dog_data_relation::change_group(mm_uint64_t group_id_old, mm_uint64_t group_id_new)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_groupInfo::iterator it_new = this->m_groupId_groupInfo.find(group_id_old);
	//	map_groupId_groupInfo::iterator it_old = this->m_groupId_groupInfo.find(group_id_new);
	//	if (it_new != this->m_groupId_groupInfo.end() && it_old != this->m_groupId_groupInfo.end())
	//	{
	//		//遍历旧组，添加到新租，删除旧组(group_id_old 成员全部放入 group_id_new ， 并且删除 旧组 group_id_old)
	//		data_relation_groupId_info::map_friendId_friendInfo::iterator it;
	//		for (it = it_old->second->m_friendId_friendInfo.begin(); it != it_old->second->m_friendId_friendInfo.end(); it++)
	//		{
	//			it_new->second->move_in_friend(it->first,it->second);
	//			//改写索引 m_friendId_groupId
	//			this->m_friendId_groupId[it->first] = group_id_new;
	//		}
	//		it_old->second->clear();
	//		this->num--;
	//		flag = true;
	//	}
	//	return flag;
	//}
	//bool KO_dog_data_relation::delete_group(mm_uint64_t group_id)
	//{
	//	return this->change_group(group_id, 0);
	//}
	////operate friend element group 
	//bool KO_dog_data_relation::change_friend_group(mm_uint64_t friend_id, mm_uint64_t group_id)
	//{
	//	bool flag = false;
	//	map_friendId_groupId::iterator it_friend = this->m_friendId_groupId.find(friend_id);
	//	if (it_friend != this->m_friendId_groupId.end())
	//	{
	//		//寻找元素 group_id_old  group_id_new 是否是map元素
	//		map_groupId_groupInfo::iterator it_new = this->m_groupId_groupInfo.find(group_id);
	//		map_groupId_groupInfo::iterator it_old = this->m_groupId_groupInfo.find(it_friend->second);
	//		//确定 friend_id 是否为 group_id_old 里面元素,然后迁移group_id_old 到 group_id_new
	//		if (it_new != this->m_groupId_groupInfo.end() && it_old != this->m_groupId_groupInfo.end())
	//		{
	//			if (it_old->second->is_member(friend_id))
	//			{
	//				it_new->second->move_in_friend(friend_id, it_old->second->move_out_friend(friend_id));
	//				//改写索引 m_friendId_groupId
	//				this->m_friendId_groupId[friend_id] = group_id;
	//				flag = true;
	//			}
	//		}
	//	}
	//	return flag;
	//}
	//bool KO_dog_data_relation::delete_friend_group(mm_uint64_t friend_id)
	//{
	//	return this->change_friend_group(friend_id, 0);
	//}
	////operate friend element
	//size_t KO_dog_data_relation::member_size()
	//{
	//	return this->num;
	//}
	//bool KO_dog_data_relation::is_member(mm_uint64_t group_id)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		flag = true;
	//	}
	//	return flag;

	//}
	//size_t KO_dog_data_relation::group_member_size(mm_uint64_t group_id)
	//{
	//	size_t num = 0;
	//	//寻找元素 
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		num = it->second->member_size();
	//	}
	//	return num;
	//}

	//bool KO_dog_data_relation::is_group_member(mm_uint64_t group_id, mm_uint64_t friend_id)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		flag = it->second->is_member(friend_id);
	//	}
	//	return flag;

	//}

	//bool KO_dog_data_relation::add_friend(mm_uint64_t group_id, mm_uint64_t friend_id, const std::string& friend_remark, mm_uint32_t build_friend_time)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		flag = it->second->add_friend(friend_id, friend_remark, build_friend_time);
	//		//增加索引 m_friendId_groupId
	//		this->m_friendId_groupId[friend_id] = group_id;

	//	}
	//	return flag;

	//}
	//void* KO_dog_data_relation::delete_friend(mm_uint64_t friend_id)
	//{
	//	void* handle = NULL;
	//	//寻找元素 
	//	map_friendId_groupId::iterator it_friend = this->m_friendId_groupId.find(friend_id);
	//	if (it_friend != this->m_friendId_groupId.end())
	//	{
	//		map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(it_friend->second);
	//		if (it != this->m_groupId_groupInfo.end())
	//		{
	//			handle = it->second->delete_friend(friend_id);
	//		}
	//		//删除索引 m_friendId_groupId
	//		this->m_friendId_groupId.erase(it_friend);

	//	}
	//	return handle;
	//}
	//bool KO_dog_data_relation::rename_friend_remark(mm_uint64_t friend_id, const std::string& friend_remark)
	//{
	//	bool flag = false;
	//	map_friendId_groupId::iterator it_friend = this->m_friendId_groupId.find(friend_id);
	//	if (it_friend != this->m_friendId_groupId.end())
	//	{
	//		map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(it_friend->second);
	//		if (it != this->m_groupId_groupInfo.end())
	//		{
	//			flag = it->second->rename_friend_remark(friend_id, friend_remark);
	//		}
	//	}
	//	return flag;
	//}
	//bool KO_dog_data_relation::put_friend_handle(mm_uint64_t friend_id, void* handle)
	//{
	//	bool flag = false;
	//	map_friendId_groupId::iterator it_friend = this->m_friendId_groupId.find(friend_id);
	//	if (it_friend != this->m_friendId_groupId.end())
	//	{
	//		map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(it_friend->second);
	//		if (it != this->m_groupId_groupInfo.end())
	//		{
	//			flag = it->second->put_handle(friend_id, handle);
	//		}
	//	}
	//	return flag;
	//}
	//void* KO_dog_data_relation::get_friend_handle(mm_uint64_t friend_id)
	//{
	//	void* handle = NULL;
	//	map_friendId_groupId::iterator it_friend = this->m_friendId_groupId.find(friend_id);
	//	if (it_friend != this->m_friendId_groupId.end())
	//	{
	//		map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(it_friend->second);
	//		if (it != this->m_groupId_groupInfo.end())
	//		{
	//			handle = it->second->get_handle(friend_id);
	//		}
	//	}
	//	return handle;

	//}
	//bool KO_dog_data_relation::put_group_handle(mm_uint64_t group_id, void* handle)
	//{
	//	bool flag = false;
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		it->second->handle = handle;
	//		flag = true;
	//	}
	//	return flag;
	//}
	//void* KO_dog_data_relation::get_group_handle(mm_uint64_t group_id)
	//{
	//	void* handle = NULL;
	//	map_groupId_groupInfo::iterator it = this->m_groupId_groupInfo.find(group_id);
	//	if (it != this->m_groupId_groupInfo.end())
	//	{
	//		handle = it->second->handle;
	//	}
	//	return handle;
	//}
}