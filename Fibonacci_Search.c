#include <stdio.h>

// Function to print the array
void printArray(int arr[], int n)
{
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the minimum of two numbers
int min(int x, int y)
{
    return (x <= y) ? x : y;
}

// Fibonacci search function
int fibSearch(int arr[], int n, int num)
{
    int fibMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMm2 + fibMm1; // m'th Fibonacci

    // fibM stores the smallest Fibonacci number greater than or equal to n
    while (fibM < n)
    {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }

    int offset = -1;

    // While there are elements to be inspected
    while (fibM > 1)
    {
        int i = min(offset + fibMm2, n - 1);

        // If num is greater than the value at index i, cut the subarray from offset to i
        if (arr[i] < num)
        {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        }
        // If num is less than the value at index i, cut the subarray after i+1
        else if (arr[i] > num)
        {
            fibM = fibMm2;
            fibMm1 -= fibMm2;
            fibMm2 = fibM - fibMm1;
        }
        // Element found
        else
        {
            return i;
        }
    }

    // Comparing the last element with num
    if (fibMm1 && arr[offset + 1] == num)
    {
        return offset + 1;
    }

    // Element not found
    return -1;
}

int main()
{
    int n;
    printf("How Many Elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printArray(arr, n);

    int num;
    printf("Search a Number: ");
    scanf("%d", &num);

    int result = fibSearch(arr, n, num);
    if (result != -1)
    {
        printf("Element %d found at index %d\n", num, result);
    }
    else
    {
        printf("Element %d not found\n", num);
    }

    return 0;
}