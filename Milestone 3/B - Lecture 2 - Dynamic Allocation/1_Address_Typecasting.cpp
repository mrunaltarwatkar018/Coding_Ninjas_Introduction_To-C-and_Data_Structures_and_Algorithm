// Dynamic Allocation

#include<iostream>
using namespace std;

int main() {
    int i = 65;
    char c = i;         // Implecet Typecasting
    cout << "The value of c is : " << c << endl;

    int *p = &i;
    char * pc = (char *)p;      // Explecet Typecasting

    cout << "The value of p is : " << p << endl;
    cout << "The value of pc is : " << pc << endl;
    cout << "The value of *p is : " << *p << endl;
    cout << "The value of *pc is : " << *pc << endl;
    cout << "The value of *(pc + 1) is : " << *(pc + 1) << endl;
    cout << "The value of *(pc + 2) is : " << *(pc + 2) << endl;
    cout << "The value of *(pc + 3) is : " << *(pc + 3) << endl;
}