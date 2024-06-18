#include<iostream>
using namespace std;
#include "2Student.cpp"

// copy constructors statically :
/*
int main() {
    Student s1(10, 1001);
    cout << "S1 : ";
    s1.display();

    // copy constructors statically
    Student s2(s1);
    cout << "S2 : ";
    s2.display();
}
*/


// copy constructors Dynamically :
/*
int main() {
    // copy constructors Dynamically
    Student * s3 = new Student( 20, 2001 );
    cout << "S3 : ";
    s3 -> display();

    Student s4(*s3);

    Student *s5 = new Student( *s3 );
    Student *s6 = new Student( s1 );
}
*/


// copy assignment operator ( = ) :
/*
int main() {
    // copy assignment operator ( = )
    Student s1( 10, 1001 );
    Student s2( 20, 2001 );

    Student * s3 = new Student( 30, 3001 );

    s2 = s1 ;

    *s3 = s1;

    s2 = *s3;   
}
*/

// Destructors : objects ki memory ko deallocate karana
// ------> same name as our class
// ------> same return type
// ------> No input arguments
// ------> structure of destructors :
// ~Student() {

// }
// ------> it call at one type as constutors at last when our objects ready to distroy
// ------> in destructors, no arguments passess

int main() {
    // copy assignment operator ( = )
    Student s1( 10, 1001 );
    Student s2( 20, 2001 );

    Student * s3 = new Student( 30, 3001 );

    s2 = s1 ;

    *s3 = s1;

    s2 = *s3;   

    delete s3;
}