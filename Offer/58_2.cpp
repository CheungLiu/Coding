#include <iostream>
#include <cstring>
using namespace std;

void Reverse(char *pBegin, char *pEnd)
{
    if (pBegin == nullptr || pEnd == nullptr)
        return;

    while (pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++, pEnd--;
    }
}

char *LeftRotateString(char *pStr, int n)
{
    if (pStr != nullptr)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if (nLength > 0 && n > 0 && n < nLength)
        {
            char *pFirstStart = pStr;
            char *pFirstEnd = pStr + n - 1;
            char *pSecondStart = pFirstEnd + 1;
            char *pSecondEnd = pFirstStart + nLength - 1;

            Reverse(pSecondStart, pSecondEnd);
            Reverse(pFirstStart, pFirstEnd);
            Reverse(pFirstStart, pSecondEnd);
        }
    }
    return pStr;
}

// ====================测试代码====================
void Test(const char *testName, char *input, int num, const char *expectedResult)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    char *result = LeftRotateString(input, num);

    if ((input == nullptr && expectedResult == nullptr) || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}