// Day0014,结构体初步、结构体指针、嵌套结构体、现代化range-for
#include <iostream>
#include <string>

using namespace std;

// 定义结构体：struct 结构体名称 {成员列表...};
// 结构体是一种自定义数据类型，
struct Student
{
	// 定义学生姓名
	string name;
	// 定义学生年龄
	int age;
	// 定义学生体重
	int weight;
};

struct Teacher
{
	// 定义教师姓名
	string name;
	// 定义教师id
	int id;
	// 定义归属该教师的学生
	Student student;
};

int main()
{
	// ========== 结构体基础 ==========
	{
		cout << "简单结构体测试：" << '\n';

		// 结构体支持与数组搭配使用，将多个结构体放入一个数组中，可一次创建多个同类型实例结构体
		// 完成自定义结构体后创建一个具体的结构体
		Student student[2];
		// 为实例结构体中成员赋值：
			// 方式一：创建结构体后用 结构体名称.成员名称 可以访问该成员并赋值
		student[0].name = "李华";
		student[0].age = 19;
		student[0].weight = 58;
		cout << "遍历结构体student[0]的名称:" << student[0].name << ' ' << "年龄:" << student[0].age << ' ' << "体重：" << student[0].weight << '\n';

		student[1].name = "李华李";
		student[1].age = 13;
		student[1].weight = 53;
		cout << "遍历结构体student[1]的名称:" << student[1].name << ' ' << "年龄:" << student[1].age << ' ' << "体重：" << student[1].weight << '\n';
		// 方式二：创建时直接按成员顺序赋值 Student student = { 成员1的值,... };
		// 方式三：自定义结构体后顺便创建实例结构体 struct 结构体名称 { 成员列表 }实例结构体名称,不推荐使用;

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 指针访问结构体 ==========
	{
		cout << "利用指针访问结构体内成员测试：" << '\n';

		Student sample = { "李华李华" , 18 ,44 };
		// 初始化指针
		Student* p = &sample;
		// 已绑定实例结构体对象的指针可用 指针名->结构体成员 来访问结构体中成员
		cout << "结构体sample名称为：" << p->name << ' ' << "年龄为：" << p->age << ' ' << "体重为：" << p->weight << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	// ========== 结构体嵌套 ==========
	{
		// 定义嵌套结构体后创建实例嵌套结构体,此处仅嵌套一个演示不嵌套结构体数组
		cout << "嵌套结构体测试：" << '\n';
		// 初始化嵌套结构体，也可逐个访问赋值
		Teacher teacher = { "小明", 4556, {"华李",15,45} };

		cout << "访问嵌套结构体teacher内层student名称为：" << teacher.student.name << '\n';

		cout << "测试结束" << '\n' << '\n';
	}

	// 结构体作为一种数据类型，自然也可作为实参传入函数内，或通过指针在函数内访问

	// ========== 现代化range-for ==========
	{
		cout << "现代range-for遍历数组arr1测试：" << '\n';

		int arr1[] = { 12,35,15,65,54 };
		// 编译器拿到：右边数组的首尾指针，每轮让指针前进一步、解引用、然后赋值给：左边的变量，至尾部停止
		// :的右边必须是真正的数组，而非退化的指针，数组作为参数传入函数时退化为指针仅有首地址，range-for无法获取尾部指针，此处不做展开则不写遍历打印函数
		// v是元素拷贝而非元素本身，对v修改不影响本体
		cout << "数组arr1内容为：";
		for (int v : arr1)
		{
			cout << v << ' ';
		}
		cout << '\n';

		// &引用(非地址取址符，后续待学内容，可实现遍历修改本体
		for (int& v : arr1)
		{
			v *= 2;
		}
		// 用原始for循环遍历被修改后的数组arr1
		cout << "&引用修改v等于原来两倍后,数组arr1为：";
		for (int i = 0; i < 5; ++i)
		{
			cout << arr1[i] << ' ';
		}

		cout << "测试结束" << '\n';
	}

	return 0;
}