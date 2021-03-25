#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    struct Status
    {
        int lSum, rSum, mSum, iSum;
    };
    Status pushp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, r.lSum + l.iSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return Status{lSum, rSum, mSum, iSum};
    }

    Status get(vector<int> &a, int l, int r)
    {
        if (l == r)
        {
            return (Status){a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushp(lSub, rSub);
    }

    int maxSubArray(vector<int> &nums)
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

int main(int argc, char **argv)
{
    int n = 332;
    Solution s = Solution();

    cout << 'a' << endl;

    return 0;
}
