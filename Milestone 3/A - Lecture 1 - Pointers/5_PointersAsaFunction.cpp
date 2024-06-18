#include<iostream>
using namespace std;


/*

void print ( int *p) {
    cout << *p << endl;
}

void incrementPointer ( int *p ) {
    p = p + 1;
}

void increment ( int *p ) {
    (*p)++;
}

int main() {
    int i = 10;
    int *p = &i;

    print( p ) ;

    cout << p << endl;
    incrementPointer ( p );
    cout << p << endl;

    cout << *p << endl;
    increment( p );
    cout << *p << endl;
}

*/

int sum( int *a, int size ) {
    int ans = 0;
    for ( int i = 0; i < size; i++ ) {
        ans += a[i];
    }
    return ans;
} 

int main() {
    int a[10];
    cout << sizeof(a) << endl;
    cout << sum(a, 10) << endl;
    cout << sum(a+3, 7) << endl;
}

