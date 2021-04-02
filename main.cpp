#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
class SingleTon
{
private:
    static SingleTon *single;
    SingleTon() {}
    ~SingleTon() {}

public:
    SingleTon(SingleTon &sin) = delete;
    SingleTon &operator=(SingleTon &sin) = delete;
    SingleTon *getInstance()
    {
        if (single == nullptr)
        {
            single = new SingleTon();
        }
    }
    void Print()
    {
        printf("%X\n", single);
    }
};

int main()
{
    cout << "end" << endl;
    return 0;
}