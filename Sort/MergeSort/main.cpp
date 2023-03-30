#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int s1 = m - l + 1;
    int s2 = r - m;

    int LEFT[s1], RIGHT[s2];

    for (i = 0; i < s1; i++)
    {
        LEFT[i] = arr[l + 1];
    }
    for (j = 0; j < s2; j++)
    {
        RIGHT[j] = arr[m + 1 + j];
    }

    while (i < s1 && j < s2)
    {
        if (LEFT[i] <= RIGHT[j])
        {
            arr[k] = LEFT[i];
            i++;
        }
        else
        {
            arr[k] = RIGHT[j];
            j++;
        }
        k++;
    }

    while (i < s1)
    {
        arr[k] = LEFT[i];
        i++;
        k++;
    }
    while (j < s2)
    {
        arr[k] = RIGHT[j];
        j++;
        k++;
    }
}

void msort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r - 1) / 2;

        msort(arr, l, m);
        msort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
