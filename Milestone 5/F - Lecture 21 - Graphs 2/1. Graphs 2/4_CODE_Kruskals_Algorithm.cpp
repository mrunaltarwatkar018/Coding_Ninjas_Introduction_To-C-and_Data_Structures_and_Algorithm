/* =================================================================================================================== */
/* 
    Question  : Code : Kruskal's Algorithm

                    Given an undirected, connected and weighted graph G(V, E) 
                    with V number of vertices (which are numbered from 0 to V-1) 
                    and E number of edges.
                    
                    Find and print the Minimum Spanning Tree (MST) using Kruskal's 
                    algorithm.
                    
                    For printing MST follow the steps -
                        1.  In one line, print an edge which is part of MST in the format - 
                                v1 v2 w
                            where, v1 and v2 are the vertices of the edge which is 
                            included in MST and whose weight is w. And v1  <= v2 i.e. 
                            print the smaller vertex first while printing an edge.
                        2.  Print V-1 edges in above format in different lines.

                    Note :  Order of different edges doesn't matter.

                Input format : 
                        Line 1: Two Integers V and E (separated by space)
                        
                        Next E lines : Three integers ei, ej and wi, denoting 
                        that there exists an edge between vertex ei and vertex 
                        ej with weight wi (separated by space)

                Output Format : 
                        Print the MST, as described in the task.

                Constraints :  
                        2 <= V, E <= 10^5

                        Time Limit: 1 sec

                Sample Input 1 :    
                        4 4
                        0 1 3
                        0 3 5
                        1 2 1
                        2 3 8

                            3
                    0 ------------- 1
                    |               |
                5   |               |   1
                    |               |
                    3 ------------- 2  
                            8

                      Input Graph


                Sample Output 1 :   
                        1 2 1
                        0 1 3
                        0 3 5


                            3
                    0 ------------- 1
                    |               |
                5   |               |   1
                    |               |
                    3               2  
                            
                    Minimum Spanning Tree

*/

#include <algorithm>

// First Step

#include <iostream>
#include <algorithm>
using namespace std;

class Edges {
    public:
        long source;
        long destination;
        long weight;
};

bool compareWeight(Edges e1, Edges e2) {
    return (e1.weight < e2.weight);
}

long find(long v, long *parents) {
    if (v == parents[v])
        return v;

    return find(parents[v], parents);
}

void Union(Edges *output, Edges *input, long v, long *parents) {
    long count = 0, i = 0;

    while (count < (v - 1)) {
        long parentSource = find(input[i].source, parents);
        long parentDestination = find(input[i].destination, parents);

        if (parentSource != parentDestination) {
            output[count] = input[i];
            count++;
            parents[parentSource] = parents[parentDestination];
        }
        i++;
    }
}

int main() {
    // Write your code here
    long v, e;
    cin >> v >> e;

    Edges *input = new Edges[e];

    for (long i = 0; i < e; i++)
        cin >> input[i].source >> input[i].destination >> input[i].weight;

    // Kruskal's algorithm

    sort(input, input + e, compareWeight);

    long *parents = new long[v];
    for (long i = 0; i < v; i++)
        parents[i] = i;

    Edges *output = new Edges[v - 1];
    Union(output, input, v, parents);

    for (long i = 0; i < (v - 1); i++)
        cout << min(output[i].source, output[i].destination) << " " << max(output[i].source, output[i].destination) << " " << output[i].weight << "\n";

    delete[] input;
    delete[] parents;
    delete[] output;
    return 0;
}



// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(E * log(E))
    Space complexity: O(V + E)
    
    where E is the number of edges in the graph and
    V is the number of vertices in the graph
*/
#include <algorithm>
#include <iostream>
using namespace std;

class Edge {
    public:
        int source;
        int dest;
        int weight;

        void printEdge() {
            cout << min(source, dest) << " " << max(source, dest) << " " << weight;
        }
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent) {
    if (parent[v] == v) {
        return v;
    }

    return findParent(parent[v], parent);
}
#include <algorithm>
void printMST(Edge *input, int v, int e) {
    // Sort the input array in ascending order based on weights
    sort(input, input + e, compare);

    Edge *output = new Edge[v - 1];

    int *parent = new int[v];

    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count != v - 1) {
        Edge currentEdge = input[i];
        
        // Check if we can add the currentEdge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (sourceParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }

        i++;
    }

    for (int i = 0; i < v - 1; i++) {
        output[i].printEdge();
        cout << "\n";
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    Edge *input = new Edge[e];

    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    printMST(input, v, e);
}

// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
    Time complexity: O(E * log(E))
    Space complexity: O(V + E)
    
    where E is the number of edges in the graph and
    V is the number of vertices in the graph
*/
#include <algorithm>
#include <iostream>
using namespace std;

class Edge {
    public:
        int source;
        int dest;
        int weight;

        void printEdge() {
            cout << min(source, dest) << " " << max(source, dest) << " " << weight;
        }
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent) {
    if (parent[v] == v) {
        return v;
    }

    return findParent(parent[v], parent);
}

void printMST(Edge *input, int v, int e) {
    // Sort the input array in ascending order based on weights
    sort(input, input + e, compare);

    Edge *output = new Edge[v - 1];
    
    int *parent = new int[v];

    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count != v - 1) {
        Edge currentEdge = input[i];
        
        // Check if we can add the currentEdge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (sourceParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }

        i++;
    }

    for (int i = 0; i < v - 1; i++) {
        output[i].printEdge();
        cout << "\n";
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    Edge *input = new Edge[e];

    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    printMST(input, v, e);
}