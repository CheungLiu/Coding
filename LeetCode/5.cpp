#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; l++)
        {
            for (int i = 0; i + l < n; i++)
            {
                int j = i + l;
                if (l == 0)
                {
                    dp[i][j] == 1;
                }
                else if (l == 1)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                }
                if (dp[i][j] && ans.size() < l + 1)
                {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution s = Solution();
    string str = "ababa";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}
