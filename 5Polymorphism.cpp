#include <iostream>
using namespace std;

/*
    Polymorphism in C++

    - Polymorphism means "many forms". It allows objects to be treated as instances of their parent class rather than their actual derived class.
    - Two main types:
        1. Compile-time (Static) Polymorphism
            - Achieved by function overloading and operator overloading.
        2. Run-time (Dynamic) Polymorphism
            - Achieved by method overriding using virtual functions and base class pointers/references.

    - Virtual functions enable dynamic binding, allowing the correct function to be called based on the actual object type at runtime.
    - Pure virtual functions make a class abstract and force derived classes to implement the function.
*/

// ----------- Compile-time Polymorphism (Function Overloading) -----------
class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << endl;
    }
    void show(double y) {
        cout << "Double: " << y << endl;
    }
    void show(string s) {
        cout << "String: " << s << endl;
    }
};

// ----------- Run-time Polymorphism (Virtual Functions) -----------
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks (base class)" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

// ----------- Operator Overloading Example -----------
class Complex {
public:
    int real, imag;
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    // Overload + operator
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    // Compile-time polymorphism: Function Overloading
    Print p;
    p.show(10);
    p.show(3.14);
    p.show("Hello");

    // Run-time polymorphism: Virtual Functions
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    a1->speak(); // Calls Dog's speak()
    a2->speak(); // Calls Cat's speak()
    delete a1;
    delete a2;

    // Operator Overloading
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2; // Uses overloaded +
    cout << "Sum of complex numbers: ";
    c3.display();

    /*
        Key Points:
        - Compile-time polymorphism is resolved during compilation (overloading).
        - Run-time polymorphism is resolved during execution (virtual functions).
        - Virtual functions allow dynamic binding and are essential for achieving true polymorphism in C++.
    */

    return 0;
}