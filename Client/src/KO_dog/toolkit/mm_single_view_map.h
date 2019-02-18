#ifndef __mm_single_view_map_h__
#define __mm_single_view_map_h__
#include <map>
#include <string>


#include "CEGUI/Window.h"
//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class mm_single_view_map
	{
	public:
		typedef std::map<std::string, CEGUI::Window*> map_type;
	public:
		mm_single_view_map();
		~mm_single_view_map();

	public:
		void clear();
		CEGUI::Window* view_now();
		void add(const std::string &s, CEGUI::Window* h);
		void rmv(const std::string &s);
		void blank();
		void view(const std::string &s);

	private:
		CEGUI::Window* get(const std::string &s);

	private:
		map_type m_string_single_view;
		CEGUI::Window* Window_now;
	};





}
//////////////////////////////////////////////////////////////////////////
#endif//__mm_single_view_map_h__