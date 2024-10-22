/* =================================================================================================================== */
/* 
    Question  : Sum of Even Numbers till N
                
                Given a number N, print sum of all even numbers from 1 to N.

                Input format : 
                                Integer N

                Output Format : 
                                Required Sum S

                Sample Input 1 :    
                                    6

                Sample Output 1 :
                                    12
                                                                        
*/


/*
	Pre-requisite to solve this problem:
	In this question, we have to find sum of all even numbers till n. 
	To take sum of all the even numbers, we have to take a variable 
	and initialize it to zero. Let us name this variable as sum. 
	Following code is used to add 2 to sum variable and update it to the same sum variable:
	sum = sum + 2 
	
	Hint to solve this problem: We will have to loop on even numbers only and add the even 
	numbers to the same sum variable, described above.
*/  


#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int sum = 0;
	int i = 0;
	while ( i <= n ) {
		sum = sum + i;
		i = i + 2;
	}
	cout << sum << endl;
}