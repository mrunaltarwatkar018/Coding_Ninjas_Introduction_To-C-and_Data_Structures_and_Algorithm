#include <iostream>
using namespace std;

int main() {
	int a = 10;
	int b = 15;
	int c = a + b;

	cout << "c = " << c << endl;


	char d = 'x';
	cout << "d = " << d << endl;

	float f = 1.23;

	bool b1 = true;
	cout << "b1 = " << b1 << endl;

	bool b2 = false;
	cout << "b2 = " << b2 << endl;

	
	int size = sizeof(f);
	cout << size << endl;
}
