#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// int LIS(vector<int> &arr)
// {
//     if (arr.size() == 0)
//     {
//         return 0;
//     }
//     int length = arr.size();
//     // int dp[length];
//     //初始化数组dp的每个值为1，memset只能填充0和-1，因为其是按字节填充
//     // memset(dp, 1, sizeof(dp));
//     vector<int> dp(length);
//     // fill_n(dp.begin(), length, 1);
//     fill(dp.begin(), dp.end(), 1);
//     int max_length = INT_MIN;
//     for (int i = 1; i < length; ++i)
//     {
//         for (int j = 0; j < i; ++j)
//         {
//             if (arr[i] >= arr[j])
//             {
//                 //dp[i]表示数组的前i个元素构成的最长上升子序列
//                 dp[i] = max(dp[i], dp[j] + 1);
//                 max_length = max(max_length, dp[i]);
//             }
//         }
//     }
//     return max_length;
// }

//二分法
int LIS(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return -1;
    }
    vector<int> vec;
    int index = 0;
    for (auto item : arr)
    {
        if (vec.empty() || vec.back() < item)
        {
            vec.emplace_back(item);
        }
        else
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                if (vec[i] > item)
                {
                    vec[i] = item;
                    break;
                }
            }
        }
    }
    return vec.size();
}

int main()
{
    vector<int> arr = {1,2,8,6,4};
    cout << LIS(arr) << endl;
    cout << "end" << endl;
    return 0;
}