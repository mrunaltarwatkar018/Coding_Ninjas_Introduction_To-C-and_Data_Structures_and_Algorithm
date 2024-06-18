#include<iostream>
#include<climits>
using namespace std;

int main() {
    // Take array input from the user
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int input[100];

    cout << "Taking input from the user : ";
    for ( int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // To print the array
    cout << "After taking input from the user, Arrays Becomes : ";
    for ( int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout << endl;

    // Largest element in the array

    // int max = input[0];   // this line is false when input of array is ZERO 
    int max = INT_MIN;

    for ( int i = 0; i < n; i++) {
        if ( input[i] > max ) {
            max = input[i];
        }
    }

    cout << "Max : " << max << endl;
}



/* : : : : : SUM OF ARRAYS : : : : : */
// #include<iostream>
// using namespace std;

// int main(){
//     /* Read input as specified in the question.
//      * Print output as specified in the question.
//     */
//     int n;
//     cin >> n;

//     int input[1000000];

//     for ( int i = 0; i < n; i++ ) {
//         cin >> input[i];
//     }
     
//     int sum = 0;
//     for ( int i = 0; i < n; i++ ) {
//         sum += input[i];
//     }

//     cout << sum << endl;

//     return 0;
    
// }
