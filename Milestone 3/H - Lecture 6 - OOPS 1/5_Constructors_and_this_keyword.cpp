#include<iostream>
using namespace std;
#include "2Student.cpp"

int main() {
    Student s1(10, 1001);
    cout << "Address of s1 : " << &s1 << endl;

    Student s2(20);
    s2.display();



    /*
    Student s1;

    s1.display();

    Student s2;

    Student * s3 = new Student;
    s3 -> display();

    cout << "Parameterized constreuctor Demo !" << endl;
    Student s4(18);
    s4.display();

    Student * s5 = new Student(101);
    s5 -> display();

    Student s6(20, 1002);
    s6.display();

    Student * s7 = new Student(25, 1235);
    s7 -> display();
    */

}