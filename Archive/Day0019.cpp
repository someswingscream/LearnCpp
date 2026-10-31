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

// ========== 函数集中声明区 ==========
// 集中声明函数及注释职能和接口，方便阅读
// =====================================================================================
int CheckSelect(string prompt);
// 职责：循环检查用户输入，输入合法则退出循环返回整型
// 输入：无参数，cin获取用户输入
// 输出：非法输入后cout输入有误，请重新输入，return范围在0-7整型int
// 通道：界面层与用户cin、cout

// =====================================================================================
int CheckAge(string prompt);
// 职责：循环检查用户输入，输入合法则退出循环返回整型
// 输入：无参数，cin获取用户输入
// 输出：非法输入后cout输入有误，请重新输入，return范围在0-200整型int
// 通道：界面层与用户cin、cout

// =====================================================================================
string CheckStr(string prompt); // 此练习中对于各字符串不做更细分的检查，仅作输入是否为空检查
// 职责：循环检查用户输入，输入合法则退出循环返回整型
// 输入：无参数，cin获取用户输入
// 输出：非法输入后cout输入有误，请重新输入，return不为空的字符串string
// 通道：界面层与用户cin、cout

// =====================================================================================
int FindByName(AddressBook* address_book,string target_name);
// 职责：按姓名查找联系人，返回其下标
// 输入：address_book —— 被查询的通讯录（只读）
//      target_name  —— 要查找的姓名（由调用方提供）
// 输出：return —— 找到返回下标；未找到或通讯录为空，返回 -1
// 通道：纯逻辑（本函数不出现任何 cin/cout）

// =====================================================================================
void PrintContact(AddressBook* address_book, int contact_idx);
// =====================================================================================

// =====================================================================================
void ShowContacts(AddressBook* address_book);
// =====================================================================================

// =====================================================================================
void FindContact(AddressBook* address_book);
// =====================================================================================

// =====================================================================================
Contact UpdateContact();
// =====================================================================================

// =====================================================================================
void AddContact(AddressBook* address_book);
// 职责：采集一个联系人并追加到通讯录末尾
// 输入：address_book —— 目标通讯录
// 输出：就地修改 address_book->contacts（push_back 一个元素）
//       cout —— 一行"添加成功"操作反馈
// 通道：混合——采集委托给 ReadContactFromCin，本函数只负责追加与反馈
// =====================================================================================

// =====================================================================================

void EditContact(AddressBook* address_book);
// =====================================================================================

// =====================================================================================

void DeleteContact(AddressBook* address_book);
// =====================================================================================

// =====================================================================================

void ShowMenu();
// =====================================================================================

// =====================================================================================
void LaunchAddressBook(AddressBook* address_book);
// 职责：运行菜单主循环，把用户选择分发给对应功能函数，直到用户退出
// 输入：address_book —— 整个程序的数据家底（由各功能函数就地修改）
// 输出：无 return；数据变化全部就地发生在 address_book 上
// 通道：混合（流程编排层，直接接触界面函数）

// ========== 定义函数区 ==========
// 循环检查用户输入的选择是否合法，合法则结束循环返回整型选择
int CheckSelect(string prompt)
{
	while (true)
	{
		cout << prompt << '\n';
		int cin_select{};
		cin >> cin_select;
		if (cin_select < 0 || cin_select >6) // 此练习仅作输入数字检查，不做输入字符串检查
		{
			cin_select = 0;
			cout << "输入有误，请重新输入" << '\n';
		}
		else
		{
			return cin_select;
		}
	}
}

// 循环检查用户输入的年龄是否合法，合法则结束循环返回整型年龄
int CheckAge(string prompt)
{
	while (true)
	{
		cout << prompt << '\n';
		int cin_age{};
		cin >> cin_age;

		if (cin_age < 0 || cin_age >200) // 暂且认为0岁下200岁上是非法年龄输入
		{
			cin_age = 0;
			cout << "输入有误，请重新输入" << '\n';
		}
		else
		{
			return cin_age;
		}
	}
}

// 获取并循环检查用户输入的字符串是否为空，不为空则结束循环返回字符串
string CheckStr(string prompt)
{
	while (true)
	{
		cout << prompt << '\n';
		string cin_str{};
		cin >> cin_str;
		if (cin_str == "")
		{
			cout << "输入为空，请重新输入" << '\n';
		}
		else
		{
			return cin_str;
		}
	}
}

// 根据用户输入查询联系人是否存在，若存在则返回联系人在通讯录中的下标
int FindByName(AddressBook* address_book,string target_name)
{
	for (int contact_idx = 0; contact_idx < address_book->contacts.size(); ++contact_idx)
	{
		if (address_book->contacts.at(contact_idx).contact_name == target_name)
		{
			return contact_idx;
		}
	}
	return -1;
}

// 根据联系人所在通讯录中下标打印该联系人信息
void PrintContact(AddressBook* address_book, int contact_idx)
{
	cout << "姓名：" << address_book->contacts.at(contact_idx).contact_name << '\t';
	cout << "性别:" << address_book->contacts.at(contact_idx).contact_sex << '\t';
	cout << "年龄:" << address_book->contacts.at(contact_idx).contact_age << '\t';
	cout << "电话号码:" << address_book->contacts.at(contact_idx).contact_phone << '\t';
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
void FindContact(AddressBook* address_book)
{
	string target_name = CheckStr("请输入要查询联系人的姓名：");
	int contact_idx = FindByName(address_book,target_name);
	if (contact_idx != -1)
	{
		cout << "找到联系人如下:" << '\n';
		PrintContact(address_book, contact_idx);
	}
	else
	{
		cout << "查无此人" << '\n';
	}
}

// 获取联系人信息并返回一个联系人结构体
Contact UpdateContact()
{
	Contact temp_contact{};
	temp_contact.contact_name = CheckStr("请输入姓名:");
	temp_contact.contact_age = CheckAge("请输入年龄:");
	temp_contact.contact_sex = CheckStr("请输入性别:");
	temp_contact.contact_phone = CheckStr("请输入电话号码:");
	temp_contact.contact_address = CheckStr("请输入地址:");
	return temp_contact;
}

// 添加联系人函数
void AddContact(AddressBook* address_book)
{
	address_book->contacts.push_back(UpdateContact());
	cout << "添加成功" << '\n';
}

// 修改联系人函数
void EditContact(AddressBook* address_book)
{
	string target_name = CheckStr("请输入要修改联系人的姓名:");
	int contact_idx = FindByName(address_book,target_name);
	if (contact_idx != -1)
	{
		address_book->contacts.at(contact_idx) = UpdateContact();
		cout << "修改成功" << '\n';
	}
	else
	{
		cout << "查无此人" << '\n';
	}
}

// 删除联系人函数
void DeleteContact(AddressBook* address_book)
{
	string target_name = CheckStr("请输入要删除联系人的姓名:");
	int contact_idx = FindByName(address_book,target_name);
	if (contact_idx != -1)
	{
		address_book->contacts.erase(address_book->contacts.begin() + contact_idx);
		cout << "删除成功" << '\n';
	}
	else
	{
		cout << "查无此人" << '\n';
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
void LaunchAddressBook(AddressBook* address_book)
{
	bool exit = false;
	while (!exit)
	{
		ShowMenu();

		switch (CheckSelect("请输入选项:"))
		{
		case 1: // 添加联系人
			AddContact(address_book);
			break;
		case 2: // 显示联系人
			ShowContacts(address_book);
			break;
		case 3: // 删除联系人
			DeleteContact(address_book);
			break;
		case 4: // 查找联系人
			FindContact(address_book);
			break;
		case 5: // 修改联系人
			EditContact(address_book);
			break;
		case 6: // 清空联系人
			address_book->contacts.clear();
			cout << "清空成功" << '\n';
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
	LaunchAddressBook(&address_book);

	return 0;
}