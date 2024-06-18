#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
     public:
        int source;
        int destination;
        int weight;
};

bool compare ( Edge e1, Edge e2 ) {
    return e1.weight < e2.weight;
}

int findParent(int v, int * parent ) {
    if ( parent[v] == v ) {
        return v;
    }

    return findParent(parent[v], parent );
} 

void Kruskals(Edge * input, int n, int E ) {
    // sort the input array - ascending order based on weights
    sort(input, input + E, compare);

    Edge * output = new Edge[n - 1];

    int * parent = new int[n];

    for ( int i = 0; i < n; i++ ) {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while ( count != n - 1 ) {
        Edge currentEdge = input[i];

        // Check if we can add the currentEdge in MST or Not

        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent = findParent(currentEdge.destination, parent);

        if ( sourceParent != destinationParent ) {
            output[count] = currentEdge;
            count++;

            parent[sourceParent] = destinationParent;
        }
        i++;
    }

    // to print

    for ( int i = 0; i < n - 1; i++ ) {
        if ( output[i].source < output[i].destination ) {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        } else {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main() {
    int n, E;
    cout << "Enter the total number of vertices : ";
    cin >> n;
    cout << "Enter the total number of edges : ";
    cin >> E;


    Edge * input = new Edge[E];

    // for taking input

    for ( int i = 0; i < E; i++ ) {
        int s, d, w;
        cout << "Enter the Source, Destination and Weight Respectively : ";
        cin >> s >> d >> w;

        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    cout << "MST using Kruskal's Algorithm is : " << endl;
    Kruskals(input, n, E);
}


// Output

/*
            Enter the total number of vertices : 6
            Enter the total number of edges : 11
            Enter the Source, Destination and Weight Respectively : 0 1 2
            Enter the Source, Destination and Weight Respectively : 1 3 1
            Enter the Source, Destination and Weight Respectively : 0 2 4
            Enter the Source, Destination and Weight Respectively : 2 4 9
            Enter the Source, Destination and Weight Respectively : 4 5 5
            Enter the Source, Destination and Weight Respectively : 3 5 7
            Enter the Source, Destination and Weight Respectively : 4 3 11
            Enter the Source, Destination and Weight Respectively : 2 5 10
            Enter the Source, Destination and Weight Respectively : 0 3 3
            Enter the Source, Destination and Weight Respectively : 2 1 8
            Enter the Source, Destination and Weight Respectively : 2 3 6
            MST using Kruskal's Algorithm is : 
            1 3 1
            0 1 2
            0 2 4
            4 5 5
            3 5 7
*/



/*
    6 11
    0 1 2
    1 3 1
    0 2 4
    2 4 9
    4 5 5
    3 5 7
    4 3 11
    2 5 10
    0 3 3
    2 1 8
    2 3 6
    1 3 1
    0 1 2
    0 2 4
    4 5 5
    3 5 7

*/