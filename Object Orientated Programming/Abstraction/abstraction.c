/*
Abstraction can be achieved by exposing only the essential details of an object via header files and keeping implementation details private.
*/

#include "abstraction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

Person* createPerson(const char* name, int age) {
    Person* person = (Person*)malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void printPerson(Person* person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void destroyPerson(Person* person) {
    free(person);
}
