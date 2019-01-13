#ifndef __mm_elem_map_h__
#define __mm_elem_map_h__
#include <string>
#include "dish/mm_event.h"

//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class mm_event_obj_ags : public mm_event_args
	{
	public:
		void* e;
	};


	template<typename K, typename T>
	class elem_event_map
	{
	public:
		class mm_event_map_ags : public mm_event_args
		{
		public:
			void* m;
			T id;
			void* e;
		};


	public:
		typedef std::map<K, T*> map_type;
	public:
		map_type m;
	public:
		//Internal events
		static const std::string event_add;
		//Internal events
		static const std::string event_rmv;
	public:
		// this member is event drive.
		mm::mm_event_set d_event_set;
	public:
		// ��get�����getΪ�գ����Զ�����һ��
		T* get_instance(K id);
		// ��get�����getΪ�գ����� NULL
		T* get(K id);
		// ��������ڣ��򴴽���ӣ��ҷ���event_add����������򷵻�ԭ������
		T* add(K id);
		// ���������ɾ���ҷ���event_rmv�����������޷�Ӧ
		void rmv(K id);
		// �ȴ����¼� event_clear����ȫ��Ԫ��ɾ��
		void clear();
	};
	template<typename K, typename T>
	const std::string elem_event_map<K,T>::event_add("event_add");

	template<typename K, typename T>
	const std::string elem_event_map<K,T>::event_rmv("event_rmv");

	template<typename K, typename T>
	T* elem_event_map<K,T>::get_instance(K id)
	{
		T p_e = this->get(id);
		if (NULL == p_e)
		{
			p_e = this->add(id);
		}
		return p_e;
	}
	template<typename K, typename T>
	T* elem_event_map<K, T>::get(K id)
	{
		T* p_e = NULL;
		//Ѱ��Ԫ�� 
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			p_e = it->second;
		}
		return p_e;
	}
	template<typename K, typename T>
	T* elem_event_map<K, T>::add(K id)
	{
		T* p_e = NULL;
		//Ѱ��Ԫ�� 
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			p_e = it->second;
		}
		else
		{
			p_e = new T;
			this->m.insert(typename map_type::value_type(id, p_e));
			mm_event_map_ags ags;
			ags.e = p_e;
			ags.id = id;
			ags.m = this;
			this->d_event_set.fire_event(event_add, ags);
		}
		return p_e;

	}
	template<typename K, typename T>
	void elem_event_map<K, T>::rmv(K id)
	{
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			mm_event_map_ags ags;
			ags.e = it->second;
			ags.id = id;
			ags.m = this;
			this->d_event_set.fire_event(event_rmv, ags);
			delete(it->second);
			this->m.erase(it);
		}
	}
	template<typename K, typename T>
	void elem_event_map<K, T>::clear()
	{
		mm_event_map_ags ags;
		//���� map_int_elem_p 
		typename map_type::iterator it = this->m.begin();
		while (it != this->m.end())
		{
			ags.e = it->second;
			ags.id = it->first;
			ags.m = this;
			this->d_event_set.fire_event(event_rmv, ags);
			delete(it->second);
			this->m.erase(it++);
		}
	}



	template<typename K, typename T>
	class elem_map
	{
	public:
		typedef std::map<K, T*> map_type;
	public:
		map_type m;
	public:
		// ��get�����getΪ�գ����Զ�����һ��
		T* get_instance(K id);
		// ��get�����getΪ�գ����� NULL
		T* get(K id);
		// ��������ڣ��򴴽���ӣ���������򷵻�ԭ������
		T* add(K id);
		// ���������ɾ�������������޷�Ӧ
		void rmv(K id);
		// ȫ��Ԫ��ɾ��
		void clear();
	};

	template<typename K, typename T>
	T* elem_map<K, T>::get_instance(K id)
	{
		T p_e = this->get(id);
		if (NULL == p_e)
		{
			p_e = this->add(id);
		}
		return p_e;
	}
	template<typename K, typename T>
	T* elem_map<K, T>::get(K id)
	{
		T* p_e = NULL;
		//Ѱ��Ԫ�� 
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			p_e = it->second;
		}
		return p_e;
	}
	template<typename K, typename T>
	T* elem_map<K, T>::add(K id)
	{
		T* p_e = NULL;
		//Ѱ��Ԫ�� 
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			p_e = it->second;
		}
		else
		{
			p_e = new T;
			this->m.insert(typename map_type::value_type(id, p_e));
		}
		return p_e;

	}
	template<typename K, typename T>
	void elem_map<K, T>::rmv(K id)
	{
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			delete(it->second);
			this->m.erase(it);
		}
	}
	template<typename K, typename T>
	void elem_map<K, T>::clear()
	{
		//���� map_int_elem_p 
		typename map_type::iterator it = this->m.begin();
		while (it != this->m.end())
		{
			delete(it->second);
			this->m.erase(it++);
		}
	}

	template<typename K, typename T>
	class elem_p_map
	{
	public:
		typedef std::map<K, T> map_type;
	public:
		map_type m;
	public:
		// ��get�����getΪ�գ����� NULL
		T get(K id );
		// ��������ڣ��򴴽���ӣ���������򸲸�
		void add(K id, T p);
		// ���������ɾ�������������޷�Ӧ
		void rmv(K id);
		// ȫ��Ԫ��ɾ��
		void clear();
	};

	template<typename K, typename T>
	T elem_p_map<K, T>::get(K id)
	{
		T p_e = NULL;
		//Ѱ��Ԫ�� 
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			p_e = it->second;
		}
		return p_e;
	}
	template<typename K, typename T>
	void elem_p_map<K, T>::add(K id, T p)
	{
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			it->second = p;
		}
		else
		{
			this->m.insert(typename map_type::value_type(id, p));
		}
	}
	template<typename K, typename T>
	void elem_p_map<K, T>::rmv(K id)
	{
		typename map_type::iterator it = this->m.find(id);
		if (it != this->m.end())
		{
			this->m.erase(it);
		}
	}
	template<typename K, typename T>
	void elem_p_map<K, T>::clear()
	{
		//���� map_int_elem_p 
		typename map_type::iterator it = this->m.begin();
		while (it != this->m.end())
		{
			this->m.erase(it++);
		}
	}


}


//////////////////////////////////////////////////////////////////////////
#endif//__mm_elem_map_h__