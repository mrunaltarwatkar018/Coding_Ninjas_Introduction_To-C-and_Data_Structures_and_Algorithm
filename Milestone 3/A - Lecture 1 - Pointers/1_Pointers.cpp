#include<iostream>
using namespace std;

// int main() {
//     int i = 10;
//     cout << "The address of i is : " << &i << endl;

//     int * p = &i;
//     cout << "The address of p is : " << p << endl;

//     cout << "The value of i is : " << *p << endl;

//     float f = 10.2;
//     cout << "The address of f is : " << &f << endl;
//     float * pf = &f;
//     cout << "The address of pf is : " << f << endl;

//     double d = 122.32;
//     cout << "The address of d is : " << &d << endl;
//     double * pd = &d;
//     cout << "The address of pd is : " << d << endl;
// }

// int main() {
//     int i = 10;
//     int *p = &i;

//     int * q = p;

//     cout << "The size of i is : " << sizeof(p) << endl;
//     cout << i << endl;
//     cout << *p << endl;

//     i++;

//     cout << i << endl;
//     cout << *p << endl;

//     int a = i;  // int a = *p;
//     a++;
//     cout << a << endl;
//     cout << *p << endl;

//     i = 12;
//     cout << i << endl;
//     cout << *p << endl;
//     *p = 23;
//     cout << i << endl;
//     cout << *p << endl;

//     (*p)++;
//     cout << i << endl;
//     cout << *p << endl;

// }

int main() {
    int i;
    cout << i << endl;

    i++;
    cout << i << endl;

    int * p = 0;
    cout << p << endl;

    cout << * p << endl;

    (*p)++;
    cout << * p << endl;
}