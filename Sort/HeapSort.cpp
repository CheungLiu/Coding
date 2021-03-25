#include <iostream>
#include <vector>
using namespace std;

void display(int array[], int size);

void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k];
    //如果i>len，就说明k是叶节点，不用调整。
    for (int i = 2 * k; i <= len; i *= 2)
    {
        //如果要比较结点k的右结点，就得有条件i<len。如果不满足，就说明k只有左结点
        if (i < len && A[i] < A[i + 1])
        {
            ++i;
        }
        if (A[0] >= A[i])
        {
            break;
        }
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildMaxHeap(int A[], int len)
{
    for (int i = (len >> 1); i > 0; --i)
    {
        HeadAdjust(A, i, len);
    }
}
void BuildSort(int A[], int len)
{
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; --i)
    {
        swap(A[i], A[1]);
        HeadAdjust(A, 1, i - 1);
    }
}
void display(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}
int main(int argc, char **argv)
{

    int array[] = {-10000, -200000, -38, 65, 970, 23, 22, 76, 1, 5, -800, 2, 0, -1, 22};
    int size = sizeof(array) / sizeof(int);

    //打印原始数据
    cout << size << endl;
    // display(array, size);
    BuildSort(array, size - 1);
    display(array, size);
    return 0;
}
