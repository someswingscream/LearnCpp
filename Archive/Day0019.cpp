// Day0019,通讯录练习二次优化
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ========== 创建结构体 ==========
// 创建联系人结构体，用于存储联系人的姓名、性别、年龄、电话号码、地址
struct Contact
{
	string contact_name{};
	string contact_sex{};
	int	   contact_age{};
	string contact_phone{};
	string contact_address{};
};

// 创建通讯录结构体，用于存储多个联系人
struct AddressBook
{
	vector<Contact> contacts{};
};

// 创建存储用户输入数据结构体，用于当作用户输入数据中转站，方便输入防御性检查，将明确使用cin、cout的函数隔离出来
// 此练习中对于各字符串不做更细分的检查，仅作输入是否为空检查，故用cin_str代表联系人结构体中的字符串类型
struct UserCin
{
	int    cin_select{};
	int    cin_age{};
	string cin_str{};
};

// ========== 函数集中声明区 ==========
// 集中声明函数及注释职能和接口，方便阅读


// ========== 定义函数区 ==========
int CheckSelect(UserCin* user_cin);
int CheckAge(UserCin* user_cin);
string CheckStr(UserCin* user_cin);
int FindByName(UserCin* user_cin, AddressBook* address_book);
void PrintContact(AddressBook* address_book, int contact_idx);
void ShowContacts(AddressBook* address_book);
void FindContact(UserCin* user_cin, AddressBook* address_book);
Contact UpdateContact(UserCin* user_cin);
void AddContact(UserCin* user_cin, AddressBook* address_book);
void EditContact(UserCin* user_cin, AddressBook* address_book);
void DeleteContact(AddressBook* address_book, UserCin* user_cin);
void ShowMenu();
void LaunchAddressBook(AddressBook* address_book, UserCin* user_cin);
// 循环检查用户输入的选择是否合法，合法则结束循环返回整型选择
int CheckSelect(UserCin* user_cin)
{
	user_cin->cin_select = 0;

	while (true)
	{
		cout << "请输入选项：" << '\n';
		cin >> user_cin->cin_select;

		if (user_cin->cin_select < 0 || user_cin->cin_select >6) // 此练习仅作输入数字检查，不做输入字符串检查
		{
			user_cin->cin_select = 0;
			cout << "输入有误，请重新输入" << '\n';
		}
		else
		{
			return user_cin->cin_select;
		}
	}
}

// 循环检查用户输入的年龄是否合法，合法则结束循环返回整型年龄
int CheckAge(UserCin* user_cin)
{
	user_cin->cin_age = 0;

	while (true)
	{
		cout << "请输入年龄：" << '\n';
		cin >> user_cin->cin_age;

		if (user_cin->cin_age < 0 || user_cin->cin_age >200) // 暂且认为0岁下200岁上是非法年龄输入
		{
			user_cin->cin_age = 0;
			cout << "输入有误，请重新输入" << '\n';
		}
		else
		{
			return user_cin->cin_age;
		}
	}
}

// 获取并循环检查用户输入的字符串是否为空，不为空则结束循环返回字符串
string CheckStr(UserCin* user_cin)
{
	user_cin->cin_str = "";

	while (true)
	{
		cout << "请输入：" << '\n';
		cin >> user_cin->cin_str;
		if (user_cin->cin_str == "")
		{
			cout << "输入为空，请重新输入" << '\n';
		}
		else
		{
			return user_cin->cin_str;
		}
	}
}

// 根据用户输入查询联系人是否存在，若存在则返回联系人在通讯录中的下标
int FindByName(UserCin* user_cin, AddressBook* address_book)
{
	cout << "按姓名查询" << '\n';
	CheckStr(user_cin);

	for (int contact_idx = 0; contact_idx < address_book->contacts.size(); ++contact_idx)
	{
		if (user_cin->cin_str == address_book->contacts.at(contact_idx).contact_name)
		{
			return contact_idx;
		}
	}
	return -1;
}

// 根据联系人所在通讯录中下标打印该联系人信息
void PrintContact(AddressBook* address_book, int contact_idx)
{
	cout << "姓名：" << address_book->contacts.at(contact_idx).contact_name << ' ';
	cout << "性别:" << address_book->contacts.at(contact_idx).contact_sex << ' ';
	cout << "年龄:" << address_book->contacts.at(contact_idx).contact_age << ' ';
	cout << "电话号码:" << address_book->contacts.at(contact_idx).contact_phone << ' ';
	cout << "地址:" << address_book->contacts.at(contact_idx).contact_address << '\n';
}

// 显示联系人函数
void ShowContacts(AddressBook* address_book)
{
	cout << "总计" << address_book->contacts.size() << "位联系人" << '\n';
	for (int contact_idx = 0; contact_idx < address_book->contacts.size(); ++contact_idx)
	{
		PrintContact(address_book, contact_idx);
	}
}

// 查找联系人函数
void FindContact(UserCin* user_cin, AddressBook* address_book)
{
	int contact_idx = FindByName(user_cin, address_book);
	if (contact_idx != -1)
	{
		cout << "找到联系人如下:" << '\n';
		PrintContact(address_book, contact_idx);
	}
}

// 获取联系人信息并返回一个联系人结构体
Contact UpdateContact(UserCin* user_cin)
{
	Contact temp_contact{}; // 此处应该可以直接细分user_cin然后直接调用并存储，但该练习不一一检查输入则选择再创联系人结构体
	cout << "姓名" << ' ';
	temp_contact.contact_name = CheckStr(user_cin);
	cout << "年龄" << ' ';
	temp_contact.contact_age = CheckAge(user_cin);
	cout << "性别" << ' ';
	temp_contact.contact_sex = CheckStr(user_cin);
	cout << "电话号码" << ' ';
	temp_contact.contact_phone = CheckStr(user_cin);
	cout << "地址" << ' ';
	temp_contact.contact_address = CheckStr(user_cin);
	return temp_contact;
}

// 添加联系人函数
void AddContact(UserCin* user_cin, AddressBook* address_book)
{
	address_book->contacts.push_back(UpdateContact(user_cin));
	cout << "添加成功" << '\n';
}

// 修改联系人函数
void EditContact(UserCin* user_cin, AddressBook* address_book)
{
	int contact_idx = FindByName(user_cin, address_book);
	if (contact_idx != -1)
	{
		address_book->contacts.at(contact_idx) = UpdateContact(user_cin);
		cout << "修改成功" << '\n';
	}
}

// 删除联系人函数
void DeleteContact(AddressBook* address_book, UserCin* user_cin)
{
	int contact_idx = FindByName(user_cin, address_book);
	if (contact_idx != -1)
	{
		address_book->contacts.erase(address_book->contacts.begin() + contact_idx);
		cout << "删除成功" << '\n';
	}
}

// 显示菜单函数
void ShowMenu()
{
	cout << "1.添加联系人" << '\n';
	cout << "2.显示联系人" << '\n';
	cout << "3.删除联系人" << '\n';
	cout << "4.查找联系人" << '\n';
	cout << "5.修改联系人" << '\n';
	cout << "6.清空联系人" << '\n';
	cout << "0.退出通讯录" << '\n';
}

// 通讯录管理系统启动函数
void LaunchAddressBook(AddressBook* address_book, UserCin* user_cin)
{
	bool exit = false;
	while (!exit)
	{
		ShowMenu();

		switch (CheckSelect(user_cin))
		{
		case 1: // 添加联系人
			AddContact(user_cin, address_book);
			break;
		case 2: // 显示联系人
			ShowContacts(address_book);
			break;
		case 3: // 删除联系人
			DeleteContact(address_book, user_cin);
			break;
		case 4: // 查找联系人
			FindContact(user_cin, address_book);
			break;
		case 5: // 修改联系人
			EditContact(user_cin, address_book);
			break;
		case 6: // 清空联系人
			address_book->contacts.clear();
			break;
		case 0: // 退出通讯录
			cout << "欢迎下次使用" << '\n';
			exit = true;
			break;
		}
	}
}

int main()
{
	AddressBook address_book{};
	UserCin user_cin{};
	LaunchAddressBook(&address_book, &user_cin);

	return 0;
}