#include<iostream>
#include<climits>
using namespace std;

// int main() {
//     // Take array input from the user
//     int n;
//     cin >> n;

//     int input[100];

//     cout << input << endl;
// }


// Arrays & Function


void printArray(int input[], int n) {

    //cout << "Function : " << sizeof(input) << endl; 
    cout << "Print the Array : ";
    for ( int i = 0; i < n; i++ ) {
        cout << input[i] << " ";
    }

    cout << endl;
}


int main() {
    // Take array input from the user
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int input[100];

    cout << "Enter the Array elements : ";
    //cout << input << endl;

    for ( int i = 0; i < n; i++ ) {
        cin >> input[i];
    }

    //cout << "Main : " << sizeof(input) << endl;

    printArray(input, n);
}