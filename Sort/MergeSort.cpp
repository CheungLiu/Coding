#include <iostream>
#include <vector>
using namespace std;

void display(int array[], int size);
//分配的空间大小是1也可以
int *B = (int *)malloc((7) * sizeof(int));
void merge(int A[], int low, int mid, int hight)
{
    int i, j, k;

    for (k = low; k <= hight; ++k)
        B[k] = A[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= hight; ++k)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = B[j++];
        }
    }
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= hight)
    {
        A[k++] = B[j++];
    }
}

void mergesort(int a[], int low, int hight)
{
    if (low < hight)
    {
        int mid = (low + hight) >> 1;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, hight);
        merge(a, low, mid, hight);
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

    int array[] = {49, 38, 65, 970, 76, -13, 27};
    int size = sizeof(array) / sizeof(int);

    //打印原始数据
    cout << size << endl;
    // display(array, size);
    mergesort(array, 0, size - 1);
    display(array, size);
    return 0;
}