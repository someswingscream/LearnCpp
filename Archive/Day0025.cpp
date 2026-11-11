// Day0025,深拷贝与浅拷贝、构造函数初始化列表
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 用于测试函数内实例化对象后return的类
class Person
{
	// 成员变量
public:
	int person_age_;
	// 构造函数
	Person()
	{
		cout << "调用Person内默认构造函数" << '\n';
	}
	// 拷贝函数
	Person(const Person& p)
	{
		cout << "调用Person内拷贝函数，传入参数为:" << &p << '\n';
	}
	// 析构函数
	~Person()
	{
		cout << "调用Person内析构函数" << '\n';
	}
};

// 返回函数内实例化对象的函数
Person ReturnTest()
{
	// 函数内实例化了类后，想要将其作为值return，但函数结束后该对象就会被销毁
	// 故return时编译器会自动调用拷贝函数实例化一个中间者来return
	// 正常模式编译器会进行优化，拷贝消失了
	// 整个程序从头到尾只有一个对象，它直接生在 main 里、死在 main 里。这叫返回值优化（RVO，Return Value Optimization）
	// 既然副本的内容和局部对象一模一样，编译器干脆跳过"造副本"这一步，让局部对象直接以 main 里变量的身份出生。这是 C++ 标准明确允许编译器做的事
	Person p_1;
	cout << "P_1的地址为:" << &p_1 << '\n';
	return p_1;
}

// 用于测试深拷贝以及析构函数的类
class ShallowCopyTest
{
	// 成员变量
public:
	// 用于后续成员函数在new创建变量
	int* test_new_ptr_;
	// 成员函数
		// 有参构造函数
	ShallowCopyTest(int new_ptr)
	{
		test_new_ptr_ = new int(new_ptr);
		cout << "CopyTest内有参构造函数的调用，传入参数为:" << new_ptr << '\n';
	}

	// 析构函数
	~ShallowCopyTest()
	{
		if (test_new_ptr_ != nullptr)
		{
			delete test_new_ptr_;
			test_new_ptr_ = nullptr;
		}
		cout << "调用ShallowCopyTest的析构函数" << '\n';
	}
};

// 用于测试深拷贝构造函数的类
class DeepCopyTest
{
	// 成员变量
public:
	int* deep_new_test_;

	// 有参构造函数
	DeepCopyTest(int deep_new_test)
	{
		deep_new_test_ = new int(deep_new_test);
		cout << "DeepCopyTest类内有参构造函数的调用，传入参数为:" << deep_new_test << '\n';
	}

	// 深拷贝函数，深拷贝的实现原理就是将传入的类中存放在堆区的变量指针解引用后重新创建一个存放在堆区的变量
	// 使得两个类中存放在堆区的同名变量指针指向的堆区内存不是同一块
	DeepCopyTest(const DeepCopyTest& test)
	{
		deep_new_test_ = new int(*test.deep_new_test_);
		cout << "调用CopyTest内拷贝构造函数" << '\n';
	}

	// 析构函数
	~DeepCopyTest()
	{
		if (deep_new_test_ != nullptr)
		{
			delete deep_new_test_;
			deep_new_test_ = nullptr;
		}
		cout << "调用DeepCopyTest的析构函数" << '\n';
	}
};

// 用于测试构造函数初始化列表的类
class ConstructorFunc
{
	// 成员变量
public:
	int example_1_;
	int example_2_;
	int example_3_;

	// 构造函数初始化列表
	ConstructorFunc(int a, int b, int c) :example_1_(a), example_2_(b), example_3_(c)
	{
		cout << "调用ConstructorFunc内的构造函数，传入参数分别为:" << a << ' ' << b << ' ' << c << '\n';
	}
};

int main()
{
	// ========== 函数内实力化对象后return返回该对象 ==========
	{
		cout << "函数内实例化对象后return该对象实验:" << '\n';
		Person p_2 = ReturnTest();
		cout << "p_2的地址为:" << &p_2 << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 浅拷贝崩溃测试 ==========
	{
		cout << "浅拷贝测试:" << '\n';
		// 注意事项：若我们没写拷贝函数，编译器会提供一个值传递拷贝构造函数
		// 当我们提供了有参构造函数后，编译器不提供默认构造函数；我们提供了拷贝函数后编译器就不提供普通构造函数
		// 编译器默认提供的拷贝函数就是简单的=赋值
		ShallowCopyTest s_test_1 = ShallowCopyTest(10);
		// ShallowCopyTest s_test_2 = ShallowCopyTest(test_1);
		// 此时运行会对test_new_ptr_这个指针所指向的堆区进行两次delete，属于重复释放的非法操作

		/*
									操作非法行为具体分析：
		   该类中为写拷贝函数，编译器会使用自提供的浅拷贝构造函数
		   每个实例化对象有自己的一整套成员变量，也就是每个对象中的同名变量是两个独立的变量
		   但浅拷贝会导致这两个同名变量的地址一致，指向同一块堆区内存
		   两个对象被销毁时其中一个test_new_ptr_不是非空指针会对堆区进行释放并变为nullptr
		   但另一个对象中仍存在一个同名但独立的不同test_new_ptr_，析构函数中if判断非空就会对已经释放过的堆区进行重复释放
		*/

		// 很显然解决方法可以是不在使用默认拷贝函数的类中定义堆区变量，或者自定义拷贝构造函数也就是深拷贝
		// 浅拷贝还有一个注意事项就是两个不同对象的成员变量的值是同步的，修改其中一个会影响另一个
		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 深拷贝测试 ==========
	{
		cout << "深拷贝测试:" << '\n';
		// 若类中的成员变量或成员函数会在堆区开辟内存，必须自定义拷贝函数而非使用编译器默认提供的拷贝函数
		DeepCopyTest d_test_1(20);
		DeepCopyTest d_test_2 = DeepCopyTest(d_test_1);

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 自定义构造函数初始化列表测试 ==========
	{
		cout << "自定义构造函数初始化列表测试:" << '\n';

		ConstructorFunc test_1(40, 50, 60);
		cout << "实例化ConstructorFunc为test_1后查询该对象中的成员变量值分别为:"
			<< test_1.example_1_ << ' ' << test_1.example_2_ << ' ' << test_1.example_3_ << '\n';

		cout << "测试结束" << '\n' << '\n';
	}
	return 0;
}