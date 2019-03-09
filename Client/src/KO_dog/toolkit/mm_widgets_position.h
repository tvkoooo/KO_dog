#ifndef __mm_widgets_position_h__
#define __mm_widgets_position_h__
//////////////////////////////////////////////////////////////////////////
#include <map>

#include "flake/mm_flake_surface.h"
#include "math/mm_vector3.h"
#include "dish/mm_event.h"

//////////////////////////////////////////////////////////////////////////
namespace mm
{
	typedef bool(*on_event_function) (const mm_event_args& args);
	class mm_event_common_l : public mm_event_args
	{
	public:
		void* v;
	public:
		mm_event_common_l()
			: v(NULL)
		{
		}
		~mm_event_common_l()
		{
		}
	};
	class mm_widgets_position_data
	{
	public:
		CEGUI::Window* widgets_handle;                   //element_handle
		on_event_function began;
		on_event_function end;
		struct mm_vector2 widgets_anchor_center;         //element_anchor_center
		struct mm_vector2 _r_min_f;                      //element_anchor_min
		struct mm_vector2 _r_max_f;                      //element_anchor_max
		bool is_anchor_touch;                            //element_is_anchor_touch
		int motion_id;
	public:
		mm_widgets_position_data()
			: widgets_handle(NULL)
			, began(NULL)
			, end(NULL)
			, is_anchor_touch(false)
			, motion_id(-1)
		{
			mm_vector2_init(&this->widgets_anchor_center);
			mm_vector2_init(&this->_r_min_f);
			mm_vector2_init(&this->_r_max_f);
		}
		~mm_widgets_position_data()
		{
			mm_vector2_destroy(&this->widgets_anchor_center);
			mm_vector2_destroy(&this->_r_min_f);
			mm_vector2_destroy(&this->_r_max_f);
		}
	};


	class mm_widgets_position
	{
	public:
		typedef std::map<CEGUI::Window*, mm_widgets_position_data*> map_type;

	public:
		map_type m;
		std::map<int, CEGUI::Window*> seach_map;
		int seach_map_id;

	public:
		mm_flake_surface* d_surface;
		double _window_size_x;
		double _window_size_y;		
		//
	public:	
		mm_widgets_position();
		~mm_widgets_position();
	public:		
		void set_flake_surface(mm_flake_surface* d_surface);
	public:
		// ��get�����getΪ�գ����Զ�����һ��
		mm_widgets_position_data* get_instance(CEGUI::Window* widgets_handle);
		// ��get�����getΪ�գ����� NULL
		mm_widgets_position_data* get(CEGUI::Window* widgets_handle);
		// ��������ڣ��򴴽���ӣ��ҷ���event_add����������򷵻�ԭ������
		mm_widgets_position_data* add(CEGUI::Window* widgets_handle);
		// ���������ɾ���ҷ���event_rmv�����������޷�Ӧ
		void rmv(CEGUI::Window* widgets_handle);
		// �ȴ����¼� event_clear����ȫ��Ԫ��ɾ��
		void clear();
	public:
		void touch_began(const mm_event_args& args);
		void touch_end(const mm_event_args& args);
	};





}












//////////////////////////////////////////////////////////////////////////
#endif//__mm_widgets_position_h__