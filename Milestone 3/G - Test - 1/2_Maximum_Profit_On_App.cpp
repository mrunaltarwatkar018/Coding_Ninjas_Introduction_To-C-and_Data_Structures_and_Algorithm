
/* =================================================================================================================== */
/* 
    Question  : You have made a smartphone app and want to set its subscription 
                price such that the profit earned is maximised. There are certain users who 
                will subscribe to your app only if their budget is greater than or equal to 
                your price.
                You will be provided with a list of size N having budgets of subscribers and 
                you need to return the maximum profit that you can earn.
                Lets say you decide that price of your app is Rs. x and there are N number of 
                subscribers. So maximum profit you can earn is :
                                                 m * n
                where m is total number of subscribers whose budget is greater than or equal to x.

                Note : 
                    Unique element is always present in the array/list 
                    according to the given condition.
        
                Input format : 
                                Line 1 : N (No. of subscribers)
                                Line 2 : Budget of subscribers (separated by space)

                Output Format : 
                                Maximum profit

                Constraints :   1 <= N <= 10^6
                                1 <=budget[i]<=9999

                Sample Input 1 :    4 
                                    30 20 53 14         
                Sample Output 1 :   60

                Sample Output 1 Explanation :   
                                                Price of your app should be Rs. 20 or Rs. 30. 
                                                For both prices, you can get the profit Rs. 60.

                Sample Input 2 :    5
                                    34 78 90 15 67        
                Sample Output 2 :   201

                Sample Output 2 Explanation :   
                                                Price of your app should be Rs. 67. You can get the 
                                                profit Rs. 201 (i.e. 3 * 67).
*/

#include <iostream>
using namespace std;

#include <algorithm>
int maximumProfit(int budget[], int n)
{
    // Write your code here
    sort(budget, budget + n);
    int max_profit = budget[0] * n;
    for (int i = 1; i < n; i++)
    {
        if (budget[i] * (n - i) > max_profit)
            max_profit = budget[i] * (n - i);
    }
    return max_profit;
}

//Another Approach
int pivot( int budget[], int l, int r ) {
    for ( int i = l; i < r; i++ ) {
        if ( budget[i] <= budget[r] ) {
            if ( i != l ) {
                int perk = budget[i];
                budget[i] = budget[l];
                budget[l] = perk;
            }
            l++;
        }
    }
    if ( l != r ) {
        int perk = budget[l];
        budget[l] = budget[r];
        budget[r] = perk;
    }
    return l;
}

void quickSort( int budget[], int l, int r ) {
    if ( l < r ) {
        int pi = pivot( budget, l, r );
        quickSort( budget, l, pi - 1 );
        quickSort( budget, pi + 1, r );
    }
}

int maximumProfit(int budget[], int n) {
    // Write your code here
    quickSort( budget, 0, n - 1 );
    int maxProfit = 0;
    for ( int i = 0; i < n; i++ ) {
        maxProfit = max(maxProfit, budget[i] * (n - i));
    }
    return maxProfit;
}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    cout << maximumProfit(input, n) << endl;
}