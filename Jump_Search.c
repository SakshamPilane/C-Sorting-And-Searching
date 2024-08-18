#include <stdio.h>
#include <math.h>

void printArray(int *arr, int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

int JSearch(int arr[], int n, int num)
{
    int jump = sqrt(n), low = 0, i;
    for (i = 0; i < n; i += jump)
    {
        if (arr[i] == num)
        {
            return i;
        }
        else if (arr[i] > num)
        {
            break;
        }
        else
        {
            low = i;
        }
    }
    for (i = low; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int n, num, index;
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
    index = JSearch(arr, n, num);
    if (index)
    {
        printf("Element %d found at position %d", num, index);
    }
    else
    {
        printf("Element %d not Found", num);
    }
    return 0;
}