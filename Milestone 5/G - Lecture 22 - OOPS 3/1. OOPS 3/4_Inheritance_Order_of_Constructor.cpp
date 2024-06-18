/*
        Order of Constructor/Destructor

                Constructors and Destructors follow a specific order of invocation.

                ●   In the case of constructors, base class constructors are called 
                    first, and the derived class constructors are called next. Moreover, 
                    the order of constructor invocation depends on the order of how the 
                    base class is inherited.

                ●   Destructors are called in reverse order of the constructor invocation, 
                    i.e., the destructor of the derived class is called first followed by 
                    the destructor of the base class sequentially.

*/




#include <iostream>
using namespace std;

// Parent class
class Vehicle { 
    private :
        int maxSpeed;

    protected :
        int numTyres;
        
    public :
        string color;

        // Vehicle() {
        //     cout << "Vehicle's default constructor " << endl;
        // }

        Vehicle( int z ) {
            cout << "Vehicle's Parametrized Constructor " << endl;
            maxSpeed = z;
        }

        ~Vehicle() {
            cout << "Vehicle's Destructor " << endl;
        }
};



// Child class with Public access modifier
class Car : public Vehicle { 
    public :
        int numGears;


        // explicitly call 
        // Car() : Vehicle(5) {
        //     cout << "Car's default constructor " << endl;
        // }

        Car() : Vehicle(5) {
            cout << "Car's default constructor " << endl;
        }

        ~Car() {
            cout << "Car's Destructor " << endl;
        }

        void print() {
            // protected data member accessible
            cout << "NumTyres : " << numTyres << endl;

            // public data member accessible
            cout << "Color : " << color << endl;

            cout << "Num gears : " << numGears << endl;
        }
};


// int main() {
//     Vehicle v;
//     v.color = "Blue";

//     // v.maxSpeed = 100; // Can’t be accessed being private
//     // v.numTyres = 4; // Can’t be accessed being protected

//     Car c;
//     c.color = "Black";

//     // c.numTyres = 4; // Can’t be accessed being protected

//     c.numGears = 5;
// }

// output 1
// Vehicle's default constructor 
// Vehicle's Parametrized Constructor 
// Car's default constructor 
// Car's Destructor 
// Vehicle's Destructor 
// Vehicle's Destructor 



int main() {
    // Vehicle v;
    // v.color = "Blue";

    // v.maxSpeed = 100; // Can’t be accessed being private
    // v.numTyres = 4; // Can’t be accessed being protected

    Car c;
    c.color = "Black";

    // c.numTyres = 4; // Can’t be accessed being protected

    // c.numGears = 5;
}

// output 2 

// Vehicle's Parametrized Constructor 
// Car's default constructor
// Car's Destructor
// Vehicle's Destructor