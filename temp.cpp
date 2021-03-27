#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if (numbers.size() == 0)
    {
        return 0;
    }
    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < numbers.size(); ++i)
    {
        if (times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else
        {
            if (result == numbers[i])
            {
                ++times;
            }
            else
            {
                --times;
            }
        }
    }
    int num = 0;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == result)
        {
            ++num;
        }
    }
    if (2 * num > numbers.size())
    {
        return result;
    }
    return 0;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 9}, {8, 1, 3, 4}, {5, 0, 6, 1}, {8, 8, 4, 0}};

    return 0;
}