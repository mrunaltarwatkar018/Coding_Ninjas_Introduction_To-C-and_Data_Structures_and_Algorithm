/*


            Reason we choose the Tries over Hashmaps overs in order to create the Dictionary  

            1) Space Opti ization
            2) Fast Searching part or word
            


            Types Of Tries

            1) Compressed Tries 
                    🔹Majorly, used for space optimization.
                    🔹We generally club the characters if they have at most one child.
                    🔹General rule: Every node has at least two child nodes.


            2) Pattern matching:
                    🔹 Used to match patterns in the trie.
                            ⏹️      Example: In the figure-1 (shown above), if we want to search for
                                    pattern ben in the trie, but the word bend was present instead,
                                    using the normal search function, we would return false, as the
                                    last character n’s isTerminal property was false, but in this trie,
                                    we would return true.
                    🔹 To overcome this problem of the last character’s identification, just
                        remove the isTerminal property of the node.
                    🔹  In the figure-1, instead of searching for the pattern ben, we now want
                        to search for the pattern en. Our trie would return false if en is not
                        directly connected to the root. But as the pattern is present in the
                        word ben, it should return true. To overcome this problem, we need to
                        attach each of the prefix strings to the root node so that every pattern
                        is encountered.
                            ⏹️     For example: for the string ben, we would store ben, en, n in
                                    the trie as the direct children of the root node.
                
*/