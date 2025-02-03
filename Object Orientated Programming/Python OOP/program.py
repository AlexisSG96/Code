# Key Features:

# Encapsulation: _name is a protected attribute (by convention).
# Inheritance: Dog and Cat inherit from Animal.
# Polymorphism: The speak() method is implemented differently for each subclass.

# Base class
class Animal:
    def __init__(self, name):
        self._name = name # Protected attribute

    def speak(self):
        raise NotImplementedError("Subclasses must implement this method!")
    
# Derived class
class Dog(Animal):
    def speak(self):
        print(f"{self._name} says: Woof!")

class Cat(Animal):
    def speak(self):
        print(f"{self._name} says: Meow!")

# Main
dog = Dog("Buddy")
cat = Cat("Whiskers")

dog.speak() # Outputs: Buddy says: Woof!
cat.speak() # Outputs: Whiskers says: Meow!