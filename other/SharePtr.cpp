#include <iostream>
#include <memory>
using namespace std;

int main()
{
    string *s1 = new string("s1");
    shared_ptr<string> ps1(s1);
    shared_ptr<string> ps2;
    ps2 = ps1;
    cout << ps1.use_count() << endl;
    cout << ps2.use_count() << endl; //2
    cout << ps1.unique() << endl;    //0

    string *s3 = new string("s3");
	shared_ptr<string> ps3(s3);

    return 0;
}