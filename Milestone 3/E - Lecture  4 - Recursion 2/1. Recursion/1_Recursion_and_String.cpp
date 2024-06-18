#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Tp eliminate the 'x'
void removeX ( char s[] ) {
    if ( s[0] == '\0' ) {
        return;
    }

    if ( s[0] != 'x' ) {
        removeX( s + 1 ); 
    } else {
        int i = 1;
        for ( i; s[i] != '\0'; i++ ) {
            s[ i - 1 ] = s[i];
        }
        s [ i - 1 ] = s[i];

        removeX(s);
    }
}

// To find out the length of the string using Recursion
int length ( char s[] ) {
    if ( s[0] == '\0' ) {
        return 0;
    }

    int smallStringLength = length ( s + 1 );
    return 1 + smallStringLength;
}

int main() {
    char str[100];
    cout << "Enter the string : ";
    cin >> str;

    int len = length(str);
    cout << "The length of the String is : " << len << endl;

    removeX(str);
    cout << "After removing the x String becomes : " << str << endl;
    len = length(str);
    cout << "The length of the String after removing x is : " << len << endl;

}