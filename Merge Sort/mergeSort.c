#include <stdio.h>

void merge(int arr[], int l, int m, int r, int *passCount, int *compareCount)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        (*compareCount)++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    (*passCount)++;
}

void mergeSort(int arr[], int l, int r, int *passCount, int *compareCount)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, passCount, compareCount);
        mergeSort(arr, m + 1, r, passCount, compareCount);
        merge(arr, l, m, r, passCount, compareCount);
    }
}

int main()
{
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int passCount = 0;
    int compareCount = 0;
    mergeSort(arr, 0, n - 1, &passCount, &compareCount);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nTotal number of passes: %d\n", passCount);
    printf("Total number of comparisons: %d\n", compareCount);
    return 0;
}