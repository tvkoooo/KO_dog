#include "mm_single_view_map.h"

namespace mm
{
	mm_single_view_map::mm_single_view_map()
		: Window_now(NULL)
	{
	}

	mm_single_view_map::~mm_single_view_map()
	{
		this->clear();
	}

	void mm_single_view_map::clear()
	{
		this->m_string_single_view.clear();
		this->Window_now = NULL;
	}
	CEGUI::Window* mm_single_view_map::view_now()
	{
		return this->Window_now;
	}
	void mm_single_view_map::add(const std::string &s, CEGUI::Window* h)
	{
		//寻找元素 
		map_type::iterator it = this->m_string_single_view.find(s);
		if (it != this->m_string_single_view.end())
		{
			//如果找到，覆盖
			it->second = h;
			h->setVisible(false);
		}
		else
		{
			//没有找到，则新建
			this->m_string_single_view.insert(map_type::value_type(s, h));
			h->setVisible(false);
		}

	}
	void mm_single_view_map::rmv(const std::string &s)
	{
		//寻找元素 
		map_type::iterator it = this->m_string_single_view.find(s);
		if (it != this->m_string_single_view.end())
		{
			//如果找到，删除
			this->m_string_single_view.erase(it);
		}
		else
		{
			//没有找到
		}
	}
	void mm_single_view_map::blank()
	{
		if ( NULL != this->Window_now)
		{
			this->Window_now->setVisible(false);
			this->Window_now = NULL;
		}
	}
	void mm_single_view_map::view(const std::string &s)
	{
		CEGUI::Window* f = this->get(s);
		if (NULL != f)
		{
			if (NULL != this->Window_now)
			{
				if (this->Window_now != f)
				{
					this->Window_now->setVisible(false);
					this->Window_now = f;
					this->Window_now->setVisible(true);
				}
			}
			else
			{
				this->Window_now = f;
				this->Window_now->setVisible(true);
			}
		}
	}

	CEGUI::Window* mm_single_view_map::get(const std::string &s)
	{
		CEGUI::Window* f;
		//寻找元素 
		map_type::iterator it = this->m_string_single_view.find(s);
		if (it != this->m_string_single_view.end())
		{
			//如果找到
			f = it->second;
		}
		else
		{
			//没有找到
			f = NULL;
		}
		return f;
	}

}