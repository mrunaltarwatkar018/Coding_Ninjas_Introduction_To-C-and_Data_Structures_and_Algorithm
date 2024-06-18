/*
        BFS & DFS for disconnected graph

        Till now, we have assumed that the graph is connected. For the disconnected graph,
        there will be a minor change in the above codes. Just before calling out the print
        functions, we will run a loop over each node and check if that node is visited or not.
        If not visited, then we will call a print function over that node, considering it as the
        starting vertex. In this way, we will be able to cover up all the nodes of the graph.

        Consider the same for the BFS function. Just replace this function in the above code
        to make it work for the disconnected graph too.
*/


/*
                0                                   2
                |                                 /   \
                1 --- 6                          4 --- 5
                 \   /
                   3
*/



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

    for ( int i = 0; i < n; i++ ) {
        delete [] edges[i];
    }

    delete [] edges;

}


/*
        Given graph:

            0           1          5
          /   \         |          |
         2 --- 3        4          6
*/


// Output

/*
        Enter the Number of Vertices : 7
        Enter the Number of Edges : 5
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 2
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 3
        Enter the Vertex Connected Between First vertex to Second Vetex : 2 3
        Enter the Vertex Connected Between First vertex to Second Vetex : 1 4
        Enter the Vertex Connected Between First vertex to Second Vetex : 5 6
        Graph DFS order is : 
        0
        2
        3
        1
        4
        5
        6
        Graph BFS order is :
        0
        2
        3
        1
        4
        5
        6
*/