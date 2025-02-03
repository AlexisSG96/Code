#include <stdio.h>
#include <string.h>

#define MAX_SIZE 8
typedef struct
{
    char name[MAX_SIZE];
    unsigned short age;
} person_t;

void method(int x)
{
    printf("Value of x in method: %d\n", x);
}

void pointer_method(int *x)
{
    printf("Value of x in method: %d\n", *x);
}

void reference_method(const int x)
{
    printf("Value of x in method: %d\n", x);
}

// person_t *init_person(char *name, unsigned int age)
// {
//     person_t p = {.name = name, .age = age};
// }

person_t *init_person(person_t * p, char *name, unsigned int age)
{
    strncpy(p->name, name, MAX_SIZE - 1);
    p->name[MAX_SIZE - 1] = '\0';
    p->age = age;
    return p;
}

// Pass a copy of p
void struct_method(person_t p)
{
    strcpy(p.name, "Amy");
    p.age = 22;
}

void struct_pointer_method(person_t *p)
{
    strcpy(p->name, "Joe");
    p->age = 10;
}

void print_person(person_t *p)
{
    printf("Person: %s\nAge:%d\n", p->name, p->age);
}

int main(void)
{
    int x = 10;
    method(x);
    pointer_method(&x);
    reference_method(x);

    int *y = &x;
    method(*y);
    pointer_method(y);
    reference_method(*y);

    *y = 5;
    method(x);
    pointer_method(&x);
    reference_method(x);

    person_t p = {.name = "Alexis", .age = 100};
    print_person(&p);
    struct_method(p);
    print_person(&p);
    struct_pointer_method(&p);
    print_person(&p);
    person_t *q;
    q = &p;
    init_person(&p, "Lex", 55);
    print_person(&p);
    init_person(q, "Xel", 22);
    print_person(q);
    // free(q); // Only when dynamically allocating memory malloc

    unsigned int num = 0x12345678;
    unsigned char *byte_ptr = (unsigned char *)&num;
    unsigned char first_byte = (unsigned char *)&num;

    for (int i = 0; i < sizeof(num); i++)
    {
        printf("Byte %d: 0x%x\n", i, byte_ptr[i]);
    }
}