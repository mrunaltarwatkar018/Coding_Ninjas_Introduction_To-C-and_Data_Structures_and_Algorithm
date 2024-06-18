#include<iostream>
using namespace std;

// No change
void increment1( int **p ) {
    p = p + 1;
}

// changes occure
void increment2( int **p ) {
    *p = *p + 1;
}

// changes occure
void increment3( int **p ) {
    ** p = ** p + 1;
}


int main() {
    int i = 10;
    int * p = &i;

    int * *p2 = &p;
    cout << "Address of p2 is : " << p2 << endl;
    cout << "Address of p is : " << &p << endl;

    cout << p << endl;
    cout << *p2 << endl;
    cout << &i << endl;

    cout << i << endl;
    cout << *p << endl;

    cout << **p2 << endl;
}



        // DOUBLE POINTER :

        //         As we know by now that pointers are variables that store address of other
        //         variables, so we can create variables that store address of pointer itself i.e. a
        //         pointer	to a pointer. Let’s see	how can	we create one.
                        
        //                 int a = 10;
        //                 int *p = &a;
        //                 int **q = &p;

        //         Here q is a pointer	to a pointer i.e. a	double pointer,as indicated	by **.
        //         Consider the following code for better understanding –

        //                 #include<iostream>
        //                 using namespace std;

        //                 int main() {
        //                     int a = 10;
        //                     int *p = &a;
        //                     int **q = &p;

        //                     /* Next three statements will print	same value i.e. address	of a. */
        //                     cout <<	&a << endl;
		//                     cout <<	p << endl;
		//                     cout <<	*q << endl;

        //                     /* Next two statements will print same value i.e. address of p. */
        //                     cout << *p << endl;
        //                     cout << q << endl;

        //                     /* Next two statements will print same value i.e. value of a which is 10. */
        //                     cout << a << endl;
        //                     cout << *p << endl;
        //                     cout << **q << endl;
        //                 }


