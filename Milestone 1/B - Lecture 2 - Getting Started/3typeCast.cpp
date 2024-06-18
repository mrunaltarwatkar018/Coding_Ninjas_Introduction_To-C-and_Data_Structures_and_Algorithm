#include <iostream>
using namespace std;

int main() {
	int a, c;
    char b, d;
    a = 100;
    b = a;
    cout << "c = " << c << endl;

    c = 1990;
    d = c;
    cout << "d = " << d << endl;

    b = 'y';
    a = b;
    cout << "a = " << a << endl;

    float f = 1.2;
    a = f;
    cout << "a = " << a << endl;

    int i = 10;
    char e = 'a';
    int o = i + e;
    char m = i + e;
    cout << "Sum of o = " << o << endl;
    cout << "Sum of m = " << m << endl;
}
