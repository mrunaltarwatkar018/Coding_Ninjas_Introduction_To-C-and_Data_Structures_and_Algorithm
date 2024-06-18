#include <iostream>
#include <queue>
using namespace std;

void print( int **edges, int n, int startingVertex, bool * visited ) {
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

            print( edges, n, i, visited );
        }
    }
}



// BFS Approach

void printBFS( int ** edges, int n, int startingVertex ) {
    queue<int> pendingVertices;

    bool * visited = new bool[n];

    for ( int i = 0; i < n; i++ ) {
        visited[i] = false;
    }

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

    delete [] visited;
    
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

    bool *visited = new bool[n];

    for ( int i = 0; i < n; i++ ) {
        visited[i] = false;
    }


    cout << "Graph DFS order is : " << endl;

    // for print 
    print( edges, n, 0, visited );

    cout << "Graph BFS order is : " << endl;
    printBFS( edges, n, 0);


    // Delete All the Memory
    return 0;

}



/*
    Given Graph :

            0
          /   \
         4     5
         |     |
         3 --- 6
       /   \    \
      2 --- 1    7

*/



// OutPut

/*
        Enter the Number of Vertices : 8
        Enter the Number of Edges : 9
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 4
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 5
        Enter the Vertex Connected Between First vertex to Second Vetex : 4 3
        Enter the Vertex Connected Between First vertex to Second Vetex : 3 2
        Enter the Vertex Connected Between First vertex to Second Vetex : 2 1
        Enter the Vertex Connected Between First vertex to Second Vetex : 1 3
        Enter the Vertex Connected Between First vertex to Second Vetex : 5 6
        Enter the Vertex Connected Between First vertex to Second Vetex : 3 6
        Enter the Vertex Connected Between First vertex to Second Vetex : 6 7
        Graph DFS order is :
        0
        4
        3
        1
        2
        6
        5
        7
        Graph BFS order is :
        0
        4
        5
        3
        6
        1
        2
        7

*/
