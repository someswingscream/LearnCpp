// Day0031,运算符重载复现
#include <iostream>
#include <string>

using namespace std;

// ============================================= ↓练习一↓ =============================================
// 集中声明:
class OperatorOverload;
ostream& operator<< (ostream& cout_overload, const OperatorOverload& overload);

class OperatorOverload
{
// ===== 类OperatorOverload中的友元 =====
	// 友元全局函数:
	friend ostream& operator<< (ostream& cout_overload, const OperatorOverload& overload);

// ===== 类OperatorOverload中的成员函数 =====
public:
	// 无参构造函数:
	OperatorOverload()
	{
		cout << "调用类OperatorOverload中的无参构造函数" << '\n';
	}

	// 有参构造函数:
	OperatorOverload(int overload_int,string overload_object_name)
		:
		overload_int_(overload_int),
		overload_object_name_(overload_object_name)
	{
		cout << "调用类OperatorOverload中的有参构造函数，构造类OperatroOverload中的成员变量" << '\n';
		cout << "调用对象" << overload_object_name << "其整型值为:" << overload_int_ << '\n';
	}

	// 析构函数:无

	// 拷贝函数:无

	// 运算符重载:
	// 加法运算符重载:实现同类对象之间相加
	
	// ===== 注意事项(第一次练习没意识到的) =====
	// 加法运算符重载的实际应用场景为 对象3 = 对象1 + 对象2; 实际执行语句是 对象3 = 对象1.operator+(对象2);
	// 实际执行语句中对象1调用重载函数的表达式应该是一个右值，故此处加法运算符重载函数的返回值类型要用类OperatorOverload
	OperatorOverload operator+(OperatorOverload operator_overload)
	{
		cout << "调用类OperatorOverload中的加法运算符重载函数，实现类间对象相加" << '\n';

		OperatorOverload temp_overload;
		temp_overload.overload_int_ = this->overload_int_ + operator_overload.overload_int_;

		return temp_overload;
	}

	// 加法运算符重载:实现类OperatorOverload对象中的成员变量与整型int数据相加
	OperatorOverload operator+(int augend_int)
	{
		cout << "调用类OperatorOverload中的加法运算符重载，实现类对象中的成员变量与整型int数据相加" << '\n';

		OperatorOverload temp_overload;
		temp_overload.overload_int_ = this->overload_int_ + augend_int;

		return temp_overload;
	}

	// 前置递增运算符重载:实现类OperatorOverload对象对成员变量进行前置递增
	OperatorOverload& operator++()
	{
		cout << "调用类OperatorOverload中的前置递增运算符重载" << '\n';

		++overload_int_;

		return *this;
	}

	// 后置递增运算符重载:实现类OperatorOverload对象对成员变量进行后置递增
	OperatorOverload operator++(int)
	{
		cout << "调用类OperatorOverload中的后置递增运算符重载" << '\n';
		// 拷贝调用函数的对象的状态，用于return递增前的对象状态
		OperatorOverload temp_overload = *this;
		// 此处是对调用该函数对象中的成员变量进行后置递增
		this->overload_int_++;
		// 此处返回记录了递增对象中成员变量前的拷贝对象
		return temp_overload;
	}

// ===== 类OperatorOverload中的成员变量 =====
private:
	int overload_int_{};
	string overload_object_name_{};
};

// 通过左移运算符重载，实现打印类OperatorOverload中成员变量的全局函数
ostream& operator<< (ostream& cout_overload, const OperatorOverload& overload)
{
	cout << "调用左移运算符重载的全局函数打印类OperatorOverload对象中的成员变量" << '\n';
	cout << "调用对象" << overload.overload_object_name_ << "的成员变量overload的值为:" << overload.overload_int_ << '\n';

	return cout_overload;
}
// ============================================= ↑练习一↑ =============================================


int main()
{
	// ========== 测试一:加法、前后置递增、左移运算符重载复现==========
	{
		cout << "加法、前后置递增、左移运算符重载测试:" << '\n';

		// 实例化三个对象用于测试类间对象相加
		OperatorOverload overload_1(1,"overload_1");
		OperatorOverload overload_2(2,"overload_2");
		OperatorOverload overload_3(0,"overload_3");

		overload_3 = overload_1 + overload_2;

		cout << "打印overload_3中的成员变量数据:" << '\n';
		cout << overload_3 << '\n';

		// 实例化两个对象用于测试类对象和整型int数据相加
		OperatorOverload overload_4(4, "overload_4");
		OperatorOverload overload_104(0, "overload_104");

		overload_104 = overload_4 + 100;
		cout << "调用加法运算符重载后打印overload_104成员变量数据" << '\n' << overload_104 << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	return 0;
}