#include <iostream>

using namespace std;

bool g_InvalidInput = false;

// int FindGreatestSumOfSubArray(int *pData, int nLength)
// {
//     if (pData == nullptr || nLength <= 0)
//     {
//         g_InvalidInput = true;
//         return 0;
//     }
//     g_InvalidInput = false;
//     int nCurSum = 0;
//     int nCurGreatestSum = 0x80000000;
//     for (int i = 0; i < nLength; ++i)
//     {
//         if (nCurSum <= 0)
//         {
//             nCurSum = pData[i];
//         }
//         else
//         {
//             nCurSum += pData[i];
//         }
//         if (nCurSum > nCurGreatestSum)
//         {
//             nCurGreatestSum = nCurSum;
//         }
//     }
//     return nCurGreatestSum;
// }

//方法二
// int FindGreatestSumOfSubArray(const int *pData, int nLength)
// {
//     if (pData == nullptr || nLength <= 0)
//     {
//         g_InvalidInput = true;
//         return 0;
//     }
//     int pre = 0, maxAns = pData[0];
//     for (int i = 0; i < nLength; ++i)
//     {
//         pre = max(pre + pData[i], pData[i]);
//         maxAns = max(maxAns, pre);
//     }
//     return maxAns;
// }

//方法三
struct Status
{
    int lSum, rSum, mSum, iSum;
};

Status pushUp(Status l, Status r)
{
    int iSum = l.iSum + r.iSum;
    int lSum = max(l.lSum, l.iSum + r.lSum);
    int rSum = max(l.rSum + r.iSum, r.rSum);
    int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
    return (Status){lSum, rSum, mSum, iSum};
}

Status _get(int *a, int l, int r)
{
    if (l == r)
    {
        return (Status){a[l], a[l], a[l], a[l]};
    }
    int m = (l + r) >> 1;
    Status lSub = _get(a, l, m);
    Status rSub = _get(a, m + 1, r);
    return pushUp(lSub, rSub);
}

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if (pData == nullptr || nLength <= 0)
    {
        g_InvalidInput = true;
        return 0;
    }
    return _get(pData, 0, nLength - 1).mSum;
}

// ====================测试代码====================
void Test(char *testName, int *pData, int nLength, int expected, bool expectedFlag)
{
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if (result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
