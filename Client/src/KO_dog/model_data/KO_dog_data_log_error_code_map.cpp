#include "KO_dog_data_log_error_code_map.h"


namespace mm
{

	//KO_dog_data_log_error_code_map/////////////////////////////////////////////////////////////////////////////////
	KO_dog_data_log_error_code_map::KO_dog_data_log_error_code_map()
	{
		this->map_err_code.clear();
		this->load();
	}
	KO_dog_data_log_error_code_map::~KO_dog_data_log_error_code_map()
	{
		this->clear();
		this->map_err_code.clear();
	}

	void KO_dog_data_log_error_code_map::load()
	{
		//this->add((mm_uint32_t)-1, "未知错误");
		//this->add(0, "成功");		

		//this->add(100000001, "解包失败");
		//this->add(100000002, "打包失败");
		//this->add(100000101, "执行存储过程失败");
		//this->add(100000102, "执行脚本失败");
		//this->add(100000103, "执行命令失败");
		//this->add(100000201, "不支持的模块");
		//this->add(100000202, "不支持的功能");
		//this->add(100000203, "不支持的接口");
		//this->add(100000204, "不支持的操作码");
		//this->add(100000301, "无效的参数");
		//this->add(100000302, "无效的用户号");
		//this->add(100000701, "网络数据库断开连接");
		//this->add(100000702, "网络服务断开连接");
		//this->add(100000801, "系统内存不足");
		//this->add(100000901, "系统输入输出打开文件失败");

		//this->add(200000001, "服务器异常");
		//this->add(200000002, "服务器异常");
		//this->add(200000003, "服务器异常");
		//this->add(200000004, "服务器异常");
		//this->add(200000005, "服务器异常");

		//this->add(400001001, "大厅令牌验证失败");
		//this->add(400000001, "获取大厅入口数据失败");
		//this->add(400100014, "你输入带有奇葩字符");

		//this->add(400100011, "登陆账号不存在");
		//this->add(400100012, "账号与密码不匹配");
		//this->add(400100013, "注册账号已经存在");
		//this->add(400100014, "你输入带有奇葩字符");
	}

	void KO_dog_data_log_error_code_map::clear()
	{
		this->map_err_code.clear();
	}
	void KO_dog_data_log_error_code_map::add(mm_uint32_t code,  const std::string& view)
	{		
		this->map_err_code[code] = view;
	}
	void KO_dog_data_log_error_code_map::remove(mm_uint32_t code)
	{
		this->map_err_code.erase(code);

	}
	static const std::string undefined_err = "未定义错误";
	//const std::string& KO_dog_data_log_error_code_map::get(mm_uint32_t code)
	//{
	//	log_error_code_map_type::iterator it = this->map_err_code.find(code);
	//	if (it == this->map_err_code.end())
	//	{
	//		//没有找到
	//		return undefined_err;
	//	}
	//	else
	//	{
	//		//找到
	//		return it->second;
	//	}
	//}

}

