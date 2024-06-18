#include <iostream>
using namespace std;

int main() {
    int f;
    cout << "Enter Fan Value : " << endl;
    cin >> f;
    int c = ( 5.0 / 9 ) * ( f - 32 );
    c = ( 5 * ( f - 32 )) / 9;
    cout << "c = " << c << endl;

    float d = ( 5.0 / 9 ) * ( f - 32 );
    cout << "d = " << d << endl;

    int r = 10 % 3;
    cout << 10 % 3 << endl;

    int a;
    int b;
    cout << "Enter a and b : " << endl;
    cin >> a >> b;

    bool isEqual = ( a == b );
    bool isAGreater = ( a > b);
    bool isALess = ( a < b);
    cout << "Are they Equal : " << isEqual << endl;
    cout << "Is A Greater : " << isAGreater << endl;
    cout << "Is A less : " << isALess << endl;

    bool third = isEqual && isAGreater;
    bool fourth = isEqual || isAGreater;
    bool fifth = isEqual && isAGreater;
    
    cout << "Not Equal : " << !isEqual << endl;

}
