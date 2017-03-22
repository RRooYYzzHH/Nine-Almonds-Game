========================================================================
               CSE 332 Lab 2: Nine Almonds Game
                           By Zihao Yang (ID: 445432)
========================================================================

1. 
Summmary of my project:

My project contains two header files (Header.h and Game.h) and two source
files (Header.cpp and Game.cpp) and one main file (Lab2.cpp). For "Header.h",
it contains one enumeration for return message and a usage message function.
"Header.cpp" is to implement the usage message function. For "Game.h", it
defines a NineAlmondsGame class and define all the variables and functions for
this class following project's instructuon. "Game.cpp" is to implement the 
functions in NineAlmondsGame class.

You can use command line: "Lab2.exe NineAlmonds" or "Lab.exe NineAlmonds auto_play"
to run my program

2.
Return Value of my Program:

There are totally 4 different return values:
   (1) when the user completes the game successfully, my program will return 0
   (2) if the user quits the game during using it, my program will return 1
   (3) if the user cannot complete the game and there is no valid move remained,
my program will return 2
   (4) if the user don't user correct command-line argument, my program will
return 3

3.
Difficulies During Finishing the Project:

(1)
It is very difficult to check whether two positions are valid move. There are 
totally 8 cases if 8 different directions. To deal with this, I implement some
helper functions

(2)
During one turn, there are lots of cases, such as user quits, user continues the 
turn, user finish the turn and invalid inputs. In order to consider all the situations,
I ran the program as a user lots of times.

 
4.
Testing the Project:

command line: Lab2.exe or Lab2.exe Almonds or Lab2.exe NineAlmonds autoPlay
output: usage: Lab2.exe NineAlmonds or Lab2.exe NineAlmonds auto_play

command line: Lab2.exe NineAlmonds
output: play the game

command line: Lab2.exe NineAlmonds auto_play
output: one way to complete the game

=========================================================================================
Extra Credit:

For the auto_play() function, I use the backtrack method. 

First, I create a 3-dimensional vector and insert the initial game board into this vector. 
I also create a string vector to denote the move. 

Then I pass these two vectors together with some other help variables into private fucntion 
autoPlay. This function then calculates and prints out one possible way to complete the game.
"autoPlay" just uses normal backtrack method. In general, it loops through the last element
of the game board 3D vector, find one valid move, update the game board, push this new game
board back to the 3D vector and do the same thing for move string vector. Whenever we cannot 
find any valid move, we pop back the 3D vector and move string vector.

The last thing I do is to deal with the final move in string vector. I combine and divide them
into turns one by one.

By the way, one problem of my code is that it uses nearly 15 minutes to find the result.
=========================================================================================


