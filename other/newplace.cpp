#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class A
{
public:
    int num1;
    int num2;

public:
    A(int a = 0, int b = 0) : num1(a), num2(b) { cout << "默认构造函数" << endl; };
    A(const A &a) { cout << "拷贝构造函数" << endl; };
    A &operator=(const A &a)
    {
        num1 = a.num1 + 1;
        num2 = a.num2 + 1;
        cout << "赋值构造函数" << endl;
        return *this;
    }
};

int main()
{
    A a(1, 1);
    A a1 = a; //拷贝初始化操作，调用拷贝构造函数
    A b;
    b = a; //赋值操作，对象a中，num1 = 1，num2 = 1；对象b中，num1 = 2，num2 = 2
    return 0;
}
