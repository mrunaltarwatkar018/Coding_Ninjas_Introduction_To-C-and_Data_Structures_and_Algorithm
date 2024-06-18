#include <iostream>
using namespace std;
#include <queue>

	
int main() {
	priority_queue<int> p;

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
                top : 165
                165
                100
                78
                21
                7
                4
*/



/*
    Inbuilt Priority Queue :

            Header file name :                  ---------------->           #include<queue>
            class Name :                        ---------------->           priority_queue<   >

            In Not Inbuild Priority Queue       <---------------->           In Inbuilt Priority Queues

            isEmpty()                         ----------------->           empty()
            getsize()                         ----------------->           size();
            void insert (element)             ----------------->           void push(element);
            getMin()                          ----------------->           T top()   ==> maximimum priority element
            T removeMin()                     ----------------->           void pop()

*/
