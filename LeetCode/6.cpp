#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (auto c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
            {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for (auto row : rows)
            ret += row;
        return ret;
    }
};

int main(int argc, char **argv)
{
    string str = "LEETCODEISHIRING";
    int numRows = 4;
    Solution s = Solution();
    cout << s.convert(str, numRows) << endl;

    return 0;
}
