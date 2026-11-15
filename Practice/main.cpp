// Day0029,友元以及嵌套类加强练习

#include<iostream>
#include<string>

using namespace std;

// ============================================= ↓练习一↓ =============================================
// 本身作为其他类Outer成员变量的类，且类Outer是其他类的友元
class Inner
{
// 类Inner中的友元：
	// 全局友元函数：
	friend void InnerGlobalFriendFunc(const Inner& inner);
	// 另一个包含类Inner的类Outer
	friend class Outer;

public:
	// 无参构造函数
	Inner()
	{
		cout << "调用类Inner内的无参构造函数:" << '\n';
	}
	// 有参构造函数
	Inner(int inner_variable_1)
		:
		inner_private_variable_(inner_variable_1)

	{
		cout << "调用类Inner内的有参构造函数构造private成员变量inner_private_variable_，传入参数为:" 
			<< inner_variable_1 << '\n';
	}

	// 析构函数：
	// 此Inner类作为其他类Outer的成员变量，且以类本身作为成员变量而非传入指针
	// 它在其他类Outer的具体对象消失后自动消失，故可以用默认构造函数

	// 拷贝函数：
	// 也可直接利用默认拷贝函数即可

	// 其他成员函数：无

private:
	int inner_private_variable_{};
};

// 类Inner的全局友元函数
// 想要在类外的全局友元函数中访问该类的对象的成员，很显然可以传值(无法访问到原对象)、传地址、引用、或直接在函数执行语句内实例化一个对象
void InnerGlobalFriendFunc(const Inner& inner)
{
	cout << "调用类Inner的全局友元函数访问类Inner类中的private成员变量inner_private_variable_，其值为:"
		<< inner.inner_private_variable_ << '\n';
}

// 包含其它类Inner的类Outer，且它是其他类Inner的友元
class Outer
{
public:
	// 无参构造函数：
	// 若类Inner中无需有参构造，且类Outer中也无需有参构造，两个类中都可以不写构造函数，使用编译器提供的默认无参构造函数
	
	// ========== 嵌套类有参构造函数的注意事项 ==========
	// 但如同Inner和outer这样被嵌套与嵌套的关系中，仍不推荐也不能将被嵌套方Inner类的有参构造函数移动到Outer的有参构造函数内
	// 即使这看起来好像可以集中完成对象的构造
	// 因为Inner的对象相较于Outer的对象先出生，Inner在出生后还必须经过Outer的构造函数才能变得合法
	// 这样让对象的出生到完整构造还存在窗口期很显然有隐患，甚至直接和构造函数的存在意义(对象出生即合法)相悖
	// 有参构造函数：
	Outer(int inner_variable_1,int outer_private_variable)
		:
		inner_ (inner_variable_1),
		outer_private_variable_(outer_private_variable)
	{
		cout << "调用类Outer内的有参构造函数构造类Inner内的private成员变量inner_private_variable_，传入参数的值为:" << inner_variable_1 << '\n';
		cout << "同时构造类Outer内的private成员变量outer_private_variable_，传入参数的值为:" << outer_private_variable << '\n';
	}

	// 析构函数：
	// 嵌套类和被嵌套类中都无需手动释放的成员，故都无需写析构函数，用编译器提供的默认析构函数

	// 拷贝构造函数：
	// 同理二者都没有需要手动释放的成员，故无需深拷贝函数，用编译器提供的默认浅拷贝函数即可

	// 其他成员函数：
	// ========== 注意事项 ===========
	// 若嵌套类是被嵌套类的友元，且被嵌套类作为嵌套类的成员变量，想要嵌套类中的其他成员函数作为被嵌套类中的友元
	// 此时无需在被嵌套类中为嵌套类中的成员函数做友元声明，因为friend class 声明的授权是"整个类的全体成员函数"，一次声明全部覆盖
	// 很显然此时嵌套类Outer都是直接访问自己类中的元素，故无需向全局函数那样传参，该局部函数能直接访问类中成员变量
	void AccessInnerPrivate()
	{
		cout << "利用类Outer内的局部成员函数访问类Inner内的private成员变量inner_private_variable_，其值为：" << inner_.inner_private_variable_ << '\n';
	}

private:
	// 成员变量
	Inner inner_               {};
	int outer_private_variable_{};
};// ============================================= ↑练习一↑ =============================================


// ============================================= ↓练习二↓ =============================================



// ============================================= ↑练习二↑ =============================================


// ============================================= ↓练习三↓ =============================================



// ============================================= ↑练习三↑ =============================================


int main()
{
	// ========== 练习一：类Inner本身作为其他类Outer的数据成员，Outer访问Inner的private成员 ==========
	{
		cout << "Outer访问Inner内private成员测试" << '\n';

		// 实例化一个类Outer的对象
		Outer outer_1(50,60);
		outer_1.AccessInnerPrivate();

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 练习二：类的指针作为其他类的数据成员，访问的private成员 ==========
	{

	}

	// ========== 练习三：友元单向以及友元不传递的测试 ==========
	{

	}

	return 0;
}