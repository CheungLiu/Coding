#include <iostream>
#include <vector>
using namespace std;

void display(int array[], int size);

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
    // InsertSort(array, size);
    display(array, size);
    return 0;
}
