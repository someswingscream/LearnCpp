// Day0006,循环结构do-while语句，循环结构for语句，
#include <iostream>
#include <string>
using namespace std;
int main()
{
	// do-while语句：先执行依次语句后，判断是否执行while循环；
	/*语法：
		do
		{
			默认无条件执行的语句;
		}while(表达式）;
	*/
	// do-while打印0~9的数字；
	int num1 = 0;
	cout << "do-while循环测试：" << '\n';
	do
	{
		cout << num1 << '\n';// 无条件执行依次从属do语句内的语句
		++num1;
	} while (num1 < 10);// 执行了一次do语句后进行while内表达式真值的判断，为真则循环执行do语句内的语句；
	cout << "测试结束" << '\n';

	// do-while输出三位数中的水仙数(个十百位上的数字三次幂之和等于这个数本身）
	int num2 = 100;
	int a = 0;// a用于获取三位数的个位数值；
	int b = 0;// b用于获取三位数的十位数值；
	int c = 0;// c用于获取三位数的百位数值；
	cout << '\n' << "do-while筛选三位数内水仙数测试" << '\n' << "水仙数为：";
	do
	{
		a = num2 % 10;
		b = (num2 / 10 % 10);
		c = num2 / 100;
		if (a * a * a + b * b * b + c * c * c == num2)
		{
			cout << num2 << '\n';
		}
		++num2;
	} while (num2 < 1000);
	cout << "测试结束" << '\n';

	// for循环语句：结构清晰，使用广泛
	/*语法：
		for (起始表达式;条件表达式;末尾循环体)
		{
			满足条件表达式后执行的循环语句;
		}
	*/
	// 起始表达式无视条件且只执行一次，然后判断此时条件表达式是否为真值，是则先执行循环语句，然后执行末尾循环体；
	// for （）语句括号内的所有内容可以移到括号外等效，括号内";"分号保留；

		// for循环打印1~9数字
	cout << '\n' << "for循环打印1~9数字测试：" << '\n';
	for (int i1 = 1; i1 < 10; ++i1)
	{
		cout << i1 << '\n';
	}
	cout << "测试结束" << '\n';

	// 上述for循环打印1~9可等效于下述结构：
	int i2 = 1;
	cout << '\n' << "for循环打印1~9等效测试：" << '\n';
	for (;;)// for(;;)是无限循环，等效时务必使用if-break语句退出循环；
	{
		if (i2 >= 10)
		{
			break;
		}
		cout << i2 << '\n';
		++i2;
	}
	cout << "测试结束" << '\n';

	// for循环判断1~99中满足七的倍数、个位为7、十位为七并输出；
	cout << '\n' << "测试for循环筛选七的倍数、个位为七、十位为七：" << '\n';
	for (int i3 = 1;; ++i3)
	{
		if (i3 >= 99)
		{
			cout << "测试结束" << '\n';
			break;
		}
		else if (i3 % 7 == 0)
		{
			cout << "七的倍数有：" << i3 << '\n';
		}
		else if (i3 % 10 == 7)
		{
			cout << "个位为七有：" << i3 << '\n';
		}
		else if (i3 / 10 == 7)
		{
			cout << "十位为七有：" << i3 << '\n';
		}
	}

	// for嵌套循环打印9*9的"*"星号：
	cout << '\n' << "for循环打印9*9的*测试：" << '\n';
	for (int out_count = 1;; ++out_count)//out_count控制行数为9；
	{
		if (out_count >= 10)
		{
			cout << "测试结束" << '\n';
			break;// 行数大于10时跳出循环，打印测试结束；
		}
		else// for（;;)已经是除了if-break语句外默认执行，无需多余的else语句控制执行；
		{
			for (int in_count = 1;; ++in_count)// in_count控制每行"*"星号个数为9；
			{
				if (in_count >= 10)
				{
					cout << '\n';// 将要打印第10个"*"星号时停止，输出一次换行符；
					break;
				}
				else// 此处同理，多余的else；
				{
					cout << "*";
				}
			}
		}
	}

	// for循环打印9*9"*"星号优化
	cout << '\n' << "for循环打印9*9星号优化测试：" << '\n';

	for (int row = 1; row < 10; ++row)//row行标准命名，控制行数为9；
	{
		for (int col = 1; col < 10; ++col)//col为column缩写，列数量标准命名，控制每行打印9个星号；
		{
			cout << "*";
		}
		cout << '\n';
	}

	cout << "测试结束" << '\n';

	system("pause");

	return 0;
}