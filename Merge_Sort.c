#include <stdio.h>

void printArray(int *arr, int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Merging(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n = (high - low + 1);
    int arrT[n];
    for (i = low, j = mid + 1, k = 0; i <= mid, j <= high;)
    {
        if (arr[i] < arr[j])
        {
            arrT[k++] = arr[i++];
        }
        else
        {
            arrT[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        arrT[k++] = arr[i++];
    }
    while (j <= high)
    {
        arrT[k++] = arr[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = arrT[k];
    }
    printArray(arr + low, n);
}

void Sorting(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        Sorting(arr, low, mid);
        Sorting(arr, mid + 1, high);
        Merging(arr, low, mid, high);
    }
}

int main()
{
    int n;

    // Input for array
    printf("How many elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements for the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    Sorting(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}