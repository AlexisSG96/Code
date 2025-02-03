#include <stdio.h>
#include <string.h>

#pragma region Prototypes and Questions
/*
5. Edge Case Handling
Problem: Write a function to reverse a string in place.
Concepts: String manipulation, array indexing.
Example: Given a string, reverse it in place without using additional memory.
*/
void test_reverse(char*);
void reverse(char*, int size);
#pragma endregion

int main(void)
{
    char str[] = "Hello World!";
    test_reverse(str);

    char str_2[] = "This is my program!";
    test_reverse(str_2);

    char str_3[] = "racecar";
    test_reverse(str_3);
}

#pragma region Edge Case Handling
void test_reverse(char * str)
{
    reverse(str, strlen(str));
    printf("New reverse string: %s\n", str);
}

void reverse(char * str, int size)
{
    if(size == 0)
        return;
    
    int start = 0;
    int end = size - 1;
    
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}
#pragma endregion