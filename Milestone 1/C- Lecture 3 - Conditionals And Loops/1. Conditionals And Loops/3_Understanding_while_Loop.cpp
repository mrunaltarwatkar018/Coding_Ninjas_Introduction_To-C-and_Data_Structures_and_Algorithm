#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter n" << endl;

	cin >> n;

	int i = 1;
	while (i <= n) {
		cout << i << endl;
		i = i + 1;
	}
}



// #include <iostream>
// using namespace std;
// int main() {

//     /*
    
// // To print 1 to "N" Numbers
//     int n;
//     cout << "Enter the value of n : " ;
//     cin >> n;

//     int i = 1;
//     while ( i <= n)
//     {
//         cout << i << endl;
//         i = i + 1;
//     }

//     */

//    // To print whether the number is prime or not from 1 to "N"
//     int n;
//     cout << "Enter the value of n : " ;
//     cin >> n;

//     int d = 2;
//     bool divided = false;
//     while (d < n)
//     {
//         if (n % d == 0) {
//             cout << "The Number is NOT Prime." << endl;
//             divided = true;
//         }
//         d = d + 1;
//     }

//     if (!divided)
//     {
//         cout << "The Number Is Prime." << endl;
//     }  
// }