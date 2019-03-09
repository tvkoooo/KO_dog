#include "mm_widgets_position.h"

#include "CEGUI/WindowManager.h"
#include "flake/mm_system_event_touch.h"
//////////////////////////////////////////////////////////////////////////
namespace mm
{
	mm_widgets_position::mm_widgets_position()
		: seach_map_id(0)
		, d_surface(NULL)
		, _window_size_x(0)
		, _window_size_y(0)
	{
		this->clear();
	}
	mm_widgets_position::~mm_widgets_position()
	{
		this->clear();
	}
	void mm_widgets_position::set_flake_surface(mm_flake_surface* d_surface)
	{
		this->d_surface = d_surface;
		this->_window_size_x = this->d_surface->d_window_size.x;
		this->_window_size_y = this->d_surface->d_window_size.y;
	}
	// 先get，如果get为空，会自动创建一个
	mm_widgets_position_data* mm_widgets_position::get_instance(CEGUI::Window* widgets_handle)
	{
		mm_widgets_position_data* p_e = this->get(widgets_handle);
		if (NULL == p_e)
		{
			p_e = this->add(widgets_handle);
		}
		return p_e;
	}
	// 先get，如果get为空，返回 NULL
	mm_widgets_position_data* mm_widgets_position::get(CEGUI::Window* widgets_handle)
	{
		mm_widgets_position_data* p_e = NULL;
		//寻找元素 
		typename map_type::iterator it = this->m.find(widgets_handle);
		if (it != this->m.end())
		{
			p_e = it->second;
		}
		return p_e;
	}
	// 如果不存在，则创建添加，且发送event_add，如存在则，则返回原来数据
	mm_widgets_position_data* mm_widgets_position::add(CEGUI::Window* widgets_handle)
	{
		mm_widgets_position_data* p_e = NULL;
		//寻找元素 
		typename map_type::iterator it = this->m.find(widgets_handle);
		if (it != this->m.end())
		{
			p_e = it->second;
		}
		else
		{
			p_e = new mm_widgets_position_data;
			this->m.insert(typename map_type::value_type(widgets_handle, p_e));
		}
		//计算 widgets_handle 区域中心点  四个顶点坐标
		{
			const CEGUI::URect& area = widgets_handle->getArea();

			const CEGUI::UVector2& _r_min = area.d_min;
			const CEGUI::UVector2& _r_max = area.d_max;

			CEGUI::UVector2 _r_size = CEGUI::UVector2(_r_max.d_x - _r_min.d_x, _r_max.d_y - _r_min.d_y);
			CEGUI::UVector2 _r_center = _r_min + _r_size / CEGUI::UDim(2.0f, 0);

			p_e->widgets_anchor_center.x = (_r_center.d_x.d_scale * this->_window_size_x) + _r_center.d_x.d_offset;
			p_e->widgets_anchor_center.y = (_r_center.d_y.d_scale * this->_window_size_y) + _r_center.d_y.d_offset;
			//
			p_e->_r_min_f.x = (_r_min.d_x.d_scale * this->_window_size_x) + _r_min.d_x.d_offset;
			p_e->_r_min_f.y = (_r_min.d_y.d_scale * this->_window_size_y) + _r_min.d_y.d_offset;

			p_e->_r_max_f.x = (_r_max.d_x.d_scale * this->_window_size_x) + _r_max.d_x.d_offset;
			p_e->_r_max_f.y = (_r_max.d_y.d_scale * this->_window_size_y) + _r_max.d_y.d_offset;
		}
		return p_e;
	}
	// 如果存在则删除且发送event_rmv，不存在则无反应
	void mm_widgets_position::rmv(CEGUI::Window* widgets_handle)
	{
		typename map_type::iterator it = this->m.find(widgets_handle);
		if (it != this->m.end())
		{
			delete(it->second);
			this->m.erase(it);
		}

	}
	// 先触发事件 event_clear，后全部元素删除
	void mm_widgets_position::clear()
	{
		//遍历 map_int_elem_p 
		typename map_type::iterator it = this->m.begin();
		while (it != this->m.end())
		{
			delete(it->second);
			this->m.erase(it++);
		}
	}

	void mm_widgets_position::touch_began(const mm_event_args& args)
	{
		const mm_event_touch_set& evt = (const mm_event_touch_set&)(args);
		//遍历 map_int_elem_p 
		typename map_type::iterator it = this->m.begin();
		while (it != this->m.end())
		{
			mm_widgets_position_data* d = it->second;
			if (NULL != d)
			{
				for (size_t i = 0; i < evt.content.size && i < 8; i++)
				{
					if ((d->_r_min_f.x - evt.content.touchs[i].minor_radius <= evt.content.touchs[i].abs_x) &&
						(d->_r_max_f.x + evt.content.touchs[i].minor_radius > evt.content.touchs[i].abs_x) &&
						(d->_r_min_f.y - evt.content.touchs[i].minor_radius <= evt.content.touchs[i].abs_y) &&
						(d->_r_max_f.y + evt.content.touchs[i].minor_radius > evt.content.touchs[i].abs_y))
					{
						if (false == d->is_anchor_touch)
						{
							d->is_anchor_touch = true;
							if (-1 == d->motion_id)
							{
								d->motion_id = evt.content.touchs[i].motion_id;
								this->seach_map_id = (this->seach_map_id++) % 100;
								this->seach_map[this->seach_map_id] = it->second->widgets_handle;
								(d->began)(args);
							}
						}
					}
				}

			}
		}
	}
	void mm_widgets_position::touch_end(const mm_event_args& args)
	{
		const mm_event_touch_set& evt = (const mm_event_touch_set&)(args);
		for (size_t i = 0; (i < evt.content.size || i < 8); i++)
		{
			int motion_id = evt.content.touchs[i].motion_id;
			//遍历 std::map<int, CEGUI::Window*> 
			std::map<int, CEGUI::Window*>::iterator it = this->seach_map.begin();
			while (it != this->seach_map.end())
			{
				mm_widgets_position_data* p_e = get(it->second);
				if (NULL != p_e)
				{
					if (p_e->motion_id == motion_id)
					{
						if (true == p_e->is_anchor_touch)
						{
							p_e->is_anchor_touch = false;
							p_e->motion_id = -1;
							this->seach_map.erase(it);
							p_e->end(args);
						}
					}

				}
			}

		}
	}
}


