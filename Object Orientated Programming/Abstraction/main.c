/*
Abstraction can be achieved by exposing only the essential details of an object via header files and keeping implementation details private.
*/

// gcc main.c abstraction.c -o main.exe

#include "abstraction.h"

int main() {
    Person* person = createPerson("Alice", 30);
    printPerson(person);
    destroyPerson(person);
    return 0;
}
