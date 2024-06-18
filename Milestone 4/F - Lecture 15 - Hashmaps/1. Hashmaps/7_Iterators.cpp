#include <iostream>
using namespace std;
#include <string>
#include <vector>


/* Data Type Of Iterators */
// unordered_map <string, int> :: iterator it;

// inbuild Libraray
#include <unordered_map>


int main() {
    unordered_map <string, int> ourmap;
    ourmap["abc0"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;

    unordered_map < string, int > :: iterator it = ourmap.begin();
    while ( it != ourmap.end() ) {
		cout << "Key : " << it -> first << " Value : " << it -> second << endl;
		it++;
	}

    // find 
    unordered_map<string, int>::iterator it2 = ourmap.find("abc");
	// ourmap.erase(it2, it2 + 4);


    vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

    cout << endl;
	vector <int> :: iterator it1 = v.begin();
    cout << "In Vector form : " << endl;
	while ( it1 != v.end() ) {
		cout << *it1 << endl;
		it1++;
	}


}


/*
        OUTPUT :
        
                Key : abc4 Value : 5
                Key : abc5 Value : 6
                Key : abc0 Value : 1
                Key : abc1 Value : 2
                Key : abc2 Value : 3
                Key : abc3 Value : 4

                In Vector form :
                1
                2
                3
                4
                5

*/