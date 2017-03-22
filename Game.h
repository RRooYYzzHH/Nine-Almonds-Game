/*
This file is main header file of my program.

Fisrt, I define the class for our game board, which is NineAlmondsGame. It has 3 private variables, including width(equals to 5), height(equals to 5) and a two-dimensional string array(game board).
The class also has seven functions:
   1. NineAlmondsGame(). This is the constructor function and initialize the game board array.
   2. operator<<. This function is to print out the whole game board.
   3. done
   4. stalemate
   5. prompt
   6. turn
   7. play 
(functions 3 to 7 just follows the project requirement)

Apart from the class, I also implement a helper function checkPosition, which takes 4 integers and return a bool value. This function is to help me judge whethen two positions can be valid-move.  
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Header.h"

using namespace std;

class NineAlmondsGame {
private:
	int width = 5;
	int height = 5;
	vector<vector<string>> gameBoard;

	void autoPlay(int turn, vector<vector<vector<string>>> &boardList, vector<string> &move, string &result, bool &judge);

public:
	NineAlmondsGame() {
		vector<string> line1;
		vector<string> line2;
		for (int i = 0; i < width; i++)
		{
			line1.push_back(" ");
			if (i == 0 || i == (width - 1))
			{
				line2.push_back(" ");
			}
			else
			{
				line2.push_back("A");
			}
		}
		for (int i = 0; i < height; i++)
		{
			if (i == 0 || i == (height - 1))
			{
				gameBoard.push_back(line1);
			}
			else
			{
				gameBoard.push_back(line2);
			}
		}
	}

	// Method
	friend ostream & operator<< (ostream &os, const NineAlmondsGame & nag);
	bool done(); 
	bool stalemate();
	int prompt(unsigned int &, unsigned int &);
	int turn();
	int play();
	void auto_play();
};

ostream & operator<< (ostream &, const NineAlmondsGame &);

bool checkPosition(int x, int y, int x_now, int y_now);
