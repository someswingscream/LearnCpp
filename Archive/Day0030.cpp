// Day0030,运算符重载
#include <iostream>
#include <string>

using namespace std;

// ============================================= ↓练习一↓ =============================================
// 集中声明
class Addend;
class Augend;
class ResultOfAdd;
ResultOfAdd operator+(Addend& addend, Augend& augend);
void operator<<(ostream& cout, Addend& addend);
ostream& operator<<(ostream& cout_result, ResultOfAdd& result_of_add);

// 类Addend，作为加数内有int和string的成员变量，与类Augen相加
class Addend
{
	// 友元
		// 友元类
	friend class ResultOfAdd;
	// 友元全局函数
	friend ResultOfAdd operator+(Addend& addend, Augend& augend);
	friend void operator<<(ostream& cout, Addend& addend);

	// ===== 类Addend的成员函数 =====
public:
	// 无参构造函数:
	Addend()
	{
		cout << "调用类Addend内的无参构造函数" << '\n';
	}

	// 有参构造函数
	Addend(int addend_int, string addend_str)
		:
		addend_int_(addend_int),
		addend_str_(addend_str)
	{
		cout << "调用类Addend内的有参构造函数，构造类Addend内成员变量:" << '\n'
			<< "addend_int_传入参数值为:" << addend_int << '\n'
			<< "addend_str_传入参数为:" << addend_str << '\n';
	}

	// 析构函数:无

	// 拷贝构造函数:无

	// 赋值运算符:加法运算符重载
	// 对同一类Addend内的具体对象间进行相加，将addend_int_数值相加，addend_str_之间字符串进行拼接
	Addend operator+ (Addend& addend)
	{
		Addend temp_addend;
		temp_addend.addend_int_ = addend.addend_int_ + this->addend_int_;
		temp_addend.addend_str_ = addend.addend_str_ + this->addend_str_;

		cout << "调用类Addend中的加法运算符重载，对类Addend的对象间进行相加" << '\n' << '\n';

		return temp_addend;
	}

	// 对类Addend中成员变量addend_int_和常规整数int之间相加的加法运算符重载
	Addend operator+ (int int_variable)
	{
		Addend temp_addend;
		temp_addend.addend_int_ = this->addend_int_ + int_variable;
		temp_addend.addend_str_ = this->addend_str_;

		cout << "调用类Addend中的加法运算符重载，对类内int和类外int类型数据相加" << '\n' << '\n';

		return temp_addend;
	}

	// 其他成员函数:无

// ===== 类Addend的成员变量 =====
private:
	int addend_int_{};
	string addend_str_{};
};

// 左移运算符重载，实现用于打印类Addend中的成员的全局函数
// 此类无返回值的左移运算符重载函数只能<<一次，因为cout是一种数据类型
// 将返回值类型改为ostream并在函数内return
void operator<<(ostream& cout, Addend& addend)
{
	cout << "调用全局函数打印类Addend中的成员变量:" << '\n';
	cout << "类Addend中的addend_int_值为：" << addend.addend_int_ << '\n';
	cout << "类Addend中的addend_str_值为：" << addend.addend_str_ << '\n' << '\n';
}

// 类Augend，作为被加数内有int和string的成员变量，与类Addend相加
class Augend
{
	// ===== 类Augend中的友元 =====
		// 友元类
	friend class ResultOfAdd;
	// 友元全局函数
	friend ResultOfAdd operator+(Addend& addend, Augend& augend);


	// ===== 类Augend中的成员函数 =====
public:
	// 无参构造函数：
	Augend()
	{
		cout << "调用类Augend中的无参构造函数" << '\n';
	}

	// 有参构造函数
	Augend(int augend_int, string augend_str)
		:
		augend_int_(augend_int),
		augend_str_(augend_str)
	{
		cout << "调用类Augend内的有参构造函数，构造类Augend内成员变量:" << '\n'
			<< "augend_int_传入参数值为:" << augend_int << '\n'
			<< "adugnd_str_传入参数为:" << augend_str << '\n';
	}

	// 析构函数:使用编译器提供的默认析构函数

	// 析构函数:无

	// 拷贝构造函数:无

	// 拷贝运算符:加法拷贝运算符重载
	Augend operator+ (Augend& augend)
	{
		Augend temp_augend;
		temp_augend.augend_int_ = augend.augend_int_ + this->augend_int_;
		temp_augend.augend_str_ = augend.augend_str_ + this->augend_str_;

		cout << "调用类Augend中的加法运算符重载,对类Augend的对象之间进行相加" << '\n' << '\n';

		return temp_augend;
	}

	// 其他成员函数:无

// ===== 类Augend中的成员变量 ======
private:
	int augend_int_{};
	string augend_str_{};
};

// 类ResultOfAdd，作为结果内有int和string的成员变量
class ResultOfAdd
{
	// ===== 类ResultOfAdd中的友元 =====
		// 友元全局函数
	friend ResultOfAdd operator+(Addend& addend, Augend& augend);
	friend ostream& operator<<(ostream& cout_result, ResultOfAdd& result_of_add);


	// ===== 类ResultOfAdd中的成员函数 =====
public:
	// 无参构造函数:
	ResultOfAdd()
	{
		cout << "调用ResultOfAdd中的无参构造函数" << '\n';
	}

	// 有参构造:此测试中暂时无需

	// 析构函数:无

	// 拷贝构造函数:无

	// 赋值运算符:加法运算符重载，将传入的类Addend对象和Augend对象中的成员变量相加结果传入类ResultOfAdd的调用对象
	// 但类中的运算符重载仅支持传入一个参数，故不能以类内的成员函数来实现超过两种类的赋值运算

	// 其他成员函数:无

// ===== 类ResultOfAdd中的成员变量 =====
private:
	int result_int_{};
	string result_str_{};
};

// 加号运算符重载的函数实现必须要求传入参数为2，故三个参数无法实现加号运算符重载
// 用于实现将类Addend的对象和类Augend对象相加后的结果放入类ResultOfAdd对象中的全局函数
ResultOfAdd operator+(Addend& addend, Augend& augend)
{
	ResultOfAdd temp_result_of_add;
	temp_result_of_add.result_int_ = addend.addend_int_ + augend.augend_int_;
	temp_result_of_add.result_str_ = addend.addend_str_ + augend.augend_str_;

	cout << "调用全局函数加号运算符重载，将类Addend对象和Augend对象相加得到类ResultOfAdd对象" << '\n' << '\n';

	return temp_result_of_add;
}

// 左移运算符重载，实现打印类ResultOfAdd中的变量成员的全局函数
ostream& operator<<(ostream& cout_result, ResultOfAdd& result_of_add)
{
	cout << "调用全局函数打印类ResultOfAdd中的成员变量" << '\n';
	cout << "类ResultOfAdd中的result_int_值为:" << result_of_add.result_int_ << '\n';
	cout << "类ResultOfAdd中的result_str_值为:" << result_of_add.result_str_ << '\n';

	return cout_result;
}
// ============================================= ↑练习一↑ =============================================


// ============================================= ↓练习二↓ =============================================
// 集中声明:
class Increment;

// 用于测试前置递增运算符重载和后置递增运算符重载的类
class Increment
{
	// ===== 类Increment中的友元 =====
		// 友元全局函数
	friend ostream& operator<< (ostream& cout_increment, const Increment& increment);

	// ===== 类Increment中的成员函数 =====
public:
	// 无参构造函数:
	Increment()
	{
		cout << "调用类Increment中的无参构造函数" << '\n';
	}

	// 有参构造函数
	Increment(int increment_int)
		:
		increment_int_(increment_int)
	{
		cout << "调用类Increment中的有参构造函数，构造类Increment中的成员变量increment_int_，传入参数值为:"
			<< increment_int << '\n';
	}

	// 析构函数:无

	// 拷贝函数:无

	// 其他成员函数:
	// 前置递增运算符重载函数:
	Increment& operator++()
	{
		++increment_int_;

		cout << "调用类Increment中的成员函数实现前置递增运算符重载，对类Increment中的成员变量increment_int_进行前置递增" << '\n';

		return *this;
	}

	// 后置递增运算符重载函数:
	Increment operator++(int) // 由于函数返回值类型不同不能实现重载，故采用int型参数占位，与前置运算符的参数有不同，实现函数重载
	{
		// 记录后置递增前的调用对象状态
		Increment temp_increment = *this;
		// 对调用对象中需后置递增的对象进行后置递增
		increment_int_++; // 此处写前置或后置效果一致，此处保持逻辑一致的后置递增

		cout << "调用类Increment中的成员函数实现后置递增运算符重载，对类Increment中的成员变量increment_int_进行后置递增" << '\n';

		// 返回递增前的调用对象状态
		return temp_increment;
	}

	// ===== 类Increment中的成员变量 =====
private:
	int increment_int_{};
};

// ===== 注意事项以及知识点补习 =====
// 后置递增运算重载只能以无名的临时值(右值)的形式实现，它无法在同一个指针的语义下实现先传出递增前的状态后追加递增
// 返回值类型为引用的函数调用表达式为左值，其余返回值类型都是临时值(返回值为指针类型的函数表达式解引用则为左值)
// 非const引用仅能接收左值，否则对临时对象进行改动后对象销毁就会导致并未实际生效，这显然是应该禁止的隐患行为
// const和引用可以延长临时对象的寿命，将引用临时对象的声明周期从;分号结束扩到当当前作用域
// 后置递增的函数调用表达式只能是一个临时对象(右值)，需要将左移运算符重载中的传入参数改为const引用才能将该临时的表达式(右值)作为实参传入

// 用于实现左移运算符重载的全局函数:
ostream& operator<< (ostream& cout_increment, const Increment& increment)
{
	cout << "调用全局函数重载左移运算符，打印类Increment中的成员变量:" << '\n';
	cout << "类Increment中成员变量increment_int_的值为:" << increment.increment_int_ << '\n';

	return cout_increment;
}
// ============================================= ↑练习二↑ =============================================


int main()
{
	// ========== 测试一:加法运算符、左移运算符重载 ==========
	{
		cout << "加法运算符重载实现自定义数据类型间进行加法运算,左移运算符重载输出对象中数据测试:" << '\n';

		// 实例化用于测试类Addend对象和类Augend对象间相加后赋值给类ResultOfAdd的对象
		Addend addend_1(121, "我是加数addend_1");
		Augend augend_1(212, "我是被加数augend_1");
		ResultOfAdd result_1 = operator+(addend_1, augend_1); // 此处直接ResultOfAdd result_1 = addend_1 + augend_1; 也可以，它和下式等价
		// 调用左移运算符重载后的全局函数打印ResultOfAdd对象的值验证结果
		cout << result_1 << '\n'; // 此处的左移运算符可以使用链式写法

		// 实例化用于测试类Addend对象间相加的Addend
		Addend addend_2(2, "我是加数addend_2");
		Addend addend_3(3, "我是加数addend_3");
		Addend addend_5 = addend_2.operator+(addend_3);
		// 调用左移运算符重载后的全局函数打印类Addend对象的值验证结果
		cout << addend_5;

		cout << '\n';

		// 实例化用于测试类Addend对象与int相加的Addend
		Addend addend_4(4, "我是加数addend_4");
		Addend addend_104 = addend_4 + 100;
		// 调用左移运算符重载后的全局函数打印类Addend对象的值验证结果
		cout << addend_104; // 下式写法和 operator<<(cout,addend_4) 等价

		cout << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 测试二:前置递增和后置递增重载 ==========
	{
		cout << "前置递增和后置递增重载测试:" << '\n';

		// 实例化用于测试前置递增的对象
		Increment prefix_increment(50);
		cout << "前置递增后，++prefix_increment该表达式中内容为:" << ++prefix_increment << '\n';
		cout << "前置递增后，prefix_increment中内容为:" << prefix_increment << '\n';

		// 实例化用于测试后置递增的对象
		Increment post_increment(60);
		cout << "后置递增后，post_increment该表达式中内容为:" << post_increment++ << '\n';
		cout << "后置递增后，post_increment中内容为:" << post_increment << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	return 0;
}