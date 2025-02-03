/*
Encapsulation
"This is about protecting data by keeping attributes private and providing public methods to access or modify them.
It prevents external code from directly messing with internal states."
*/

#include <stdio.h>
#include <string.h>

// Define a structure (object)
typedef struct
{
    char name[50];
    int age;

    // Method to print details
    void (*printDetails)(struct Person *);
} Person;

// Method implementation
void printPersonDetails(Person *self)
{
    printf("Name: %s, Age: %d\n", self->name, self->age);
}

// Initialize the object
void initPerson(Person *person, const char *name, int age)
{
    strcpy(person->name, name);
    person->age = age;
    person->printDetails = printPersonDetails; // Assign the function
}

int main()
{
    Person person;
    initPerson(&person, "Alice", 30);

    // Call the method
    person.printDetails(&person);
    return 0;
}