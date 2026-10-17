// Day0015,结构体数组冒泡排序练习
#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name = "未命名";

	int age = 0;
};

struct Teacher
{
	string name = "未命名";

	int age = 0;

	Student students[3];
};

// 为老师结构体填入名称、年龄，为学生结构体填入名称、年龄
void RewriteData(Teacher teachers[], int teachers_len, int students_len)
{
	string name_seed = "abc";

	for (int i = 0; i < teachers_len; i++)
	{
		teachers[i].name = "teacher_";
		teachers[i].name += name_seed[i];

		int t_random = rand() % 30 + 20;
		teachers[i].age = t_random;

		for (int j = 0; j < students_len; ++j)
		{
			teachers[i].students[j].name = "student_";
			teachers[i].students[j].name += name_seed[j];

			int s_random = rand() % 10 + 18;
			teachers[i].students[j].age = s_random;
		}
	}
}

// 打印老师结构体内容
void PrintTeachers(Teacher teachers[], int teachers_len, int students_len)
{
	for (int i = 0; i < teachers_len; ++i)
	{
		cout << "教师姓名：" << teachers[i].name << ' ' << "年龄：" << teachers[i].age << '\n';

		for (int j = 0; j < students_len; ++j)
		{
			cout << "\t" << "学生姓名：" << teachers[i].students[j].name << ',' << "年龄" << teachers[i].students[j].age << ';';
		}

		cout << '\n';
	}
}

// 先将每位老师的所有学生按年龄进行升序冒泡排序，后对按年龄对老师进行升序冒泡排序
void BubbleSort(Teacher teachers[], int teachers_len, int students_len)
{
	// 最外层i控制的循环是为了遍历外层老师结构体
	for (int i = 0; i < teachers_len; ++i)
	{
		for (int j = students_len - 1; j > 0; --j)
		{
			for (int k = 0; k < j; ++k)
			{
				if (teachers[i].students[k].age > teachers[i].students[k + 1].age)
				{
					Student temp = teachers[i].students[k];
					teachers[i].students[k] = teachers[i].students[k + 1];
					teachers[i].students[k + 1] = temp;
				}
			}
		}
	}

	for (int i = teachers_len - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (teachers[j].age > teachers[j + 1].age)
			{
				Teacher temp = teachers[j];
				teachers[j] = teachers[j + 1];
				teachers[j + 1] = temp;
			}
		}
	}
}

int main()
{
	// ========== 结构体数组排序 ==========
	{
		Teacher teachers[3];
		int teachers_len = sizeof(teachers) / sizeof(teachers[0]);
		int students_len = sizeof(teachers[0].students) / sizeof(teachers[0].students[0]);

		RewriteData(teachers, teachers_len, students_len);

		cout << "排序前结构体内容为：" << '\n';
		PrintTeachers(teachers, teachers_len, students_len);

		cout << "排序后结构体内容为：" << '\n';
		BubbleSort(teachers, teachers_len, students_len);
		PrintTeachers(teachers, teachers_len, students_len);
	}

	return 0;
}