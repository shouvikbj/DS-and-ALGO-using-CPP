#include <iostream>

using namespace std;

void insertionsort(int arr[], int n)
{
    int i, j, val;
    for (i = 1; i < n; i++)
    {
        val = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = val;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {9, 6, 7, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionsort(arr, n);
    printArray(arr, n);
    return 0;
}
