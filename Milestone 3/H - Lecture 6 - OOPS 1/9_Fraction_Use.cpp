#include <iostream>
using namespace std;
#include "8_Fraction_Class.cpp"

int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	f1.add(f2);

	f1.print();
	f2.print();

    f1.multiply(f2);
    f1.print();
	f2.print();
    
}

