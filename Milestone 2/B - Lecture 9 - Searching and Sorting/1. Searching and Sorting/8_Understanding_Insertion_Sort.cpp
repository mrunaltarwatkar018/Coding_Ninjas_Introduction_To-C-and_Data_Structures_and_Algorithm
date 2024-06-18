#include <iostream>
using namespace std;

void printArray(int input[], int n) {
	for(int i = 0; i < n; i++) {
		cout << input[i] << " " ;
	}
	cout << endl;
}

void insertionSort(int arr[], int n) {
    for ( int i = 1; i < n; i++ ) {
        int current = arr[i];
        int j;
        for ( j = i - 1; j >= 0; j-- ) {
            if ( current < arr[j] ) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = current;
    }
}

int main() {
	// Take array input from the user
	int n;
    cout << "Enter the value of n : ";
	cin >> n;

	int input[100];
	
    cout << "Enter the Array elements : ";
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
    // calling insertioneSort function
	insertionSort(input, n);

    // After Sorting Print the giving array
    cout << "After Sorting : ";
	printArray(input, n);
	
}