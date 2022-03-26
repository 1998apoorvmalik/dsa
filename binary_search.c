#include <stdio.h>
#include <stdlib.h>

// Command to run static test case : gcc binary_search.c -o tmp && cat test_cases.txt | ./tmp && rm tmp
// Command to run dynamic test case: gcc binary_search.c -o tmp && python3 test_cases.py | ./tmp && rm tmp

int binarySearch_iterative(int *array, int left, int right, int target)
{
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (array[middle] == target)
        {
            return middle;
        }
        else if (array[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return -1;
}

int binarySearch_recursive(int *array, int left, int right, int target)
{
    int middle = left + (right - left) / 2;

    if (left > right)
    {
        return -1;
    }

    if (array[middle] == target)
    {
        return middle;
    }

    if (array[middle] > target)
    {
        return binarySearch_recursive(array, left, middle - 1, target);
    }

    return binarySearch_recursive(array, middle + 1, right, target);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int arraySize, target;
        scanf("%d %d", &arraySize, &target);
        int *array = (int *)malloc(sizeof(int) * arraySize);
        printf("\nGiven array is: ");
        for (int i = 0; i < arraySize; i++)
        {
            scanf("%d", &array[i]);
            printf("%d ", array[i]);
        }

        int index1 = binarySearch_iterative(array, 0, arraySize - 1, target);
        int index2 = binarySearch_recursive(array, 0, arraySize - 1, target);

        printf("\n[Binary Search Iterative Method] Index of %d in array of size %d is: %d\n", target, arraySize, index1);
        printf("[Binary Search Recursive Method] Index of %d in array of size %d is: %d\n\n", target, arraySize, index2);
    }
}