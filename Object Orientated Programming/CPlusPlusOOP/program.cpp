/*
Key Features:

Encapsulation: Attributes like name are protected.
Inheritance: Dog and Cat derive from Animal.
Polymorphism: speak() is overridden in each derived class.
*/

// g++ program.cpp -o main.exe

#include <iostream>
#include <string>

// Base class
class Animal
{
protected:
    std::string name;

public:
    Animal(const std::string &name) : name(name) {}
    virtual void speak() const = 0; // Pure virtual function for polymorphism
};

// Derived class
class Dog : public Animal
{
public:
    Dog(const std::string &name) : Animal(name) {}
    void speak() const override
    {
        std::cout << name << " says: Woof!" << std::endl;
    }
};

class Cat : public Animal
{
public:
    Cat(const std::string &name) : Animal(name) {}
    void speak() const override
    {
        std::cout << name << " says: Meow!" << std::endl;
    }
};

int main()
{
    Animal *dog = new Dog("Buddy");
    Animal *cat = new Cat("Whiskers");

    dog->speak(); // Outputs: Buddy says: Woof!
    cat->speak(); // Outputs: Whiskers says: Meow!

    delete dog;
    delete cat;
    return 0;
}
