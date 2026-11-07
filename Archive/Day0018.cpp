// Day0018,通讯录管理系统改造练习
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ========== 通讯录管理系统优化练习 ==========

// 2026.11.2日再复盘优化
// 通讯录需求：添加、显示、删除、查找、修改、清空联系人，循环执行直到用户主动选择退出通讯录交互系统
// ========== 需求实现思路 ==========
// 重点是根据用户输入获得该联系人在通讯录数组中的下标，此练习仅简单设计根据输入姓名返回下标
// 其中添加、显示、删除、查找、修改都基于联系人下标进行操作，故最先实现输入检查以及根据输入姓名返回联系人下标
// ========== 经验总结 ==========
// 数据流通范围有在程序之间流通(参数、函数内修改、return)和人与程序间流通(cin、cout、会充分利用的数据return)
// 编写函数时尽量将函数按通道分为两类:只走数据通道的函数和只走交互通道的函数，非必要不用混合通道函数
// 此举是为了将cin、cout集中在固定的小部分函数内而非分散在四处，即方便整体结构后续拓展，也便于排查错因

// ========== 创建结构体 ==========
// 创建联系人结构体
struct Contact
{
	string contact_name = "未命名";
	string contact_sex = "空";
	int contact_age = 0;
	string contact_phone = "空";
	string contact_address = "空";
};
// 创建通讯录结构体
struct AddressBook
{
	vector<Contact> contacts{};
};

// ========== 函数集中声明区 ==========
// 提前声明函数方便阅读，说实话从函数职责描述就能看出哪些函数还能进行重复结构优化
// 选项输入检查函数：循环检查用户输入的数字是否非法(目前阶段能力还无法防御输入字符串，暂且忽略)，合法后return整型int
// 

// ========== 创建函数区 ==========
// 展示菜单函数
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
void LaunchAddressBook(AddressBook* address_book)
{
	bool exit = false; // 设置退出while循环条件
	while (!exit)
	{
		ShowMenu();

		int user_select{};
		cin >> user_select;
		if (user_select < 0 || user_select > 6)
		{
			cout << "输入有误，请重新输入" << '\n';
		}
		else
		{
			switch (user_select)
			{
			case 1: // 添加联系人
				AddContact(address_book);
				break;
			case 2: // 显示联系人
				ShowAddressBook(address_book);
				break;
			case 3: // 删除联系人
			{
				string confirm_name{ GetUserCin() };
				DeleteContact(address_book, confirm_name);
			}
			break;
			case 4: // 查找联系人
			{
				string confirm_name{ GetUserCin() };
				FindContact(address_book, confirm_name);
			}
			break;
			case 5: // 修改联系人
			{
				string confirm_name{ GetUserCin() };
				EditContact(address_book, confirm_name);
			}
			break;
			case 6: // 清空联系人
				ClearContacts(address_book);
				break;
			case 0: // 退出通讯录、
				cout << "欢迎下次使用" << '\n';
				exit = true;
				break;
			}
		}
	}
}

// 由联系人数组下标更新联系人信息函数
void UpdataContactInfo(AddressBook* address_book, int contact_idx)
{
	cout << "请输入联系人姓名：" << '\n';
	cin >> address_book->contacts.at(contact_idx).contact_name;
	cout << "请输入联系人性别：" << '\n';
	cin >> address_book->contacts.at(contact_idx).contact_sex;
	cout << "请输入联系人年龄：" << '\n';
	cin >> address_book->contacts.at(contact_idx).contact_age;
	cout << "请输入联系人电话号码:" << '\n';
	cin >> address_book->contacts.at(contact_idx).contact_phone;
	cout << "请输入联系人地址：" << '\n';
	cin >> address_book->contacts.at(contact_idx).contact_address;
}

// 添加联系人函数
void AddContact(AddressBook* address_book)
{
	address_book->contacts.push_back({});
	UpdataContactInfo(address_book, address_book->contacts.size()-1);
}

// 遍历单个联系人内成员函数
void PrintContact(AddressBook* address_book, int contact_idx)
{
	cout << "姓名：" << address_book->contacts.at(contact_idx).contact_name << ' ';
	cout << "性别：" << address_book->contacts.at(contact_idx).contact_sex << ' ';
	cout << "年龄：" << address_book->contacts.at(contact_idx).contact_age << ' ';
	cout << "电话号码：" << address_book->contacts.at(contact_idx).contact_phone << ' ';
	cout << "地址：" << address_book->contacts.at(contact_idx).contact_address << '\n';
}

// 显示联系人函数
void ShowAddressBook(AddressBook* address_book)
{
	if (address_book->contacts.empty())
	{
		cout << "当前通讯录为空" << '\n';
	}
	else
	{
		for (int contact_idx = 0; contact_idx < address_book->contacts.size(); ++contact_idx)
		{
			PrintContact(address_book, contact_idx);
		}
	}
}

// 按姓名检查通讯录是否存在联系人函数
bool IsExist(AddressBook* address_book, string confirm_name)
{
	int contact_idx{};
	for (const Contact& contact_idx : address_book->contacts)
	{
		if (confirm_name == address_book->contacts.at(contact_idx).contact_name)
		{
			return true;
		}
	}
	return false;
}

// 按输入姓名获取联系人数组下标函数
int FindByName(AddressBook* address_book, string confirm_name)
{
	int contact_idx{};
	for (const Contact& contact_idx : address_book->contacts)
	{
		if (confirm_name == address_book->contacts.at(contact_idx).contact_name)
		{
			return contact_idx;
		}
	}
	return{};
}

// 获取用户cin输入的联系人姓名并作为返回值传出
string GetUserCin()
{
	string confirm_name{}; // 重置姓名值
	cout << "请输入目标联系人的姓名:" << '\n';
	cin >> confirm_name;
	return confirm_name;
}

// 删除联系人函数
void DeleteContact(AddressBook* address_book, string confirm_name)
{
	if (!IsExist(address_book, confirm_name))
	{
		cout << "未查询到该联系人" << '\n';
	}
	else
	{
		int contact_idx = FindByName(address_book, confirm_name);
		address_book->contacts.erase(address_book->contacts.begin() + contact_idx);
		cout << "删除成功" << '\n';
	}
}

// 查找联系人函数
void FindContact(AddressBook* address_book, string confirm_name)
{
	if (!IsExist(address_book, confirm_name))
	{
		cout << "未查询到该联系人" << '\n';
	}
	else
	{
		cout << "查找到联系人如下：" << '\n';
		int contact_idx = FindByName(address_book, confirm_name);
		PrintContact(address_book, contact_idx);
	}
}

// 修改联系人函数
// 与查找联系人函数相似度过高，很明显还有优化空间
void EditContact(AddressBook* address_book, string confirm_name)
{
	if (!IsExist(address_book, confirm_name))
	{
		cout << "未查询到该联系人" << '\n';
	}
	else
	{
		int contact_idx{};
		contact_idx = FindByName(address_book, confirm_name);
		UpdataContactInfo(address_book, contact_idx);
		cout << "修改成功" << '\n';
	}
}

// 清空联系人函数
void ClearContacts(AddressBook* address_book)
{
	if (address_book->contacts.empty())
	{
		cout << "当前无联系人，无法清空" << '\n';
	}
	else
	{
		address_book->contacts.clear();
		cout << "已清空通讯录" << '\n';
	}
}


// 主函数
int main()
{
	// 创建一个通讯录
	AddressBook address_book{};

	LaunchAddressBook(&address_book);

	return 0;
}