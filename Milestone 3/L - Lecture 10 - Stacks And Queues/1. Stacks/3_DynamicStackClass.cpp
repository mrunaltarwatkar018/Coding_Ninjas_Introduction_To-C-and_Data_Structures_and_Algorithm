#include<iostream>
#include<climits>
#include <limits.h>
using namespace std;

class StackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

    public :

    StackUsingArray() {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    // return the number of elements present in my stack

    int size() {
        return nextIndex;
    }


    // to check if my stack is empty or not

    bool isEmpty() {
        // if ( nextIndex == 0 ) {
        //     return true;
        // } else {
        //     return false;
        // }

        /* Above code in one line */
        return nextIndex == 0;
    }


    // to insert an element in the stack 

    void push( int element ) {

        if ( nextIndex == capacity ) {
            int *newData = new int[2 * capacity];
            for ( int i = 0; i < capacity; i++ ) {
                newData[i] = data[i];
            }
            capacity *= 2;

            delete [] data;
            data = newData;
            /* cout << "Stack is Full" << endl;
            return; */
        }
        data[nextIndex] = element;
        nextIndex++;
    }


    // to delete the element

    int pop() {

        // if ( nextIndex == 0 ) {
        //     cout << "Stack Is Empty" << endl;
        // }
        // OR

        if ( isEmpty() ) {
            cout << "Stack Is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // to knowwing the position of stack
    int top() {
        if ( isEmpty() ) {
            cout << "Stack Is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};