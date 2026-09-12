#include <iostream>
using namespace std;

/*
    Inheritance in C++

    - Inheritance is an OOP concept where a new class (derived/child) acquires the properties and behaviors (data and functions) of an existing class (base/parent).
    - Promotes code reusability and establishes a relationship between classes.
    - Types of inheritance:
        1. Single Inheritance
        2. Multiple Inheritance
        3. Multilevel Inheritance
        4. Hierarchical Inheritance
        5. Hybrid Inheritance

    - Access specifiers:
        * public: public members of base become public in derived
        * protected: public and protected members of base become protected in derived
        * private: public and protected members of base become private in derived

    - Constructors and destructors are called in the order: base -> derived (constructor), derived -> base (destructor)
*/

// 1. Single Inheritance: One base, one derived
class Animal {
public:
    void eat() {
        cout << "Animal eats." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

// 2. Multiple Inheritance: Derived from more than one base class
class A {
public:
    void showA() { cout << "Class A" << endl; }
};
class B {
public:
    void showB() { cout << "Class B" << endl; }
};
class C : public A, public B {
public:
    void showC() { cout << "Class C (Multiple Inheritance)" << endl; }
};

// 3. Multilevel Inheritance: Derived from a derived class
class Vehicle {
public:
    void start() { cout << "Vehicle starts." << endl; }
};
class Car : public Vehicle {
public:
    void drive() { cout << "Car drives." << endl; }
};
class SportsCar : public Car {
public:
    void turbo() { cout << "SportsCar turbo mode!" << endl; }
};

// 4. Hierarchical Inheritance: Multiple derived classes from one base
class Shape {
public:
    void draw() { cout << "Drawing shape." << endl; }
};
class Circle : public Shape {
public:
    void area() { cout << "Area of circle." << endl; }
};
class Square : public Shape {
public:
    void area() { cout << "Area of square." << endl; }
};

// 5. Hybrid Inheritance: Combination of two or more types (can lead to diamond problem)
class X {
public:
    void showX() { cout << "Class X" << endl; }
};
class Y : public X {};
class Z : public X {};
class Hybrid : public Y, public Z {};

int main() {
    // Single Inheritance
    Dog d;
    d.eat();
    d.bark();

    // Multiple Inheritance
    C objC;
    objC.showA();
    objC.showB();
    objC.showC();

    // Multilevel Inheritance
    SportsCar sc;
    sc.start();
    sc.drive();
    sc.turbo();

    // Hierarchical Inheritance
    Circle cir;
    Square sq;
    cir.draw();
    cir.area();
    sq.draw();
    sq.area();

    // Hybrid Inheritance (Diamond problem demonstration)
    Hybrid h;
    // h.showX(); // Error: ambiguous, need to specify path
    h.Y::showX(); // Resolving ambiguity

    /*
        Key Points:
        - Inheritance supports code reuse and logical hierarchy.
        - Access specifiers control visibility of base class members in derived class.
        - Constructors and destructors are called in a specific order.
        - Multiple and hybrid inheritance can cause ambiguity (diamond problem), solved using virtual inheritance.
    */

    return 0;
}