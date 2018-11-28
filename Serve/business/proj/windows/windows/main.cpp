#include "core/mm_config.h"
#include "core/mm_core.h"
#include "core/mm_logger_manager.h"

#include <stdio.h>
#define use_vld_check_memory_leak
#if _DEBUG && MM_WIN32
#ifdef use_vld_check_memory_leak
#include <vld.h>
#endif
#endif // _DEBUG

#include <exception>

#include "mm_application.h"

BOOL WINAPI __static_signal_destroy(DWORD msgType)
{
	switch (msgType)
	{
	case CTRL_C_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		{
			struct mm_application* p = mm_application_instance();
			struct mm_logger* g_logger = mm_logger_instance();
			mm_application_shutdown(p);
			mm_logger_log_I(g_logger,"signal_destroy %d signal:%d.",__LINE__,msgType);
			return TRUE;
		}
		break;
	default:
		return FALSE;
	}
	return FALSE;
}
int main(int argc,char **argv)
{
	struct mm_application* p = NULL;
#ifdef _DEBUG
	int _argc = g_argument.argc;
	const char** _argv = g_argument.argv;
#else
	int _argc = argc;
	const char** _argv = (const char**)argv;
#endif
	try
	{
		//
		SetConsoleCtrlHandler(__static_signal_destroy, TRUE);
		//
		p = mm_application_instance();
		mm_application_init(p);
		mm_application_initialize(p,_argc,_argv);
		mm_application_start(p);
		mm_application_join(p);
		mm_application_destroy(p);
	}
	catch (std::exception& e)
	{
		mm_printf("A untreated exception occur:%s\n",e.what());
		MessageBox(NULL, e.what(), "An exception has occurred!", MB_ICONERROR | MB_TASKMODAL);
	}
	return 0;
}