#include<iostream>
using namespace std;

int length(char input[]) {
    int count = 0;
    for ( int i = 0; input[i] != '\0'; i++ ) {
        count++;
    }
    return count;
}

// int main() {
//     char name[100];
//     cout << "Enter your name : ";
//     cin >> name;

//     // name[4] = 'x';
//     // name[3] = 'd';
//     // name[1] = '\0';
//     cout << "Name : " << name << endl;


//     cout << "Length of the String : " << length(name) << endl;
// }

void reverseString(char input[]) {
    int len = length(input);
    int i = 0, j = len - 1;

    while ( i < j ) {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char input[100];
    //cin >> input;
    //cin.getline(input, 100);            // cin.getline( string_name, length )
    //cin.getline( input, 100, 'o');     // cin.getline( string_name, length, delimiter )      Note : by default, gthe value of DELIMITER is '\n'. So avoid DELIMITER.
    cout << "Enter the string : ";
    cin.getline(input, 100);
    cout << "After Reversing the string : ";
    reverseString(input);
    cout << input << endl;
}