/*

        Run-time polymorphism:

                Run-time polymorphism demonstrates the property of dynamic resolution 
                or late binding and is achieved by using function overriding.

                In the above code, we saw that by using the car class’ object, when we 
                were calling the print() function, we were redirected to Vehicle class’s 
                print() function. Suppose, in the aforementioned example, if we want that 
                instead of the base class’(vehicle) print function, the derived class’(car) 
                print function gets called, we can use ​Virtual Functions ​to achieve the same..

                When the base class’s function is overridden in the child class, then that 
                function is known as a virtual function. Keyword ​virtual​ is used for the 
                same. By doing so, we are redirecting the compiler to take the decision at 
                runtime only.

*/


#include <iostream>
using namespace std;

class Vehicle {
    public :
        string color;
        void print() {
            cout << "Vehicle" << endl;
        }
};

class Car : public Vehicle {
    public :
        int numGears;
        virtual void print() { // function made virtual
            cout << "Car" << endl;
        }
};

int main() {
    Vehicle v;
    Car c;

    v.print();
    c.print();

    Vehicle *v1 = new Vehicle;
    Vehicle *v2;

    v2 = &c;

    v1 -> print(); // This will print Vehicle class’ print()
    v2 -> print(); // This will now print car class’ print() due to virtual function
}
