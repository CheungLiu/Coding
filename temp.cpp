#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int LIS(vector<int> &arr)
{
    // write code here
    int length = arr.size();

    if (length == 0)
    {
        return -1;
    }
    vector<int> vec;
    // vector不能数组那样填充元素再push_back
    // fill_n(vec.begin(), length, 1);
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
    vector<int> vec = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    cout << LIS(vec) << endl;
    return 0;
}