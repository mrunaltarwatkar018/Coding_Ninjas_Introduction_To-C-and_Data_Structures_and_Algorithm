#include <iostream>
using namespace std;
#include <queue>

	
int main() {
	priority_queue<int, vector<int>, greater<int> > p;

	p.push(100);
	p.push(21);
	p.push(7);
	p.push(165);
	p.push(78);
	p.push(4);

	cout << "Size : " << p.size() << endl;
	cout << "Empty or not : " << p.empty() << endl;
	cout << "top : " << p.top() << endl;


	while( !p.empty() ) {
		cout << p.top() << endl;
		p.pop();
	}
}


/*
        OUTPUT :
                    Size : 6
                    Empty or not : 0
                    top : 4
                    4
                    7
                    21
                    78
                    100
                    165
*/