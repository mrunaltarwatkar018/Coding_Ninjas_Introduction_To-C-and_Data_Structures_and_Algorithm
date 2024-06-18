/*
Pure Virtual functions and Abstract classes

        A virtual function whose declaration ends with =0 is called a ​pure virtual function​.
        These functions do not have any definition. An Abstract class has at least one pure
        virtual function. Abstract classes are those that can’t be instantiated, i.e., we cannot
        create an object of this class. However, we can derive a class from it and instantiate
        the object of the derived class.


        Properties of the abstract classes:

                ●   It can have normal functions and variables along with the pure 
                    virtual functions.
                ●   Prominently used for upcasting(​converting a derived-class reference 
                    or pointer to a base-class. In other words, upcasting allows us to 
                    treat a derived type as a base type​), so its derived classes can use 
                    its interface.
                ●   If an abstract class has derived class, they must implement all pure 
                    virtual functions, or else they will become abstract too.


        Kindly check the following code for better understanding.


*/

#include <iostream>
using namespace std;

class Vehicle { // This class becomes abstract as it contains a pure virtual function
    public :
        string color;

        // Pure virtual function
        virtual void print() = 0;
};
