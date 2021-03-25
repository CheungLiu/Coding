#include <iostream>
#define cJSON_Raw (1 << 7) /* raw json */

using namespace std;

int main()
{
    cout << cJSON_Raw << endl;
    return 0;
}