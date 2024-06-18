#include<iostream>
using namespace std;
#include "tempclass.cpp"

int main() {
    Student s1(100, 23);
    cout << s1.rollNumber << " " << s1.age;
}