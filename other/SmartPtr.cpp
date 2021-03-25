#include <iostream>
#include <memory>
using namespace std;

class B; //声明
class A
{
public:
    shared_ptr<B> pb_;
    ~A()
    {
        cout << "A delete\n";
    }
};

class B
{
public:
    shared_ptr<A> pa_;
    ~B()
    {
        cout << "B delete\n";
    }
};

void fun()
{
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());
    cout << pb.use_count() << endl; //1
    cout << pa.use_count() << endl; //1
    pb->pa_ = pa;
    pa->pb_ = pb;
    cout << pb.use_count() << endl; //2
    cout << pa.use_count() << endl; //2
}

int main()
{
    fun();
    return 0;
}