// Day0005,程序流程结构_选择结构switch语句，循环结构while语句
#include <iostream>

using namespace std;

int main()
{
// 选择结构switch语句：执行效率可比if语句高，表达式只能是整型、字符型，switch作为多分支不推荐将bool型作为整型使用；
	/*语法：
		switch(表达式)
		{
		case 结果1:
			执行结果1的语句;
			break;
		case 结果2:
			执行结果2的语句;
			break;
		case 结果3:
			执行结果3的语句;
			break;
		default:
			执行不满足所有结果的语句;
			break;
		}
	*/

	// 分段判断输入：10输出Perfect，9输出Good，其余输出Bad；
	int num1 = 0;
	cout << "switch分段判断测试，输入整数：" << '\n';
	cin >> num1;
	switch (num1)
	{
	case 10:// 注意有":" ；
		cout << "测试结束，Perfect" << '\n';
		break;// 不加break则会继续选择符合条件的语句执行；
	case 9:
		cout << "测试结束，Good" << '\n';
		break;
	default:
		cout << "测试结束，Bad" << '\n';
		break;
	}

// 循环结构while语句：当表达式结果为真值时循环执行语句，当表达式结果为假值时停止；
	/*语法：
		while(表达式)
		{
			循环执行的语句;
		}
	*/

	// while循环打印1~9；
	int num2 = 1;
	cout << "while循环测试:" << '\n';
	while (num2 < 10)
	{
		cout << num2 << '\n';
		++num2;// 前置递增相比后置递增理论上不需要保存旧值，性能影响更小？；
	}
	cout << "while循环测试结束" << '\n';

	// while练习：无限次判断输入是否等于已获得的1~100随机数，每次判断后提示过大过小，猜中后退出；
	int rand_num = rand() % 100 + 1;//rand() % 100随机生成一个0~99的整数；
	int tries = 1;
	int guess_num = 0;
	cout << "猜一个1~100的数字" << '\n';

	// 用bool型控制while循环结束；
	bool flag = true;
	while (flag)
	{
		cin >> guess_num;
		if (guess_num == rand_num)
		{
			cout << "第" << tries << "次，你猜对了" << '\n';
			flag = false;// 设置退出条件，也可用break；
			//break;示例，break在简单循环中更方便；
		}
		else if (guess_num > rand_num)
		{
			cout << "猜的数大了，再来一次" << '\n';
		}
		else
		{
			cout << "猜的数小了，再来一次" << '\n';
		}
		++tries;// 每次while循环结束后递增+1，用于记录猜数次数；
	}

	system("pause");

	return 0;
}