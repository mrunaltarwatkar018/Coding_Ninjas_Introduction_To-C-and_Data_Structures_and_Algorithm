/* =================================================================================================================== */
/* 
    Question  : Number Pattern 1
                
                Print the following pattern

                Pattern for N = 4

                                1
                                23
                                345
                                4567

                Input format : 
                                N (Total no. of rows)

                Output Format : 
                                Pattern in N lines

                Sample Input 1 :    
                                    3


                Sample Output 1 :
                                    1
                                    23
                                    345
                                                                                                            
*/


// First method
#include<iostream>
using namespace std;

 int main() {
    int n;
    cin >> n;

    int start =1; 
	while(start<=n){
		  
		int len= start; 
	    for(int i=start ; i<start+len ; i++){
			cout<<i; 
		} 

		cout<<endl; 
		start++; 
	} 
	
}


// Another Method
#include<iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    int i = 1;
    while(i <= n){
        int col = 1;
        int value = i;
        while(col <= i){
            cout << value;
            value = value + 1;
            col = col + 1;
        }
        cout << endl;
        i = i + 1;
    }
} 