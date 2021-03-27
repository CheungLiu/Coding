#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
int longestPalindromeSubseq(string A)
{
    int n = A.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    // for (int i = 1; i <= n; ++i)
    // {
    //     dp[i][i] = 1;
    // }
    for (int i = n; i >= 1; --i)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j <= n; ++j)
        {
            if (A[i - 1] == A[j - 1])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[1][n];
}

int main()
{
    cout << longestPalindromeSubseq(
                "abc1234321ab")
         << endl;
    return 0;
}