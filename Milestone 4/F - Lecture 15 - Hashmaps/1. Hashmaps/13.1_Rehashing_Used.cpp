#include <iostream>
#include <string>
#include "13_Rehashing.cpp"
using namespace std;

int main() {
    OurMap <int> map;

    for ( int i = 0; i < 10; i++ ) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert( key, value );
        cout << "Load Factor : " <<  map.getLoadFactor() << endl;
    }

    cout << endl;

    cout << "Size of map : " << map.size() << endl;
    map.remove("abc2");
    map.remove("abc7");
    cout << "Size of map : " << map.size() << endl;

    cout << endl;
    
    for ( int i = 0; i < 10; i++ ) { 
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << " : " << map.getValue(key) << endl;
    }
    cout << "Size of map : " << map.size() << endl;
}