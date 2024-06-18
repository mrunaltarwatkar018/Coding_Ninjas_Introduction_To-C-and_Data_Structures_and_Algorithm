

/*
    A graph is a pair G = (V, E), where V is a set whose elements are called vertices, and E
    is a set of two-sets of vertices, whose elements are called edges.

    The vertices x and y of an edge {x, y} are called the endpoints of the edge. The edge
    is said to join x and y and to be incident on x and y. A vertex may not belong to any
    edge.

    For example: Suppose there is a road network in a country, where we have many
    cities, and roads are connecting these cities. There could be some cities that are not
    connected by some other cities like an island. This structure seems to be
    non-uniform, and hence, we can’t use trees to store it. In such cases, we will be
    using graphs. Refer to the figure for better understanding.


            6
              \
               \
                4 ------------ 5
                |               | \
                |               |  \
                |               |   1
                |               |  /
                |               | /
                3 ------------- 2



    Relationship between trees and graphs:

        ●   A tree is a special type of graph in which we can reach any node to any other
            node using some path, unlike the graphs where this condition may or may
            not hold.
            
        ●   A tree does not have any cycles in it.


*/