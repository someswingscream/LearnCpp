// Day0012,函数分文件写法,
#include <iostream>
#include "SortTest.h"

using namespace std;

int main()
{
	// 函数分文件写法步骤:
	// 创建.h后缀的头文件,创建与头文件同名的实现文件(后缀为.cpp),在主函数main进行调用;
	// 函数分文件写法中一组头文件和实现文件经常包含同类型功能函数的声明及定义,按功能分类比每个函数一组头文件实现文件更利于管理;
		// 分文件写法初次尝试;
	cout << "调用分文件写法冒泡排序函数测试:" << '\n';

	// 获取键盘输入;
	cout << "请输入待升序排序的整数个数:" << '\n';
	int n = 0;
	cin >> n;

	// 输出获取的整数;
	cout << "排序前数据的顺序为:";
	for (int i = 0; i < n; ++i)
	{
		cin >> arr1[i];
		cout << arr1[i] << ' ';
	}

	// 调用分文件写法的冒泡排序函数;
	void bubbleSort(arr1[], n);
	cout << "测试结束";



	system("pause");

	return 0;
}