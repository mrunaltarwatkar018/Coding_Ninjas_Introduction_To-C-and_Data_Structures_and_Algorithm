#include <iostream>
using namespace std;
#include <string>

// inbuild Libraray
#include <unordered_map>


int main() {

	// object
	unordered_map<string, int> ourmap;
	
	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);

	ourmap["def"] = 2;		// it is another way to insert an element

	// find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;		// it is another way to find or access an element
	
	//cout << ourmap.at("ghi") << endl;
	cout << "size : " << ourmap.size() << endl;
	cout << ourmap["ghi"] << endl;
	cout << "size : " << ourmap.size() << endl;

	// check Presense or not
	if ( ourmap.count("ghi") > 0 ) {
		cout << "ghi is present" << endl;
	}

	// erase an element
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

}