// Day0009,一维数组逆序及冒泡排序，变量作用域
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// for循环实现一维数组内元素逆序练习；
	cout << "for循环逆序数组测试：" << '\n';

	int arr1[] = { 90,80,70,60,50,40,30,20,10 };
	// cpp中不推荐同时也不能用arr[-1]访问数组中末尾数据；
	int end_num = sizeof(arr1) / sizeof(arr1[0]) - 1;// 数组长度end_num可用len；
	int tries = end_num;// 右指针tries可用right表示；

	cout << "数组arr1中数据顺序为：" << '\n';
	for (int num1 = 0; num1 <= end_num; ++num1)
	{
		cout << arr1[num1] << '\n';
	}

	// 利用middle_num作为中间交换数来实现逆序；
	for (int start_num = 0; start_num < (end_num / 2); ++start_num)
	{
		int middle_num = 0;// 中间暂存数可用temp表示，且此处无需每次循环时进行归零；
		middle_num = arr1[start_num];
		arr1[start_num] = arr1[tries];
		arr1[tries] = middle_num;
		--tries;
	}

	cout << "数组arr1中数据逆序为：" << '\n';
	for (int num2 = 0; num2 <= end_num; ++num2)
	{
		cout << arr1[num2] << '\n';
	}

	cout << "测试结束" << '\n';

	// while循环优化实现逆序数组数据；
		// 逆序时先初始化左右指针位置，后用中间数复制左指针数据暂存，用右指针数据为左指针数据赋值，用暂存数为右指针赋值完成逆序；
		// 循环条件用while(left<right)比较简易方便；
	cout << '\n' << "while循环优化逆序数组数据测试：" << '\n';

	int arr2[] = { 9,8,7,6,5,4,3,2,1 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);

	cout << "数组arr2中的数据顺序为：" << '\n';
	for (int num3 = 0; num3 < len2; ++num3)
	{
		cout << arr2[num3] << '\n';
	}

	int left1 = 0;// 记录左指针数据；
	int right1 = len2 - 1;// 记录右指针数据；
	int temp2 = 0;// 初始化中间暂存数；
	while (left1 < right1)
	{
		temp2 = arr2[left1];// 暂存数复制左指针数据；
		arr2[left1] = arr2[right1];// 用右指针的数据赋值左指针数据；
		arr2[right1] = temp2;// 右指针获取暂存数中数据完成左右指针数据交换；
		++left1;
		--right1;
	}

	cout << "数组arr2中的数据逆序为：" << '\n';
	for (int num4 = 0; num4 < len2; ++num4)
	{
		cout << arr2[num4] << '\n';
	}

	cout << "测试结束" << '\n';

	// 升序冒泡排序训练：相邻两数交换的冒泡排序每一次完整对比后都会筛选出当前范围最大值，下一次对比次数减一，筛选数范围也减一；
	cout << '\n' << "升序冒泡排序测试：" << '\n';

	int arr3[] = { 1,23,43,65,76,43,8,6,2,77,4,867,9,44,67,8 };
	int len3 = sizeof(arr3) / sizeof(arr3[0]);

	cout << "数组arr3中的数据初始顺序为：" << '\n';
	for (int num4 = 0; num4 < len3; ++num4)
	{
		cout << arr3[num4] << '\n';
	}

	int left3 = 0;
	int temp3 = 0;
	int tries3 = 0;// 记录交换次数；
	for (int right3 = len3 - 1; right3 > left3; --right3)// 右指针控制外层循环
	{
		bool swapped = false;// 用bool数据监视这轮是否进行交换，若某一轮没有进行过相邻两数对换则说明排序已经完成可以提前退出；
		for (int num5 = 0; num5 < right3; ++num5)
		{
			if (arr3[num5] > arr3[num5 + 1])
			{
				temp3 = arr3[num5];
				arr3[num5] = arr3[num5 + 1];
				arr3[num5 + 1] = temp3;

				swapped = true;
				++tries;
			}
		}
		if (!swapped)break;
	}

	cout << "数组arr3中的数据进行升序冒泡排序后顺序为：" << '\n';
	for (int num6 = 0; num6 < len3; ++num6)
	{
		cout << arr3[num6] << '\n';
	}
	cout << "此arr3数组一共进行了" << tries << "次排序。" << '\n';

	cout << "测试结束" << '\n';

	// 用于控制内外层循环的变量用i,j,k···等，现代cpp中声明的变量作用域只在{}内，在for(int 变量名 = 变量值;;){}下该变量名的作用域只在{}内；
	// 多层嵌套时内层优先级较高，外层{}可以访问从属于自己的内层{}内的变量，但内层无法访问自己所从属的外层{}变量；
	// 多层嵌套时有同名变量则同级优先级高，如下内层会遮蔽外层的同名变量：
	cout << '\n' << "同级遮蔽测试：" << '\n';

	int num7 = 1;
	{
		int num7 = 2;
		cout << "内层同名变量为：" << num7 << '\n';// cout调用变量num7时与它同级的num7优先级更高，故调用内层的num7；
	}

	cout << "外层同名变量为：" << num7 << '\n';// 同理此处cout与外层num7同级；

	cout << '\n';

	system("pause");

	return 0;

}