#include<iostream>
using namespace std;
#include "4_TemplatePairClass.cpp"


// int main() {


//     Pair1<int> p1;

//     p1.setX(10);
//     p1.setY(20);

//     cout << "For Object : p1 - " << endl;
//     cout << "X : " << p1.getX() << endl;
//     cout << "Y : " << p1.getY() << endl;


//     Pair1<double> p2;

//     p2.setX(100.34);
//     p2.setY(34.21);


//     cout << "For Object : p2 - " << endl;
//     cout << "X : " << p2.getX() << endl;
//     cout << "Y : " << p2.getY() << endl;


//     Pair1<char> p3;

//     /*
//     p3.setX("Mrunal");
//     p3.setY("Shardul");

//     cout << "For Object : p3 - " << endl;
//     cout << "X : " << p3.getX() << endl;
//     cout << "Y : " << p3.getY() << endl;
//     */

// }

// int main() {

//     Pair2<int, double> p1;

//     p1.setX(100.34);
//     p1.setY(100.34);

//     cout << "For Object : p1 - " << endl;
//     cout << "X : " << p1.getX() << endl;
//     cout << "Y : " << p1.getY() << endl;
// }


int main() {

    Pair2<Pair2<int, int>, int> p2;

    p2.setY(10);

    Pair2<int, int> p4;

    p4.setX(5);
    p4.setY(16);

    p2.setX(p4);




    cout << "For Object : p2 - " << endl;
    // cout << "X : " << p2.getX() << endl;
    cout << "For pair p4 : " << "X : " << p2.getX().getX() << endl;
    cout << "For pair p4 : " << "Y : " << p2.getX().getY() << endl;
    cout << "For pair p2 : " << "Y : " << p2.getY() << endl;


    cout << endl;
    cout << endl;

    char s= 'a';

    Pair2<int, Pair2<double, char>> p5;

    p5.setX(101);

    Pair2<double, char> p6;

    p6.setX(102.52);
    p6.setY(s);

    p5.setY(p6);

    cout << "For Object : p5 - " << endl;
    // cout << "X : " << p2.getX() << endl;
    cout << "For pair p5 : " << "X : " << p5.getX() << endl;
    cout << "For pair p6 : " << "X : " << p5.getY().getX() << endl;
    cout << "For pair p6 : " << "Y : " << p5.getY().getY() << endl;

}