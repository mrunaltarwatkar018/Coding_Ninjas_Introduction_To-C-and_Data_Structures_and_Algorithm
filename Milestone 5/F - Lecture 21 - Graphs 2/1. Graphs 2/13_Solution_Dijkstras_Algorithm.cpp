#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int* distance, bool* visited, int n){

	int minVertex = -1;
    
	for ( int i = 0; i < n; i++ ) {

		if ( !visited[i] && ( minVertex == -1 ||  distance[i] < distance[minVertex] ) ){
			minVertex = i;
		}
	}

	return minVertex;
}


void Dijkstra(int** edges, int n) {
	int* distance = new int[n];
	bool* visited = new bool[n];

    // Initialize all vertices as unvisited and set their weight to infinity.

	for ( int i = 0; i < n; i++ ) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[0] = 0; // source distance is 0

	for ( int i = 0; i < n - 1; i++ ) {
		int minVertex = findMinVertex( distance, visited, n );

		visited[minVertex] = true;

		for ( int j = 0; j < n; j++ ) {	
            
			if ( edges[minVertex][j] != 0 && !visited[j] ) {
				int dist = distance[minVertex] + edges[minVertex][j];

				if ( dist < distance[j] ) {
					distance[j] = dist;
				}
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		cout << i << " " << distance[i] << endl;
	}

	delete [] visited;

	delete [] distance;
	
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

    cout << "MST Using Dijkstra's Algorithm is : " << endl;
	Dijkstra(edges, n);

	for ( int i = 0; i < n; i++ ) {
		delete [] edges[i];
	}

	delete [] edges;
}




/*
    Given Graph 1 :
                    5
                1 ----- 3
            4 / |     / |
             /  |  5 /  |
            0  2|   /   |4
             \  |  /    |
            8 \ | /  9  |
                2 ----- 4


*/


// Output of Given Graph 1 :

/*
        Enter the total number of vertices : 5
        Enter the total number of edges : 7
        Enter the First Vertex, Second Vertex and Weight of edge : 0 1 4
        Enter the First Vertex, Second Vertex and Weight of edge : 0 2 8
        Enter the First Vertex, Second Vertex and Weight of edge : 1 3 5
        Enter the First Vertex, Second Vertex and Weight of edge : 1 2 2
        Enter the First Vertex, Second Vertex and Weight of edge : 2 3 5
        Enter the First Vertex, Second Vertex and Weight of edge : 2 4 9
        Enter the First Vertex, Second Vertex and Weight of edge : 3 4 4

        MST Using Dijkstra's Algorithm is :
        0 0
        1 4
        2 6
        3 9
        4 13
*/



/*
    Given Graph 2 :
                    6
                1 ----- 3
            4 / |     / |
             /  |  3 /  |
            0  2|   /   |5
             \  |  /    |
            8 \ | /  9  |
                2 ----- 4


*/


// Output of Given Graph 2 :

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

MST Using Dijkstra's Algorithm is :
0 0
1 4
2 6
3 9
4 14

*/