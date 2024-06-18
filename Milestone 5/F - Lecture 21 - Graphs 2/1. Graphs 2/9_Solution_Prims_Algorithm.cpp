#include <iostream>
using namespace std;
#include <climits>

int findMinVertex( int * weights, bool * visited, int n ) {

    int minVertex = -1;

    for ( int i = 0; i < n; i++ ) {
        if ( !visited[i] && ( minVertex == -1 || weights[i] < weights[minVertex] ) ) {
            minVertex = i;
        }
    }

    return minVertex;
}


void Prims( int ** edges, int n ) {

    int * parent = new int[n];      // to store all vertices parents
    int * weights = new int[n];     // to store wiight of edges of all the vertexes
    bool * visited = new bool[n];   // to figure out the vertex is visited or not

    // Initialize all vertices as unvisited and set their weight to infinity.

    for ( int i = 0; i < n; i++ ) {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    // initialize first or starting vertex parent as -1 & weight of that vertex is 0
    parent[0] = -1;
    weights[0] = 0;

    for ( int i = 0; i < n - 1; i++ ) {
        // Find Min Vertex
        int minVertex = findMinVertex( weights, visited, n );
        visited[minVertex] = true;

        // Explore unvisted neighbours
		for( int j = 0; j < n; j++ ){

			if( edges[minVertex][j] != 0 && !visited[j] ){
				if( edges[minVertex][j] < weights[j] ){
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
    }


    // to print 
    for ( int i = 1; i < n; i++ ) {
        if ( parent[i] < i ) {
            cout << parent[i] << " " << i << " " << weights[i] << endl;
        } else {
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }
    }
}



int main() {
    int n, e;
    cout << "Enter the total number of vertices : ";
    cin >> n;
    cout << "Enter the total number of edges : ";
    cin >> e;

	int** edges = new int*[n];

    // for taking input

	for ( int i = 0; i < n; i++ ) {
		edges[i] = new int[n];

		for ( int j = 0; j < n; j++ ) {
			edges[i][j] = 0;
		}
	}

	for ( int i = 0; i < e; i++ ) {
		int firstVertex, secondVertex, weight;
        cout << "Enter the First Vertex, Second Vertex and Weight of edge : ";
		cin >> firstVertex >> secondVertex >> weight;
		edges[firstVertex][secondVertex] = weight;
		edges[secondVertex][firstVertex] = weight;
	}

	cout << endl;

    cout << "MST Using Prim's Algorithm is : " << endl;
	Prims(edges, n);

	for ( int i = 0; i < n; i++ ) {
		delete [] edges[i];
	}

	delete [] edges;
}

// output

/*
    Given Graph 1 :
                    6
                1 ----- 3
            4 / |     / |
             /  |  3 /  |
            0  2|   /   |5
             \  |  /    |
            8 \ | /  9  |
                2 ----- 4


*/


/*
        Enter the total number of vertices : 5
        Enter the total number of edges : 7
        Enter the First Vertex, Second Vertex and Weight of edge : 0 1 4
        Enter the First Vertex, Second Vertex and Weight of edge : 0 2 8
        Enter the First Vertex, Second Vertex and Weight of edge : 1 3 6
        Enter the First Vertex, Second Vertex and Weight of edge : 1 2 2
        Enter the First Vertex, Second Vertex and Weight of edge : 2 3 3
        Enter the First Vertex, Second Vertex and Weight of edge : 2 4 9
        Enter the First Vertex, Second Vertex and Weight of edge : 3 4 5

        MST Using Prim's Algorithm is : 
        0 1 4
        1 2 2
        2 3 3
        3 4 5

*/


