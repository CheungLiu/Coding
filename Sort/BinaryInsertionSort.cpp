#include <iostream>
#include <vector>
using namespace std;
void display(int array[], int size);
void InsertSort(int A[], int n)
{
    int i, j, low, hight, mid, temp;
    for (i = 1; i < n; ++i)
    {
        temp = A[i];
        low = 0, hight = i - 1;
        while (low <= hight)
        {
            mid = (low + hight) >> 1;
            if (A[mid] > temp)
            {
                hight = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= hight + 1; --j)
        {
            A[j + 1] = A[j];
        }
        A[hight + 1] = temp;
        // display(A, n);
    }
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}
int main(int argc, char **argv)
{

    int array[] = {49, 38, 65, 97, 76, 13, 27};
    int size = sizeof(array) / sizeof(int);

    //打印原始数据
    cout << size << endl;
    // display(array, size);
    InsertSort(array, size);
    display(array, size);
    return 0;
}
