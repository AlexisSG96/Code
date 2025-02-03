/*
Key Features:

Encapsulation: Name is protected and accessible only within the class and its derived classes.
Inheritance: Dog and Cat inherit from Animal.
Polymorphism: Abstract methods ensure each derived class provides its own implementation.
*/

// dotnet new console
// dotnet new console --force # if program.cs exists
// dotnet run

using System;

// Base class
abstract class Animal
{
    protected string Name;

    public Animal(string name)
    {
        Name = name;
    }

    public abstract void Speak(); // Abstract method for polymorphism
}

// Define the interface
public interface IAnimal
{
    string Name { get; }    // Property
    void Speak();           // Method
}

// Derived class
class Dog : Animal
{
    public Dog(string name) : base(name) { }

    public override void Speak()
    {
        Console.WriteLine($"{Name} says: Woof!");
    }
}

class Dog2 : IAnimal
{
    public string Name { get; }

    public Dog2(string name)
    {
        Name = name;
    }
    
    public void Speak() {
        Console.WriteLine($"{Name} says: Woof!");
    }
}


class Cat : Animal
{
    public Cat(string name) : base(name) { }

    public override void Speak()
    {
        Console.WriteLine($"{Name} says: Meow!");
    }
}

class Program
{
    static void Main()
    {
        Animal dog = new Dog("Buddy");
        Animal cat = new Cat("Whiskers");

        dog.Speak();  // Outputs: Buddy says: Woof!
        cat.Speak();  // Outputs: Whiskers says: Meow!
    }
}
