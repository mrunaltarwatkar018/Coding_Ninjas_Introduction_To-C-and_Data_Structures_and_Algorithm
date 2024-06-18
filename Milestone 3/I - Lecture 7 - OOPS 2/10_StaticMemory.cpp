#include<iostream>
using namespace std;
#include "9_StaticMemoryClass.cpp"

int main() {
    Student s1;

    // cout << s1.rollNumber << " " << s1.age << endl;
    // cout << s1.totalStudents << endl;
    // s1.totalStudents = 20;


    Student s2;
    // cout << s2.totalStudents << endl;
    // cout << Student :: totalStudents << endl;

    Student s3, s4, s5;
    // cout << Student :: totalStudents << endl;

    cout << Student :: getTotalStudents() << endl;
}