#include<iostream>
using namespace std;

// int main() {
//     int * p = new int;
//     *p = 10;
//     cout << * p << endl;

//     double * pd = new double;

//     char * c = new char;

//     int * pa = new int[50];
//     int n;
//     cout << "Enter the Number of elements : ";
//     cin >> n;
//     int * pa2 = new int[n];
//     // pa2[0] = 10;
//     for ( int i = 0; i < n; i++ ) {
//         cin >> pa2[i];
//     }

//     int max = -1;
//     for ( int i = 0; i < n; i++ ) {
//         if ( max < a[i] ) {
//             max = a[i];
//         }
//     }
//     cout << "Maximum Number : " << max << endl;
// }

// int main() {
//     while ( true ) {
//         int *p = new int;
//     }
// }

// int main() {
//     while ( true ) {
//         int i = 10;
//     }
// }

int main() {
    int *p = new int;
    delete p;

    p = new int;
    delete p;       // Single element deletion

    p = new int[100];
    delete [] p;        // Arrayt deletion
}