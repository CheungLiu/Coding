#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        //全初始化为0
        vector<int> vis(26), num(26);
        for (char ch : s)
        {
            num[ch - 'a']++;
        }
        string stk;
        for (auto ch : s)
        {
            if (!vis[ch - 'a'])
            {
                //非空，而且栈顶元素大于S[i]
                while (!stk.empty() && stk.back() > ch)
                {
                    if (num[stk.back() - 'a'] > 0)
                    {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }
                }
                //前面不满足，则进栈，设为可见
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            //因为当前ch元素是一定会进栈的，至于后面会不会在while里面被弹出，不管
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};

int main(int argc, char **argv)
{
    //cbacdcbc
    string str = "cbacdcbc";
    Solution s = Solution();
    cout << s.removeDuplicateLetters(str) << endl;

    return 0;
}
