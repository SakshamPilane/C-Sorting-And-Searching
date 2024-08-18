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

int BSearch(int arr[], int low, int high, int num)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num)
        {
            return mid;
            break;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}

void bubble_Sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void ExpSearch(int arr[], int n, int num)
{
    int i = 1, index = 0;
    if (arr[0] == num)
    {
        printf("Number %d Found at Position %d\n", num, 0);
    }

    while (i <= n && arr[i] < num)
    {
        i *= 2;
    }
    int high = (i < n) ? i : n - 1;
    index = BSearch(arr, i / 2, high, num);
    if (index)
    {
        printf("Number %d Found at Position %d\n", num, index);
    }
    else
    {
        printf("Number %d Not found", num);
    }
}

int main()
{
    int index;
    int num, i, n;
    printf("How Many Elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_Sort(arr, n);
    printArray(arr, n);
    printf("Search a Number: ");
    scanf("%d", &num);
    ExpSearch(arr, n, num);
    return 0;
}