/*
Polymorphism in C can be achieved using function pointers to define behavior that can vary depending on the object.
*/

#include <stdio.h>

// Base structure with a function pointer
typedef struct
{
    void (*speak)(void);
} Animal;

// Function implementations
void dogSpeak()
{
    printf("Woof!\n");
}

void catSpeak()
{
    printf("Meow!\n");
}

// Initialize the object
void initAnimal(Animal *animal, void (*speakFunc)(void))
{
    animal->speak = speakFunc;
}

int main()
{
    Animal dog, cat;

    initAnimal(&dog, dogSpeak);
    initAnimal(&cat, catSpeak);

    dog.speak();
    cat.speak();

    return 0;
}