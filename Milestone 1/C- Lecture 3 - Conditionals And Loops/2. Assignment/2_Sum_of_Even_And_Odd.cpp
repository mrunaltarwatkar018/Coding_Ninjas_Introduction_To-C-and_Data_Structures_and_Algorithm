/* =================================================================================================================== */
/* 
    Question  : Sum of even & odd
                
                Write a program to input an integer N and print the sum 
                of all its even digits and sum of all its odd digits 
                separately.
                
                Digits mean numbers, not the places! That is, if the given 
                integer is "13245", even digits are 2 & 4 and odd digits 
                are 1, 3 & 5.

                Input format : 
                                 Integer N
                Output Format : 
                                Sum_of_Even_Digits Sum_of_Odd_Digits
                                (Print first even sum and then odd sum 
                                separated by space)

                Constraints :   
                                0 <= x <= 8 

                Sample Input 1 :    
                                    1234 
                                          
                Sample Output 1 :   
                                    6 4

                Sample Input 2 :    
                                    552245 
                                          
                Sample Output 2 :   
                                    8 15

                Explanation for Input 2:
                            For the given input, the even digits are 2, 2 
                            and 4 and if we take the sum of these digits 
                            it will come out to be 8(2 + 2 + 4) and similarly, 
                            if we look at the odd digits, they are, 5, 5 and 5 
                            which makes a sum of 15(5 + 5 + 5). Hence the answer
                            would be, 8(evenSum) <single space> 15(oddSum)
*/




// First Method
// #include<iostream>
// using namespace std;

// int main() {
// 	// Write your code here
// 	int n;
// 	cin >> n;
// 	int Sum_of_Even_Digits = 0;
// 	int Sum_of_Odd_Digits = 0;

// 	while (n > 0) {
// 		int last = n % 10;

// 		if ( last % 2 == 0) {
// 			Sum_of_Even_Digits += last;
// 		} else {
// 			Sum_of_Odd_Digits += last;
// 		}

// 		n = n / 10;
// 	}

// 	cout << Sum_of_Even_Digits << " " << Sum_of_Odd_Digits;
	
// }




// Second Method
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int evenSum = 0, oddSum = 0;

    while(n > 0) {
        int last = n % 10;
        if(last % 2 == 0) {
            evenSum = evenSum + last;
        }
        else {
            oddSum = oddSum + last;
        }
        n = n / 10;
    }
    cout<<evenSum<<" "<<oddSum;
}
