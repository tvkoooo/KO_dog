#include "core/mm_core.h"
#include "core/mm_logger_manager.h"

#define use_vld_check_memory_leak
#if _DEBUG && MM_WIN32
#ifdef use_vld_check_memory_leak
#include <vld.h>
#endif
#endif // _DEBUG

#include <sys/types.h>
#include <signal.h>

#include <exception>

#include "mm_application.h"

static void __static_signal_destroy(int n)  
{
	struct mm_application* p = mm_application_instance();
	struct mm_logger* g_logger = mm_logger_instance();
	mm_application_shutdown(p);
	mm_logger_log_I(g_logger,"signal_destroy %d signal:%d.",__LINE__,n);
}
int main(int argc,char **argv)
{
	struct mm_application* p = NULL;
	//
	signal(SIGINT	,&__static_signal_destroy);
	// We expect write failures to occur but we want to handle them where 
	// the error occurs rather than in a SIGPIPE handler.
	// when send to a disconnected socket,will trigger SIGPIPE,default handler is terminate.
	// we not find a best way for this signal.
	signal(SIGPIPE  ,SIG_IGN);
	//
	try
	{
		p = mm_application_instance();
		mm_application_init(p);
		mm_application_initialize(p,argc,(const char**)argv);
		mm_application_start(p);
		mm_application_join(p);
		mm_application_destroy(p);
	}
	catch (std::exception& e)
	{
		mm_printf("A untreated exception occur:%s\n",e.what());
	}
	return 0;
}