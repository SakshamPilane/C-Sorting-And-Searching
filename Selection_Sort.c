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

void Selection_sort(int arr[], int count)
{
    int temp = 0, min;
    for (int i = 0; i < count; i++)
    {
        min = i;
        for (int j = i + 1; j < count; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        printArray(arr, count);
    }
    printArray(arr, count);
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

    Selection_sort(arr, n);

    return 0;
}
