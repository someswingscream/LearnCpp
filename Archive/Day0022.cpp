// Day0022, 函数重载
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 函数重载实例函数，很显然此时函数都属于全局作用域
void func_1()
{
	cout << "调用函数func_1" << '\n';
}
// 更改参数个数来实现重载
void func_1(int a)
{
	cout << "重载下调用函数func_1(int a)" << '\n';
}
// 更改参数类型来实现重载
void func_1(double d)
{
	cout << "重载下调用函数func_1(double d)" << '\n';
}
// 更改参数顺序来实现重载
void func_1(int a, double d)
{
	cout << "重载下调用函数func_1(int a,double d)" << '\n';
}
// 更改参数顺序来实现重载
void func_1(double d, int a)
{
	cout << "重载下调用函数func_1(double d,int a)" << '\n';
}
// 引用&与const引用&能实现重载，会被视为不同的参数
void func_1(string& c)
{
	cout << "调用函数func_1(int& c)" << '\n';
}
// const引用
void func_1(const string& c)
{
	cout << "重载下调用函数func_1(const int& c)" << '\n';
}

// 重载遇到默认参数
void func_2(int a, int b = 10)
{
	cout << "调用函数func_2(int a,int b)" << '\n';
}
void func_2(int a)
{
	cout << "调用函数func_2(int a)" << '\n';
}

int main()
{
	// ========== 函数重载 ==========
	{
		cout << "函数重载测试:" << '\n';

		// 函数重载可以让函数名相同，提高复用性
		// 函数重载条件：
					// 在同一作用域，函数名相同，但函数内参数的类型不同或参数个数不同或函数顺序不同
					// 注意事项，同名函数下仅返回值不同无法实现重载
		func_1();
		func_1(15);
		func_1(3.1);
		func_1(3, 5.6);
		func_1(5.6, 4);
		string s_1{ "字符串" };
		func_1(s_1);
		const string s_2{ "const字符串" };
		func_1(s_2);
		// 函数重载遇到默认参数，出现二义性报错，例如定义的函数func_2(int a,int b = 10)以及func_2(int a)
		// 此时在主函数内以func_2(10)调用函数，发现两种函数满足调用条件，故存在二义性会报错
		// 以func_2(10,20)调用函数则不存在二义性，会调用func_2(int a,int b)
		func_2(10, 20);

		cout << "测试结束" << '\n' << '\n';
	}



	return 0;
}