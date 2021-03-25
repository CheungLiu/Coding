#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (p[i - 1] == '*')
            {
                dp[0][i] = true;
            }
            else
            {
                //在 j 大于模式 p 的开头出现的星号字符个数之后，值恒为假
                break;
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char **argv)
{
    Solution obj = Solution();
    string s("acdcb");
    string p("a*c?b");
    cout << obj.isMatch(s, p) << endl;
    return 0;
}
