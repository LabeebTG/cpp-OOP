#include <iostream>
using namespace std;

/*
    Constructors in C++

    - A constructor is a special member function of a class that is automatically called when an object is created.
    - Its main purpose is to initialize the object's data members.
    - Constructors have the same name as the class and do not have a return type (not even void).
    - Types of constructors:
        1. Default Constructor
        2. Parameterized Constructor
        3. Copy Constructor
        4. Dynamic Constructor (using new)
        5. Constructor with default arguments
    - Constructors can be overloaded (multiple constructors with different parameters).
    - If no constructor is defined, the compiler provides a default constructor.
*/

// 1. Default Constructor: No parameters
class DefaultConstructorExample {
public:
    int x;
    DefaultConstructorExample() {
        x = 0;
        cout << "Default constructor called, x = " << x << endl;
    }
};

// 2. Parameterized Constructor: Takes arguments
class ParameterizedConstructorExample {
public:
    int a, b;
    ParameterizedConstructorExample(int x, int y) {
        a = x;
        b = y;
        cout << "Parameterized constructor called, a = " << a << ", b = " << b << endl;
    }
};

// 3. Copy Constructor: Initializes an object using another object of the same class
class CopyConstructorExample {
public:
    int value;
    CopyConstructorExample(int v) {
        value = v;
    }
    // Copy constructor
    CopyConstructorExample(const CopyConstructorExample &obj) {
        value = obj.value;
        cout << "Copy constructor called, value = " << value << endl;
    }
};

// 4. Dynamic Constructor: Allocates memory dynamically
class DynamicConstructorExample {
public:
    int *arr;
    int size;
    DynamicConstructorExample(int s) {
        size = s;
        arr = new int[size]; // dynamic memory allocation
        for (int i = 0; i < size; i++) arr[i] = i + 1;
        cout << "Dynamic constructor called, array of size " << size << " created." << endl;
    }
    ~DynamicConstructorExample() {
        delete[] arr; // free memory
        cout << "Destructor called, memory released." << endl;
    }
    void printArray() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

// 5. Constructor with default arguments
class DefaultArgConstructorExample {
public:
    int x, y;
    DefaultArgConstructorExample(int a = 1, int b = 2) {
        x = a;
        y = b;
        cout << "Constructor with default arguments called, x = " << x << ", y = " << y << endl;
    }
};

int main() {
    // Default constructor
    DefaultConstructorExample obj1;

    // Parameterized constructor
    ParameterizedConstructorExample obj2(10, 20);

    // Copy constructor
    CopyConstructorExample original(50);
    CopyConstructorExample copy = original; // invokes copy constructor

    // Dynamic constructor
    DynamicConstructorExample dynObj(5);
    dynObj.printArray();

    // Constructor with default arguments
    DefaultArgConstructorExample defObj1;         // uses default values
    DefaultArgConstructorExample defObj2(100);    // uses 100 for x, default for y
    DefaultArgConstructorExample defObj3(100, 200); // uses 100 for x, 200 for y

    /*
        Key Points:
        - Constructors can be overloaded.
        - Constructors cannot be inherited, but the derived class can call the base class constructor.
        - If you define any constructor, the compiler does not provide a default constructor.
        - Copy constructor is called when:
            * An object is initialized from another object of the same type.
            * An object is passed by value to a function.
            * An object is returned by value from a function.
        - Destructor (~ClassName) is called when an object goes out of scope or is deleted.
    */

    return 0;
}