// day0002，浮点型、字符型、转义字符、字符串型
# include <iostream>
# include <string>
using namespace std;

int main()
{
// 浮点型（实型）：float（存储7位有效数字）、double（存储15~16位有效数字）
	/*
	有效数字：从第一位非零数字开始计数，故float可以存储0.000000000001；
	小数默认为double数据类型，需在末尾加f声明为float数据类型；
	cout默认显示六位有效数字；遇到极小极大值时默认以科学计数法表示数字；
		(科学计数法：1e-4 = 0.0001 1e+4 = 10000)
		(前导零则表示八进制；0b表示二进制；0x表示十六进制，表示进制的数字及字母不纳入有效位数；）
	*/
	float f1 = 0.000000000001f;//1e-12
	cout << f1 << endl;

// 字符型：用于存储单字符变量，字符型变量以ASCII码对应的十进制值存储；
	// 语法：char 变量名 = '字符';
	char ch1 = ':'; // 必须用单引号，必须为单字符而非字符串；
	int num_ch = sizeof(ch1); //sizeof实际是运算符；
	cout << ":所占内存大小为" << num_ch << "字节" << endl;// 字符型所占内存大小为1字节；

// 查询字符型变量对应的ASCII码方法
	cout << ":对应的ASCII码为" << (int)ch1 << endl;// : = 58

// ASCII码可以直接给字符型变量赋值，来改变字符型变量的字符；
	ch1 = 98; // b = 98
	cout << ch1 << endl;

// 转义字符：以反斜杠\为首的特殊字符组合，有特殊用途或特殊含义；
// 常见转义字符：\n换行符；\\输出一个\； \t水平制表符，推荐用''，例如'\n'；

// \n换行符：与endl（强制刷新）相比对性能影响更小；
	cout << "Hello\nWorld";

// \\：输出一个\，仅前\具一次转义作用；
	cout << "\\\n" << "\\\\\n";// 奇数的\则会报错；

// \t水平制表符：整齐输出数据；
	cout << "aa\tbbbb\n" << "aaa\tbbbb";

// 字符串型：一串字符的数据类型；
	// c语言语法：char 变量名[] = "字符串值";
	char c_str[] = "haha";// 字符串需用双引号""；
	// cpp语法：string 变量名 = "字符串值";
	string cpp_str = "niania";// 刚需添加 #include <string>的头文件；
	cout << c_str << cpp_str;

	system("pause");

	return 0;
}