/*
Weighted and directed graphs

There are two more variations of the graphs:

    ●   Directed graphs:  
            These are generally required when we have one-way 
            routes. Suppose you can go from node A to node B, 
            but you cannot go from node B to node A. Another 
            example could be of social media(like Twitter) if 
            you are following someone, it does not mean that 
            they are following you too.

        To implement these, there is a small change in the 
        implementation of indirect graphs. In indirect graphs, 
        if there was an edge between node i and j, then we did:

                --------------------
                | edges[i][j] = 1; |
                | edges[j][i] = 1; |
                --------------------
        
        But, in the case of a directed graph, we will just do the 
        following:
                --------------------
                | edges[i][j] = 1; |
                --------------------


    ●   Weighted graphs: 
            These generally mean that all the edges are not equal, 
            means somehow, each edge has some weight assigned to it. 
            This weight can be the length of the road connecting the 
            cities or many m

            To implement this, in the edges matrix, we will assign a 
            weight to connected nodes instead of putting it 1 at that 
            position. For example: If node i and j are connected, and 
            the weight of the edge connecting them is 5, then 
            edges[i][j] = 5.
*/


/*
    Practice problems:
        ●   https://www.codechef.com/problems/CHEFDAG

        ●   https://www.spoj.com/problems/WORDS1/
        
        ●   https://www.hackerrank.com/challenges/the-quickest-way-up/problem
*/