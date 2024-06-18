#include<iostream>
using namespace std;

#include "2Student.cpp"

// int main() {
//     // Create objects Statically
//     Student s1;
//     Student s2;
//     Student s3, s4, s5;

    
//     s1.rollNumber = 101;

//     cout << "S1 Age : " << s1.getAge() << endl;
//     cout << "S1 Roll Number : " << s1.rollNumber << endl;


//     s1.display();
//     s2.display();

//     // Create objects dynamically
//     Student * s6 = new Student;
//     Student * s7 = new Student;

//     //(*s6).age = 23;
//     (*s6).rollNumber = 104;

//     (*s6).display();

//     cout << "S6 Age : " << s6 -> getAge() << endl;


//     // above to lines can be written as 
//     //s6 -> age = 23;
//     s6 -> rollNumber = 104;
//     s6 -> display();
// }


int main() {
    Student s1;

    Student * s2 = new Student;

    s1.setAge(25);
    s2 -> setAge(30);

    s1.display();
    s2 -> display();
}