
/*
            Problem :   Sudoku

                Write a program to find a solution to a sudoku puzzle. 
                The input will consist of puzzles with exactly one 
                solution. Or in other words, the Sudoku solved must be 
                a legitimate Sudoku!

            Input :
                The input consists of one test case. Each test case 
                will consist of nine lines with nine digits on each 
                line. There will not be any blanks between the digits. 
                The digits '1' through '9' will represent a number 
                and the digit '0' will represent a blank square. The 
                end of input is indicated by the end of the file.

            Output : 
                For each test case print, in the format shown below, 
                the solved puzzle. There should be no spaces between 
                digits and lines.

            Example :
                Input:
                        023456789
                        406789123
                        780123456
                        234067891
                        567801234
                        891230567
                        345678012
                        678912305
                        912345670


                Output:
                        123456789
                        456789123
                        789123456
                        234567891
                        567891234
                        891234567
                        345678912
                        678912345
                        912345678

*/


/*      Suduko Structure :

            It is a 9 * 9 matrix, i.e.,

                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
                    |   |   |   |   |   |   |   |   |   |
                    -------------------------------------
            
            and each 9 box are divided into 3 * 3 matrix from
                -------------     ------------     ------------
                |   |   |   |     |   |   |   |    |   |   |  |
                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------

                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------

                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------
                |   |   |   |     |  |   |   |     |  |   |   |
                -------------     ------------     ------------



        Solve Sudoku board Steps :
        1. Find empty position on a board
        2. if not find, then return trun
        3. If find, start explire that position from 1 to 9
                    -- check for ROW
                    -- check for COLUMN
                    -- check for BOX

                    board[empty_Position]
                            = number
                    solveSudoku(board)

                    if return true, then return the ans
                    if return false, then make/mark the position empty again
                    and try to fill with further numbers.
        4. if your are not abel to solve the suduko, then retun false 


*/