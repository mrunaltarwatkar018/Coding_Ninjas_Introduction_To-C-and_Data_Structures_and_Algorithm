// Text Compression Part 

/*
            Huffman Coding

            Huffman Coding is one approach followed for Text Compression. Text
            compression means reducing the space requirement for saving a particular text.

            Huffman Coding is a lossless data compression algorithm, ie. it is a way of
            compressing data without the data losing any information in the process. It is
            useful in cases where there is a series of frequently occurring characters.


            Time complexity:

                In case of encoding, inserting each character into the priority queue takes O(log n)
                time. Therefore, for the complete array, the time complexity becomes O(nlog n).
                Similarly, extraction of the element from the priority queue takes O(log n) time.
                Hence, for the complete array, the achieved time complexity is O(nlog n).

            Applications of Huffman Coding:

                ● They are used for transmitting fax and text.
                ● They are used by conventional compression formats like PKZIP, GZIP, etc.

*/