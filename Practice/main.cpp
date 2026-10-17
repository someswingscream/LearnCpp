// Day0016,通讯录练习
#include <iostream>
#include <string>

using namespace std;

// ========== 通讯录管理系统练习 ==========

// 创建联系人结构体存储联系人信息
struct Contact
{
	string person_name = "未命名";
	int person_sex = 0;// 1男2女
	int person_age = 0;
	string person_phone = "空";
	string address = "空";
};

// 创建通讯录结构体存储联系人
struct AddressBook
{
	int contacts_num = 0;
	Contact contacts[500];
};

// 集中声明函数，将函数定义置后方便阅读
void LaunchContactManager(AddressBook* address_book);
void ShowMenu();
void AddContact(AddressBook* address_book);
void ShowContact(AddressBook* address_book);
int CheckContact(AddressBook* address_book);
void DeleteContact(AddressBook* address_book);
void FindContact(AddressBook* address_book);
void EditContact(AddressBook* address_book);
void ClearContacts(AddressBook* address_book);

// 启动通讯录函数
void LaunchContactManager(AddressBook* address_book)
{
	// 设置退出循环的出口
	bool exit = false;
	// 当不退出时循环使用通讯录管理系统
	while (!exit)
	{
		// 循环显示菜单，方便用户使用完一个功能后继续
		ShowMenu();
		// 获取用户输入
		cout << "请输入：" << '\n';
		int user_select = 0;
		cin >> user_select;
		// 用于判断用户输入是否合法
		int cin_arr[7] = { 0,1,2,3,4,5,6 };
		if (user_select != cin_arr[user_select])
		{
			cout << "输入有误，请重新输入" << '\n';
		}
		else
		{
			// 管理系统函数主体，根据用户不同输入后调用不同函数
			switch (user_select)
			{
			case 1:// 添加联系人
				AddContact(address_book);
				break;
			case 2:// 显示联系人
				ShowContact(address_book);
				break;
			case 3:// 删除联系人
				DeleteContact(address_book);
				break;
			case 4:// 查找联系人
				FindContact(address_book);
				break;
			case 5:// 修改联系人
				EditContact(address_book);
				break;
			case 6:// 清空联系人
				ClearContacts(address_book);
				break;
			case 0:// 退出联系人管理系统
				cout << "欢迎下次使用" << '\n';
				exit = true;
				break;
			}
		}
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

// 添加联系人函数
void AddContact(AddressBook* address_book)
{
	if (address_book->contacts_num == 500)
	{
		cout << "人数已满，无法添加联系人" << '\n';
	}
	else
	{
		// 修改姓名
		cout << "请输入联系人姓名:" << '\n';
		string cin_name;
		cin >> cin_name;
		address_book->contacts[address_book->contacts_num].person_name = cin_name;
		// 修改性别
		cout << "请输入联系人性别：" << ' ' << "(男输入1，女输入2)" << '\n';
		int cin_sex = 0;
		while (true)
		{
			cin >> cin_sex;
			if (cin_sex == 1 || cin_sex == 0)
			{
				address_book->contacts[address_book->contacts_num].person_sex = cin_sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << '\n';
			}
		}
		// 修改年龄。该函数自此后防御用户输入设计不再一一重复，直接省略
		cout << "请输入联系人年龄:" << '\n';
		int cin_age = 0;
		cin >> cin_age;
		address_book->contacts[address_book->contacts_num].person_age = cin_age;
		// 修改电话号码
		cout << "请输入联系人电话号码：" << '\n';
		string cin_phone = "空";
		cin >> cin_phone;
		address_book->contacts[address_book->contacts_num].person_phone = cin_phone;
		// 修改地址
		cout << "请输入联系人地址:" << '\n';
		string cin_address = "空";
		cin >> cin_address;
		address_book->contacts[address_book->contacts_num].address = cin_address;
		// 修改联系人数量，输出修改成功反馈
		cout << "添加成功" << '\n';
		++address_book->contacts_num;
	}
}

// 显示联系人函数
void ShowContact(AddressBook* address_book)
{
	if (address_book->contacts_num == 0)
	{
		cout << "暂无联系人" << '\n';
	}
	else
	{
		cout << "一共" << address_book->contacts_num << "名联系人" << '\n';

		for (int i = 0; i < address_book->contacts_num; ++i)
		{
			cout << "姓名：" << address_book->contacts[i].person_name << '\t';
			cout << "性别：" << (address_book->contacts[i].person_sex == 1 ? '男': '女') << '\t';
			cout << "年龄：" << address_book->contacts[i].person_age << '\t';
			cout << "电话号码：" << address_book->contacts[i].person_phone << '\t';
			cout << "地址：" << address_book->contacts[i].address << '\n';
		}
	}
}

// 按名称遍历通讯录查询联系人是否存在的函数
int CheckContact(AddressBook* address_book)
{
	string contact_name;
	cin >> contact_name;
	for (int i = 0; i < address_book->contacts_num; ++i)
	{
		if (address_book->contacts[i].person_name == contact_name)
		{
			return i;
		}
	}
	// 遍历结束后还未找到则返回-1
	return -1;
}

// 获取用户输入的联系人姓名，按函数返回的联系人下标索引删除联系人的函数
void DeleteContact(AddressBook* address_book)
{
	cout << "请输入要删除联系人的姓名：" << "\n";
	int contact_idx = CheckContact(address_book);
	if (contact_idx == -1)
	{
		cout << "暂无此人" << '\n';
	}
	else
	{
		// 用逐项向前覆盖实现删除联系人
		for (int i = contact_idx; i < address_book->contacts_num -1; ++i)
		{
			address_book->contacts[i] = address_book->contacts[i + 1];
		}
		// 完成删除联系人后对通讯录人数进行修改
		cout << "删除成功" << '\n';
		--address_book->contacts_num;
	}
}

// 获取用户输入的姓名，按姓名进行索引并显示索引结果的函数
void FindContact(AddressBook* address_book)
{
	cout << "请输入要查询联系人的姓名：" << '\n';
	int contact_idx = CheckContact(address_book);
	if (contact_idx == -1)
	{
		cout << "查无此人" << '\n';
	}
	else
	{
		cout << "找到联系人信息如下：" << '\n';
		cout << "姓名：" << address_book->contacts[contact_idx].person_name << '\t';
		cout << "性别：" << (address_book->contacts[contact_idx].person_sex == 1 ? '男' : '女') << '\t';
		cout << "年龄：" << address_book->contacts[contact_idx].person_age << '\t';
		cout << "电话号码：" << address_book->contacts[contact_idx].person_phone << '\t';
		cout << "地址：" << address_book->contacts[contact_idx].address << '\n';
	}
}

// 修改联系人函数
void EditContact(AddressBook* address_book)
{
	cout << "请输入要修改联系人的姓名：" << '\n';
	int contact_idx = CheckContact(address_book);
	if (contact_idx == -1)
	{
		cout << "查无此人" << '\n';
	}
	else
	{
		// 显示联系人方便用户参考用于修改信息
		cout << "找到联系人信息如下：" << '\n';
		cout << "姓名：" << address_book->contacts[contact_idx].person_name << '\t';
		cout << "性别：" << (address_book->contacts[contact_idx].person_sex == 1 ? '男' : '女') << '\t';
		cout << "年龄：" << address_book->contacts[contact_idx].person_age << '\t';
		cout << "电话号码：" << address_book->contacts[contact_idx].person_phone << '\t';
		cout << "地址：" << address_book->contacts[contact_idx].address << '\n';

		// 修改姓名
		cout << "请输入修改后的姓名:" << '\n';
		string cin_name = "空";
		cin >> cin_name;
		address_book->contacts[contact_idx].person_name = cin_name;
		// 修改性别
		cout << "请输入修改后的性别(1为男2为女):" << '\n';
		int cin_sex = 0;
		cin >> cin_sex;
		address_book->contacts[contact_idx].person_sex = cin_sex;
		// 修改年龄
		cout << "请输入修改后的年龄:" << '\n';
		int cin_age = 0;
		cin >> cin_age;
		address_book->contacts[contact_idx].person_age = cin_age;
		// 修改电话号码
		cout << "请输入修改后的电话号码：" << '\n';
		string cin_phone = "空";
		cin >> cin_phone;
		address_book->contacts[contact_idx].person_phone = cin_phone;
		// 修改地址
		cout << "请输入修改后的地址:" << '\n';
		string cin_address = "空";
		cin >> cin_address;
		address_book->contacts[contact_idx].address = cin_address;
		// 修改联系人数量，输出修改成功反馈
		cout << "修改成功" << '\n';
	}
}

// 清空通讯录中联系人函数(仅作逻辑上清空而非物理删除)
void ClearContacts(AddressBook* address_book)
{
	cout << "是否确认清空联系人？输入0确认清空,输入其他数取消" << '\n';
	bool has_revoked = true;
	int user_cin = 1;

	cin >> user_cin;
	has_revoked = static_cast<bool>(user_cin);// 静态转换整型01为布尔类型

	// 将通讯录的联系人数量修改为0，以无法访问实现逻辑上清空通讯录的效果
	if (has_revoked)
	{
		cout << "已取消清空" << '\n';
	}
	else
	{
		address_book->contacts_num = 0;
		cout << "已清空通讯录中所有联系人" << '\n';
	}
}
// 主函数
int main()
{
	// 创建一个空通讯录，默认该次练习中通讯录上限为1，且一个通讯录中存储联系人上限为500
	AddressBook address_book;
	LaunchContactManager(&address_book);

	return 0;
}