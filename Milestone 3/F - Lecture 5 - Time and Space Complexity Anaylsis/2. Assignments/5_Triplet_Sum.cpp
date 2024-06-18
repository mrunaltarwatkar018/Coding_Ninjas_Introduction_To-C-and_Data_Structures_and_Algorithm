
/* =================================================================================================================== */
/* 
    Question  : Triplet Sum
                You have been given a random integer array/list(ARR) and a number X. 
                Find and return the triplet(s) in the array/list which sum to X.

                Note : 
                        Third line contains an integer 'X'.

                Input format : 
                                The first line contains an Integer 't' which denotes 
                                the number of test cases or queries to be run. Then the 
                                test cases follow.
                                First line of each test case or query contains an 
                                integer 'N' representing the size of the array/list.
                                Second line contains 'N' single space separated integers 
                                representing the elements in the array/list.
                                Third line contains an integer 'X'.

                Output Format : 
                                For each test case, print the unique element present in the array.
                                Output for every test case will be printed in a separate line.

                Constraints :   1 <= t <= 10^2
                                0 <= N <= 10^3
                                0 <= X <= 10^9
                                Time Limit: 1 sec

                Sample Input 1 : 1        
                                 7   
                                 1 2 3 4 5 6 7
                                 12
                Sample Output 1 : 5

                Sample Input 2 :    2
                                    7
                                    1 2 3 4 5 6 7
                                    19
                                    9
                                    2 -5 8 -6 0 5 10 11 -3
                                    10       
                Sample Output 2 :   0
                                    5 

                Explanation for Input 2 :
                                        Since there doesn't exist any triplet with sum equal 
                                        to 19 for the first query, we print 0.
                                        For the second query, we have 5 triplets in total 
                                        that sum up to 10. They are, (2, 8, 0), (2, 11, -3), 
                                        (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)                 
*/


#include <iostream>
using namespace std;

int pairSum ( int *arr, int start, int end, int target ) {
  	// Write your code here
 	int finalCount = 0;
  	while (start < end) {
    	// case1 when more than target
    	if (arr[start] + arr[end] > target) {
    	  end--;
    	}

    	// case2 when less than target
    	else if (arr[start] + arr[end] < target) {
			start++;
		}
		// case3 when equal to target
		else {
			// case 3-a when elements having more of similar elements
			int startIndex = start;
			int endIndex = end;
			if ( arr[start] == arr[end] ) {
				int betweenIndexes = ( end - start ) + 1;
				finalCount += ( betweenIndexes * ( betweenIndexes - 1)) / 2;
				return finalCount;
			}
			// case 3-b when we are finding internal matches
			int newStart = start + 1;
			int newEnd =end - 1;

			while ( newStart <= newEnd && arr[newStart] == arr[start]) {
				newStart++;
			}

			while ( newStart <= newEnd && arr[newEnd] == arr[end]) {
				newEnd--;
			}

			int eleFromStart = newStart - start;
			int eleFromEnd = end - newEnd;

			finalCount += ( eleFromStart * eleFromEnd);
			start = newStart;
			end = newEnd;
		}
 	}
	 return finalCount;
}


int tripletSum(int *arr, int n, int num)
{
	//Write your code here
	if ( n == 0 ) {
		return 0;
	}

	sort( arr, arr + n);

	int finalCount = 0;

	for ( int i = 0; i < n; i++ ) {
		int pairSumFor = num - arr[i];
		finalCount += pairSum(arr, i + 1, n - 1, pairSumFor);
	}
	return finalCount;
}


// Another Apporah
// int pairSum(int *arr, int startIndex, int endIndex, int num)
// {
//     int numPair = 0;
//     while (startIndex < endIndex)
//     {
//         if (arr[startIndex] + arr[endIndex] < num)
//         {
//             startIndex++;
//         }
//         else if (arr[startIndex] + arr[endIndex] > num)
//         {
//             endIndex--;
//         }
//         else
//         {
//             int elementAtStart = arr[startIndex];
//             int elementAtEnd = arr[endIndex];
//             if (elementAtStart == elementAtEnd)
//             {
//                 int totalElementsFromStartToEnd = (endIndex - startIndex) + 1;
//                 numPair += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1) / 2);
//                 return numPair;
//             }
//             int tempStartIndex = startIndex + 1;
//             int tempEndIndex = endIndex - 1;
//             while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart)
//             {
//                 tempStartIndex += 1;
//             }
//             while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == elementAtEnd)
//             {
//                 tempEndIndex -= 1;
//             }
//             int totalElementsFromStart = (tempStartIndex - startIndex);
//             int totalElementsFromEnd = (endIndex - tempEndIndex);
//             numPair += (totalElementsFromStart * totalElementsFromEnd);
//             startIndex = tempStartIndex;
//             endIndex = tempEndIndex;
//         }
//     }
//     return numPair;
// }

// int tripletSum(int *arr, int n, int num)
// {
//     sort(arr, arr + n);
//     int numTriplets = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int pairSumFor = num - arr[i];
//         int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor);
//         numTriplets += numPairs;
//     }
//     return numTriplets;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        int x;
        cin >> size;
        int *input = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cin >> x;
        cout << tripletSum(input, size, x) << endl;
        delete[] input;
    }
    return 0;
}
