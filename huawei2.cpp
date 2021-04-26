#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <stack>
using namespace std;

int number(vector<int> &vec)
{
    int length = vec.size();
    if (length == 0)
    {
        return 0;
    }
    int dp[length][length];
    int vaule[length];
    vaule[0] = 1;
    int minPath = INT_MAX;
    memset(dp, 0, sizeof(dp));
    int i = 0, j = 0, k = 0;
    for (i = 0; i < length; ++i)
    {
        for (j = i; j <= vec[i] + i && j < length; ++j)
        {
            dp[i][j] = 1;
        }
    }
    for (i = 0; i < length; ++i)
    {

        for (j = i + 1; j <= i; ++j)
        {
            vaule[i] =min()
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {2, 3, 1, 1};
    cout << number(vec) << endl;
    return 0;
}