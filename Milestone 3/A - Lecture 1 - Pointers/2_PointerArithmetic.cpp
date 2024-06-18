#include<iostream>
using namespace std;

// int main() {
//     int i = 10;
//     int* p = &i;
//     cout << p << endl;
//     p = p + 2;
//     cout << p << endl;

//     cout << p << endl;
//     p = p - 2;
//     cout << p << endl;

//     double d = 102.3;
//     double * dp = &d;
//     cout << dp << endl;
//     dp++;
//     cout << dp << endl;
// }

int main() {
int *ptr = 0;
int a = 10;
*ptr = a;
cout << *ptr << endl;
}