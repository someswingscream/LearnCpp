// Day0017,窄化、{}初始化变量、vector数组
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

int main()
{
// ========== 窄化概念 ==========
    // 数据类型值范围及窄化转换
    {
        // 常见数据类型值范围
        // lowest()：最小值；max()：最大值（C++11 起对整数浮点都适用）
        // 获取值范围目前超纲内容仅认识
        cout << "常见数据值范围测试：" << '\n';

        cout << "bool:    [" << static_cast<int>(numeric_limits<bool>::lowest()) << ", " << static_cast<int>(numeric_limits<bool>::max()) << "]\n";
        cout << "char:    [" << static_cast<int>(numeric_limits<char>::lowest()) << ", " << static_cast<int>(numeric_limits<char>::max()) << "]\n";
        cout << "short:   [" << numeric_limits<short>::lowest() << ", " << numeric_limits<short>::max() << "]\n";
        cout << "int:     [" << numeric_limits<int>::lowest() << ", " << numeric_limits<int>::max() << "]\n";
        cout << "long long: [" << numeric_limits<long long>::lowest() << ", " << numeric_limits<long long>::max() << "]\n";
        cout << "float:   [" << numeric_limits<float>::lowest() << ", " << numeric_limits<float>::max() << "]\n";
        cout << "double:  [" << numeric_limits<double>::lowest() << ", " << numeric_limits<double>::max() << "]\n";

        cout << "测试结束" << '\n' << '\n';

        // 窄化转化：从值范围大的类型转换到值范围小的类型数据，目标数据类型可能装不下源值，转换过程可能丢失信息
        // 实际判断标准，源值数据类型的值范围不是目标数据类型值范围的超集，则是窄化转换
        // c++中用=来进行初始化、赋值修改变量时不会因窄化转化而报错
        cout << "经典窄化转化测试：" << '\n';

        double d = 3.99;
        int i = d; // 小数部分直接砍掉，i = 3，而非四舍五入
        cout << "将浮点数 d=3.99窄化转化为整型int i后结果为:" << i << '\n';

        int big = 300;
        char c = big; // 300 超出 char 范围，截断成 44（',' 字符）
        cout << "将整型int big=300窄化转化为字符串char c后结果为：" << c << '\n';

        int n = 100000000;
        short s = n; // 高位被丢弃
        cout << "将整型int n=100000000窄化转换位短整型short s后结果为：" << s << '\n';

        cout << "测试结束" << '\n' << '\n';
    }

// ========== {}花括号初始化优点 ===========
    // {}初始化
    {
        // 花括号{}初始化变量时静态检查，会将窄化当为编译错误指出
        // 常见数据类型{}初始化
        // 结构体{}会检查成员列表是否按序逐个填入，不允许跳过中间成员进行赋值
        int      a1{ 42 };
        bool     b1{ true };
        char     c1{ 'x' };
        double   d1{ 3.14 };
        int      arr1[5]{ 1, 2 }; // {1, 2, 0, 0, 0} —— 没写的地方自动补 0
        int* p1{ &a1 };
        string   s1{ "hello" };

        // 常见数据类型{}零初始化的值，可以避免初始化赋垃圾值
        // 结构体{}初始化在填入最后一个有效值后会自动补零
        int      a2{}; // 0
        bool     b2{}; // false
        char     c2{}; // '\0'（编码为 0 的字符）
        double   d2{}; // 0.0
        int      arr2[5]{};  // 5 个元素全是 0
        int* p2{}; // 等价于int* p2 = nullptr
        string   s2{}; // 空串""

        // {}花括号只能初始化时单用，定义后再赋值时需配合=
        // int i{0}后再次用i{19};进行赋值还是会被视为声明变量但缺少类型声明故会报错，需i = {19};
        // 用i = {19};来再赋值时花括号仍具有静态检查作用
        // 花括号仅能负责在运行前经行检查，在运行后出现新值超出源值数据类型的值范围无法避免
        // {}在编译期拦截窄化转换，判定分两种：
            // ① 源是常量表达式（编译期能确定值）：检查具体值。
            //    整型之间：装得下方行（char c{100}✓），装不下拦截（char c{300}✗）；
            //    浮点转整型：一律拦截，哪怕值恰好是整数（int x{3.0}✗）；
            //    整型转浮点：值能被精确表示才放行（float f{3}✓）
            // ② 源是普通变量：不看当前值，只看类型——目标类型装不下源类型的全部可能值就拦截
            // 核心思想：宁可错杀(例如3.0 没小数也拦)，不可放过导致运行期悄悄丢数据

        // 例如以下内容，浮点转整型
        //double d{};
        //int x{ d };

        // 数据类型进行转换是具有潜在危险的行为，需要特别小心
        // 故推荐使用static_cast<目标数据类型>(表达式)这样较为显眼的方法，再次声明该方法也会对数据进行截断      
    }

// ========== vector数组 ==========
    // vector初始化
    {
        // vector作为传统数组加强版，需#include <vector>,能动态增删、自动管理数组长度、不退化为指针
        // vector初始化
        vector<int> v1;
        vector<int> v2{}; // 标准零初始化

        // ()和{}在定义时有区别,()初始化接近于填入规格(数量,初始值)而非直接填入数组实际内容
        vector<int> v3{ 5 }; // 初始化为5
        vector<int> v4(5); // 初始化为5个0

        vector<int> v5{ 5,0 }; // 初始化为5,0
        vector<int> v6(5, 0); // 初始化为5个0
    }

    // vector访问、遍历、尾部添加删除、清空、判断是否为空、获取数组长度
    {
        cout << "vector常见操作测试：" << '\n';

        // vector用 数组名[下标] 来访问
        vector<int> v1{ 12 };
        cout << "v1用下标索引0结果为：" << v1[0] << '\n';

        // 配合range-for来遍历
        vector<int> v2{ 12,2312,4432,53 };

        cout << "v2range-for遍历结果为：" << '\n';
        for (int i : v2)
        {
            cout << i << ' ';
        }
        cout << '\n';

        // push_back尾部添加，pop_back尾部删除，clear清空，empty判断是否为空，size获取当前长度
        cout << "零初始化数组v3" << '\n';
        vector<int> v3{};
        bool isEmpty = false;

        cout << "若empty返回值为true则会输出v3长度" << ' ';
        isEmpty = v3.empty(); // empty会检测当前数组是否为空，为空则返回true
        if (isEmpty)
        {
            cout << "v3当前数组长度为：" << v3.size() << '\n';
        }

        // vector甚至支持中部添加，但尾部添加尾部删除对性能影响很小，这些内容暂不了解
        v3.push_back(10); // push_back仅支持单个修改
        v3.push_back(20);
        v3.push_back(30);
        cout << "自尾部添加10、20、30后数组长度为：" << v3.size() << ' ' << "当前数组内容为：";
        for (int i : v3)
        {
            cout << i << ' '; // 由此可见push_back自尾部添加
        }
        cout << '\n';

        v3.pop_back();
        v3.pop_back();
        cout << "进行两次pop_back后数组长度为：" << v3.size() << ' ' << "当前数组内容为：";
        for (int i : v3)
        {
            cout << i << ' ';
        }
        cout << '\n';

        isEmpty = v3.empty();
        if (!isEmpty)
        {
            cout << "如果当前数组不为空，则输出当前当前语句" << '\n';
        }

        v3.clear();
        isEmpty = v3.empty();
        if (isEmpty)
        {
            cout << "执行.clear，若成功则输出当前语句" << '\n';
        }

        cout << "测试结束" << '\n';
    }
    return 0;
}