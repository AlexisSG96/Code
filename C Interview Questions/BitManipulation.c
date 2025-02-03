#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#pragma region Prototypes and Questions
/*
1. Bit Manipulation
Problem: Write a function to check if a number is a power of two.
Concepts: Bitwise AND, bit shifting.
Example: Given an integer n, return true if n is a power of two.
*/
void test_is_power_of_two(int);
void test_is_power_of_two_args(int, ...);
bool is_power_of_two(int);
#pragma endregion

int main(void)
{
    test_is_power_of_two(2);
    test_is_power_of_two_args(4,6,8,10,0);
}

#pragma region Bit Manipulation
void test_is_power_of_two(int n)
{
    int test_value = n;
    bool power_of_two = is_power_of_two(test_value);
    printf("Is %d a power of two? %s\n", test_value, power_of_two ? "Yes" : "No");
}

void test_is_power_of_two_args(int n, ...) {
    va_list args;
    va_start(args, n);

    // Process the first value explicitly
    bool is_power = is_power_of_two(n);
    printf("Is %d a power of two? %s\n", n, is_power ? "Yes" : "No");

    // Process the remaining values
    int current_value;
    while ((current_value = va_arg(args, int)) != 0) {
        is_power = is_power_of_two(current_value);
        printf("Is %d a power of two? %s\n", current_value, is_power ? "Yes" : "No");
    }

    va_end(args);  // Clean up the argument list
}

// 00000000
// 00000001
// 00000010
// 00000100
// 00001000
// 00010000
// 00100000
// 01000000
// 10000000

// 00010000
// 00001111

bool is_power_of_two(int n)
{
    // 0b0010 2
    // 0b1110 -2

    // 0b0011 3
    // 0b1101 -3 With & its 0b0010 2

    // return (n > 0 && (n & -n) == n ); // 2's CCompliment
    return (n > 0 && (n & (n - 1)) == 0);
}
#pragma endregion

// 0b0111
//& b0001
//= b0001

// 0b1000
//& b0001
//= b0000
//>>b0100
//& b0001
//= b0000