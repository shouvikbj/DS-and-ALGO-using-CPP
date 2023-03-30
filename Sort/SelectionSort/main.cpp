#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void selectionsort(int arr[], int n)
{
    int i, j, min_index;

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
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
    int arr[] = {5, 4, 1, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, n);
    printArray(arr, n);
    return 0;
}
