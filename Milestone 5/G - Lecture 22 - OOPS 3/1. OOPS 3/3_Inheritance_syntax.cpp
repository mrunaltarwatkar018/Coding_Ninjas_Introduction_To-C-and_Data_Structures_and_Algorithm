/*
    Inheritance: Syntax

            The syntax for inheriting a base class by a derived class:

                    class derived_class_name : access_modifier base_class_name {
                            ----
                            ----
                    };

*/


/*
        Kindly look at the following example for better understanding:

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
};

// Child class with Public access modifier
class Car : public Vehicle { 
    public :
        int numGears;

        void print() {
            // protected data member accessible
            cout << "NumTyres : " << numTyres << endl;

            // public data member accessible
            cout << "Color : " << color << endl;

            cout << "Num gears : " << numGears << endl;
        }
};


int main() {
    Vehicle v;
    v.color = "Blue";

    // v.maxSpeed = 100; // Can’t be accessed being private
    // v.numTyres = 4; // Can’t be accessed being protected

    Car c;
    c.color = "Black";

    // c.numTyres = 4; // Can’t be accessed being protected

    c.numGears = 5;
}
