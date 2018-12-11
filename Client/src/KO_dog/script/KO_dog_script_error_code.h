#ifndef __KO_dog_script_error_code_h__
#define __KO_dog_script_error_code_h__
#include <string>
#include "core/mm_core.h"

struct lua_State;


extern void KO_dog_script_error_code_get_view(struct lua_State* L, mm_uint32_t code, std::string& view);




#endif//__KO_dog_script_error_code_h__