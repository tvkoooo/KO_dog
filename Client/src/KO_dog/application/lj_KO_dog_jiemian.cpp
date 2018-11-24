#include "lj_KO_dog_jiemian.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"

namespace mm
{
	lj_KO_dog_jiemian::lj_KO_dog_jiemian()
		: d_flake_context(NULL)
		, d_surface(NULL)

	{

	}

	lj_KO_dog_jiemian::~lj_KO_dog_jiemian()
	{

	}
	void lj_KO_dog_jiemian::assign_flake_context(mm_flake_context* flake_context)
	{
		this->d_flake_context = flake_context;
	}

	void lj_KO_dog_jiemian::on_finish_launching(mm_flake_surface* surface)
	{
		this->d_surface = surface;
		/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
		CEGUI::GUIContext* _gui_context = this->d_surface->d_gui_context;
		//////////////////////////////////////////////////////////////////////////
		int index = 0;
		char index_string[64] = { 5 };
		mm_sprintf(index_string, "_%d", index);

		std::string system_font_18_name = "system_font_18";
		system_font_18_name = system_font_18_name + index_string;
		//////////////////////////////////////////////////////////////////////////
		// CEGUI relies on various systems being set-up, so this is what we do
		// here first.
		//
		// The first thing to do is load a CEGUI 'scheme' this is basically a file
		// that groups all the required resources and definitions for a particular
		// skin so they can be loaded / initialised easily
		//
		// So, we use the SchemeManager singleton to load in a scheme that loads the
		// imagery and registers widgets for the TaharezLook skin.  This scheme also
		// loads in a font that gets used as the system default.
		CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");

		// create the default surface font.
		CEGUI::Font& _defaultFont = this->d_flake_context->d_cegui_system.create_system_font_by_size(this->d_surface->get_canvas_size(), system_font_18_name.c_str(), 18.0f);

		// The next thing we do is to set a default mouse cursor image.  This is
		// not strictly essential, although it is nice to always have a visible
		// cursor if a window or widget does not explicitly set one of its own.
		//
		// The TaharezLook Imageset contains an Image named "MouseArrow" which is
		// the ideal thing to have as a defult mouse cursor image.
		_gui_context->getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

		// load font and setup default if not loaded via scheme
		// Set default font for the gui context
		_gui_context->setDefaultFont(&_defaultFont);

		this->zhujiemian.set_data(this->d_flake_context,this->d_surface);
		this->zhujiemian.on_finish_launching();

	}
	void lj_KO_dog_jiemian::on_before_terminate(mm_flake_surface* surface)
	{
		this->zhujiemian.on_before_terminate();
		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_zhujiemian::%s %d success.", __FUNCTION__, __LINE__);
		CEGUI::SchemeManager::getSingleton().destroy("TaharezLook");

	}


}