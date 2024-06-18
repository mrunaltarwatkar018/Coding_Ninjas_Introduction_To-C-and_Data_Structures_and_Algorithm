#include<iostream>
#include<vector>
using namespace std;


int main() {
    // vector<int> * vp = new vector<int>();
    vector <int> v;

    for ( int i = 0; i < 100; i++ ) {
        cout << "Capacity :" << v.capacity() << endl;
        cout << "Size : " << v.size() << endl;
        v.push_back(i + 1);
    }

    // to insert the last element : v.push_back( some value ) function

    v.push_back(10);        // to enter the element
    v.push_back(20);
    v.push_back(30);

    // cout << v[0] << endl;
    // cout << v[1] << endl;
    // cout << v[2] << endl;

    v[1] = 100;     // to update the element [] are use only

    // dont use [] for inserting elements
    // use [] to get and update the elemrnts only
    // v[3] = 1002;
    // v[4] = 1234;

    v.push_back(23);
    v.push_back(25);


    // to delete the last element : v.pop_back() function
    v.pop_back();


    /*
    for ( int i = 0; i < v.size(); i++ ) {
        cout << v[i] << endl;
    }
    */
    
    /*

    cout << v[0] << endl;           // to get the elements [] are use only
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;

    // size of a vector  we use v.size() function
    cout << "Size : " << v.size() << endl;

    // alternate to [] bracket is at() function
    // at() function use to what is the element at thet position
    // alternate to [] braccket is at() function
    
    cout << v.at(2) << endl;         // alternate to [] bracket is at() function which gives the element at position 2   
    cout << v.at(6) << endl;        // alternate to [] bracket is at() function which gives the element at position 3

    */


}