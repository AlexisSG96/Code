

#pragma region Prototypes and Questions

#pragma endregion

int main(void)
{
    return 0;
}

#pragma region Bit Manipulation
// Summary of Use Cases by Application:
// Check if a number is even or odd:	            &
// Toggle specific bits:	                        ^
// Isolate or modify specific bits:                 &, `
// Multiply or divide by powers of 2:	            <<, >>
// Check if a number is a power of two:	            &
// Count bits set in a number	Loop with & and:    >>
#pragma region Bitwise AND (&)
// Compares each bit of two numbers; the result is 1 only if both corresponding bits are 1.
void bitwise_AND_example()
{
    int a = 6;          // 0110
    int b = 3;          // 0011
    int result = a & b; // 0010 (2 in decimal)
}
// The least significant bit (LSB) of odd numbers is 1, and for even numbers, it’s 0.
void bitwise_AND_use_case(int x)
{
    if (x & 1)
    {
        printf("Odd\n");
    }
    else
    {
        printf("Even\n");
    }
}
void bitwise_AND_clear_bits()
{
    int x = 0b1011; // Clear bit 1
    int mask = 0b1101;
    x &= mask; // Result: 0b1001
}
#pragma endregion
#pragma region Bitwise OR (|)
// Compares each bit of two numbers; the result is 1 if either of the corresponding bits is 1.
void bitwise_OR_example()
{
    int a = 6;          // 0110
    int b = 3;          // 0011
    int result = a | b; // 0111 (7 in decimal)
}
void bitwise_OR_use_case()
{
    int x = 0b1010; // Set bit 1
    int mask = 0b0001;
    x |= mask; // Result: 0b1011
}
#pragma endregion
#pragma region Bitwise XOR (^)
// Compares each bit of two numbers; the result is 1 if the corresponding bits are different.
void bitwise_XOR_example()
{
    int a = 6;          // 0110
    int b = 3;          // 0011
    int result = a ^ b; // 0101 (5 in decimal)
}
void bitwise_XOR_use_case()
{
    // Toggling specific bits
    int x = 0b1010; // Toggle bit 1
    int mask = 0b0001;
    x ^= mask; // Result: 0b1011

    // Assume only 1 unique value and every other number appears twice
    int arr[] = {2, 3, 2, 4, 4};
    int unique = 0;
    for (int i = 0; i < 5; i++)
    {
        unique ^= arr[i];
    }
    printf("Unique element: %d\n", unique); // Output: 3
}
#pragma endregion
#pragma region Bitwise NOT (~)
// Inverts all bits of a number (0 becomes 1, and 1 becomes 0).
void bitwise_NOT_example()
{
    int a = 6;       // 0110
    int result = ~a; // 1001 (in 4-bit representation, -7 in signed integer)
}
void bitwise_NOT_use_case()
{
    // Flipping all bits (1’s complement):
    int x = 0b1010;
    int flipped = ~x; // Result: Depends on integer size and representation

    // Creating masks:
    int mask = ~(1 << 3); // Creates a mask with all bits set except bit 3
}
#pragma endregion
#pragma region Bitwise Left Shift (<<)
void bitwise_LEFT_SHIFT_example()
{
    // Shifts bits to the left, filling the rightmost bits with 0.
    int a = 3;           // 0011
    int result = a << 2; // 1100 (12 in decimal)
}
void bitwise_LEFT_SHIFT_use_case()
{
    // Multiplying by powers of 2:
    int x = 5;           // Multiply by 4
    int result = x << 2; // 20
}
#pragma endregion
#pragma region Bitwise Right Shift (>>)
void bitwise_RIGHT_SHIFT_example()
{
    // Shifts bits to the right. For signed integers, behavior depends on whether the number is signed (arithmetic shift) or unsigned (logical shift).
    int a = 12;          // 1100
    int result = a >> 2; // 0011 (3 in decimal)
}
void bitwise_RIGHT_SHIFT_use_case()
{
    // Dividing by powers of 2
    int x = 20;          // Divide by 4
    int result = x >> 2; // 5

    // Extracting individual bits:
    int x = 0b1010;
    int bit = (x >> 2) & 1; // Extract bit 2
}
#pragma endregion
#pragma endregion