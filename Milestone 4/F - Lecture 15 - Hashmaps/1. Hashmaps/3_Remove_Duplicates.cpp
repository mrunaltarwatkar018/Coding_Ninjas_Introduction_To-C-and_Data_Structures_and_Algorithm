


// Given an array of intergers, we need to remove the Duplicates using Unsorted Hashmaps ( inbuilt Hashmaps )

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Time Complexity : O(1)
*/
vector <int> removeDuplicates( int * a, int size ) {
    vector <int> output;
    unordered_map <int, bool> seen;

    for ( int i = 0; i < size; i++ ) {

        if ( seen.count(a[i]) > 0 ) {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main() {
    int a[] = {1,2,3,3,2,1,4,3,6,5,5};
	vector<int> output = removeDuplicates(a, 11);
    
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}


/*
            OUTPUT :
                        1
                        2
                        3
                        4
                        6
                        5
*/