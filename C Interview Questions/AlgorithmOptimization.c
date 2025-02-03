#include <stdio.h>
#include <stddef.h>

#pragma region Prototypes and Questions
/*
8. Algorithm Optimization
Problem: Given a sorted array, write a function that finds the first duplicate element.
Concepts: Sorting, search algorithms, optimization.
Example: Given a sorted array, return the first repeated element.
*/
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
void test_search_first_repeated(int*, int);
int search_first_repeated(int*, int);
#pragma endregion

int main(void)
{
    int arr[] = {0, 1, 2, 4, 6, 7, 7, 9, 10};
    int arr_2[] = {};
    int arr_3[] = { 0 };
    int arr_4[] = { 0, 1, 2};

    test_search_first_repeated(arr, ARRAY_SIZE(arr));
    test_search_first_repeated(arr_2, ARRAY_SIZE(arr_2));
    test_search_first_repeated(arr_3, ARRAY_SIZE(arr_3));
    test_search_first_repeated(arr_4, ARRAY_SIZE(arr_4));
    
    return 0;
}

#pragma region Algorithim Optimization
void test_search_first_repeated(int * arr, int size)
{
    int first_repeated = search_first_repeated(arr, size);
    if(first_repeated != -1)
        printf("First repeated number is: %d\n", first_repeated);
    else
        printf("No repeated number found.\n");
}

int search_first_repeated(int *arr, int size)
{
    if(size <= 1)
    {
        printf("Array of size 1 or less provided.\n");
        return -1;
    }

    for (int i = 1; i < size; i++)  // Start from the second element
    {
        if(arr[i] == arr[i - 1])  // Compare adjacent elements
        {
            return arr[i];  // Return the first duplicate element
        }
    }

    return -1;  // No duplicates found
}
#pragma endregion

