#include "KO_dog_script_error_code.h"
#include <string>


#include "lua/mm_lua.h"



void KO_dog_script_error_code_get_view(struct lua_State* L,  mm_uint32_t code , std::string& view)
{
	// ����չʾ����Ҫʹ��utf8��bom��ʽ�����ı� ���پ��� CEGUI::String ת�����������������
	// String(const utf8* utf8_str, size_type chars_len)
	mm::mm_lua _lua(L);
	_lua.push(code);
	_lua.call("model_error", "err_code_view", 1, 1);
	_lua.pop(view);
}




