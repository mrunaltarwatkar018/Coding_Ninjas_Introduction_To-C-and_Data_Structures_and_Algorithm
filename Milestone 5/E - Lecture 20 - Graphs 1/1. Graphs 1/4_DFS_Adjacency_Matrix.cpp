
/* DFS : DEpth First Search */

/* 
        Here, if we have n vertices(labelled: 0 to n-1). Then we will be asking the user for the
        number of edges. We will run the loop from 0 to the number of edges, and at each
        iteration, we will take input for the two connected nodes and correspondingly
        update the adjacency matrix. 
*/



/*
        In DFS,
        Here, we are starting from a node, going in one direction as far as we can, and then
        we return and do the same on the previous nodes. This method of graph traversal
        is known as the depth-first search (DFS). As the name suggests, this algorithm
        goes into the depth first and then recursively does the same in other directions.
        Follow the figure below, for step-by-step traversal using DFS.
*/


#include <iostream>
using namespace std;

void print( int **edges, int n, int startingVertex, bool * visited ) {
    cout << "Starting Vertex is : " << startingVertex << endl;
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


    // Delete All the Memory
    return 0;

}


// Output

/*

        Enter the Number of Vertices : 4
        Enter the Number of Edges : 3
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 2
        Enter the Vertex Connected Between First vertex to Second Vetex : 2 1
        Enter the Vertex Connected Between First vertex to Second Vetex : 1 3
        Graph DFS order is : 
        Starting Vertex is : 0
        Starting Vertex is : 2
        Starting Vertex is : 1
        Starting Vertex is : 3

*/





/*
        GRaph :

                    0
                  /   \
                 1     2
                 |     | \
                 5     3  6
                  \   /
                    4



        Enter the Number of Vertices : 7
        Enter the Number of Edges : 6
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 1
        Enter the Vertex Connected Between First vertex to Second Vetex : 1 5
        Enter the Vertex Connected Between First vertex to Second Vetex : 5 4
        Enter the Vertex Connected Between First vertex to Second Vetex : 3 2
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 2
        Enter the Vertex Connected Between First vertex to Second Vetex : 2 6
        Graph DFS order is : 
        Starting Vertex is : 0
        Starting Vertex is : 1
        Starting Vertex is : 5
        Starting Vertex is : 4
        Starting Vertex is : 2
        Starting Vertex is : 3
        Starting Vertex is : 6
*/

/*

        GRaph :

                    0
                  /   \
                 1     2
                 |     | \
                 5     3  6
                  \   
                    4

        Enter the Number of Vertices : 7
        Enter the Number of Edges : 6
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 1
        Enter the Vertex Connected Between First vertex to Second Vetex : 0 2
        Enter the Vertex Connected Between First vertex to Second Vetex : 1 5
        Enter the Vertex Connected Between First vertex to Second Vetex : 5 4
        Enter the Vertex Connected Between First vertex to Second Vetex : 2 3
        Enter the Vertex Connected Between First vertex to Second Vetex : 2 6
        Graph DFS order is : 
        Starting Vertex is : 0
        Starting Vertex is : 1
        Starting Vertex is : 5
        Starting Vertex is : 4
        Starting Vertex is : 2
        Starting Vertex is : 3
        Starting Vertex is : 6

*/


/*

        GRaph :

                    0
                  /   \
                 1     2
               /   \    \
              3     4   6
               \   /  /
                \ /  /
                 5 --

            DFS order : 0 1 3 5 4 6 2
*/


