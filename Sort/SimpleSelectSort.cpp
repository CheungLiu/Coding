#include <iostream>
#include <vector>
using namespace std;

void display(int array[], int size);
void SelectSort(int A[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(A[i], A[min]);
        }
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
    SelectSort(array, size);
    display(array, size);
    return 0;
}
