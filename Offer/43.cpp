#include <iostream>
#include <math.h>
using namespace std;

// ====================方法一====================
int NumberOf1(unsigned int n);

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
    int number = 0;

    for (unsigned int i = 1; i <= n; ++i)
        number += NumberOf1(i);

    return number;
}

int NumberOf1(unsigned int n)
{
    int number = 0;
    while (n)
    {
        if (n % 10 == 1)
            number++;

        n = n / 10;
    }

    return number;
}

// ====================方法二====================
int PowerBase10(unsigned int n)
{
    int result = 1;
    for (unsigned int i = 0; i < n; ++i)
    {
        result *= 10;
    }
    return result;
}
int NumberOf1(const char *strN)
{
    if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;
    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));
    if (length == 1 && first == 0)
    {
        return 0;
    }
    if (length == 1 && first > 0)
    {
        return 1;
    }
    int numFirstDigit = 0;
    if (first > 1)
    {
        numFirstDigit =
    }
}

int NumberOf1Between1AndN_Solution2(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    char strN[50];
    sprintf(strN, "%d", n);
    return NumberOf1(strN);
}

int main()
{
    char strN[50];
    sprintf(strN, "%d", 31234);
    cout << *strN << endl;
    int array[] = {49, 38, 65, 97, 23, 22, 76, 1, 5, 8, 2, 0, -1, 22};
    return 0;
}