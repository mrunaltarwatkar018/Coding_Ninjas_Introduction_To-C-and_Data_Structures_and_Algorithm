/* =================================================================================================================== */
/* 
    Question  : Code : Is Connected ?

                    Given an undirected graph G(V,E), check if the graph G 
                    is connected graph or not.
                
                Note:
                    1.  V is the number of vertices present in graph G and 
                        vertices are numbered from 0 to V-1. 
                    2.  E is the number of edges present in graph G.

                Input format : 
                    The first line of input contains two integers, that denote 
                    the value of V and E.
                    
                    Each of the following E lines contains two integers, that 
                    denote that there exists an edge between vertex a and b.

                Output Format : 
                        The first and only line of output contains "true" if 
                        the given graph is connected or "false", otherwise.

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
                        1 3
                                          
                Sample Output 1 :   
                        true

                Sample Input 2 :    
                        4 3
                        0 1
                        1 3 
                        0 3
                                          
                Sample Output 2 :   
                        false   
                
                Sample Output 2 Explanation :
                        The graph is not connected, even though vertices 
                        0,1 and 3 are connected to each other but there 
                        isn’t any path from vertices 0,1,3 to vertex 2. 
*/


// First Approach

#include <iostream>
using namespace std;
#include <queue>

bool checkIsConnected(int **edges, int n, int start) {
    queue<int> vertices;
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    vertices.push(start);
    visited[start] = true;

    while (!vertices.empty()) {
        int current = vertices.front();
        vertices.pop();

        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[current][i] == 1 && i != current) {
                vertices.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    if (checkIsConnected(edges, n, 0)) {
         // its enough if you check with single vertex
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

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

void DFS(bool** graph, int v, bool* visited, int currentVertex) {
    visited[currentVertex] = true;
    
    for (int i = 0; i < v; ++i) {
        if (graph[currentVertex][i] && !visited[i]) {
            DFS(graph, v, visited, i);
        }
    }
}

bool isConnected(bool** graph, int v) {
    bool* visited = new bool[v]();
    
    DFS(graph, v, visited, 0);
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
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
    
    cout << (isConnected(graph, v) ? "true" : "false");
    
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

void DFS(bool** graph, int v, bool* visited, int currentVertex) {
    visited[currentVertex] = true;
    
    for (int i = 0; i < v; ++i) {
        if (graph[currentVertex][i] && !visited[i]) {
            DFS(graph, v, visited, i);
        }
    }
}

bool isConnected(bool** graph, int v) {
    bool* visited = new bool[v]();
    
    DFS(graph, v, visited, 0);
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
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
    
    cout << (isConnected(graph, v) ? "true" : "false");
    
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    
    delete[] graph;
}