#include <stdio.h>

#define TO_BIG_ENDIAN_16(x) ((x >> 8) & 0xFF) | ((x & 0xFF) << 8)
#define TO_LITTLE_ENDIAN_16(x) ((x >> 8) & 0xFF) | ((x & 0xFF) << 8)

// Macro for Big Endian Conversion
#define TO_BIG_ENDIAN_32(num)   \
    ((num & 0xFF000000) >> 24 | \
     (num & 0x00FF0000) >> 8 |  \
     (num & 0x0000FF00) << 8 |  \
     (num & 0x000000FF) << 24)

// Macro for Little Endian Conversion
#define TO_LITTLE_ENDIAN_32(num) \
    ((num & 0xFF000000) >> 24 |  \
     (num & 0x00FF0000) >> 8 |   \
     (num & 0x0000FF00) << 8 |   \
     (num & 0x000000FF) << 24)

#define TO_BIG_ENDIAN_64(x) ((x >> 56) & 0xFF) | ((x >> 40) & 0xFF00) | ((x >> 24) & 0xFF0000) | ((x >> 8) & 0xFF000000) | \
                                ((x << 8) & 0xFF00000000) | ((x << 24) & 0xFF0000000000) | ((x << 40) & 0xFF000000000000) | ((x << 56) & 0xFF00000000000000)
#define TO_LITTLE_ENDIAN_64(x) ((x >> 56) & 0xFF) | ((x >> 40) & 0xFF00) | ((x >> 24) & 0xFF0000) | ((x >> 8) & 0xFF000000) | \
                                   ((x << 8) & 0xFF00000000) | ((x << 24) & 0xFF0000000000) | ((x << 40) & 0xFF000000000000) | ((x << 56) & 0xFF00000000000000)

void check_endianness()
{
    int x = 1;
    char *ptr = (char *)&x;     // 1. `ptr` points to the first byte of `x`.
    char value = *((char *)&x); // 2. `value` stores the first byte of `x` by dereferencing a casted pointer.
    char data = x;              // 3. `data` stores the **entire value** of `x`, truncated to a `char`.

    if (*ptr == 1)
    {
        printf("System uses little-endian.\n");
    }
    else
    {
        printf("System uses big endian.\n");
    }
}

// 0x12 34 56 78
// 0x78 56 34 12
// Function to reverse the endianness of a 32-bit integer
int reverse_endianness(int num)
{
    return ((num & 0xFF000000) >> 24) | // Move MSB to LSB
           ((num & 0x00FF0000) >> 8) |  // Move second byte to second last
           ((num & 0x0000FF00) << 8) |  // Move third byte to second
           ((num & 0x000000FF) << 24);  // Move LSB to MSB
}

// Serialize a 32-bit integer into a big-endian byte buffer
void serialize_to_big_endian(int num, unsigned char *buff)
{
    buff[0] = (num >> 24) & 0xFF; // MSB
    buff[1] = (num >> 16) & 0xFF;
    buff[2] = (num >> 8) & 0xFF;
    buff[3] = num & 0xFF; // LSB
}

// Deserialize a big-endian byte buffer into a 32-bit integer
int deserialize_from_big_endian(unsigned char *buff)
{
    return (buff[0] << 24) | // MSB
           (buff[1] << 16) |
           (buff[2] << 8) |
           buff[3]; // LSB
}

int main(void)
{
    check_endianness();
    int num = 0x12345678;
    printf("Original: 0x%X\n", num);
    printf("Big Endian: 0x%X\n", TO_BIG_ENDIAN_32(num));
    printf("Little Endian: 0x%X\n", TO_LITTLE_ENDIAN_32(num));
    return 0;
}
