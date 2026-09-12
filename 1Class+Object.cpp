#include <iostream>
using namespace std;

//The process of creating a class, adding access modifiers etc. is called "Encapsulation".

class vehicle{  //class acts as a blueprint for creating objects
   public:

   //Attributes
    string color , model;
    double speed , fuel_capacity;

    //Methods
    void accelerate(){
        cout << "The speed has increased\n";
    }

    void stop(){
        cout << "Your vehile has stopped\n";
    }
};

class Car : public vehicle{  //Derived class by inheriting from vehicle
    public:
    int seatnum,numbag;

    void open_top(){
        cout << "Roof of car has been opened\n";
    }


};

int main(){
    // This is an object created with the help of class also called "instance" of class
    vehicle Car;
    Car.color = "Red";
    Car.model = "Ferrari";
    Car.speed = 50; // in meters per second
    Car.fuel_capacity = 20; // in liters

    // To display and check object's attributes and methods
    cout << Car.color << "\n";
    cout << Car.model << "\n";
    cout << Car.speed << "\n";
    cout << Car.fuel_capacity << "\n";

    Car.accelerate();
    Car.stop();


    return 0;
}