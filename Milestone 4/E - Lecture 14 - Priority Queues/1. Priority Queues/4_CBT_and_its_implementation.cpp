/*

        CBT & ITS IMPLEMENTATION :

                1.  Minimum number of nodes with height 'h' of the CBT  :   2^(h-1)

                2.  Maximum number of nodes with height 'h' of the CBT  :   2^(h) - 1


                if CBT has 'n' number of nodes then - 
                        2^(h-1) <= n <= 2^(h) - 1


                        On solving      2^(h-1) <= n        We get     h <= log2 (n) + 1

                                                        &

                        On Solving      n <= 2^(h) - 1      We get     log2 ((n)+1) <= h


                The Value of 'h' is --

                            log2 (n+1)    <=  h   <=  log2 (n) + 1

                                    where 'h' is the height of complete Binary Tree (CBT)

                            In case of time Complexity --

                            O(log2 (n))    <=  h   <=  O(log2 (n))

                    that means the Height Of CBT is always O(log2 (n))



*/