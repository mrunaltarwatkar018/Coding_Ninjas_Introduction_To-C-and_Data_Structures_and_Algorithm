/* Time Complexity & Load factor */

/* 

    Let’s define specific terms before moving forward :

        1.  n = Number of entries in our map.

        2.  l = length of the word (in case of strings)

        3.  b = number of buckets. On average, each box contains (n/b) entries. This is
            known as load factor means b boxes contain n entries. We also need to
            ensure that the load factor is always less than 0.7, i.e.,

                (n/b) < 0.7, this will ensure that each bucket does not contain too
                many entries in it.
                
        4.  To make sure that load factor < 0.7, we can’t reduce the number of entries,
            but we can increase the bucket size comparatively to maintain the ratio. This
            process is known as Rehashing.

        This ensures that time complexity is on an average O(1) for insertion, deletion, and
        search operations each.


*/



/*

    1.  For Insertion :

            n = number of entries in our map
            in case of string, l = length of word
             Hash Compitutuion time : O(l)

             In the wrost case : O(n)

             load factor = n / b < 0.7

                O( n/b )

            we can assume that every box has a constant number of entries and these going to be O(1).

            

*/