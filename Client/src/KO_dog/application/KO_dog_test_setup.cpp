#include "KO_dog_test_setup.h"
#include "stdio.h"
#include <string>
#include <map>



//类型的前置声明
class AAA_test;

//使用前置类型声明指针的函数示例，这种函数只能使用指针
void funaazhengchang(AAA_test* a);
void funbucunzai(AAA_test* a)
{
	//a->launch() ; //这种是不存在的，如果要使用这个的具体函数，必须包含他的完整类型，例如下面的函数 void funaazhengchang(AAA_test* a)。
}


class AAA_test
{
public:
	std::string s;

public:
	AAA_test()
		:s("")
	{

	};
	AAA_test(const std::string& zfc)
		:s(zfc)
	{

	};
	virtual ~AAA_test()
	 {

	 };

public:
	virtual void launch()
	{
		printf("AAA_test \n");
	};
};

void funaazhengchang(AAA_test* a)
{
	a->launch() ; //前置声明放最上面。
}


class AAA_test_win :public AAA_test
{
public:


public:
	////总结：
	//	带参数构造函数和默认构造函数的区别（如果什么构造函数都没有，编译器会默认生成一个默认构造函数，如果显示定义一个构造函数，
	//	编译器不会再生成一个默认构造函数，特别情况，如果只定义显式带参数构造函数，则不会有默认无参数的默认构造函数，当子类调用父类构造函数时，
	//	不能使用无参数构造函数，要么显式添加父类的带参数构造函数，传人参数，要么多添加一个无参数的构造函数）
	AAA_test_win(const std::string& zfc)
	//构造函数初始化，一定要按照顺序初始化变量
		: AAA_test(zfc)
		, p_int(NULL)
	{
		this->p_int = new int;

	};

	////总结：
	//	析构函数是否添加 virtual，如果class里面所有函数都没有virtual，析构函数不带virtual
	//	如果class里面所有函数有任何一个函数带virtual，析构函数必须带virtual，否则某些子类的虚构函数可能不会被调用，造成内存泄漏，或者逻辑错误。
	virtual ~AAA_test_win() 
	{
		delete this->p_int;
		this->p_int = NULL;
	};
	int * p_int;


	////总结：
	//	函数之前有virtual，并且是属于某个父类的虚函数，需要做一个备注，是哪个父类的虚函数（可读性更强）
	//	父类带virtual，子类推荐带有virtual（不带也是对的），可读性更强
	//	父类一个情况下的虚函数，尽量在一个public组当中，分割
public:
	// AAA_test
	virtual void launch()
	{
		AAA_test::launch();
		printf("AAA_test_win \n");
	};
};

class AAA_test_android :public AAA_test
{
public:


public:
	AAA_test_android(const std::string& zfc)
		: AAA_test(zfc)
	{

	};
	virtual ~AAA_test_android() {};

public:
	// AAA_test
	virtual void launch()
	{
		AAA_test::launch();
		printf("AAA_test_android \n");
	};
};

class AAA_test_linux :public AAA_test
{
public:


public:
	//const type &取引用 例如（const std::string& zfc），可以不用使用 -> 更方便，且不用判空，并且不会产生值拷贝，对象比较大更好。 加const， zfc不能被改变，更安全
	//const type *取指针 例如（const std::string* zfc），加const， zfc不能被改变，更安全
	//直接使用type 例如（int/float等），基础类型
	//使用type*  ，需要修改传入的数据，c语言只能用*
	AAA_test_linux(const std::string& zfc)
		: AAA_test(zfc)
	{

	};
	virtual ~AAA_test_linux() {};

public:
	// AAA_test
	virtual void launch()
	{
		//使用特定目标父类的函数，在使用函数前面加上类型::  (例如 AAA_test::launch();比较安全，不会错)  或者(this->AAA_test::launch();可读性强 ，如果父类函数是静态函数，this-> 是不能添加的)
		this->AAA_test::launch();
		printf("AAA_test_linux \n");
	};
};

//虚工厂类型
//最关键的四个接口：注册，解注册，创建（虚基类），销毁（虚基类）；所以它叫虚工厂
class factory
{
	//函数签名
	typedef AAA_test* (*fun_type_test)(const std::string& zfc);
public:
	//易用性更强，改一处就可以改全部地方
	typedef std::map<std::string, fun_type_test>  map_type_test;//类型实例化，泛型要实例化操作
	//行为表，特征是用不同的标志来表示不同的行为块（函数），
	map_type_test zhuce_map;
	
	void zhuce(const std::string& zfc, fun_type_test f)
	{
		//迭代器插入
		map_type_test::iterator it = this->zhuce_map.find(zfc);
		if (it == zhuce_map.end())
		{
			//没有找到
			zhuce_map.insert(map_type_test::value_type(zfc, f));
		}
		else
		{
			//找到
			printf("bu neng congfu zhuce. \n");
			//it->first;
			//it->second;
		}
	}

	void jiebang(const std::string& zfc)
	{
		//迭代器删除
		map_type_test::iterator it = this->zhuce_map.find(zfc);
		if (it == zhuce_map.end())
		{
			//没有找到
			printf("guocheng bu cunzhai. \n");
			
		}
		else
		{
			//找到
			zhuce_map.erase(it);
			//it->first;
			//it->second;
		}
	}

	//普通工厂实现函数，带参（实例 子类型标志）
	AAA_test* fun_chuangjian(const std::string& zfc)
	{
		AAA_test* t = NULL;
		//if (zfc == "windows")
		//{
		//	t = new AAA_test_win(zfc);
		//}
		//if (zfc == "android")
		//{
		//	t = new AAA_test_android(zfc);
		//}
		//if (zfc == "linux")
		//{
		//	t = new AAA_test_linux(zfc);
		//}

		//迭代器查询
		map_type_test::iterator it = this->zhuce_map.find(zfc);
		if (it == zhuce_map.end())
		{
			//没有找到
			printf("chuangjian shibai. \n");
		}
		else
		{
			
			//找到
			//可调用体（仿函数）的使用方法 (it->second) 这个最好加个括号
			t = (it->second)(zfc);
			//it->first;
			//it->second;
		}
		return t;
	}

	void fun_xiaohui(AAA_test *test)
	{
		if (test != NULL)
		{
			delete test;
		}
	}

};

//static 加在函数签名，只能在本cpp使用，避免函数命名空间冲突
//最简式工厂函数不同实现
static AAA_test* fun_chuangjian_windouws(const std::string& zfc)
{
	AAA_test* t = new AAA_test_win(zfc);
	return t;
}
//最简式工厂函数
static AAA_test* fun_chuangjian_android(const std::string& zfc)
{
	AAA_test* t = new AAA_test_android(zfc);
	return t;
}
//最简式工厂函数
static AAA_test* fun_chuangjian_linux(const std::string& zfc)
{
	AAA_test* t = new AAA_test_linux(zfc);
	return t;
}


void KO_dog_test_a()
{
	//栈空间的效率高，如果可以使用栈空间，不推荐堆空间（new 或者malloc 出来的）
	factory f;
	f.zhuce("windows", fun_chuangjian_windouws);
	f.zhuce("android", fun_chuangjian_android);
	f.zhuce("linux", fun_chuangjian_linux);

	// 添加一个括号有个好处，可以快速复制代码，防止命名空间冲突
	{
		AAA_test *a_test = f.fun_chuangjian("windows");
		a_test->launch();
		f.fun_xiaohui(a_test);
	}
	{
		AAA_test *a_test = f.fun_chuangjian("android");
		a_test->launch();
		f.fun_xiaohui(a_test);
	}
	{
		AAA_test *a_test = f.fun_chuangjian("linux");
		a_test->launch();
		f.fun_xiaohui(a_test);
	}
	f.jiebang("windows");
	f.jiebang("android");
	f.jiebang("linux");
}

//空class类型的 sizeof 是1
//无virtual 等于基础sizeof 相加，但是要考虑字节对齐
//有virtual 等于基础sizeof 相加 再加一个指针的长度，是编译器加上去的虚表，但是要考虑字节对齐，但是虚表不考虑字节对齐，虚表会放在class内存块的最前面
