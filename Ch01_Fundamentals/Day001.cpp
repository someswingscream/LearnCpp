//我是单行注释
# include <iostream>
using namespace std;
/*
我
是
多
行
注
释
*/
int main()
{
	//创建变量：数据类型 变量名 = 变量值;
	//变量不使用关键字；

	int a = 10;

	//常量：不可更改的数据，有宏常量、const修饰的变量；
	/*
	宏常量：由#define创建，一般位于文件上方；
	语法：#define 常量名 常量值

	const修饰变量：不可在事后修饰已定义的变量，需在创建时就声明；
	语法：const 数据类型 变量名 = 变量值;
	*/

	cout << "a = " << a << endl;

	system("pause");

	return 0;
}