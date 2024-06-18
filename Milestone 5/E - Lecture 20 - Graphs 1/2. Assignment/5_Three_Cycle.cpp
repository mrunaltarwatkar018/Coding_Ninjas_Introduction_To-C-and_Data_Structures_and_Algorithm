/* =================================================================================================================== */
/* 
    Question  : 3 Cycle

                    Given a graph with N vertices (numbered from 0 to N-1) and M 
                    undirected edges, then count the distinct 3-cycles in the graph. 
                    A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are 
                    connected by an edge.

                Input format : 
                    The first line of input contains two space separated integers, 
                    that denotes the value of N and M.

                    Each of the following M lines contain two integers, that denote
                    the vertices which have an undirected edge between them. Let us 
                    denote the two vertices with the symbol u and v. 

                Output Format : 
                        Print the count the number of 3-cycles in the given graph

                Constraints :  
                        0 <= N <= 100
                        0 <= M <= (N*(N-1))/2
                        0 <= u <= N - 1
                        0 <= v <= N - 1

                        Time Limit: 1 sec

                Sample Input 1 :    
                        3 3
                        0 1
                        1 2
                        2 0
                                          
                Sample Output 1 :   
                        1

*/

// First Approach

#include <iostream>
using namespace std;

int countCycles(bool **arr, long long n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (j != k && k != i && arr[j][k] == 1) {
                        if (arr[i][k] == 1) {
                            count += 1;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    // Write your code here
    long long v, e;
    cin >> v >> e;

    bool **edges = new bool *[v];

    for (long long i = 0; i < v; i++) {
        edges[i] = new bool[v];

        for (long long j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }

    for (long long i = 0; i < e; i++) {
        long long start, end;
        cin >> start >> end;

        edges[start][end] = true;
        edges[end][start] = true;
    }

    cout << countCycles(edges, v) / 6;
    
    return 0;
}

// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(V^3)
    Space complexity: O(V^2)
    
    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/

#include <iostream>
using namespace std;

int getCycles(bool** graph, int v) {
    int cycleCount = 0;
    
    for (int i = 0; i < v - 2; ++i) {
        for (int j = i + 1; j < v - 1; ++j) {
            for (int k = j + 1; k < v; ++k) {
                if (graph[i][j] && graph[j][k] && graph[k][i]) {
                    ++cycleCount;
                }
            }
        }
    }
    
    return cycleCount;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    bool** graph = new bool*[v];
    
    for (int i = 0; i < v; ++i) {
        graph[i] = new bool[v]();
    }
    
    for (int i = 0, a, b; i < e; ++i) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    cout << getCycles(graph, v);
    
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    
    delete[] graph;
}

// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
    Time complexity: O(V^3)
    Space complexity: O(V^2)
    
    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/
#include <iostream>
using namespace std;

int getCycles(bool** graph, int v) {
    int cycleCount = 0;

    for (int i = 0; i < v - 2; ++i) {
        for (int j = i + 1; j < v - 1; ++j) {
            for (int k = j + 1; k < v; ++k) {
                if (graph[i][j] && graph[j][k] && graph[k][i]) {
                    ++cycleCount;
                }
            }
        }
    }

    return cycleCount;
}

int main() {
    int v, e;
    cin >> v >> e;

    bool** graph = new bool*[v];

    for (int i = 0; i < v; ++i) {
        graph[i] = new bool[v]();
    }

    for (int i = 0, a, b; i < e; ++i) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    cout << getCycles(graph, v);

    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }

    delete[] graph;
}