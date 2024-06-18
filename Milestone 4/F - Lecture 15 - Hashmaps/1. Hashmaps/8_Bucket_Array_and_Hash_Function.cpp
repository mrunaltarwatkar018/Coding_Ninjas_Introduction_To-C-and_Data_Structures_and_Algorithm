


/* Bucket array and hash function */


/*
        Now, let’s see how to perform insertion, deletion, and search operations using hash
        tables. Till now, we have seen that arrays are the fastest way to extract data as
        compared to other data structures as the time complexity of accessing the data in
        the array is O(1). So we will try to use them in implementing the hashmaps.

        Now, we want to store the key-value pairs in an array, named as a bucket array.
        We need an integer corresponding to the key so that we can keep it in the bucket
        array. To do so, we use a hash function. A hash function converts the key into an
        integer, which acts as the index for storing the key in the array.

        For example: Suppose, we want to store some names from the contact list in the
        hash table, check out the following the image:

        Suppose we want to store a string in a hash table, and after passing the string
        through the hash function, the integer we obtain is equal to 10593, but the bucket
        array’s size is only 20. So, we can’t store that string in the array as 10593, as this
        index does not exist in the array of size 20.

        To overcome this problem, we will divide the hashmap into two parts:

            ● Hash code
            ● Compression function

        The first step to store a value into the bucket array is to convert the key into an
        integer (this could be any integer irrespective of the size of the bucket array). This
        part is achieved by using hashcode. For different types of keys, we will be having
        different kinds of hash codes. Now we will pass this value through the compression
        function, which will convert that value within the range of our bucket array’s size.
        Now, we can directly store that key against the index obtained after passing
        through the compression function.

        The compression function can be used as (% bucket_size).

        One example of a hash code could be: (Example input: “abcd”)


        “abcd” = (‘a’ * p3) + (‘b’ * p2) + (‘c’ * p1) + (‘d’ * p0)
        Where p is generally taken as a prime number so that they are well
        distributed.

        But, there is still a possibility that after passing the key through from hash code,
        when we give the same through the compression function, we can get the same
        values of indices. For example, let s1 = “ab” and s2 = “cd”. Now using the above hash
        function for p = 2, h1 = 292 and h2 = 298. Let the bucket size be equal to 2. Now, if
        we pass the hash codes through the compression function, we will get:

        Compression_function1 = 292 % 2 = 0
        Compression_function2 = 298 % 2 = 0
        This means they both lead to the same index 0.
        This is known as a collision.

*/