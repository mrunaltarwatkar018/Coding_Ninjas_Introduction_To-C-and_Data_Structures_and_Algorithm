/* =================================================================================================================== */
/* 
    Question  : Loot Houses
                
                A thief wants to loot houses. He knows the amount 
                of money in each house. He cannot loot two consecutive 
                houses. Find the maximum amount of money he can loot.

                Input format : 
                        The first line of input contains an integer value 
                        of 'n'. It is the total number of houses.

                        The second line of input contains 'n' integer 
                        values separated by a single space denoting the 
                        amount of money each house has.

                Output Format : 
                       Print the the maximum money that can be looted.

                Constraints :  
                        0 <= n <= 10 ^ 4

                        Time Limit: 1 sec

                Sample Input 1 :    
                        6
                        5 5 10 100 10 5
                                          
                Sample Output 1 :   
                        110

                Sample Input 2 :    
                        6
                        10 2 30 20 3 50
                                          
                Sample Output 2 :   
                        90

                Explanation of Sample Output 2 :
                        Looting first, third, and the last houses([10 + 30 + 50]) 
                        will result in the maximum loot, and all the other 
                        possible combinations would result in less than 90.
*/

#include <iostream>
using namespace std;

// First Approach
int maxMoneyLooted(int *arr, int n) {
    int *output = new int[n];
    output[0] = arr[0];
    output[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
        output[i] = max(output[i - 1], output[i - 2] + arr[i]);
    return output[n - 1];
}

// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity : O(n)
    Space complexity : O(n)

    where n is the total number of houses
*/

int maxMoneyLooted(int *houses, int n) {
    /*
        We are assuming that the n houses are numbered from 0 to n - 1.
        maxMoney[i] stores the maximum amount of money that can be looted
        from houses numbered 0 to i (both inclusive).
    */

    int *maxMoney = new int[n];
    maxMoney[0] = houses[0];

    if (n > 1) {
        maxMoney[1] = max(houses[1], maxMoney[0]);
    }

    for (int i = 2; i < n; i++) {
        //maxMoney[i-2] + houses[i] : In case we are including current element
        //maxMoney[i-1] : In case we are excluding current element
        
        maxMoney[i] = max(maxMoney[i - 2] + houses[i], maxMoney[i - 1]);
    }

    int result = maxMoney[n - 1];


    delete[] maxMoney;
    
    return result;
}


// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
    Time complexity : O(n)
    Space complexity : O(n)

    where n is the total number of houses
*/
int maxMoneyLooted(int *houses, int n) {
    /*
        We are assuming that the n houses are numbered from 0 to n - 1.
        maxMoney[i] stores the maximum amount of money that can be looted
        from houses numbered 0 to i (both inclusive).
    */
    int *maxMoney = new int[n];
    maxMoney[0] = houses[0];

    if (n > 1) {
        maxMoney[1] = max(houses[1], maxMoney[0]);
    }
    
    for (int i = 2; i < n; i++) {
        //maxMoney[i-2] + houses[i] : In case we are including current element
        //maxMoney[i-1] : In case we are excluding current element

        maxMoney[i] = max(maxMoney[i - 2] + houses[i], maxMoney[i - 1]);
    }

    int result = maxMoney[n - 1];

    delete[] maxMoney;

    return result;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}