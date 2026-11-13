// Day0027，this指针，const修饰成员
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NullClass
{

};

class IntClass
{
	int int_member_;
};

class StringClass
{
	int str_member_;
};

class MixedClass
{
	int mixed_int_member_;
	string mixed_str_member_;
};

class SameName
{
	// 定义一个与成员函数形参同名的成员变量
public:
	int age;

	void ThisPtr(int age)
	{
		// 若我实例化了一个对象名称为samename_1,并samename.ThisPtr(0),this->指向的对象就是samename_1中的age成员变量
		this->age = age;
	}

	// 此处若不使用引用就会直接调用拷贝函数新实例化一个非samename_1的对象
	SameName& AddAge(const SameName& samename)
	{
		this->age += samename.age;
		// this是指向samename_1的指针，则*this就是解引用后的samename_1这个对象本身
		return *this;
	}
};

class NullPtr
{
	// 成员变量
public:
	int nullptr_member_;

	// 成员函数
	void PrintMember()
	{
		// 可以在访问成员变量前判断调用对象是否是空指针，若为空指针在访问成员变量前直接return结束函数
		cout << "类NullPtr中的成员函数访问类的成员变量，当调用者是空指针时" << nullptr_member_ << '\n';
	}

	void PrintTest()
	{
		cout << "类NullPtr中的成员函数不访问任何成员变量，仅打印该语句" << '\n';
	}

};

class FixedFunc
{
	// 成员变量
public:
	int fixedfunc_member_;
	// mutable变量，可以在常函数中进行修改
	mutable int mutable_member_;

	// 成员函数
	void PrintFixedFuncMember(int number) const // 常函数在此处书写const
	{
		mutable_member_ = number;
		cout << "传入形参" << number << "后，常函数修改对象中的mutable成员变量值为" << mutable_member_ << '\n';
	}
};

int main()
{
	// ========== 类和对象的一些基础补充知识 ==========
	{
		cout << "类和对象补充知识测试:" << '\n';

		// 空对象所占内存空间大小一般为1字节，要区分不同的空对象，那么空对象必须要有实际占用存储空间
		cout << "空对象所占内存大小为:" << sizeof(NullClass) << "字节" << '\n';
		// 对象所占空间大小与内含数据类型相关
		cout << "内只含int类型的对象所占内存大小为:" << sizeof(IntClass) << "字节" << '\n';
		cout << "内只含string类型的对象所占内存大小为:" << sizeof(StringClass) << "字节" << '\n';
		cout << "内含int和string类型的对象所占内存大小为:" << sizeof(MixedClass) << "字节" << '\n';
		// c++类中成员函数和成员变量是分开存储的，且只有非静态成员变量属于类的对象上
		cout << "测试结束" << '\n' << '\n';
	}

	// ========== this指针 ==========
	{
		cout << "this指针测试" << '\n';

		// 类中的成员函数和成员变量是分开存储的，每一个非静态成员函数只会诞生一份函数实例，故多个同类的对象使用同一份函数实例
		// c++中通过this指针来区分具体调用函数的对象，this指针指向调用成员函数的具体对象
		// 具体地，它可以解决传入参数与成员变量同名的问题
		// 不过它也可以简单地通过改变命名习惯来解决，如类内成员变量带后缀_即可
		SameName samename_1;
		samename_1.ThisPtr(80);
		cout << "samename_1内age的数据为:" << samename_1.age << '\n';

		// this返回调用函数的对象本身
		SameName samename_2;
		samename_2.age = 40;

		cout << "调用samename_1.AddAge(samename_2).AddAge(samename_2).AddAge(samename_2);前，samename_1的年龄为:"
			<< samename_1.age << '\n';
		cout << "调用samename_1.AddAge(samename_2).AddAge(samename_2).AddAge(samename_2);前，samename_2的年龄为:"
			<< samename_2.age << '\n';

		// samename_1.AddAge(samename_2)的返回值仍是samename_1，故可以叠加写.AddAge(samename_2)
		samename_1.AddAge(samename_2).AddAge(samename_2).AddAge(samename_2);

		cout << "调用samename_1.AddAge(samename_2).AddAge(samename_2).AddAge(samename_2);后，samename_1的年龄为:"
			<< samename_1.age << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 类的空指针与this指针 ==========
	{
		cout << "类的空指针内访问成员变量测试:" << '\n';
		// 类中成员函数若访问定义过的成员变量，此成员变量名前默认隐含this->指针
		// 但实例化的对象是空指针时，我调用成员函数访问成员变量时，成员变量前的this指针指向空指针，就相当于访问空指针内的元素
		NullPtr* nullptr_1{ nullptr };
		// 很显然此时调用不访问任何成员变量的成员函数不会有任何问题
		nullptr_1->PrintTest();
		// 但不能进行nullptr_1.PrintMember();

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== const修饰成员 ==========
	{
		cout << "const修饰成员测试:" << '\n';

		// this是通过指针常量(指针指向不可修改)实现的，故在函数后加上const该成员函数不能修改成员变量
		// 若想在常函数中也想修改成员变量，可以在变量前加上mutable
		FixedFunc fixedfunc_1;
		fixedfunc_1.fixedfunc_member_ = 40;
		fixedfunc_1.mutable_member_ = 20;

		cout << "通过常函数修改mutable_member_前，其值为:" << fixedfunc_1.mutable_member_ << '\n';
		fixedfunc_1.PrintFixedFuncMember(80);
		cout << "通过常函数修改mutable_member_后，其值为:" << fixedfunc_1.mutable_member_ << '\n';

		// 在实例化对象前加const可以创建常对象，例如const FixedFunc fixedfunc_2;
		// mutable成员变量在常对象中也可以修改,但常对象只能调用常函数
		// 很显然普通的成员函数存在修改常对象中成员变量的可能，故常对象只能调用常函数

		cout << "测试结束" << '\n' << '\n';
	}
}