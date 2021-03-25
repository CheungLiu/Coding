#include <iostream>
#include <vector>
using namespace std;

// 在单词 A 中插入一个字符：如果我们知道 horse 到 ro 的编辑距离为 a，
// 那么显然 horse 到 ros 的编辑距离不会超过 a + 1。这是因为我们可以
// 在 a 次操作后将 horse 和 ro 变为相同的字符串，只需要额外的 1 次操
// 作，在单词 A 的末尾添加字符 s，就能在 a + 1 次操作后将 horse 和 ro 变
// 为相同的字符串；(意思就是原本A=horse，添加一个s为A=horses)

// 在单词 B 中插入一个字符：如果我们知道 hors 到 ros 的编辑距离为 b，
// 那么显然 horse 到 ros 的编辑距离不会超过 b + 1，原因同上；

// 修改单词 A 的一个字符：如果我们知道 hors 到 ro 的编辑距离为 c，
// 那么显然 horse 到 ros 的编辑距离不会超过 c + 1，原因同上。

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        if (n * m == 0)
        {
            return n + m;
        }

        int D[n + 1][m + 1];
        // 边界状态初始化
        for (int i = 0; i < n + 1; i++)
        {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++)
        {
            D[0][j] = j;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                {
                    left_down += 1;
                }
                D[i][j] = min(left, min(down, left_down));
            }
        }
        return D[n][m];
    }
};
int main(int argc, char **argv)
{
    Solution obj = Solution();
    string s1("intention");
    string s2("execution");
    cout << obj.minDistance(s1, s2) << endl;

    return 0;
}
