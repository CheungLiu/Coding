#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int num[3] = {0};
        num[0] = 0, num[1] = 0, num[2] = 1;
        for (int i = 1; i <= n; i++)
        {
            num[0] = num[1];
            num[1] = num[2];
            num[2] = num[1] + num[0];
        }
        return num[2];
    }
};

int main(int argc, char **argv)
{
    Solution s = Solution();
    cout << "1+3" << endl;

    return 0;
}
