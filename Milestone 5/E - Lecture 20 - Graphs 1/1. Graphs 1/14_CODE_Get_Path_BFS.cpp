/* =================================================================================================================== */
/* 
    Question  : Code : Get Path - DFS

                    Given an undirected graph G(V, E) and two vertices v1 
                    and v2(as integers), find and print the path from v1 
                    to v2 (if exists). Print nothing if there is no path 
                    between v1 and v2.
                    
                    Find the path using BFS and print the shortest path 
                    available.
                
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



// My fisrt Approach
// #include <iostream>
// #include <queue>
// #include <map>
// using namespace std;

// void getPathBFS(bool **edges, long long v, long long v1, long long v2, bool *visited) {
//     queue<int> pendingVertices;
//     map<int, int> m;
//     pendingVertices.push(v1);
//     visited[v1] = true;
//     while (!pendingVertices.empty()) {
//         for (int i = 0; i < v; i++) {
//             if (visited[i])
//                 continue;
//             if (i == pendingVertices.front())
//                 continue;
//             if (edges[pendingVertices.front()][i]) {
//                 pendingVertices.push(i);
//                 m[i] = pendingVertices.front();
//                 visited[i] = true;
//             }
//         }
//         pendingVertices.pop();
//     }
//     if (!visited[v2])
//         return;
//     int i = v2;
//     cout << v2 << " ";
//     while (i != v1) {
//         cout << m[i] << " ";
//         i = m[i];
//     }
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
//     getPathBFS(edges, v, v1, v2, visited);
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
// #include <queue>
// #include <vector>
// using namespace std;

// vector<int>* getBFSPath(bool** graph, int v, int start, int end) {
//     queue<int> pendingVertices;
//     bool* visited = new bool[v]();
    
//     pendingVertices.push(start);
//     visited[start] = true;

//     bool pathFound = false;
    
//     vector<int> parent(v, -1);
    
//     while (!pendingVertices.empty() && !pathFound) {
//         int front = pendingVertices.front();
//         pendingVertices.pop();
        
//         for (int i = 0; i < v; i++) {
//             if (graph[front][i] && !visited[i]) {
//                 parent[i] = front;
//                 pendingVertices.push(i);
//                 visited[i] = true;
//                 if (i == end) {
//                     pathFound = true;
//                     break;
//                 }
//             }
//         }
//     }
    
//     delete[] visited;
    
//     if (!pathFound) {
//         return NULL;
//     }
    
//     vector<int>* output = new vector<int>();
    
//     int current = end;
//     output->push_back(end);
    
//     while (current != start) {
//         current = parent[current];
//         output->push_back(current);
//     }
    
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
    
//     vector<int>* output = getBFSPath(graph, v, start, end);
    
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
// #include <queue>
// #include <vector>
// using namespace std;

// vector<int>* getBFSPath(bool** graph, int v, int start, int end) {
//     queue<int> pendingVertices;
//     bool* visited = new bool[v]();
    
//     pendingVertices.push(start);
//     visited[start] = true;
    
//     bool pathFound = false;

//     vector<int> parent(v, -1);
    
//     while (!pendingVertices.empty() && !pathFound) {
//         int front = pendingVertices.front();
//         pendingVertices.pop();

//         for (int i = 0; i < v; i++) {
//             if (graph[front][i] && !visited[i]) {
//                 parent[i] = front;
//                 pendingVertices.push(i);
//                 visited[i] = true;
//                 if (i == end) {
//                     pathFound = true;
//                     break;
//                 }
//             }
//         }
//     }
    
//     delete[] visited;

//     if (!pathFound) {
//         return NULL;
//     }
    
//     vector<int>* output = new vector<int>();
    
//     int current = end;
//     output->push_back(end);
    
//     while (current != start) {
//         current = parent[current];
//         output->push_back(current);
//     }
    
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
    
//     vector<int>* output = getBFSPath(graph, v, start, end);
    
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



// Solution for Get Path BFS 

#include <iostream>
#include <queue>
#include <unordered_map>
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

// vector<int> *getPathHelper( int **edegs, int n, int StartingVertex, int endVertex, bool * visited ) {
//     if ( StartingVertex == endVertex ) {

//         vector<int> * output = new vector<int>();
//         output -> push_back(endVertex);
//         return output;
//     }

//     visited[StartingVertex] = true;

//     for ( int i = 0; i < n; i++ ) {
//         if ( edegs[StartingVertex][i] && !visited[i] ) {
//             vector<int> * smallOutput = getPathHelper( edegs, n, i, endVertex, visited );

//             if ( smallOutput != NULL ) {
//                 smallOutput -> push_back(StartingVertex);

//                 return smallOutput;
//             }
//         }
//     }

//     return NULL;
// }

// vector<int> * getPathDFS( int ** edegs, int n, int StartingVertex, int endVertex ) {
//     bool * visited = new bool[n];

//     // mark everything as not visited i.e., verties are not visited
//     for ( int i = 0; i < n; i++ ) {
//         visited[i] = false;
//     }

//     vector<int> * output = getPathHelper( edegs, n, StartingVertex, endVertex, visited );
    
//     delete [] visited;

//     return output;
// }


// For Get Path BFS

vector<int> * getPathBFS( int ** edges, int n, int startVertex, int endVertex ) {
    queue <int> BFS_Q;

    bool * visited = new bool[n];

    for ( int i = 0; i < n; i++ ) {
        visited[i] = false;
    }

    BFS_Q.push(startVertex);
    visited[startVertex] = true;
    bool done = false;
    unordered_map<int, int> parent;
    while (!BFS_Q.empty() && !done ) {
        int front = BFS_Q.front();
        BFS_Q.pop();

        for ( int i = 0; i < n; i++ ) {
            if ( edges[front][i] && !visited[i] ) {
                parent[i] = front;
                BFS_Q.push(i);

                visited[i] = true;
                if ( i == endVertex ) {
                    done = true;
                    break;
                }
            }
        }
    }

    delete [] visited;

    if ( !done ) {
        return NULL;
    } else {
        vector<int> * output = new vector<int>();
        int current = endVertex;
        output -> push_back(endVertex);

        while ( current != startVertex ) {
            current = parent[current];
            output -> push_back(current);
        }
        return output;
    }
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

    // int startingVertex, endVertex;
    // cout << "Enter Starting Vertex fir Get Path DFS : ";
    // cin >> startingVertex;
    // cout << "Enter Ending Vertex fir Get Path DFS : ";
    // cin >>  endVertex;

    // vector<int> * output = getPathDFS( edges, n, startingVertex, endVertex );

    // if ( output != NULL ) {
    //     cout << "No Path Found through DFS Approach" << endl;
    //     cout << "Obtained Path is : " << endl;
    //     for ( int i = 0; i < output -> size(); i++ ) {
    //         cout << output -> at(i) << endl;
    //     }

    //     delete [] output;
    // } else {
    //     cout << "No Path Found through DFS Approach" << endl;
    // }


    // Get path BFS

    int startingVertex, endVertex;
    cout << "Enter Starting Vertex fir Get Path BFS : ";
    cin >> startingVertex;
    cout << "Enter Ending Vertex fir Get Path BFS : ";
    cin >>  endVertex;

    vector<int> * output = getPathBFS( edges, n, startingVertex, endVertex );

    if ( output != NULL ) {
        cout << "Path Found through BFS Approach" << endl;
        cout << "Obtained Path is : " << endl;
        for ( int i = 0; i < output -> size(); i++ ) {
            cout << output -> at(i) << endl;
        }

        delete output;
    } else {
        cout << "No Path Found through BFS Approach" << endl;
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


// output 

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
        Enter Starting Vertex fir Get Path BFS : 0
        Enter Ending Vertex fir Get Path BFS : 3
        Path Found through BFS Approach
        Obtained Path is :
        3
        2
        0
*/