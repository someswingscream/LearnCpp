//day0001，注释、变量、常量
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
//标识符（变量、常量）：不能用关键字，由字母、数字、下划线构成，且不已数字开头；
//标识符区分大小写；

	int a = 10;

	cout << "a = " << a << endl;

/*常量：不可更改的数据，有宏常量、const修饰的变量；

宏常量：由#define创建，一般位于文件上方；
	语法：#define 常量名 常量值
	
const修饰变量：不可在事后修饰已定义的变量，需在创建时就声明；
	语法：const 数据类型 变量名 = 变量值;
*/

//整型数据类型：短整型 short；整型 int；长整型 long；长长整型 long long；
//短整型的取值范围：-32768~32767 不常用；

//sizeof作为运算符，可用于查看数据类型或变量占用的内存大小；
	//语法：sizeof(数据类型或变量) 
	// sizeof（变量名）是直接获取该变量所属数据类型所占内存大小，而非变量所储存数值大小；
	short num1 = 1;

	cout << "short所占用的内存空间大小为：" << sizeof(num1) << endl;

	system("pause");

	return 0;
}