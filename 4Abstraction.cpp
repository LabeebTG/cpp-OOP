#include <iostream>
using namespace std;

/*
    Abstraction in C++

    - Abstraction is the concept of hiding complex implementation details and showing only the essential features of an object.
    - It helps reduce programming complexity and effort.
    - In C++, abstraction is achieved using:
        1. Abstract classes (classes with at least one pure virtual function)
        2. Interfaces (in C++, achieved using abstract classes with only pure virtual functions)
    - Pure virtual function: A function declared in a base class that has no definition and must be overridden in derived classes.
        Syntax: virtual void func() = 0;
    - Abstract class: Any class with at least one pure virtual function. Cannot be instantiated directly.
*/

// Abstract class (contains at least one pure virtual function)
class Shape {
public:
    // Pure virtual function (no implementation here)
    virtual void draw() = 0;

    // Regular member function (can have implementation)
    void info() {
        cout << "This is a shape." << endl;
    }
};

// Derived class must override the pure virtual function
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    // Shape s; // Error: cannot instantiate abstract class

    // Using pointers or references to base class for abstraction
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Calls Circle's draw()
    shape2->draw(); // Calls Rectangle's draw()

    shape1->info(); // Calls base class function

    // Clean up
    delete shape1;
    delete shape2;

    /*
        Key Points:
        - Abstraction focuses on what an object does, not how it does it.
        - Abstract classes cannot be instantiated directly.
        - Pure virtual functions force derived classes to provide specific implementations.
        - Abstraction is useful for defining interfaces and base classes in large projects.
    */

    return 0;
}