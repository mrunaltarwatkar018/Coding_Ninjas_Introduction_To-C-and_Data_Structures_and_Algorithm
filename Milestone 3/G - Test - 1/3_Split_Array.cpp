
/* =================================================================================================================== */
/* 
    Question  : Split Array
                    Given an integer array A of size N, check if the input array 
                        - Sum of both parts is equal
                        - All elements in the input, which are divisible by 5 
                          should be in same group.
                        - All elements in the input, which are divisible by 3 
                          (but not divisible by 5) should be in other group.
                        - Elements which are neither divisible by 5 nor by 3, 
                          can be put in any group.  
                    Groups can be made with any set of elements, i.e. elements 
                    need not to be continuous. And you need to consider each and 
                    every element of input array in some group.
                    Return true, if array can be split according to the above 
                    rules, else return false.

                Note : 
                    You will get marks only if all the test cases are passed.
        
                Input format : 
                                Line 1 : Integer N (size of array)
                                Line 2 : Array A elements (separated by space)

                Output Format : 
                                true or false

                Constraints :   
                                0 <= N <= 50
                                

                Sample Input 1 : 2        
                                 1 2   
                                           
                Sample Output 1 : false

                Sample Input 1 :    3
                                    1 4 3
                                            
                Sample Output 1 : true
*/

#include <iostream>
using namespace std;

bool spliter(int arr[], int n, int start, int ls, int rs)
{

    if (start == n)
        return ls == rs;
    if (arr[start] % 5 == 0)
        ls += arr[start];
    else if (arr[start] % 3 == 0)
        rs += arr[start];
    else
        return spliter(arr, n, start + 1, ls + arr[start], rs) || spliter(arr, n, start + 1, ls, rs + arr[start]);
    return spliter(arr, n, start + 1, ls, rs);
}
bool splitArray(int *input, int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return spliter(input, size, 0, 0, 0);
}


// Another Apporach
bool checkBalance(int *input, int size, int n, int l, int r) {
    if ( n == size ) {
        return l == r;
    }

    if ( input[0] % 3 == 0 && input[0] % 5 != 0 ) {
        l += input[0];
    }
    else if ( input[0] % 5 == 0 ) {
        r += input[0];
    }
    else {
        return checkBalance(input + 1, size, n+1, l+input[0], r) || checkBalance(input+1, size, n+1, l, r + input[0]);
    }
    return checkBalance(input+1, size, n+1, l, r);
}


bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
    */
    return checkBalance(input, size, 0, 0, 0);
    
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}