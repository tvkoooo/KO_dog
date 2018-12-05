#include "KO_dog_test_setup.h"
#include "stdio.h"
#include <string>
#include <map>



//���͵�ǰ������
class AAA_test;

//ʹ��ǰ����������ָ��ĺ���ʾ�������ֺ���ֻ��ʹ��ָ��
void funaazhengchang(AAA_test* a);
void funbucunzai(AAA_test* a)
{
	//a->launch() ; //�����ǲ����ڵģ����Ҫʹ������ľ��庯����������������������ͣ���������ĺ��� void funaazhengchang(AAA_test* a)��
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
	a->launch() ; //ǰ�������������档
}


class AAA_test_win :public AAA_test
{
public:


public:
	////�ܽ᣺
	//	���������캯����Ĭ�Ϲ��캯�����������ʲô���캯����û�У���������Ĭ������һ��Ĭ�Ϲ��캯���������ʾ����һ�����캯����
	//	����������������һ��Ĭ�Ϲ��캯�����ر���������ֻ������ʽ���������캯�����򲻻���Ĭ���޲�����Ĭ�Ϲ��캯������������ø��๹�캯��ʱ��
	//	����ʹ���޲������캯����Ҫô��ʽ��Ӹ���Ĵ��������캯�������˲�����Ҫô�����һ���޲����Ĺ��캯����
	AAA_test_win(const std::string& zfc)
	//���캯����ʼ����һ��Ҫ����˳���ʼ������
		: AAA_test(zfc)
		, p_int(NULL)
	{
		this->p_int = new int;

	};

	////�ܽ᣺
	//	���������Ƿ���� virtual�����class�������к�����û��virtual��������������virtual
	//	���class�������к������κ�һ��������virtual���������������virtual������ĳЩ������鹹�������ܲ��ᱻ���ã�����ڴ�й©�������߼�����
	virtual ~AAA_test_win() 
	{
		delete this->p_int;
		this->p_int = NULL;
	};
	int * p_int;


	////�ܽ᣺
	//	����֮ǰ��virtual������������ĳ��������麯������Ҫ��һ����ע�����ĸ�������麯�����ɶ��Ը�ǿ��
	//	�����virtual�������Ƽ�����virtual������Ҳ�ǶԵģ����ɶ��Ը�ǿ
	//	����һ������µ��麯����������һ��public�鵱�У��ָ�
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
	//const type &ȡ���� ���磨const std::string& zfc�������Բ���ʹ�� -> �����㣬�Ҳ����пգ����Ҳ������ֵ����������Ƚϴ���á� ��const�� zfc���ܱ��ı䣬����ȫ
	//const type *ȡָ�� ���磨const std::string* zfc������const�� zfc���ܱ��ı䣬����ȫ
	//ֱ��ʹ��type ���磨int/float�ȣ�����������
	//ʹ��type*  ����Ҫ�޸Ĵ�������ݣ�c����ֻ����*
	AAA_test_linux(const std::string& zfc)
		: AAA_test(zfc)
	{

	};
	virtual ~AAA_test_linux() {};

public:
	// AAA_test
	virtual void launch()
	{
		//ʹ���ض�Ŀ�길��ĺ�������ʹ�ú���ǰ���������::  (���� AAA_test::launch();�Ƚϰ�ȫ�������)  ����(this->AAA_test::launch();�ɶ���ǿ ��������ຯ���Ǿ�̬������this-> �ǲ�����ӵ�)
		this->AAA_test::launch();
		printf("AAA_test_linux \n");
	};
};

//�鹤������
//��ؼ����ĸ��ӿڣ�ע�ᣬ��ע�ᣬ����������ࣩ�����٣�����ࣩ�����������鹤��
class factory
{
	//����ǩ��
	typedef AAA_test* (*fun_type_test)(const std::string& zfc);
public:
	//�����Ը�ǿ����һ���Ϳ��Ը�ȫ���ط�
	typedef std::map<std::string, fun_type_test>  map_type_test;//����ʵ����������Ҫʵ��������
	//��Ϊ���������ò�ͬ�ı�־����ʾ��ͬ����Ϊ�飨��������
	map_type_test zhuce_map;
	
	void zhuce(const std::string& zfc, fun_type_test f)
	{
		//����������
		map_type_test::iterator it = this->zhuce_map.find(zfc);
		if (it == zhuce_map.end())
		{
			//û���ҵ�
			zhuce_map.insert(map_type_test::value_type(zfc, f));
		}
		else
		{
			//�ҵ�
			printf("bu neng congfu zhuce. \n");
			//it->first;
			//it->second;
		}
	}

	void jiebang(const std::string& zfc)
	{
		//������ɾ��
		map_type_test::iterator it = this->zhuce_map.find(zfc);
		if (it == zhuce_map.end())
		{
			//û���ҵ�
			printf("guocheng bu cunzhai. \n");
			
		}
		else
		{
			//�ҵ�
			zhuce_map.erase(it);
			//it->first;
			//it->second;
		}
	}

	//��ͨ����ʵ�ֺ��������Σ�ʵ�� �����ͱ�־��
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

		//��������ѯ
		map_type_test::iterator it = this->zhuce_map.find(zfc);
		if (it == zhuce_map.end())
		{
			//û���ҵ�
			printf("chuangjian shibai. \n");
		}
		else
		{
			
			//�ҵ�
			//�ɵ����壨�º�������ʹ�÷��� (it->second) �����üӸ�����
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

//static ���ں���ǩ����ֻ���ڱ�cppʹ�ã����⺯�������ռ��ͻ
//���ʽ����������ͬʵ��
static AAA_test* fun_chuangjian_windouws(const std::string& zfc)
{
	AAA_test* t = new AAA_test_win(zfc);
	return t;
}
//���ʽ��������
static AAA_test* fun_chuangjian_android(const std::string& zfc)
{
	AAA_test* t = new AAA_test_android(zfc);
	return t;
}
//���ʽ��������
static AAA_test* fun_chuangjian_linux(const std::string& zfc)
{
	AAA_test* t = new AAA_test_linux(zfc);
	return t;
}


void KO_dog_test_a()
{
	//ջ�ռ��Ч�ʸߣ��������ʹ��ջ�ռ䣬���Ƽ��ѿռ䣨new ����malloc �����ģ�
	factory f;
	f.zhuce("windows", fun_chuangjian_windouws);
	f.zhuce("android", fun_chuangjian_android);
	f.zhuce("linux", fun_chuangjian_linux);

	// ���һ�������и��ô������Կ��ٸ��ƴ��룬��ֹ�����ռ��ͻ
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

//��class���͵� sizeof ��1
//��virtual ���ڻ���sizeof ��ӣ�����Ҫ�����ֽڶ���
//��virtual ���ڻ���sizeof ��� �ټ�һ��ָ��ĳ��ȣ��Ǳ���������ȥ���������Ҫ�����ֽڶ��룬������������ֽڶ��룬�������class�ڴ�����ǰ��
