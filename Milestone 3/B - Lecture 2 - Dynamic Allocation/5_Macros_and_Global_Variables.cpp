#include<iostream>
using namespace std;
#define PI 3.14

int main() {
    int r;
    cout << "Enter the value of Radius of circle r : ";
    cin >> r;

    cout << "Area of circle : " << PI * r * r << endl;
}


/*

        Global Variables Not used

int a;      

void g() {
    a++;
    cout << a << endl;
}

void f() {
    cout << a << endl;
    a++;
    g();
}

int main() {
    a = 10;
    f();
    cout << a << endl;
}
        
*/