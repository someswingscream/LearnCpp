//Day0007,for嵌套循环练习，goto语句
#include <iostream>
using namespace std;
int main()
{
	// for嵌套循环训练，打印九九乘法表
		// 初试，for循环打印99乘法表测试：右上角式；
	cout << "for循环打印九九乘法表测试：" << '\n';
	int answer = 0;// 无需命名answer来接受乘积，直接打印row_1*col_1；
	int col_1 = 0;

	for (int row_1 = 1; row_1 <= 9; ++row_1)// row控制行数；
	{
		col_1 = row_1;// 令列数等于行数，避免每行从1*row开始打印；
		for (; col_1 <= 9; ++col_1)// for标准结构拆分，可读性差；
		{
			answer = row_1 * col_1;
			cout << row_1 << '*' << col_1 << '=' << answer << '\t';
		}

		cout << '\n';
	}

	cout << "测试结束" << '\n';

	// 九九乘法表优化，右上角式；
	cout << '\n' << "九九乘法表优化测试：" << '\n';

	for (int i = 1; i <= 9; ++i)// i控制行数；
	{
		for (int j = i; j <= 9; ++j)// 令列数等于行数，避免每行从j=1的情况开始打印；
		{
			cout << i << '*' << j << '=' << i * j << '\t';
		}
		cout << '\n';
	}

	cout << "测试结束" << '\n';

	// 九九乘法表右下角式
	cout << '\n' << "九九乘法表(右下角式)测试：" << '\n';

	for (int row_2 = 1; row_2 <= 9; ++row_2)
	{
		for (int col_2 = 1; col_2 <= row_2; ++col_2)// 用行数来限制列数，避免每行都出现col_2 = 0的情况；
		{
			cout << row_2 << '*' << col_2 << '=' << row_2 * col_2 << '\t';
		}
		cout << '\n';
	}

	cout << "测试结束" << '\n';

	// continue语句，用于跳过循环语句下的同级后续语句，break则是直接跳过该循环；
		// 利用continue输出1~100之间的偶数；
	cout << '\n' << "for-continue筛选1~100偶数测试：" << '\n' << "偶数有：" << '\n';

	for (int num1 = 1; num1 <= 100; ++num1)
	{
		if (num1 % 2 == 1)
		{
			continue;
		}
		cout << num1 << '\n';
	}

	cout << "测试结束" << '\n';

	// goto语句：设计标记，执行到goto语句时直接跳转到标记处开始执行；
	// 不可避免地降低代码可读性，无特殊情况不推荐使用；

		// goto实现循环
	cout << '\n' << "goto实现循环测试：" << '\n';

	int num2 = 1;
FLAG:// 标记无需像变量一样事先声明；
	if (num2 <= 100)
	{
		cout << num2 << '\n';
		++num2;
		goto FLAG;
	}

	cout << "测试结束" << '\n';


	system("pause");

	return 0;
}