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

void bsearch(int arr[], int num, int n)
{
    int low = 0, high = n - 1, mid, flag = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == num)
        {
            printf("Number %d Found at %d position", num, mid + 1);
            flag = 1;
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
    if (!flag)
    {
        printf("Not Found");
    }
}

void bubble_sort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, num;
    printf("How Many Elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printArray(arr, n);
    printf("Search A Number: ");
    scanf("%d", &num);
    bsearch(arr, num, n);
    return 0;
}