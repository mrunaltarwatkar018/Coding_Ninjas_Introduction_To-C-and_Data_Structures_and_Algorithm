#include<iostream>
using namespace std;
#include "7_constantFunctionClass.cpp"


int main() {
    // objects f1 and f2
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    cout << "Numerator of f1 is : " << f1.getNumerator() << " " << "Denominator of f1 is : " << f1.getDenominator() << endl;
    cout << "Numerator of f2 is : " << f2.getNumerator() << " " << "Denominator of f2 is : " << f2.getDenominator() << endl;

    // constant object = which doesn't changes any property of current object
    // Fraction const f3;

    // cout << f3.getNumerator() << " " << f3.getDenominator() << endl;

    // f3.setNumerator(10);

}



// Here, line no. 15 to line no. 19 showing error because it doesn't mark any const function