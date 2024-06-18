#include<iostream>
using namespace std;

/*
        Enter the value of n :  5
                      output :      *
                                   **
                                  ***
                                 ****
                                *****
*/
// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while ( i <= n ) {
//         int spaces = 1;
//         while ( spaces <= n-i ) {
//             cout << ' ';
//             spaces = spaces + 1;
//         }

//         int stars = 1;
//         while ( stars <= i ) {
//             cout << '*';
//             stars = stars + 1;
//         }
//         cout << endl;
//         i = i + 1;    
//     }   
// }

// int main() {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;

//     int i = 1;
//     while ( i <= n ) {
//         int spaces = 1;
//         while ( spaces <= n-i ) {
//             cout << ' ';
//             spaces++;
//         }

//         int stars = 1;
//         while ( stars <= i ) {
//             cout << '*';
//             stars++;
//         }
//         cout << endl;
//         i++;    
//     }   
// }


/*
        Enter the value of n : 5
                      Output :      1
                                   12
                                  123
                                 1234
                                12345
*/
int main(){
	int n;
    cout << "Enter the value of n : ";
	cin >> n;

	int i = 1;
	while ( i <= n ) {
		int spaces = 1;
		while ( spaces <= n - i ) {
			cout << ' ';
			spaces = spaces + 1;
		}

		int starts = 1;
        while (starts <= i)
        {
            cout << starts;
            starts++;
        }
		cout << endl;
		i++;
	}  
}
