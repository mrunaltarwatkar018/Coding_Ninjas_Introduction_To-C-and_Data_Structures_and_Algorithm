
#include<iostream>
using namespace std;

#include "Vehicle.cpp"

class Car : public Vehicle {
	public :
		int numGears;




		
		void print() {
			cout << "Car" << endl;
		}


};
