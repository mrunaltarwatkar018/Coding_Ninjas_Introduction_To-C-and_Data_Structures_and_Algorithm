#include<iostream>
using namespace std;

// void increment ( int& n ) {
//     n++;
// }

void increment ( int& i ) {
    i++;
}

/*
        Wrong Way i.e. BAD Practice

int f ( int n) {
    int a = n;
    return n;
}

int * f2() {
    int i = 10;
    return &i;
}

*/


int main() {
    // int *p = f2();

    int i;
    i = 10;

    // int &k1 = f(i);
    increment(i);
    int &j = i;

    i++;
    cout << j << endl;
    j++;
    cout << i << endl;

    int k = 100;
    j = k;

    cout << i << endl;
}

// int main() {
//     int i;
//     i = 10;

//     increment(i);

//     cout << i << endl;

//     int &j = i;

//     i++;
//     cout << j << endl;
//     j++;
//     cout << i << endl;

//     int k = 100;
//     j = k;
//     cout << i << endl;
// }