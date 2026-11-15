// Day0028,友元
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================= ↓测试一↓ =============================
// 用于测试全局函数做友元的类
class GlobalFuncFriend
{
	// 全局函数做友元的声明
	friend void TestGlobalFunc(GlobalFuncFriend* globalfunc_friend);

	// 成员变量
protected:
	int globalfunc_protected_variable_;

private:
	int globalfunc_private_variable_;

public:
	int globalfunc_public_variable_;

	// 构造函数
	GlobalFuncFriend()
	{
		globalfunc_public_variable_ = 70;
		globalfunc_private_variable_ = 80;
		globalfunc_protected_variable_ = 90;
	}
};
// 用于测试全局函数做友元的函数
void TestGlobalFunc(GlobalFuncFriend* globalfunc_friend)
{
	cout << "尝试访问全局函数做友元类的public成员变量，其内容为:" << globalfunc_friend->globalfunc_public_variable_ << '\n';
	cout << "尝试访问全局函数做友元类的private成员变量，其内容为:" << globalfunc_friend->globalfunc_private_variable_ << '\n';
	cout << "尝试访问全局函数做友元类的protected成员变量，其内容为:" << globalfunc_friend->globalfunc_protected_variable_ << '\n';
}
// ============================= ↑测试一↑ =============================


// ============================= ↓测试二↓ =============================
// 用于本身作为其他类成员变量的类
class SelfAsOtherClassVariable
{
	// 友元类声明
	friend class IncludeOtherClass;

	// 成员变量
public:
	int selfasotherclassvariable_public_;
protected:
	int selfasotherclassvariable_protected_;
private:
	int selfasotherclassvariable_private_;

	// 构造函数
public:
	SelfAsOtherClassVariable()
		:
		selfasotherclassvariable_public_(2),
		selfasotherclassvariable_protected_(3),
		selfasotherclassvariable_private_(4)
	{
	}
};
// 用于包含SelfAsOtherClassVariable类作为成员变量的类
class IncludeOtherClass
{
	// 成员变量
public:
	SelfAsOtherClassVariable selfasotherclassvariable_;

	// 此类中只有一个其他类作为成员变量，且该其他类它自己的构造函数无需传参，故无需写构造函数，用编译器自提供的默认构造函数即可
	// 若这个唯一的成员变量(其他类)的构造函数有参数但参数具有默认值，很显然无需传参，故也不用提供构造函数
	// 若这个唯一的成员变量(其他类)的构造函数需要传入参数，很明显需要提供构造函数，定义参数并传入

	// 成员函数
	void AccessFriendVariable()
	{
		cout << "访问作为成员变量的类中的public成员变量，其值为:"
			<< selfasotherclassvariable_.selfasotherclassvariable_public_ << '\n';

		cout << "访问作为成员变量的类中的protected成员变量，其值为:"
			<< selfasotherclassvariable_.selfasotherclassvariable_protected_ << '\n';

		cout << "访问作为成员变量的类中的private成员变量，其值为:"
			<< selfasotherclassvariable_.selfasotherclassvariable_private_ << '\n';
	}
};
// ============================= ↑测试二↑ =============================


// ============================= ↓测试三↓ =============================
// 用于测试被其友元类访问的类(类的指针作为其友元类的成员变量)
class AccessedByFriend
{
	// 友元类
	friend class ClassPlayFriend;

	// 成员变量
public:
	int accessedbyfriend_public_variable_;
protected:
	int accessedbyfriend_protected_variable_;
private:
	int acceddedbyfriend_private_variable_;

	// 构造函数
	AccessedByFriend()
		:
		accessedbyfriend_public_variable_(1),
		accessedbyfriend_protected_variable_(2),
		acceddedbyfriend_private_variable_(3)
	{
	}
};
// 用于测试类做友元的类
class ClassPlayFriend
{
	// 成员变量
public:
	AccessedByFriend* accessedbyfriend;

	// 构造函数
public:
	ClassPlayFriend()
		:
		accessedbyfriend(new AccessedByFriend)
	{
	}

	// 深拷贝函数
	ClassPlayFriend(const ClassPlayFriend& classplayfriend)
	{
		accessedbyfriend = new AccessedByFriend(*classplayfriend.accessedbyfriend);
	}

	// 析构函数
	~ClassPlayFriend()
	{
		if (accessedbyfriend != nullptr)
		{
			delete accessedbyfriend;
			accessedbyfriend = nullptr;
		}
	}

	// 成员函数
public:
	void AccessOtherClass(AccessedByFriend* accessedbyfriend)
	{
		cout << "做AccessedByFriend友元的ClassPlayFriend利用函数访问其public成员变量，其值为:"
			<< accessedbyfriend->accessedbyfriend_public_variable_ << '\n';

		cout << "做AccessedByFriend友元的ClassPlayFriend利用函数访问其protected成员变量，其值为:"
			<< accessedbyfriend->accessedbyfriend_protected_variable_ << '\n';

		cout << "做AccessedByFriend友元的ClassPlayFriend利用函数访问其private成员变量，其值为:"
			<< accessedbyfriend->acceddedbyfriend_private_variable_ << '\n';
	}
};
// ============================= ↑测试三↑ =============================


// ============================= 主函数 =============================
int main()
{
	// ========== 测试一:友元基础知识及全局函数作为友元 ==========
	{
		cout << "全局函数做友元访问类中的private、protected成员变量测试：" << '\n';

		// 实例化一个全局函数做友元的类
		GlobalFuncFriend globalfunc_friend_1;
		// 调用函数
		TestGlobalFunc(&globalfunc_friend_1);

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 测试二:类做友元(类本身作为其他类的成员变量) ==========
	{
		cout << "类本身做其友元类的成员，其友元类访问该类中private、protected成员变量测试(本身作为成员版):" << '\n';
		IncludeOtherClass includeotherclass_1;
		includeotherclass_1.AccessFriendVariable();


		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 测试三:类做友元(类的指针作为其他类的成员变量) ==========
	{
		cout << "类做友元访问其他类中的private、protected成员变量测试(本身的指针作为成员版):" << '\n';

		// 实例化一个做AccessedByFriend友元的类的对象
		ClassPlayFriend classplayfriend_1;
		// 调用成员函数
		classplayfriend_1.AccessOtherClass(classplayfriend_1.accessedbyfriend);

		cout << "测试结束" << '\n' << '\n';
	}
	return 0;
}