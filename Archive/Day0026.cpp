// Day0026,静态成员
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StaticMember
{
	// 静态成员变量
public:
	static int static_member_variable; // 静态变量的类内声明

	// 非静态成员变量
	int unstatic_variable;

	// 静态成员函数
		// 静态成员函数不能访问非静态成员变量,例如该函数中就不能对unstatic_variable进行访问和修改
		// 即使有调用方，但它无法区分应该访问、修改诸多对象中的哪个对象中的非静态成员变量，而静态成员变量同一类中所有对象共享，故可以安全访问
		// 显而易见，静态成员函数也有访问权限的区分
	static void static_member_func()
	{
		cout << "StaticMember类内静态成员函数static_member_func的调用" << '\n';
	}
};

// static_member_variable的类外初始化定义
int StaticMember::static_member_variable{ 100 };

int main()
{
	// ========== 静态成员变量 ==========
	{
		cout << "静态成员变量测试:" << '\n';

		// 静态成员：在成员变量和成员函数前加上关键字static，这样的成员变量和成员函数被称为静态成员
		// 静态成员变量：所有对象共享同一份数据，在编译阶段分配内存，类内声明、类外初始化
		// 所有对象共享用一份数据，在类中创建了静态变量，则同一类中的所有实例化对象的该静态变量之间的状态是同步的
		StaticMember test_1;
		cout << "零初始化test_1时，其静态成员static_member_variable的值为:" << test_1.static_member_variable << '\n';

		test_1.static_member_variable = 300;
		cout << "在test_1内修改static_member_variable为300后，其值为:" << test_1.static_member_variable << '\n';

		StaticMember test_2;
		cout << "零初始化test_2时，其静态成员static_member_variable的值为:" << test_2.static_member_variable << '\n';

		test_2.static_member_variable = 500;
		cout << "在test_2内修改static_member_variable的值为500，test_2的static_member_variable值为:" << test_2.static_member_variable << '\n'
			<< "此时test_1内static_member_variable的值为:" << test_1.static_member_variable << '\n';

		// 类中的静态变量除了可以通过实例化对象来访问，还可以直接通过类名来进行访问
		// 不过静态变量可以通过更改访问权限为private让类外不能访问
		cout << "通过类名StaticMember直接访问类中的静态变量static_member_variable,其值现在为:" << StaticMember::static_member_variable << '\n';

		// 静态成员函数：所有对象共享同一个函数，静态成员函数只能访问静态成员变量

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 静态成员函数 ==========
	{
		cout << "静态成员函数测试:" << '\n';

		// 静态成员函数：所有对象共享一个函数，静态成员函数只能访问静态成员变量
		// 调用静态成员函数方法：通过对象访问和通过类名访问

		cout << "通过类名访问" << '\n';
		StaticMember::static_member_func;

		cout << "通过类中对象访问" << '\n';
		StaticMember test_3;
		test_3.static_member_func;

		cout << "测试结束" << '\n';
	}
	return 0;
}