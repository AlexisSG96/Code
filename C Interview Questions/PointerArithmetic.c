#include <stdio.h>

#pragma region Prototypes and Questions
/*
2. Pointer Arithmetic
Problem: Implement a function that swaps two integers using pointers.
Concepts: Pointer dereferencing, passing by reference.
Example: Write a function swap that takes two integer pointers and swaps their values.
*/
void test_swap_pointer_values(int, int);
void swap_pointer_values(int *, int *);
#pragma endregion

int main(void)
{
    test_swap_pointer_values(1, 5);
    test_swap_pointer_values(5, 10);
}

#pragma region Pointer Arithmetic
void test_swap_pointer_values(int x, int y)
{
    printf("Before Swap: x is %d and y is %d\n", x, y);
    swap_pointer_values(&x, &y);
    printf("After Swap: x is %d and y is %d\n", x, y);
}

void swap_pointer_values(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
#pragma endregion