#include<iostream>
using namespace std;
#include "3_QueueUsingArray.h"
#include<queue>


/*
    Header file name :                  ---------------->           #include<queue>

    In Not Inbuild Queue                ---------------->           in Inbuilt Queues

    enqueue( T element )                ---------------->           void push( T element );
    T front()                           ---------------->           T front();
    T dequeue()                         ---------------->           void pop();
    int getSize()                       ---------------->           int size();
    bool isEmpty()                      ---------------->           bool empty();

*/




int main() {

    queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);

	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	cout << q.empty() << endl;

	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}