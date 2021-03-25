#include <iostream>
using namespace std;

class Father
{
public:
   void fun()
   {
      cout << "I am father!" << endl;
   }
};
class Son : public Father
{
public:
   void fun()
   {
      cout << "I am son!" << endl;
   }
};

int main()
{
   Son son;
   Father *Pfather = &son;
   Pfather->fun();
   system("pause");
   return 0;
}