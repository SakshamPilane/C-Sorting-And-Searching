#include <stdio.h>

void bsearch(int arr[], int num, int n, int i, int low, int high, int mid)
{
    mid = low + (high - low) / 2;
    if (arr[mid] == num)
    {
        printf("Number %d Found at %d position", num, mid+1);
        return;
    }
    if (arr[mid] < num)
    {
        low = mid + 1;
    }
    if (arr[mid] > num)
    {
        high = mid - 1;
    }
    if (low>high)
    {
        printf("Not Found");
    }
    else if (low<=high)
    {
        bsearch(arr,num,n,i+1,low,high,mid);
    }
}

void printArray(int *arr, int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void bubble_sort(int *arr,int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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
    int low=0, high=n-1, mid;
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr,n);
    printArray(arr,n);
    printf("Search A Number: ");
    scanf("%d", &num);
    bsearch(arr, num, n, 0, low, high, mid);
    return 0;
}