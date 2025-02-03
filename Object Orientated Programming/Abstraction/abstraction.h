/*
Abstraction can be achieved by exposing only the essential details of an object via header files and keeping implementation details private.
*/

#ifndef ABSTRACTION_H
#define ABSTRACTION_H

typedef struct Person Person;

Person *createPerson(const char *name, int age);
void printPerson(Person *person);
void destroyPerson(Person *person);

#endif