#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

vector<int> LIS(vector<int> &arr)
{
    int length = arr.size();
    if (length < 0)
    {
        return arr;
    }
    vector<int> vec;
    vector<int> maxLength;
    vec.emplace_back(arr[0]);
    maxLength.emplace_back(1);
    for (int k = 1; k < length; ++k)
    {
        if (arr[k] > vec.back())
        {
            vec.emplace_back(arr[k]);
            maxLength.emplace_back(vec.size());
        }
        else
        {
            int index = lower_bound(vec.begin(), vec.end(), arr[k]) - vec.begin();
            vec[index] = arr[k];
            maxLength.emplace_back(index + 1);
        }
    }
    // 首先因为在lower_bound的过程中，vec中的元素可能会被会面较小的元素所替换
    // 所以我们需要在maxLength从后往前查找，如果maxLength[i] == j，说明vec[j-1]的值应该是
    // arr[i]对应的值
    // 因为maxLength[i]数组里存放以元素i结尾的最大递增子序列长度
    for (int i = length - 1, j = vec.size(); j > 0; --i)
    {
        // maxLength[i]的值是vec对应值下标+1
        // 也就是说，maxLength最后一个元素=vec最后一个元素的下标+1
        // 等价于maxLength[length-1]=vec.size()
        if (maxLength[i] == j)
        {
            j--;
            vec[j] = arr[i];
        }
    }
    return vec;
}

int main()
{
    vector<int> vec = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    LIS(vec);
    return 0;
}