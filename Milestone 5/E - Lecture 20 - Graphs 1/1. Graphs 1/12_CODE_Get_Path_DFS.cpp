/* =================================================================================================================== */
/* 
    Question  : Code : Get Path - DFS

                    Given an undirected graph G(V, E) and two vertices v1 
                    and v2(as integers), find and print the path from v1 
                    to v2 (if exists). Print nothing if there is no path 
                    between v1 and v2.
                    
                    Find the path using DFS and print the first path that 
                    you encountered.
                
                Note:
                    1.  V is the number of vertices present in graph G and 
                        vertices are numbered from 0 to V-1. 
                    2.  E is the number of edges present in graph G.
                    3.  Print the path in reverse order. That is, print v2 
                        first, then intermediate vertices and v1 at last.
                    4.  Save the input graph in Adjacency Matrix.

                Input format : 
                    The first line of input contains two integers, that denote 
                    the value of V and E.

                    Each of the following E lines contains two integers, that 
                    denote that there exists an edge between vertex 'a' and 'b'.

                    The following line contain two integers, that denote the 
                    value of v1 and v2.

                Output Format : 
                        Print the path from v1 to v2 in reverse order.

                Constraints :  
                        2 <= V <= 1000
                        1 <= E <= (V * (V - 1)) / 2
                        0 <= a <= V - 1
                        0 <= b <= V - 1
                        0 <= v1 <= 2^31 - 1
                        0 <= v2 <= 2^31 - 1

                        Time Limit: 1 sec

                Sample Input 1 :    
                        4 4
                        0 1
                        0 3
                        1 2
                        2 3
                        1 3
                                          
                Sample Output 1 :   
                        3 0 1

                Sample Input 2 :    
                        6 3
                        5 3
                        0 1
                        3 4
                        0 3
                                          
                Sample Output 2 :   
                        

*/

// First Approach

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<long long> getPath(bool **edges, long long v, bool *visited, long long v1, long long v2) {
//     vector<long long> path;

//     if (v1 == v2) {
//         path.push_back(v1);
//         return path;
//     }

//     for (long long i = 0; i < v; i++) {
//         if (i == v1)
//             continue;

//         if (visited[i])
//             continue;
        
//         if (edges[v1][i]) {
//             visited[i] = true;

//             path = getPath(edges, v, visited, i, v2);
            
//             if (path.size()) {
//                 path.push_back(v1);
//                 return path;
//             }
//         }
//     }
//     return path;
// }

// int main() {
//     // Write your code here
//     long long v, e;
//     cin >> v >> e;
    
//     bool **edges = new bool *[v];
    
//     for (long long i = 0; i < v; i++) {
//         edges[i] = new bool[v];

//         for (long long j = 0; j < v; j++) {
//             edges[i][j] = false;
//         }
//     }
    
//     for (long long i = 0; i < e; i++) {
//         long long start, end;
//         cin >> start >> end;

//         edges[start][end] = true;
//         edges[end][start] = true;
//     }

//     bool *visited = new bool[v];
    
//     for (long long i = 0; i < v; i++) {
//         visited[i] = false;
//     }

//     long long v1, v2;
//     cin >> v1 >> v2;
    
//     visited[v1] = true;
    
//     vector<long long> path = getPath(edges, v, visited, v1, v2);
    
//     if (path.size()) {
//         for (long long i = 0; i < path.size(); i++) {
//             cout << path[i] << " ";
//         }
//     }
//     return 0;
// }



// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(V + E)
    Space complexity: O(V^2)
    
    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int>* getDFSPathHelper(bool** graph, int v, int start, int end, bool* visited) {
//     if (start == end) {
//         vector<int>* output = new vector<int>();
//         output->push_back(end);
//         return output;
//     }
    
//     visited[start] = true;
    
//     for (int i = 0; i < v; ++i) {
//         if (graph[start][i] && !visited[i]) {
//             vector<int>* smallOutput = getDFSPathHelper(graph, v, i, end, visited);
//             if (smallOutput != NULL) {
//                 smallOutput->push_back(start);
//                 return smallOutput;
//             }
//         }
//     }

//     return NULL;
// }

// vector<int>* getDFSPath(bool** graph, int v, int start, int end) {
//     bool* visited = new bool[v];

//     for (int i = 0; i < v; i++) {
//         visited[i] = false;
//     }
    
//     vector<int>* output = getDFSPathHelper(graph, v, start, end, visited);
    
//     delete[] visited;

//     return output;
// }

// int main() {
//     int v, e;
//     cin >> v >> e;
    
//     bool** graph = new bool*[v];
    
//     for (int i = 0; i < v; ++i) {
//         graph[i] = new bool[v]();
//     }
    
//     for (int i = 0, a, b; i < e; ++i) {
//         cin >> a >> b;
//         graph[a][b] = true;
//         graph[b][a] = true;
//     }
    
//     int start, end;
//     cin >> start >> end;
    
//     vector<int>* output = getDFSPath(graph, v, start, end);
    
//     if (output != NULL) {
//         for (int i = 0; i < output->size(); ++i) {
//             cout << output->at(i) << " ";
//         }
//         delete output;
//     }
    
//     for (int i = 0; i < v; ++i) {
//         delete[] graph[i];
//     }
    
//     delete[] graph;
// }


// Optimized Approach [ C++ ( g++ 5.4 ) ]


/*
    Time complexity: O(V + E)
    Space complexity: O(V^2)
    
    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int>* getDFSPathHelper(bool** graph, int v, int start, int end, bool* visited) {
//     if (start == end) {
//         vector<int>* output = new vector<int>();
//         output->push_back(end);
//         return output;
//     }
    
//     visited[start] = true;
    
//     for (int i = 0; i < v; ++i) {
//         if (graph[start][i] && !visited[i]) {
//             vector<int>* smallOutput = getDFSPathHelper(graph, v, i, end, visited);
//             if (smallOutput != NULL) {
//                 smallOutput->push_back(start);
//                 return smallOutput;
//             }
//         }
//     }
    
//     return NULL;
// }

// vector<int>* getDFSPath(bool** graph, int v, int start, int end) {
//     bool* visited = new bool[v];
//     for (int i = 0; i < v; i++) {
//         visited[i] = false;
//     }
    
//     vector<int>* output = getDFSPathHelper(graph, v, start, end, visited);
    
//     delete[] visited;
    
//     return output;
// }

// int main() {
//     int v, e;
//     cin >> v >> e;
    
//     bool** graph = new bool*[v];
    
//     for (int i = 0; i < v; ++i) {
//         graph[i] = new bool[v]();
//     }
    
//     for (int i = 0, a, b; i < e; ++i) {
//         cin >> a >> b;
//         graph[a][b] = true;
//         graph[b][a] = true;
//     }
    
//     int start, end;
//     cin >> start >> end;
    
//     vector<int>* output = getDFSPath(graph, v, start, end);
    
//     if (output != NULL) {
//         for (int i = 0; i < output->size(); ++i) {
//             cout << output->at(i) << " ";
//         }
//         delete output;
//     }
    
//     for (int i = 0; i < v; ++i) {
//         delete[] graph[i];
//     }
    
//     delete[] graph;
// }



// Solution for Get Path DFS


#include <iostream>
#include <queue>
using namespace std;

void printDFS( int **edges, int n, int startingVertex, bool * visited ) {
    // cout << "Starting Vertex is : " << startingVertex << endl;
    cout << startingVertex << endl;

    // as soon as vertex is visited, then it is necessary to mark
    visited[startingVertex] = true;

    for ( int i = 0; i < n; i++ ) {

         if ( i == startingVertex ) {
            continue;
         }
        
        if ( edges[startingVertex][i] == 1 ) {

            if ( visited[i] ) {
                continue;
            }

            printDFS( edges, n, i, visited );
        }
    }
}



// BFS Approach

void printBFS( int ** edges, int n, int startingVertex, bool * visited ) {
    queue<int> pendingVertices;

    pendingVertices.push(startingVertex);
    visited[startingVertex] = true;

    while ( !pendingVertices.empty() ) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;

        for ( int i = 0; i < n; i++ ) {

            if ( i == currentVertex ) {
                continue;
            }

            if ( edges[currentVertex][i] == 1 && !visited[i] ) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}



// BFS & DFS Disconnected Graph

void BFS( int ** edges, int n ) {
    bool * visited = new bool[n];

    // mark everything as not visited i.e., verties are not visited
    for ( int i = 0; i < n; i++ ) {
        visited[i] = false;
    }

    for ( int i = 0; i < n; i++ ) {

        if ( !visited[i] )
            printBFS( edges, n, i, visited );
    }

    delete [] visited;
}

void DFS( int ** edges, int n ) {
    bool * visited = new bool[n];

    // mark everything as not visited i.e., verties are not visited
    for ( int i = 0; i < n; i++ ) {
        visited[i] = false;
    }

    for ( int i = 0; i < n; i++ ) {

        if ( !visited[i] )
            printDFS( edges, n, i, visited );
    }

    delete [] visited;
}

// Get Path DFS

vector<int> *getPathHelper( int **edegs, int n, int StartingVertex, int endVertex, bool * visited ) {
    if ( StartingVertex == endVertex ) {

        vector<int> * output = new vector<int>();
        output -> push_back(endVertex);
        return output;
    }

    visited[StartingVertex] = true;

    for ( int i = 0; i < n; i++ ) {
        if ( edegs[StartingVertex][i] && !visited[i] ) {
            vector<int> * smallOutput = getPathHelper( edegs, n, i, endVertex, visited );

            if ( smallOutput != NULL ) {
                smallOutput -> push_back(StartingVertex);

                return smallOutput;
            }
        }
    }

    return NULL;
}

vector<int> * getPath( int ** edegs, int n, int StartingVertex, int endVertex ) {
    bool * visited = new bool[n];

    // mark everything as not visited i.e., verties are not visited
    for ( int i = 0; i < n; i++ ) {
        visited[i] = false;
    }

    vector<int> * output = getPathHelper( edegs, n, StartingVertex, endVertex, visited );
    
    delete [] visited;

    return output;
}


int main() {
    // n = number of vertices
    int n;
    // e = number of edges
    int e;
    cout << "Enter the Number of Vertices : ";
    cin >> n;
    cout << "Enter the Number of Edges : ";
    cin >> e;

    // dynamically created 2D aaray
    int **edges = new int *[n];


    for ( int i = 0; i < n; i++ ) {
        edges[i] = new int [n];

        // for clearing the garbage values

        for ( int j = 0; j < n; j++ ) {
            edges[i][j] = 0;
        }  
    } 

    // input from the user
    for ( int i = 0; i < e; i++ ) {
        // f = first vertex, s = second vertex
        int f, s;
        cout << "Enter the Vertex Connected Between First vertex to Second Vetex : "; 
        cin >> f >> s;

        edges[f][s] = 1;    // edge from first to second
        edges[s][f] = 1;    // edge from second to first
    }


    cout << "Graph DFS order is : " << endl;

    // for print 
    DFS( edges, n );

    cout << "Graph BFS order is : " << endl;
    BFS( edges, n );


    // Get path DFS

    int startingVertex, endVertex;
    cout << "Enter Starting Vertex fir Get Path DFS : ";
    cin >> startingVertex;
    cout << "Enter Ending Vertex fir Get Path DFS : ";
    cin >>  endVertex;

    vector<int> * output = getPath( edges, n, startingVertex, endVertex );

    if ( output != NULL ) {
        cout << "Path Found through DFS Approach" << endl;
        cout << "Obtained Path is : " << endl;
        for ( int i = 0; i < output -> size(); i++ ) {
            cout << output -> at(i) << endl;
        }

        delete [] output;
    } else {
        cout << "No Path Found through DFS Approach" << endl;
    }


    // for delete created visited array
    for ( int i = 0; i < n; i++ ) {
        delete [] edges[i];
    }

    delete [] edges;

}



/*
        Given Graph :

                    0
                  /   \
                 1 --- 2
                       |
                       3

*/


/*
    Enter the Number of Vertices : 4
    Enter the Number of Edges : 4
    Enter the Vertex Connected Between First vertex to Second Vetex : 0 1
    Enter the Vertex Connected Between First vertex to Second Vetex : 0 2
    Enter the Vertex Connected Between First vertex to Second Vetex : 1 2
    Enter the Vertex Connected Between First vertex to Second Vetex : 2 3
    Graph DFS order is : 
    0
    1
    2
    3
    Graph BFS order is :
    0
    1
    2
    3
    Enter Starting Vertex fir Get Path DFS : 0
    Enter Ending Vertex fir Get Path DFS : 3
    Path Found through DFS Approach
    Obtained Path is : 
    3 
    2 
    1 
    0

*/