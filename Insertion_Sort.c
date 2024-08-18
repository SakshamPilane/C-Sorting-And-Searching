#include <stdio.h>

void printArray(int arr[], int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n)
{
    int key = 0,j;
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
    printArray(arr, n);
}

int main()
{
    int n;
    printf("How many elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);

    return 0;
}
