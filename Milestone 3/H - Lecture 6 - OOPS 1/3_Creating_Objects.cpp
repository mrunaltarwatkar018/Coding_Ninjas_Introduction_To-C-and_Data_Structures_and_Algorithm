#include<iostream>
using namespace std;

#include "2Student.cpp"

int main() {
    // Create objects Statically
    Student s1;
    Student s2;
    Student s3, s4, s5;

    s1.age = 24;
    s1.rollNumber = 101;

    cout << s1.age << endl;
    cout << s1.rollNumber << endl;

    // Create objects dynamically
    Student * s6 = new Student;
    Student * s7 = new Student;

    (*s6).age = 23;
    (*s6).rollNumber = 104;


    // above to lines can be written as 
    s6 -> age = 23;
    s6 -> rollNumber = 104;
}