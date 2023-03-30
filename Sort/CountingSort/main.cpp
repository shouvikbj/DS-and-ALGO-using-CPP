#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int getmax(int array[], int size)
{
    int max = array[1];
    for (int i = 2; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void countSort(int *array, int size)
{
}

int main()
{
    int arr[] = {5, 3, 2, 3, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    printArray(arr, n);
    return 0;
}