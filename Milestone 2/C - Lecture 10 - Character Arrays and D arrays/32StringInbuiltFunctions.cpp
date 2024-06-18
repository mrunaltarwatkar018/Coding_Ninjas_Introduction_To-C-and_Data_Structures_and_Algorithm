#include<iostream>
#include<cstring>
using namespace std;

// int main() {
    
//     char input1[100], input2[100];
//     cout << "Enter the String1 : ";
//     cin >> input1;
//     cout << "Enter the String2 : ";
//     cin >> input2; 
//     // To count length of the string, we have to use : "strlen(string_name)" function.
//     int len = strlen(input1);       
//     cout << "The length of the string is : " << len << endl;

//     // To compare 2 strings, we have to use : "strcmp(input_1, input_2)" Function
//     /* 
//         iff above function return 0, then our string will be EQUAL, 
//         otherwise if this function return ANY NON_ZERO VALUE, then our string NOT-EQUAL.
//     */
//    if( strcmp(input1, input2) ==0 ) {
//     cout << "String is Equal : True";
//    } else {
//     cout << "String not Equal : False";
//    }

//    // To Copy the Source_string in to the Destination_string, we have to use : "strcpy(destination_string, source_string)" Function
//     char string1[100] = "abcd";
//     char string2[100] = "def";
//     cout << "Before Copying : " << endl;
//     cout << "String1 : " << string1 << endl;
//     cout << "String2 : " << string2 << endl;
//     strcpy(string1, string2);
//     strcpy(string2, "MRunal");
//     cout << "After Copying : " << endl;
//     cout << "String1 : " << string1 << endl;
//     cout << "String2 : " << string2 << endl;    


//     //To Copy only a specified number of characters from source_string to destination_string, we have to use : "strncpy(destination_string, source_string, number_of_characters_to_copy)" Function
//     char string1[100] = "abcdefg";
//     char string2[100] = "Mrunal";
//     char string3[100] = "xy";
//     cout << "Before Copying : " << endl;
//     cout << "String1 : " << string1 << endl;
//     cout << "String2 : " << string2 << endl;
//     strncpy(string1, string2, 3);
//     strncpy(string2, string3, 4);
//     cout << "After Copying : " << endl;
//     cout << "String1 : " << string1 << endl;
//     cout << "String2 : " << string2 << endl;   
//     cout << "String3 : " << string3 << endl;    
// }


/*
    PROBLEM : 
    Que. :  1)  Enter the string :  abcd
                          output :  a
                                    ab
                                    abc
                                    abcd
            2)  Enter the string :  Mrunal
                                    M
                                    Mr
                                    Mru
                                    Mrun
                                    Mruna
                                    Mrunal

*/
void printAllPrefixes(char input[]) {

    // Here, 'i' represents end index of my prefix
    for ( int i = 0; input[i] != '\0'; i++ ) {
        //Here, 'j' represents start index of my prefix
        for ( int j = 0; j <= i; j++ ) {
            cout << input[j];
        }
        cout << endl;
    }
}

int main() {
    char input[100];
    cout << "Enter the string : ";
    cin >> input;

    printAllPrefixes(input);
}