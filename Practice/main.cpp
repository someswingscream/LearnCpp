// Day0017,窄化、{}初始化变量、vector数组
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // ========== 数据类型值范围及窄化转换 ==========
    {
        // 常见数据类型值范围
        // lowest()：最小值；max()：最大值（C++11 起对整数浮点都适用）
        // 目前超纲内容仅认识
        cout << "bool:    [" << (int)numeric_limits<bool>::lowest() << ", " << (int)numeric_limits<bool>::max() << "]\n";
        cout << "char:    [" << (int)numeric_limits<char>::lowest() << ", " << (int)numeric_limits<char>::max() << "]\n";
        cout << "short:   [" << numeric_limits<short>::lowest() << ", " << numeric_limits<short>::max() << "]\n";
        cout << "int:     [" << numeric_limits<int>::lowest() << ", " << numeric_limits<int>::max() << "]\n";
        cout << "long long: [" << numeric_limits<long long>::lowest() << ", " << numeric_limits<long long>::max() << "]\n";
        cout << "float:   [" << numeric_limits<float>::lowest() << ", " << numeric_limits<float>::max() << "]\n";
        cout << "double:  [" << numeric_limits<double>::lowest() << ", " << numeric_limits<double>::max() << "]\n";

        cout << '\n';
        
        // 窄化转化：从值范围大的类型转换到值范围小的类型数据，目标数据类型可能装不下源值，转换过程可能丢失信息
        // 实际判断标准，源值数据类型的值范围不是目标数据类型值范围的超集，则是窄化转换
        // c++中用=来进行初始化、赋值修改变量时不会因窄化转化而报错
        double d = 3.99;
        int i = d;  // 小数部分直接砍掉，i = 3，而非四舍五入
        cout << "将浮点数 d=3.99窄化转化为整型int i后结果为:" << i << '\n';

        int big = 300;
        char c = big;   // 300 超出 char 范围，截断成 44（'，' 字符）
        cout << "将整型int big=300窄化转化为字符串char c后结果为：" << c << '\n';

        int n = 100000000;
        short s = n;    // 高位被丢弃
        cout << "将整型int n=100000000窄化转换位短整型short s后结果为：" << s << '\n';
    }

    // ========== {}初始化 ==========
    {
        // 花括号{}初始化变量时静态检查，会将窄化当为编译错误指出
        // 常见数据类型{}初始化
        // 结构体{}会检查成员列表是否按序逐个填入，不允许跳过成员进行赋值
        int      a1{ 42 };
        bool     b1{ true };
        char     c1{ 'x' };
        double   d1{ 3.14 };
        int      arr1[5]{ 1, 2 };    // {1, 2, 0, 0, 0} —— 没写的地方自动补 0
        int*     p1{ &a1 };
        string   s1{ "hello" };

        // 常见数据类型{}零初始化的值，可以避免初始化赋垃圾值
        // 结构体{}初始化在填入最后一个有效值后会自动补零
        int      a2{};  // 0
        bool     b2{};  // false
        char     c2{};  // '\0'（编码为 0 的字符）
        double   d2{};  // 0.0
        int      arr2[5]{};  // 5 个元素全是 0
        int*     p2{};  // 等价于int* p2 = nullptr
        string   s2{};  // 空串""

        // {}花括号只能初始化时单用，定义后再赋值时需配合=
        // int i{0}后再次用i{19};进行赋值还是会被视为声明变量但缺少类型声明故会报错，需i = {19};
        // 用i = {19};来再赋值时花括号仍具有静态检查作用
        // 花括号仅能负责在运行前经行检查，在运行后出现新值超出源值数据类型的值范围无法避免
        
        // 数据类型进行转换是具有潜在危险的行为，
        
    }


    

	return 0;
}