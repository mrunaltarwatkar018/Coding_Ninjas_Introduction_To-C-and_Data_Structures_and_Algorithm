/* =================================================================================================================== */
/* 
    Question  : Code : BFS Traversal

                    Given an undirected and disconnected graph G(V, E), 
                    print its BFS traversal.
                
                Note:

                    1.  Here you need to consider that you need to print 
                        BFS path starting from vertex 0 only. 
                    2.  V is the number of vertices present in graph G 
                        and vertices are numbered from 0 to V-1. 
                    3.  E is the number of edges present in graph G.
                    4.  Take graph input in the adjacency matrix.
                    5.  Handle for Disconnected Graphs as well

                Input format : 
                        The first line of input contains two integers, 
                        that denote the value of V and E.

                        Each of the following E lines contains space 
                        separated two integers, that denote that there 
                        exists an edge between vertex a and b.

                Output Format : 
                        Print the BFS Traversal, as described in the task.

                Constraints :  
                        0 <= V <= 1000
                        0 <= E <= (V * (V - 1)) / 2
                        0 <= a <= V - 1
                        0 <= b <= V - 1

                        Time Limit: 1 sec

                Sample Input 1 :    
                        4 4
                        0 1
                        0 3
                        1 2
                        2 3
                                          
                Sample Output 1 :   
                        0 1 3 2

*/


// Firat Approach

#include <iostream>
#include <queue>
using namespace std;

void print(bool **edges, long long v, long long sv, bool *visited) {
    queue<long long> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty()) {
        cout << pendingVertices.front() << " ";

        for (long long i = 0; i < v; i++) {
            if (i == pendingVertices.front())
                continue;

            if (visited[i])
                continue;

            if (edges[pendingVertices.front()][i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
        pendingVertices.pop();
    }
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

    for (long long i = 0; i < e; i++)  {
        long long start, end;
        cin >> start >> end;
        edges[start][end] = true;
        edges[end][start] = true;
    }

    bool *visited = new bool[v];

    for (long long i = 0; i < v; i++) {
        visited[i] = false;
    }

    for (long long i = 0; i < v; i++) {
        if (!visited[i])
            print(edges, v, i, visited);
    
    }
    delete[] visited;

    for (long long i = 0; i < v; i++)
        delete edges[i];

    delete[] edges;

    return 0;
}


// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(V + E)
    Space complexity: O(V^2)

    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/
#include <iostream>
#include <queue>
using namespace std;

void singleComponentBFS(bool** graph, int v, bool* visited, int vertex) {
    queue<int> pendingVertices;
    pendingVertices.push(vertex);
    visited[vertex] = true;

    while (!pendingVertices.empty()) {
        int frontVertex = pendingVertices.front();
        pendingVertices.pop();

        cout << frontVertex << " ";

        for (int i = 0; i < v; ++i) {
            if (graph[frontVertex][i] && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(bool** graph, int v) {
    bool* visited = new bool[v]();

    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            singleComponentBFS(graph, v, visited, i);
        }
    }

    delete[] visited;
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

    BFS(graph, v);

    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }

    delete[] graph;
}

// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
    Time complexity: O(V + E)
    Space complexity: O(V^2)
    
    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/

#include <iostream>
#include <queue>
using namespace std;

void singleComponentBFS(bool** graph, int v, bool* visited, int vertex) {
    queue<int> pendingVertices;
    pendingVertices.push(vertex);
    visited[vertex] = true;
    
    while (!pendingVertices.empty()) {
        int frontVertex = pendingVertices.front();
        pendingVertices.pop();

        cout << frontVertex << " ";
        
        for (int i = 0; i < v; ++i) {
            if (graph[frontVertex][i] && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(bool** graph, int v) {
    bool* visited = new bool[v]();
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            singleComponentBFS(graph, v, visited, i);
        }
    }
    
    delete[] visited;
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
    
    BFS(graph, v);
    
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    
    delete[] graph;
}