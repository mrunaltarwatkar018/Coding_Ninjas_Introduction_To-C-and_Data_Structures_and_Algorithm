/* Keywoed :  Const */

#include<iostream>
using namespace std;

// int main() {
//     //constant integer
//     const int i = 10;
//     int const i2 = 10;

//     // constant reference from a non-constant integer
//     int j = 12;
//     const int & k = j;
//     //k++;
//     j++;

//     cout << k << endl;

//     // constant reference from a constant integer
//     int const j2 = 12;
//     int const & k2 = j2;
//     // j2++;
//     // k2++;

//     // reference from a constant integer
//     int const j3 = 123;
//     int & k3 = j3;
//     // k3++;
// }


// /* Const Pointers */ 
// void g( int const & a ) {
//     a++;
// }

// void f( const int * p ) {
//     //(*p)++;             // Error occur
// }   

// int main() {
//     int const i = 10;

//     int const * p = &i;

//     int j = 12;
//     int * p3 = &j;
//     f( p3 );
//     g( j );

//     int const * p2 = &j;
//     cout << * p2 << endl;
//     j++;
//     cout << *p2 << endl;
// }


int main() {
    int i = 10;
    int j = 21;
    int const * p = &i;

    p = &j;

    int * const p2 = &i;
    (*p2)++;
    //p2 = &j;


    int const * const p3 = &i;
    // p3 = &j;
    // (*p3)++;
}



