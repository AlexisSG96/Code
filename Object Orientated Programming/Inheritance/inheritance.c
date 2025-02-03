/*
C does not have native inheritance, but you can simulate it by embedding one structure into another (composition).
The "derived class" contains the "base class."
*/
#include <stdio.h>

// Base structure
typedef struct
{
    char name[50];
} Animal;

typedef struct
{
    Animal base;
    int legCount;

    void (*printDetails)(struct Mammal *);
} Mammal;

void printMammalDetails(Mammal *self)
{
    printf("Animal: %s, Legs: %d\n", self->base.name, self->legCount);
}

void initMammal(Mammal *mammal, const char *name, int legCount)
{
    strcpy(mammal->base.name, name);
    mammal->legCount = legCount;
    mammal->printDetails = printMammalDetails;
}

int main()
{
    Mammal mammal;
    initMammal(&mammal, "Dog", 4);

    mammal.printDetails(&mammal);
    return 0;
}
