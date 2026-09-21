// Day0010，二维数组定义及多人总成绩打印练习,函数声明;
#include <iostream>
#include <string>

using namespace std;

// 函数声明:函数五要素(返回值类型,函数名,参数列表,函数体语句,return语句);
	// 例如创建一个实现两个整数求和并输出结果的函数;
int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}
// 创建一个交换cin输入两数的函数;
void inputswap()// 无需传参时用void命名函数;
{
	int cin_num1 = 0;
	int cin_num2 = 0;

	cout << "请输入两个整数:" << '\n';
	cin >> cin_num1 >> cin_num2;

	cout << "交换前:" << '\n';
	cout << "cin_num1为:" << cin_num1 << '\n';
	cout << "cin_num2为:" << cin_num2 << '\n';

	int temp = cin_num1;
	cin_num1 = cin_num2;
	cin_num2 = temp;

	cout << "交换后:" << '\n';
	cout << "cin_num1为:" << cin_num1 << '\n';
	cout << "cin_num12为:" << cin_num2 << '\n';

}

int main()
{
	// 二维数组定义:
		// 定义方式一：数据类型 二维数组名称[行数][列数] = {{数据1,数据2,数据3},{数据4,数据5,数据6}};
	cout << "二维数组打印测试:" << '\n';

	int arr1[2][3] = { { 1,2,3}, {4,5,6} };// 这样定义二维数组更加直观,首选;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr1[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "测试结束" << '\n';

	// 定义方式二:数据类型 二维数组名称[行数][列数] = {数据1,数据2,数据3,数据4,数据5,数据6};
	// 定义方式三:数据类型 二维数组名称[行数][列数];
	// 定义方式四:数据类型 二维数组名称[][列数] = {数据1,数据2,数据3,数据4,数据5,数据6};
	// 方式四中已知列数以及数据集后能自动得到行数;

// 用二维数组名称查询数组所占用内存空间大小以及首地址;
	cout << '\n' << "查询二维数组内存大小以及首地址测试:" << '\n';
	// 获取数组所占内存大小;
	int arr2[][3] = { {10,20,30},{40,50,60} };
	cout << "二维数组arr2所占内存大小为:" << sizeof(arr2) << '\n';
	cout << "二维数组arr2第一行所占内存大小为:" << sizeof(arr2[0]) << '\n';
	// 计算行数以及列数;
	cout << "二维数组arr2行数为:" << sizeof(arr2) / sizeof(arr2[0]) << '\n';
	cout << "二维数组arr2列数为:" << sizeof(arr2[0]) / sizeof(arr2[0][0]) << '\n';

	cout << '\n';
	// 获取数组首地址;
	cout << "二维数组arr2的首地址为:" << (int)arr2 << '\n';// 尽量不用(int)将64位的地址信息转换为32位的整数型;
	cout << "二维数组arr2首位数据的首地址为:" << (int)(&arr2[0][0]) << '\n';
	cout << "二维数组arr2第二行数据的首地址为:" << (int)(arr2[1]) << '\n';

	cout << "测试结束" << '\n';

	// 二维数组记录三人三科成绩数据并计算总成绩;
	cout << '\n' << "三人成绩统计总成绩测试:" << '\n';

	int scores[3][3] =
	{
		{70,80,90},
		{44,85,85},
		{91,39,56}
	};

	for (int i = 0; i < 3; ++i)
	{
		int sum = 0;// 用于计算单人总成绩;
		for (int j = 0; j < 3; ++j)
		{
			sum += scores[i][j];
		}
		cout << "第" << i + 1 << "人的总成绩为:" << sum << '\n';
	}

	cout << "测试结束" << '\n';

	// 在主函数内调用add函数,定义函数时参数列表中的参数无实际数据,称为形式参数,简称形参;
	cout << '\n' << "主函数内调用add函数测试:" << '\n';

	int a = 50;
	int b = 60;
	cout << "参与求和的两个数分别为:" << a << ' ' << b << '\n';

	// 调用add函数,主函数内调用函数时视情况需传入参数,此时在函数名后传入的参数称为实际参数,简称实参;
	int c = add(a, b);
	cout << "两数之和为:" << c << '\n';

	cout << "测试结束" << '\n';

	// 调用swap函数;
	cout << '\n' << "调用swap函数对换cin输入测试:" << '\n';
	inputswap();// 调用函数;

	cout << "测试结束" << '\n';


	cout << '\n';

	system("pause");

	return 0;
}