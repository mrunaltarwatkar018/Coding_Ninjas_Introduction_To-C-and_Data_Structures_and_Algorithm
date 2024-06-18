/*
Polymorphism

        The word polymorphism means ​different forms​. It occurs when multiple 
        classes are related to each other by inheritance. In ​C++, polymorphism 
        means, a call to a member function will cause a different function to be 
        executed depending on the type of object that invokes it. For example, 
        (+) sign is used as an addition operator as well as the concatenation 
        operator.

        Polymorphism is generally of two types:

                ●   Compile-time polymorphism
                ●   Run-time polymorphism

        Compile-time polymorphism:

        It demonstrates the properties of static/early binding and occurs 
        in the following cases:

                ●   Function Overloading and Operator Overloading
                ●   Function Overriding

    We already have studied operator overloading. So, let’s discuss function 
    overloading.

    When two or more functions have the same name but differ in any of the number
    of arguments or the return-type, then this process is known as ​Function
    Overloading.

    Note:   ​In static/early binding, ​the compiler (or linker) directly associates 
            an address to the function call. It replaces the call with a machine 
            language instruction that tells the mainframe to leap to the address 
            of the function.
    
    
    For example:

*/

#include <iostream>
using namespace std;

// function with 2 arguments
int test(int a, int b) { 

}

// function with 1 argument
int test(int a) { 

}

// function with no argument
int test() { 

}

int main() {
    // All the above functions have same name but differ in number of arguments
}



/*
        Now, suppose we have two classes, A and B where A is the base/parent class, 
        and B is the child/derived class. If the base class has a function named 
        print()​ and a child class of it also contains such a function, then this is 
        a case of function overriding.

        Here, we are deciding at the compile time about the function to be called. 
        Look at the code below:


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

        void print() {
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

    v1 -> print();  // This will print Vehicle class’ print()
    v2 -> print();  // This will also print Vehicle class’ print() due to overriding
}
