#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxAns = nums[0];
        for (const auto &x : nums)
        {
            //记录当前长度（从0开始到i的长度）的最大和为多少
            pre = max(x, x + pre);
            //更新最大值
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

int main(int argc, char **argv)
{
    int n = 332;
    Solution s = Solution();

    cout << 'a' << endl;

    return 0;
}
