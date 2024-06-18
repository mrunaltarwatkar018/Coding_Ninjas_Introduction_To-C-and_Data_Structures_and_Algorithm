
/* Collision Handling */

/* 
        We can handle collisions in two ways: 

            ● Closed hashing (or closed addressing)
            ● Open addressing

        In closed hashing, each entry of the array will be a linked list. This means it should
        be able to store every value that corresponds to this index. The array position holds
        the address to the head of the linked list, and we can traverse the linked list by
        using the head pointer for the same and add the new element at the end of that
        linked list. This is also known as separate chaining.

        On the other hand, in open addressing, we will check for the index in the bucket
        array if it is empty or not. If it is empty, then we will directly insert the key-value pair
        over that index. If not, then will we find an alternate position for the same. To find
        the alternate position, we can use the following:

                    hi(a) = hf(a) + f(i)

        Where hf(a) is the original hash function, and f(i) is the i-th try over the hash
        function to obtain the final position hi(a).

        To figure out this f(i), following are some of the techniques:

            1.  Linear probing: In this method, we will linearly probe to the next slot until
                we find the empty index. Here, f(i) = i.

            2.  Quadratic probing: As the name suggests, we will look for alternate i2
                positions ahead of the filled ones, i.e., f(i) = i2.

            3.  Double hashing: According to this method, f(i) = i * H(a), where H(a) is some
                other hash function.

            In practice, we generally prefer to use separate chaining over open addressing, as it
            is easier to implement and is also more efficient.

*/