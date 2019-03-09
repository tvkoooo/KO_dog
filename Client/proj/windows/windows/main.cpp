#include "core/mm_config.h"
#include "core/mm_core.h"
#include "core/mm_logger_manager.h"

#include <tchar.h>
#include <stdio.h>
// #define use_vld_check_memory_leak
#if _DEBUG && MM_WIN32
#ifdef use_vld_check_memory_leak
#include <vld.h>
#endif
#endif // _DEBUG

#include <exception>

#include "dish/mm_config_value.h"
#include "dish/mm_config_parse.h"

#include "flake/mm_flake_context.h"

#include "application/KO_dog.h"

//BOOL WINAPI __static_signal_destroy(DWORD msgType)
//{
//	switch (msgType)
//	{
//	case CTRL_C_EVENT:
//	case CTRL_BREAK_EVENT:
//	case CTRL_CLOSE_EVENT:
//	case CTRL_LOGOFF_EVENT:
//	case CTRL_SHUTDOWN_EVENT:
//		{
//			mm::mm_flake_application* application = mm::mm_flake_application::get_global_weak_instance();
//			if (NULL != application)
//			{
//				struct mm_logger* g_logger = mm_logger_instance();
//				application->shutdown();
//				mm_logger_log_I(g_logger,"signal_destroy %d signal:%d.",__LINE__,msgType);
//			}
//			return TRUE;
//		}
//		break;
//	default:
//		return FALSE;
//	}
//	return FALSE;
//}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR    lpCmdLine,
					   _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	::AllocConsole();
	HWND console_hwnd = GetConsoleWindow();
	freopen("CONIN$"	, "r", stdin );
	freopen("CONOUT$"	, "w", stdout);
	freopen("CONOUT$"	, "w", stderr);

	// SW_SHOW
	// SW_HIDE
#ifdef _DEBUG
	ShowWindowAsync(console_hwnd, SW_SHOW);
#else
	ShowWindowAsync(console_hwnd, SW_HIDE);
#endif//_DEBUG
	try
	{
		//////////////////////////////////////////////////////////////////////////
		//SetConsoleCtrlHandler(__static_signal_destroy, TRUE);
		//////////////////////////////////////////////////////////////////////////
		std::string application_name = "mm";
		std::string logger_file_name = "mm";
		std::string logger_path = "log";
		mm_uint32_t logger_level = 7;
		mm_sint8_t	logger_is_console = 1;
		mm_sint8_t	logger_is_immediately = 1;
		mm_uint32_t root_resources_type = 0;
		std::string root_resources_path = "";
		std::string root_resources_base = "";
		std::string shader_cache_folder = "";
		std::string plugin_folder = "";
		std::string dynlib_folder = "";
		mm_scalar_t window_size_w = 480.0f;
		mm_scalar_t window_size_h = 800.0f;
		mm_scalar_t canvas_size_w = 480.0f;
		mm_scalar_t canvas_size_h = 800.0f;
		double frame_zoom_factor  =   0.8f;
		double logical_frequency = 30.0;
		double display_frequency = 60.0;
		std::string render_system_name = "";
		std::string render_window_name = "";
		//////////////////////////////////////////////////////////////////////////
		mm::mm_config_value config_value;
		mm::mm_config_parse config_parse(config_value);
		config_parse.load_file("launch.config");
		config_value.get_value("application_name", application_name);
		config_value.get_value("logger_file_name", logger_file_name);
		config_value.get_value("logger_path", logger_path);
		config_value.get_value("logger_level",logger_level);
		config_value.get_value("logger_is_console",logger_is_console);
		config_value.get_value("logger_is_immediately",logger_is_immediately);
		config_value.get_value("root_resources_type",root_resources_type);
		config_value.get_value("root_resources_path",root_resources_path);
		config_value.get_value("root_resources_base",root_resources_base);
		config_value.get_value("shader_cache_folder",shader_cache_folder);
		config_value.get_value("plugin_folder",plugin_folder);
		config_value.get_value("dynlib_folder",dynlib_folder);
		config_value.get_value("window_size_w",window_size_w);
		config_value.get_value("window_size_h",window_size_h);
		config_value.get_value("canvas_size_w",canvas_size_w);
		config_value.get_value("canvas_size_h",canvas_size_h);
		config_value.get_value("frame_zoom_factor",frame_zoom_factor);
		config_value.get_value("logical_frequency", logical_frequency);
		config_value.get_value("display_frequency", display_frequency);
		config_value.get_value("render_system_name",render_system_name);
		config_value.get_value("render_window_name",render_window_name);
		//////////////////////////////////////////////////////////////////////////
		mm::mm_flake_context* flake_context = mm::mm_flake_context::native_alloc();
		mm::mm_flake_activity* impl = mm::mm_flake_activity_native_alloc();
		struct mm_vector2 window_size;
		struct mm_vector2 canvas_size;
		window_size.x = window_size_w;
		window_size.y = window_size_h;
		canvas_size.x = canvas_size_w;
		canvas_size.y = canvas_size_h;
		//
		impl->init();
		// assign
		flake_context->init();
		flake_context->set_application_name(application_name);
		flake_context->set_root_resources_path(root_resources_path);
		flake_context->set_shader_cache_folder(shader_cache_folder);
		flake_context->assign_assets_root(root_resources_type, root_resources_path, root_resources_base);
		//
		flake_context->set_flake_activity(impl);
		flake_context->set_context_handler(hInstance);
		//
		flake_context->assign_logger_file_name(logger_file_name.c_str());
		flake_context->assign_logger_path(logger_path.c_str());
		flake_context->assign_logger_level(logger_level);
		flake_context->assign_logger_is_console(logger_is_console);
		flake_context->assign_logger_is_immediately(logger_is_immediately);
		//
		flake_context->set_render_system_name(render_system_name);
		flake_context->set_logical_frequency(logical_frequency);
		flake_context->set_display_frequency(display_frequency);
		flake_context->set_main_surface_window_size(window_size);
		flake_context->set_main_surface_canvas_size(canvas_size);
		flake_context->set_main_surface_frame_zoom_factor(frame_zoom_factor);
		flake_context->set_main_surface_render_window_name(render_window_name);
		//
		flake_context->assembled_context();
		flake_context->start();
		flake_context->join();
		flake_context->dismantle_context();
		flake_context->destroy();
		//
		impl->destroy();
		//
		mm::mm_flake_activity_native_dealloc(impl);
		mm::mm_flake_context::native_dealloc(flake_context);
		//////////////////////////////////////////////////////////////////////////
	}
	catch (std::exception& e)
	{
		mm_printf("A untreated exception occur:%s\n",e.what());
		MessageBox(NULL, e.what(), "An exception has occurred!", MB_ICONERROR | MB_TASKMODAL);
	}

	::FreeConsole();

	return 0;
}