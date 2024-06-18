#include<iostream>
using namespace std;

void selectionSort(int input[], int n) {

    for ( int i = 0; i < n - 1; i++ ) {
        // Find minimum element from the array
        int min = input[i], minIndexz = i;

        for( int j = i + 1; j <n; j++ ) {
            if ( input[j] < min ) {
                min = input[j];
                minIndexz = j;
            }
        }

        // Swap
        int temp = input[i];
        input[i] = input[minIndexz];
        input[minIndexz] = temp;
    }

}

int main() {

    // Take array input from the user
    int m;
    cout << "Size of an Array : ";
    cin >> m;

    int input[100];
    cout << "Input Array : ";
    for(int i = 0; i < m; i++ ) {
        cin >> input[i];
    }
    // int input[] = {3, 1, 6, 9, 0, 4};
    selectionSort(input, m);

    // After Sorting Print the giving array
    cout << "After Sorting : ";
    for ( int i = 0; i < m; i++ ) {
        cout << input[i] << " ";
    }
    cout << endl;
}