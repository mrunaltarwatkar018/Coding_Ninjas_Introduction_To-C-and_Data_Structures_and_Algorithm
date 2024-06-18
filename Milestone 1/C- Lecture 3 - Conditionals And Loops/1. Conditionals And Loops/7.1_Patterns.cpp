#include<iostream>
using namespace std;


/*
    if N = 5 then
    55555
    55555
    55555
    55555
    55555
*/

int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
	int rows;
	cin >> rows;

	int i = 1;

    // for (int i = 1; i <= rows; i++) {
    //   int j = 1;
    //   for ( int j = 1; j <= rows; j++) {
	// 	  cout << rows;
	//   }
    //   cout << endl;
    // }

        for (int i = 1; i <= rows; i++) {
          int j = 1;
          do {
			  cout << rows;
			  j++;
		  } while ( j <= rows);
          cout << endl;
        }

    // for ( int i = 1; i <= rows; i++) {
    //       int j = 1;
    //       while (j <= rows) {
    //         cout << rows;
    //         j++;
    //       }
    //       cout << endl;
    //     }


	// while ( i <= rows ) {
	// 	int j = 1;
	// 	while ( j<= rows ) {
	// 		cout << rows;
	// 		j++;
	// 	}
	// 	cout << endl;
	// 	i++;
	// }
}


