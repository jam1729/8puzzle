# 8puzzle
A simple program that solves the 8 puzzle game, with intermediate states

Enter the number of test cases.
Then enter the 3*3 matrix for each test case.
Enter the position of gap as zero.
There are 9! total possible states , in which only half (i.e) 9!/2 
states are solvable states.

Some states like 

1 2 3

4 6 5

7 8 0

------

1 2 3

4 5 6

8 7 0 

are unsolvable cases.

For each solvable test case , I have printed the minimum number of steps
taken to solve the puzzle.
And then I have printed the states (moves) , that proceeds towards 
the solution.

The states given below takes the longest possible steps , 31 steps.

8 6 7

2 5 4

3 0 1

------

6 4 7

8 5 0

3 2 1


The program might take upto 10 seconds to execute.
