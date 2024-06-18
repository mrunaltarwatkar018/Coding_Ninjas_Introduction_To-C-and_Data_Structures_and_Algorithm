#include <iostream>
using namespace std;

void printArray(int input[], int n) {
	for(int i = 0; i < n; i++) {
		cout << input[i] << " " ;
	}
	cout << endl;
}

void bubbleSort(int arr[], int n) {
	for(int j = 0; j < n - 1; j++) {
		for(int i = 0; i < n - 1 - j; i++) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
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
	
    // calling bubbleSort function
	bubbleSort(input, n);

    // After Sorting Print the giving array
    cout << "After Sorting : ";
	printArray(input, n);
	
}
