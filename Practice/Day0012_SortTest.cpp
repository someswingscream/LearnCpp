#include "SortTest.h"// 包含自己的头文件;
#include <iostream>// 包含本文件所需;

using namespace std;// 待改进;

// 函数实现,需写出函数体;

// 冒泡排序分文件写法测试:
	// 函数体功能:cin获取指定数量整数输入并输出升序冒泡排序;
void bubbleSort(int arr1[], int n)
{
	for (int right = n - 1; right > 0; --right)
	{
		// 用于检测这轮是否发生对换,如整轮未发生对换则提前结束循环;
		bool flag = false;

		// 冒泡排序主体;
		for (int left = 0; left < right; ++left)
		{
			if (arr1[left] > arr1[left + 1])
			{
				int temp = arr1[left];
				arr1[left] = arr1[left + 1];
				arr1[left + 1] = temp;
				flag = true;
			}
		}

		// 用于提前结束循环
		if (!flag)
		{
			break;
		}
	}
	// 打印冒泡排序后的数据;
	cout << '\n' << "排序后数据升序为:";
	for (int i = 0; i < n; ++i)
	{
		cout << arr1[i] << ' ';
	}
}