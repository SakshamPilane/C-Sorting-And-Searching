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

void tsearch(int arr[], int num, int n)
{
    int low = 0, mid1, mid2, high = n - 1;
    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;
        if (arr[mid1] == num)
        {
            printf("Number %d Found at %d Position", num, mid1);
            break;
        }
        else if (arr[mid2] == num)
        {
            printf("Number %d Found at %d Position", num, mid2);
            break;
        }
        else
        {
            if (num < arr[mid1])
            {
                high = mid1 - 1;
            }
            else if (num > arr[mid2])
            {
                low = mid2 + 1;
            }
            else
            {
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }
    }
    if (low > high)
    {
        printf("Number %d Not Found\n", num);
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
    tsearch(arr, num, n);
    return 0;
}