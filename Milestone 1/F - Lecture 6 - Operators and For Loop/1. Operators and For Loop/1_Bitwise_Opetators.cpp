#include<iostream>
using namespace std;

int main() {
    int ResultofOR = 15 | 30;
    int ResultofAND = 15 & 30; 
    int ResultofNOT = ~15;
    int ResultofXOR = 15 ^ 30;
    int ResultofLEFTSHIFT = 15 << 2;
    int ResultofRIGHTSHIFT = 15 >> 2;

    cout << ResultofOR << endl;
    cout << ResultofAND << endl;
    cout << ResultofNOT << endl;
    cout << ResultofXOR << endl;
    cout << ResultofLEFTSHIFT << endl;
    cout << ResultofRIGHTSHIFT << endl;
}