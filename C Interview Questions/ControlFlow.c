#include <stdio.h>

#pragma region Prototypes and Questions
/*
4. Control Flow
Problem: Write a function that finds the maximum number in an array of integers.
Concepts: Arrays, iteration, comparison.
Example: Given an array of integers, return the largest integer in the array.
*/
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
void test_find_largest_number(int*, int);
int find_largest_number(int*, int);
#pragma endregion

int main(void)
{
    int arr[] = {0, 1, 2, 5, 8 };
    int arr_2[0];
    test_find_largest_number(arr, ARRAY_SIZE(arr));
    test_find_largest_number(arr_2, ARRAY_SIZE(arr_2));
}

#pragma region Control Flow
void test_find_largest_number(int* arr, int size)
{
    if(size == 0)
    {
        printf("Array of size 0 given.");
    }
    else
    {
        int largest_number = find_largest_number(arr, size);
        printf("Largest number in array is: %d\n", largest_number); 
    }
}

// #define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))
int find_largest_number(int* arr, int size)
{
    if(size == 0)
        return -1;

    int largest_number = arr[0];
    for (int i = 1; i < size; i++)
    {
        if(arr[i] > largest_number)
        {
            largest_number = arr[i];
        }
    }

    return largest_number;
}
#pragma endregion