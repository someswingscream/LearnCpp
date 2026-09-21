//Day0011,常见函数样式,函数的声明;
#include<iostream>
#include<string>

using namespace std;

//简单值传递验证形参改变不影响实参;
	// void swap(int num1 = 10, int num2 = 20,int temp)
	// 错误示例:形参必须从左到右连续设置,某个参数有默认值其后所有参数都必须有默认值;
	// 调用时形参和实参个数需匹配;
void swap(int num1, int num2)
{
	cout << "交换前形参num1为:" << num1 << '\n';
	cout << "交换前形参num2为:" << num2 << '\n';

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后形参num1为:" << num1 << '\n';
	cout << "交换后形参num2为:" << num2 << '\n';

	return;// 无需返回值时可用"return;"结尾,或直接不写"return;";

}

// 常见函数参返形式:
	// 无参无返:
void func01()
{
	cout << "调用无参无返函数func01" << '\n';
}
// 有参无返:
void func02(int a)
{
	cout << "调用有参无返函数func0" << a << ':' << '\n';
	cout << "传入参数为:" << a << '\n';
}
// 无参有返:
int func03()
{
	cout << "调用无参有返函数func03:" << '\n';

	return 03;
}
// 有参有返:
int func04(int a)
{
	cout << "调用有参有返函数func04" << '\n';
	cout << "传入参数为:" << a << '\n';

	return 04;
}

// 定义前声明函数func05:
void func05();// 函数声明结束后需";";

int main()
{
	// 调用函数传入实参;
	cout << "调用swap函数测试值传递:" << '\n';

	int a = 30;
	int b = 40;

	swap(a, b);

	cout << "调用swap函数后实参a为:" << a << '\n';
	cout << "调用swap函数后实参b为:" << b << '\n';
	cout << "测试结束" << '\n';

	// 常见函数参返测试;
	cout << '\n' << "常见函数参返测试:" << '\n';

	// 调用无参无返函数func01:
	func01();
	// 调用有参无返函数func02:
	func02(2);
	// 调用无参有返函数func03:
	int num1 = func03();
	cout << "返回值为:" << num1 << '\n';
	// 调用有参有返函数func04;
	int num2 = func04(4);
	cout << "返回值为:" << num2 << '\n';

	cout << "测试结束" << '\n';

	// 声明与定义的区别:定义创造实体并分配内存仅能定义一次,声明告诉编译器该实体存在,是什么样,不分配内存且可多次声明;
	cout << '\n' << "函数使用声明实现在调用函数后定义函数测试:" << '\n';

	func05();// 调用函数func05;
	cout << "测试结束" << '\n';


	cout << '\n';

	system("pause");

	return 0;

}

// 声明后可在调用后定义函数;
void func05()
{
	cout << "成功调用函数func05" << '\n';
}