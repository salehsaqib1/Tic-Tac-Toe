# Tic-Tac-Toe
Assignment 3

Introduction

You have most likely played the classic game tic-tac-toe. If not you can read about the
history and the rules of the game at http://en.wikipedia.org/wiki/Tic-tac-toe.
Assignment
You are to write a program that simulates a game of tic-tac-toe. It will read a sequence of
moves from a file, and determine the final result. (There are four possible outcomes: X
wins, O wins, it is a draw or the game is incomplete). The program will also display the
game board after the moves are complete.
(For those of you who are interested in a more challenging problem, think about
simulating the more general (m, n, 3) puzzle mentioned in the above link. It should not be
too difficult to generalize your program.)

Input

The input will be in a file named “moves.txt” representing the moves of the game. All the
moves are presented at once in the file (rather than interactively). The file is formatted as
follows:

x11 y11

x21 y21

x12 y12

x22 y22

…

Where (xij, yij) are the x and y coordinates of the jth move of player i. They should have
the values 0, 1 or 2. That is, the first line represents the coordinates of the square where
the first player moves. The next line of the file represents the move of the second player.
Then this pattern repeats with the first and second players alternating moves.
An example input file would be:

0 0

1 1

0 2

0 1

Your program must be able to detect invalid moves. For example moves where the
coordinates are out of range, where the square is already occupied or where a move is
attempted after the game has ended.

Output

Your program should write the results to an output file named “result.txt”. The output
should consist of the result of the game followed by a graphical representation of the final
board.
The possible results are:

Incomplete Game

X Wins

O Wins

Draw

For the sample input file above, the output should be as below. Note that empty cells are
displayed as a dot (.).

Incomplete Game

X|O|X

.|O|.

.|.|.

Methodology

You should assume that X is the first player to start. The other player is O.
You can use a two dimensional array to represent the board.
You must define and use at least two functions in your solution. For example you
might write a function definition that, given an array representing the board and a pair of
values representing a move) determines whether the move is valid or not. You might
write a function definition that, given a board, checks whether the game has been won or
is a draw.
You can use one of the techniques discussed in class to determine when the end of the
input file has been reached.
