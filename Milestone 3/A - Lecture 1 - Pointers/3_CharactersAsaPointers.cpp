#include<iostream>
using namespace std;


int main() {

    char str[] = "abcde";
    char *pstr = "abcde";

    cout << "str : " << str << endl;
    cout << "pstr : " << pstr << endl;

    int a[] = {1, 2, 3};
    char b[] = "abc";
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    char * c = &b[0];
    cout << "c : " << c << endl;

    char c1 = 'a';
    char * pc = &c1;

    cout << "c1 : " << c1 << endl;
    cout << "pc : " << pc << endl;
}


/*  Output : 
            38CharactersAsaPointers.cpp: In function 'int main()':
            38CharactersAsaPointers.cpp:8:18: warning: ISO C++ forbids converting a string constant to 'ch
            ar*' [-Wwrite-strings]
                 char *pstr = "abcde";
                              ^~~~~~~
            str : abcde
            pstr : abcde
            a : 0x61fef0
            b : abc
            c : abc
            c1 : a
            pc : aabc
*/