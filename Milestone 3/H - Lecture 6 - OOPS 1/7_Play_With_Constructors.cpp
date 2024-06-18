#include<iostream>
using namespace std;
#include "2Student.cpp"


int main() {
    Student s1;     // Constructors 1 called

    Student s2(101);    // Constructors 2 called

    Student s3(20, 102);    // Constructors 3 called

    Student s4(s3);     // Copy Constructors called

    s1 = s2;        // Copy assignment operator to copy the values of s2 to s1

    Student s5 = s4;    // Copy Constructors called'

}



// Above codes are just an examples of Constructors, not for run