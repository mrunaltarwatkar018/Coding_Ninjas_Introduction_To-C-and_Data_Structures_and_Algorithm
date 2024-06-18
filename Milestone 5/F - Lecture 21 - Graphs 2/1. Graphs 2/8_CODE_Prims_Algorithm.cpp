/* =================================================================================================================== */
/* 
    Question  : Code : Prim's Algorithm

                    Given an undirected, connected and weighted graph G(V, E) 
                    with V number of vertices (which are numbered from 0 to V-1) 
                    and E number of edges.

                    Find and print the Minimum Spanning Tree (MST) using 
                    Prim's algorithm.

                    
                    For printing MST follow the steps -
                        1.  In one line, print an edge which is part of MST 
                            in the format - 
                                v1 v2 w
                            where, v1 and v2 are the vertices of the edge which is 
                            included in MST and whose weight is w. And v1 <= v2 i.e. 
                            print the smaller vertex first while printing an edge.
                        2.  Print V-1 edges in above format in different lines.

                    Note :  Order of different edges doesn't matter.

                Input format : 
                        Line 1: Two Integers V and E (separated by space)
                        
                        Next E lines : Three integers ei, ej and wi, denoting 
                        that there exists an edge between vertex ei and vertex 
                        ej with weight wi (separated by space)

                Output Format : 
                        Print the MST, as described in the task.

                Constraints :  
                        2 <= V, E <= 10^5
                        1 <= Wi <= 10^5

                        Time Limit: 1 sec

                Sample Input 1 :    
                        4 4
                        0 1 3
                        0 3 5
                        1 2 1
                        2 3 8

                            3
                    0 ------------- 1
                    |               |
                5   |               |   1
                    |               |
                    3 ------------- 2  
                            8

                      Input Graph


                Sample Output 1 :   
                        0 1 3
                        1 2 1
                        0 3 5


                            3
                    0 ------------- 1
                    |               |
                5   |               |   1
                    |               |
                    3               2  
                            
                    Minimum Spanning Tree

*/


// First Approach


#include <iostream>
#include <climits>
using namespace std;

long findMinimumVertex(long *weights, bool *visited, long v) {
    long vertex = -1;
    for (long i = 0; i < v; i++) {
        if (!visited[i] && (vertex == -1 || weights[i] < weights[vertex]))
            vertex = i;
    }

    return vertex;
}

int main() {
    // Write your code here
    long v, e;
    cin >> v >> e;

    long **edges = new long *[v];

    for (long i = 0; i < v; i++) {
        edges[i] = new long[v];
        for (long j = 0; j < v; j++)
            edges[i][j] = 0;
    }

    for (long i = 0; i < e; i++) {
        long start, end, weight;
        cin >> start >> end >> weight;
        edges[start][end] = weight;
        edges[end][start] = weight;
    }

    // Prim's algorithm

    bool *visited = new bool[v];
    long *weights = new long[v];
    long *parents = new long[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    parents[0] = -1;
    weights[0] = 0;

    for (long i = 0; i < (v - 1); i++) {
        long vertex = findMinimumVertex(weights, visited, v);
        visited[vertex] = true;

        for (long j = 0; j < v; j++) {
            if (edges[vertex][j] && !visited[j] && edges[vertex][j] < weights[j]) {
                parents[j] = vertex;
                weights[j] = edges[vertex][j];
            }
        }
    }

    for (long i = 1; i < v; i++)
        cout << min(i, parents[i]) << " " << max(i, parents[i]) << " " << weights[i] << "\n";

    for (int i = 0; i < v; i++)
        delete edges[i];

    delete[] edges;
    delete[] weights;
    delete[] parents;
    delete[] visited;
    
    return 0;
}

// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(E * log(V))
    Space compleity: O(V^2)

    where E is the number of edges in the graph and
    V is the number of vertices in the graph
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &weights, vector<bool> &visited, int v) {
    int minVertex = -1;

    for (int i = 0; i < v; ++i) {
        if (!visited[i] &&
                (minVertex == -1 || weights[i] < weights[minVertex])) {
            minVertex = i;
        }
    }

    return minVertex;
}

void printMST(vector<vector<int>> &graph, int v) {
    vector<int> parent(v);
    vector<int> weights(v, INT_MAX);
    vector<bool> visited(v, false);

    parent[0] = -1;
    weights[0] = 0;

    for (int i = 0; i < v - 1; ++i) {
        // Find Min Vertex
        int minVertex = findMinVertex(weights, visited, v);
        visited[minVertex] = true;

        // Explore unvisted neighbours
        for (int j = 0; j < v; ++j) {
            if (graph[minVertex][j] != 0 && !visited[j]) {
                if (graph[minVertex][j] < weights[j]) {
                    weights[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < v; ++i) {
        cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weights[i] << "\n";
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, 0));
    
    for (int i = 0, s, d, weight; i < e; ++i) {
        cin >> s >> d >> weight;
        graph[s][d] = weight;
        graph[d][s] = weight;
    }

    printMST(graph, v);
}



// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
    Time complexity: O(E * log(V))
    Space compleity: O(V^2)

    where E is the number of edges in the graph and
    V is the number of vertices in the graph
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &weights, vector<bool> &visited, int v) {
    int minVertex = -1;

    for (int i = 0; i < v; ++i) {
        if (!visited[i] &&
                (minVertex == -1 || weights[i] < weights[minVertex])) {
            minVertex = i;
        }
    }

    return minVertex;
}

void printMST(vector<vector<int>> &graph, int v) {
    vector<int> parent(v);
    vector<int> weights(v, INT_MAX);
    vector<bool> visited(v, false);

    parent[0] = -1;
    weights[0] = 0;
    
    for (int i = 0; i < v - 1; ++i) {
        // Find Min Vertex
        int minVertex = findMinVertex(weights, visited, v);
        visited[minVertex] = true;

        // Explore unvisted neighbours
        for (int j = 0; j < v; ++j) {
            if (graph[minVertex][j] != 0 && !visited[j]) {
                if (graph[minVertex][j] < weights[j]) {
                    weights[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < v; ++i) {
        cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weights[i] << "\n";
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, 0));
    
    for (int i = 0, s, d, weight; i < e; ++i) {
        cin >> s >> d >> weight;
        graph[s][d] = weight;
        graph[d][s] = weight;
    }

    printMST(graph, v);
}