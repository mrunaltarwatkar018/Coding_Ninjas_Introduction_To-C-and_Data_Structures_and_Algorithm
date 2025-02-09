/* =================================================================================================================== */
/* 
    Question  : Code : Has Path

                    Given an undirected graph G(V, E) and two vertices v1 
                    and v2 (as integers), check if there exists any path 
                    between them or not. Print true if the path exists and 
                    false otherwise.
                
                Note:

                    1.  V is the number of vertices present in graph G and 
                        vertices are numbered from 0 to V-1.  
                    2.  E is the number of edges present in graph G.

                Input format : 
                        The first line of input contains two integers, that 
                        denote the value of V and E.
                        
                        Each of the following E lines contains two integers, 
                        that denote that there exists an edge between 
                        vertex 'a' and 'b'.
                        
                        The following line contain two integers, that denote 
                        the value of v1 and v2.

                Output Format : 
                        The first and only line of output contains true, if 
                        there is a path between v1 and v2 and false otherwise.

                Constraints :  
                        0 <= V <= 1000
                        0 <= E <= 1000
                        0 <= a <= V - 1
                        0 <= b <= V - 1
                        0 <= v1 <= V - 1
                        0 <= v2 <= V - 1

                        Time Limit: 1 sec

                Sample Input 1 :    
                        4 4
                        0 1
                        0 3
                        1 2
                        2 3
                        1 3
                                          
                Sample Output 1 :   
                        true

                Sample Input 2 :    
                        6 3
                        5 3
                        0 1
                        3 4
                        0 3
                                                                
                Sample Output 2 :   
                        false
*/

// First Approach

#include <iostream>
#include <queue>
using namespace std;

bool hasPath(bool **edges, long long v, bool *visited, long long v1, long long v2) {
    if (v2 >= v || v1 >= v)
        return false;

    if (v1 == v2)
        return true;

    if (edges[v1][v2] || edges[v2][v1])
        return true;

    queue<long long> pendingVertices;

    pendingVertices.push(v1);

    visited[v1] = true;

    while (!pendingVertices.empty()) {
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

        if (visited[v2])
            return true;
    }

    return false;
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

    bool *visited = new bool[v];

    for (long long i = 0; i < v; i++) {
        visited[i] = false;
    }

    long long v1, v2;

    cin >> v1 >> v2;

    if (hasPath(edges, v, visited, v1, v2))
        cout << "true";
    else
        cout << "false";

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
using namespace std;

bool hasPathHelper(bool** graph, int v, int start, int end, bool* visited) {
    if (start == end) {
        return true;
    }
    
    visited[start] = true;
    
    for (int i = 0; i < v; ++i) {
        if (graph[start][i] && !visited[i]) {
            if (hasPathHelper(graph, v, i, end, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool hasPath(bool** graph, int v, int start, int end) {
    bool* visited = new bool[v]();
    
    return hasPathHelper(graph, v, start, end, visited);
    
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
    
    int start, end;
    cin >> start >> end;
    cout << (hasPath(graph, v, start, end) ? "true" : "false");
    
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
using namespace std;

bool hasPathHelper(bool** graph, int v, int start, int end, bool* visited) {
    if (start == end) {
        return true;
    }
    
    visited[start] = true;
    
    for (int i = 0; i < v; ++i) {
        if (graph[start][i] && !visited[i]) {
            if (hasPathHelper(graph, v, i, end, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool hasPath(bool** graph, int v, int start, int end) {
    bool* visited = new bool[v]();
    return hasPathHelper(graph, v, start, end, visited);
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
    
    int start, end;
    cin >> start >> end;
    cout << (hasPath(graph, v, start, end) ? "true" : "false");
    
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    
    delete[] graph;
}