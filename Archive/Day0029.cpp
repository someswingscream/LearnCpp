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

	// ===== 类Inner中的成员函数 =====
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

// ===== 类Inner中的成员变量 =====
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
	// ===== 类Outer中的成员函数 =====
public:
	// 无参构造函数：
		// 若类Inner中无需有参构造，且类Outer中也无需有参构造，两个类中都可以不写构造函数，使用编译器提供的默认无参构造函数

	// 有参构造函数：
		// ========== 嵌套类有参构造函数的注意事项 ==========
		// 但如同Inner和outer这样被嵌套与嵌套的关系中，仍不推荐也不能将被嵌套方Inner类的有参构造函数移动到Outer的有参构造函数内
		// 即使这看起来好像可以集中完成对象的构造
		// 因为Inner的对象相较于Outer的对象先出生，Inner在出生后还必须经过Outer的构造函数才能变得合法
		// 这样让对象的出生到完整构造还存在窗口期很显然有隐患，甚至直接和构造函数的存在意义(对象出生即合法)相悖
	Outer(int inner_variable_1, int outer_private_variable)
		:
		inner_(inner_variable_1),
		outer_private_variable_(outer_private_variable)
	{
		cout << "调用类Outer内的有参构造函数构造类Inner内的private成员变量inner_private_variable_，传入参数的值为:"
			<< inner_variable_1 << '\n';
		cout << "同时构造类Outer内的private成员变量outer_private_variable_，传入参数的值为:"
			<< outer_private_variable << '\n';
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
		cout << "利用类Outer内的局部成员函数访问类Inner内的private成员变量inner_private_variable_，其值为："
			<< inner_.inner_private_variable_ << '\n';
	}

	// ===== 类Outer中的成员变量 =====
private:
	Inner inner_{};
	int outer_private_variable_{};
};
// ============================================= ↑练习一↑ =============================================


// ============================================= ↓练习二↓ =============================================
// 类A作为其他类FriendOfClassA的数据成员，且将自己的指针传入其他类FriendOfClassA中作为它的数据成员
class A
{
	// ===== 类A中的友元 =====
		// 友元类:
	friend class FriendOfClassA;

	// ===== 类A中的成员函数 =====
public:
	// 构造函数
		// 默认无参构造函数：

		// 有参构造函数:
	A(int private_variable_of_classA)
		:
		private_variable_of_classA_(private_variable_of_classA)
	{
		cout << "调用类A中的有参构造函数构造类A中private成员变量private_variable_of_classA_，传入参数值为:"
			<< private_variable_of_classA << '\n';
	}

	// 析构函数:此类中没有需手动释放的成员变量，故无需写构造函数，使用编译器提供的默认析构函数

	// 拷贝构造函数:同理没有需手动释放的成员变量，故无需写深拷贝函数，使用编译器提供的默认浅拷贝函数即可

	// 其他成员函数:无

	// ===== 类A中的成员变量 =====
private:
	int private_variable_of_classA_{};
};

class FriendOfClassA
{
	// ===== 类FriendOfClassA中的友元 =====
		// 无

	// ===== 类FriendOfClassA中的成员函数 =====
public:
	// 构造函数
		// 默认无参构造函数:无，使用默认构造函数

		// 有参构造函数:
		// ========== 注意事项 ==========
		// 初始化列表中的参数列表只能存放"值的类型名称"，故new A()作为表达式无法直接放入参数列表
		// 很显然可以将new A（）这个表达式转移到主函数实例化类FriendOfClassA时，但默认不推荐
	FriendOfClassA(int private_of_FriendOfClassA, int private_variable_of_classA)
		:
		private_variable_of_FriendOfClassA_(private_of_FriendOfClassA),
		ptr_to_A_object_(new A(private_variable_of_classA))
	{
		cout << "调用类FriendOfClassA中的有参构造函数构造类FriendOfClassA中的成员变量private_of_FriendOfClassA_，传入参数为:"
			<< private_of_FriendOfClassA << '\n';

		cout << "同时构造FriendOfClassA中的成员变量指向类A的指针ptr_to_A_object_，"
			<< "利用传入参数private_variable_of_classA在new一个类A的对象后作为类A的成员变量private_variable_of_classA_的值" << '\n'
			<< "且将new的返回值作为指针ptr_to_A_object_的值，传入参数的值为:" << private_variable_of_classA << '\n';
	}

	// 析构函数:
		// 成员变量A* ptr_to_A_object_内有需要手动释放的堆区数据，故须写析构函数
	~FriendOfClassA()
	{
		delete ptr_to_A_object_;

		cout << "调用类FrienddOfClassA中的析构函数，清理类FriendOfClassA中的成员变量ptr_to_A_object_指向堆区的类A对象"
			<< "并将成员变量ptr_to_A_object_设为空指针" << '\n';
	}

	// 拷贝构造函数:
		// 因为类FriendOfClassA中存在new的堆区数据，故需手写深拷贝函数
	FriendOfClassA(const FriendOfClassA& friendofclassA)
		:
		private_variable_of_FriendOfClassA_(friendofclassA.private_variable_of_FriendOfClassA_),
		ptr_to_A_object_(new A(*friendofclassA.ptr_to_A_object_))
	{
		cout << "调用类FriendOfClassA中的深拷贝函数，拷贝类FriendOfClassA中的成员变量private_of_FriendOfClassA_和ptr_to_A_object_" << '\n';
	}

	// 其他成员函数:
	void AccessClassAPrivate()
	{
		cout << "调用类FriendOfClassA中的其他成员函数AccessClassAPrivate，访问类A中的private成员" << '\n'
			<< "类A中private成员private_variable_of_classA_值为:" << ptr_to_A_object_->private_variable_of_classA_ << '\n';
	}

	// ===== 类FriendOfClassA中的成员变量 =====
private:
	int private_variable_of_FriendOfClassA_{};
	A* ptr_to_A_object_{};
};
// ============================================= ↑练习二↑ =============================================


// ============================================= ↓练习三↓ =============================================
// 类C,类FriendOfClassC作为类C的友元，测试友元关系的单向性
class C
{
	// ===== 类C中的友元 =====
		// 友元类:
	friend class FriendOfClassC;

	// ===== 类C中的成员函数 =====
public:
	// 构造函数
		// 无参默认构造函数:类C无需写无参构造函数，使用编译器提供的默认无参构造函数

		// 有参构造函数:
	C(int private_variable_of_classC)
		:
		private_variable_of_classC_(private_variable_of_classC)
	{
		cout << "调用类C中的有参构造函数构造类C中的成员函数private_variable_of_classC_，传入参数为:"
			<< private_variable_of_classC << '\n';
	}

	// 析构函数:类C中无需手动释放的成员，故无需析构函数，使用编译器提供的默认析构函数

	// 拷贝函数:类C中无需手动释放的成员，故无需深拷贝函数，使用编译器提供的默认浅拷贝函数

	// 其他成员函数:
		// 类FriendOfClassC是类C的友元，但友元是单向的
		// 类C不是类FriendOfClassC的友元,故类C无法访问类FriendOfClassC中的成员变量
		// 当形参为const FriendOfClassC& friendofclassC时尝试失败
	void AccessPrivateOfFriendOfClassC()
	{
		cout << "类FriendOfClassC访问类C中的private成员测试，很显然无法成功" << '\n';
	}

	// ===== 类C中的成员变量 =====
private:
	int private_variable_of_classC_{};
};

// 类FriendOfClassC，作为类C的友元，用于测试友元关系的单向性
class FriendOfClassC
{
	// ===== 类FriendOfClassC的友元 ======
		// 无

	// ===== 类FriendOfClassC的成员变量 =====
public:
	// 构造函数
		// 默认无参构造函数:类FriendOfClassC无需写无参构造函数，使用编译器提供的默认无参构造函数

		// 有参构造函数:
	FriendOfClassC(int private_variable_of_FriendOfClassC)
		:
		private_variable_of_FriendOfClassC_(private_variable_of_FriendOfClassC)
	{
		cout << "调用类FriendOfClassC中的有参构造函数构造类FriendOfClass中的成员变量private_variable_of_FriendOfClassC_"
			<< '\n' << "传入参数值为:" << private_variable_of_FriendOfClassC << '\n';
	}

	// 析构函数:类C中无需手动释放的成员，故无需析构函数，使用编译器提供的默认析构函数

	// 拷贝函数:类C中无需手动释放的成员，故无需深拷贝函数，使用编译器提供的默认浅拷贝函数

	// 其他成员函数:
	void AccessPrivateOfClassC(const C& c)
	{
		cout << "类FriendOfClassC调用成员函数访问类C中private成员private_variable_of_classC_，其值为:"
			<< c.private_variable_of_classC_ << '\n';
	}

	// ===== 类FriendOfClassC的成员变量 =====
private:
	int private_variable_of_FriendOfClassC_{};
};
// ============================================= ↑练习三↑ =============================================


// ============================================= ↓练习四↓ =============================================
// 类ThirdOfChain
class ThirdOfChain
{
	// ===== 类ThirdOfChain的友元 ======
		// 友元类:
	friend class SecondOfChain;

	// 成员函数
public:
	// 构造函数
		// 默认无参构造函数:类ThirdOfChain无需写无参构造函数，使用编译器提供的默认无参构造函数

		// 有参构造函数:
	ThirdOfChain(int third_private_variable)
		:
		third_private_variable_(third_private_variable)
	{
		cout << "调用类ThirdOfChain中的构造函数构造类ThirdOfChain内成员变量third_private_variable_"
			<< '\n' << "传入参数值为:" << third_private_variable << '\n';
	}

	// 析构函数:类ThirdOfChain中无需手动释放的成员，故无需析构函数，使用编译器提供的默认析构函数

	// 拷贝函数:类ThirdOfChain中无需手动释放的成员，故无需深拷贝函数，使用编译器提供的默认浅拷贝函数

	// 其他成员函数:

	// ===== 类ThirdOfChain的成员变量 =====
private:
	int third_private_variable_{};
};

// 类SecondOfChain，作为ThirdOfChain的友元
class SecondOfChain
{
	// ===== 类SecondOfChain的友元 ======
		// 友元类:
	friend class FirstOfChain;

	// 成员函数
public:
	// 构造函数
		// 默认无参构造函数:类SecondOfChain无需写无参构造函数，使用编译器提供的默认无参构造函数

		// 有参构造函数:
	SecondOfChain(int second_private_variable)
		:
		second_private_variable_(second_private_variable)
	{
		cout << "调用类SecondOfChain中的构造函数构造类SecondOfChain内成员变量second_private_variable_"
			<< '\n' << "传入参数值为:" << second_private_variable << '\n';
	}

	// 析构函数:类SecondOfChain中无需手动释放的成员，故无需析构函数，使用编译器提供的默认析构函数

	// 拷贝函数:类SecondOfChain中无需手动释放的成员，故无需深拷贝函数，使用编译器提供的默认浅拷贝函数

	// 其他成员函数:
	void SecondToThird(const ThirdOfChain& third_of_chain)
	{
		cout << "类SecondOfChain利用成员函数访问类ThirdOfChain中的private成员，其值为:"
			<< third_of_chain.third_private_variable_ << '\n';
	}

	// ===== 类SecondOfChain的成员变量 =====
private:
	int second_private_variable_{};
};

// 类FirstOfChain，作为SecondOfChain的友元
class FirstOfChain
{
	// ===== 类FirstOfChain中的友元 ======
		// 无

	// ===== 类FirstOfChain中的成员变量 =====
public:
	// 构造函数
		// 默认无参构造函数:类FirstOfChain无需写无参构造函数，使用编译器提供的默认无参构造函数

		// 有参构造函数:
	FirstOfChain(int first_private_variable)
		:
		first_private_variable_(first_private_variable)
	{
		cout << "调用类FirstOfChain中的构造函数构造类FirstOfChain内成员变量first_private_variable_"
			<< '\n' << "传入参数值为:" << first_private_variable << '\n';
	}

	// 析构函数:类FirstOfChain中无需手动释放的成员，故无需析构函数，使用编译器提供的默认析构函数

	// 拷贝函数:类FirstOfChain中无需手动释放的成员，故无需深拷贝函数，使用编译器提供的默认浅拷贝函数

	// 其他成员函数:
	void FirstToSecond(const SecondOfChain& second_of_chain)
	{
		cout << "类FirstOfChain利用成员函数访问类SecondOfChain中的private成员，其值为:"
			<< second_of_chain.second_private_variable_ << '\n';
	}

	void FirstToThird(const ThirdOfChain& third_of_chain)
	{
		// 此处尝试访问类ThirdOfChain中的private经尝试显示无法访问
		cout << "类FirstOfChain利用成员函数访问类ThirdOfChain中的private成员，访问失败" << '\n';
	}

	// ===== 类FirstOfChain的成员变量 =====
private:
	int first_private_variable_{};
};
// ============================================= ↑练习四↑ =============================================


int main()
{
	// ========== 练习一：类Inner本身作为其他类Outer的数据成员，Outer访问Inner的private成员 ==========
	{
		cout << "Outer访问Inner内private成员测试:" << '\n';

		// 实例化一个类Outer的对象
		Outer outer_1(50, 60);
		// 调用类Outer中成员函数访问Inner内private成员
		outer_1.AccessInnerPrivate();

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 练习二：类的指针作为其他类的数据成员，访问的private成员 ==========
	{
		cout << "FriendOfClassA访问A内private成员测试:" << '\n';

		// 实例化一个类FriendOfClassA的对象
		FriendOfClassA friendofclassA_1(50, 60);
		// 利用对象friendofclassA来调用类FriendOfClassA的中的成员函数AccessClassAPrivate
		friendofclassA_1.AccessClassAPrivate();

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 练习三：友元单向测试 ==========
	{
		cout << "利用两个类验证友元关系单向性测试:" << '\n';

		// 初始化两个类的对象
		C c_1(91);
		FriendOfClassC friend_of_classC_1(9);
		// 利用两个类的实例化对象分别调用两个类的成员函数访问对方的private成员变量
		c_1.AccessPrivateOfFriendOfClassC();
		friend_of_classC_1.AccessPrivateOfClassC(c_1);

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 练习四:友元不具有传递性测试 ==========
	{
		cout << "利用三个类验证友元关系不传递测试:" << '\n';

		// 分别实例化三个类的对象
		FirstOfChain  first_of_chain(50);
		SecondOfChain second_of_chain(60);
		ThirdOfChain  third_of_chain(70);

		// 调用类中的其他函数验证友元关系的不传递性
		first_of_chain.FirstToSecond(second_of_chain);
		first_of_chain.FirstToThird(third_of_chain);
		second_of_chain.SecondToThird(third_of_chain);

		cout << "测试结束" << '\n' << '\n';
	}
	return 0;
}