// Day0023,类和对象-封装初步
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 用class关键字来设计一个类，类后紧跟类名称
// 此处以园这种数学概念进行举例
class Circle
{
	// 访问权限
	// 公共权限
public:
	// 类的属性，例如圆的半径
	int circle_r_;
private:
	double PI{ 3.14 };
	// 行为
	// 获取圆的周长，通过定义函数来实现
public:
	double CalculateC()
	{
		return 2 * PI * circle_r_;
	}

protected:
	void Test1()
	{
		cout << "protected成员访问测试" << '\n';
	}
};

int main()
{
	// ========== 类和对象-封装定义 ==========
	{
		cout << "封装基础测试:" << '\n';

		// 类和对象的简易理解：c++中将一切事物是为对象，具有相同性质的对象可抽象地称为类，如车属于车类，类拥有属性、行为
		// 类中的属性和行为统一称为成员，属性也可称为成员属性、成员变量，行为可称为成员函数、成员方法
		// c++类和对象中三大特性之一封装：将对象的属性和行为作为一个整体来表现生活中的事物，对属性和行为加以权限控制

		// 实例化：利用定义的圆类来创建一个具体的圆，并给属性赋值
		Circle c_1;
		c_1.circle_r_ = 6;
		cout << "当半径为6，圆的周长为：" << c_1.CalculateC() << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 封装权限 ==========
	{
		cout << "访问权限测试:" << '\n';

		// 权限的三种形式：
		// public    公共权限：类内可以访问，类外不能访问
		// protected 保护权限：类内可以访问，类外不可以访问
		// private   私有权限：类内可以访问，类外不可以访问
		Circle c_2;
		c_2.circle_r_ = 10;

		// 保护权限和私有权限这类权限中的成员（成员变量、成员函数）类外都不可以访问
		// clasee中若不定义成员权限，成员默认权限为private，struct中默认权限为public
		cout << c_2.CalculateC(); // 此时访问类内的PI无法访问，但通过定义中包含PI的函数CalculateC可以访问PI
		// 由private权限的成员变量和public权限的函数组合可以实现只读、只写、可读可写的效果

		cout << "测试结束" << '\n' << '\n';
	}
	return 0;
}