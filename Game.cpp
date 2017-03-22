/*
This source file is to implement all the functions defined on Game.h
*/

#include "stdafx.h"
#include "Game.h"

#include <utility>

using namespace std;

// Print out the Game Board
ostream & operator<< (ostream &os, const NineAlmondsGame & nag) {
	for (int i = nag.height - 1; i >= 0; i--) {
		os << i << " ";
		for (int j = 0; j < nag.width; j++) {
			os << nag.gameBoard[j][i] << " ";
		}
		os << endl;
		os << endl;
		if (i == 0)
		{
			os << "X 0 1 2 3 4" << endl;
		}
	}
	return os;
}

void NineAlmondsGame::auto_play() {
	vector<vector<vector<string>>> boardList;
	boardList.push_back(gameBoard);
	vector<string> move;
	move.push_back("");
	string result;
	bool judge = false;
	autoPlay(0, boardList, move, result, judge);
	int size = result.size();
	cout << result << "size is: " << size << endl;
	int index = 0;
	int turnNum = 1;
	bool cont = true;
	cout << "Use the following turns to complete the game: " << endl;
	while (cont)
	{
		cout << "Turn " << turnNum << ":" << endl;
		string t = result.substr(index, 3) + " to ";
		while (true)
		{
			if (index + 9 >= size)
			{
				t = t + result.substr(index + 5, 3);
				cout << t << endl;
				cont = false;
				break;
			}
			if (result[index + 5] != result[index + 9] || result[index + 7] != result[index + 11])
			{
				t = t + result.substr(index + 5, 3);
				cout << t << endl;
				index += 9;
				break;
			}
			else
			{
				t = t + result.substr(index + 5, 3) + " to ";
				index += 9;
			}
		}
		turnNum++;
	}
}

void NineAlmondsGame::autoPlay(int turn, vector<vector<vector<string>>> &boardList, vector<string> &move, string &result, bool &judge) {
	if (turn == 8)
	{
		gameBoard = boardList.back();
		if (done()) 
		{
			result = move.back();
			judge = true;
			return;
		}
	}
	if (judge) 
	{
		return;
	}

	for (int w = 0; w < width; w++)
	{
		for (int h = 0; h < height; h++)
		{
			vector<vector<string>> nowBoard = boardList.back();
			vector<vector<string>> newBoard;
			string nowMove = move.back();
			string newMove = nowMove;
			// Copy Board
			for (int i = 0; i < width; i++)
			{
				vector<string> temp;
				for (int j = 0; j < height; j++)
				{
					temp.push_back(nowBoard[i][j]);
				}
				newBoard.push_back(temp);
			}
			vector<vector<string>> tempBoard = newBoard;
			string tempMove = newMove;
			if (newBoard[w][h] == "A")
			{
				// Case 1
				if (w > 1)
				{
					if (newBoard[w - 1][h] == "A" && newBoard[w - 2][h] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w - 1][h] = " ";
						newBoard[w - 2][h] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w - 2) + "," + to_string(h) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}

				// Case 2
				if (h > 1)
				{
					if (newBoard[w][h - 1] == "A" && newBoard[w][h - 2] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w][h - 1] = " ";
						newBoard[w][h - 2] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w) + "," + to_string(h - 2) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}

				// Case 3
				if (w < 3)
				{
					if (newBoard[w + 1][h] == "A" && newBoard[w + 2][h] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w + 1][h] = " ";
						newBoard[w + 2][h] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w + 2) + "," + to_string(h) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}

				// Case 4
				if (h < 3)
				{
					if (newBoard[w][h + 1] == "A" && newBoard[w][h + 2] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w][h + 1] = " ";
						newBoard[w][h + 2] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w) + "," + to_string(h + 2) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}

				// Case 5
				if (w > 1 && h > 1)
				{
					if (newBoard[w - 1][h - 1] == "A" && newBoard[w - 2][h - 2] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w - 1][h - 1] = " ";
						newBoard[w - 2][h - 2] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w - 2) + "," + to_string(h - 2) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}

				// Case 6
				if (w > 1 && h < 3)
				{
					if (newBoard[w - 1][h + 1] == "A" && newBoard[w - 2][h + 2] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w - 1][h + 1] = " ";
						newBoard[w - 2][h + 2] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w - 2) + "," + to_string(h + 2) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}

				// Case 7
				if (w < 3 && h > 1)
				{
					if (newBoard[w + 1][h - 1] == "A" && newBoard[w + 2][h - 2] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w + 1][h - 1] = " ";
						newBoard[w + 2][h - 2] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w + 2) + "," + to_string(h - 2) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}

				// Case 8
				if (w < 3 && h < 3)
				{
					if (newBoard[w + 1][h + 1] == "A" && newBoard[w + 2][h + 2] == " ")
					{
						newBoard[w][h] = " ";
						newBoard[w + 1][h + 1] = " ";
						newBoard[w + 2][h + 2] = "A";
						newMove = newMove + to_string(w) + "," + to_string(h) + "to" + to_string(w + 2) + "," + to_string(h + 2) + ";";
						boardList.push_back(newBoard);
						move.push_back(newMove);
						autoPlay(turn + 1, boardList, move, result, judge);
						boardList.pop_back();
						move.pop_back();
						newBoard = tempBoard;
						newMove = tempMove;
					}
				}
			}
		}
	}
}

int NineAlmondsGame::play() {
	int turns = 0;
	while (true) 
	{
		cout << *this << endl;
		int turnValue = turn();
		turns += 1;
		// check the return value of turn(); user quit
		if (turnValue == 1)
		{
			cout << "The user played " << turns << " turns and then quit the game.." << endl;
			return user_quit;
		}
		// check done(); finish the game
		if (done())
		{
			cout << "The user used " << turns << " turns to complete the game.." << endl;
			return success;
		}
		// check stalemate(); no valid move remain
		cout << "3" << endl;
		if (stalemate())
		{
			cout << "The user played " << turns << " turns and no valid moves remain.." << endl;
			return no_valid_move_remain;
		}
	}
}


int NineAlmondsGame::prompt(unsigned int & first, unsigned int & second) {
	bool conti = true;
	while (conti)
	{
		cout << "Hint: you can either input 'quit' to end the game or input a valid comma-separated coordinate.." << endl;
		string input;
		cin >> input;
		if (input == "quit")
		{
			return user_quit;
		}
		int validCheck = 0;
		int coma = 0;
		int size = input.size();
		char inputArray[1024];
		strcpy_s(inputArray, input.c_str());
		for (int i = 0; i < size; i++)
		{
			if (!isdigit(inputArray[i]) && inputArray[i] != ',')
			{
				validCheck += 1;
			}
			if (inputArray[i] == ',') {
				coma += 1;
				inputArray[i] = ' ';
			}
		}
		if (validCheck > 0 || coma != 1) {
			cout << "Your input is unvalid, please re-input.." << endl;
			continue;
		}
		input = string(inputArray);
		istringstream iss(input);
		int f, s;
		iss >> f;
		iss >> s;
		if (f < 0 || f > (width - 1) || s < 0 || s > (height - 1))
		{
			cout << "Your input is out of the game board, please re-input.." << endl;
			continue;
		}
		first = f;
		second = s;
		conti = false;
	}
	return 0;
}

int NineAlmondsGame::turn() {
	string print = "";
	int x_now, y_now;
	int temp = 0;
	while (true)
	{
		if (temp == 0)
		{
			cout << "Please select a starting square:" << endl;
		}
		else
		{
			cout << "Please select an ending square: (the square to move is " << x_now << "," << y_now << ")" << endl;
		}

		bool judge = true;
		while (judge)
		{
			unsigned int x = 1;
			unsigned int y = 1;
			int returnValue = prompt(x, y);
			// Quit 
			if (returnValue == 1)
			{
				return user_quit;
			}

			if (temp == 0)
			{
				if (gameBoard[x][y] != "A")
				{
					cout << "Error: invalid starting square, the starting square needs to have a almond, please re-input!" << endl;
					continue;
				}
				x_now = x;
				y_now = y;
				print = to_string(x) + ',' + to_string(y) + ' ';
				break;
			}
			if (!checkPosition(x, y, x_now, y_now) || gameBoard[x][y] != " " || gameBoard[(x + x_now) / 2][(y + y_now) / 2] != "A")
			{
				cout << "Error: invalid ending square, no valid move, please re-input! " 
					<< "(Square to move is " << x_now << "," << y_now << ")" << endl;

				continue;
			}

			gameBoard[x_now][y_now] = " ";
			gameBoard[x][y] = "A";
			gameBoard[(x + x_now) / 2][(y + y_now) / 2] = " ";
			string print_tmp = print + "to " + to_string(x) + ',' + to_string(y) + ' ';
			cout << *this << endl;
			cout << print_tmp << endl;
			cout << endl;

			string ctr;
			while (true)
			{
				cout << "Continue this turn (YyNn)?" << endl;
				cin >> ctr;
				if (ctr == "N" || ctr == "n")
				{
					return success;
				}
				else if (ctr == "Y" || ctr == "y")
				{
					x_now = x;
					y_now = y;
					print = print_tmp;
					judge = false;
					break;
				}
				else {
					cout << "Error: invalid answer, please re-answer.." << endl;
					continue;
				}
			}

		}
		temp = 1;
	}
}

// helper function
bool checkPosition(int x, int y, int x_now, int y_now) {
	if (x - x_now == 2 || x - x_now == -2) 
	{
		if (y - y_now == 2 || y - y_now == -2 || y == y_now)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (y - y_now == 2 || y - y_now == -2)
	{
		if (x - x_now == 2 || x - x_now == -2 || x == x_now)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	return false;
}



bool NineAlmondsGame::done() {
	bool result = true;
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++)
		{
			if (i == (height - 1) / 2 && j == (width - 1) / 2 && gameBoard[j][i] != "A") 
			{
				return false;
			}
			if (i != (height - 1) / 2 && j != (width - 1) / 2 && gameBoard[j][i] == "A")
			{
				return false;
			}
		}
	}
	return result;
}

bool NineAlmondsGame::stalemate() {
	if (done()) 
	{
		return true;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			string display = gameBoard[j][i];
			if (display == "A") 
			{
				// totally 8 cases in 8 different directions
				if (j - 1 > 0)
				{
					if (gameBoard[j - 1][i] == "A" && gameBoard[j - 2][i] == " ")
					{
						return false;
					}
				}
				if (j + 1 < width - 1)
				{	
					if (gameBoard[j + 1][i] == "A" && gameBoard[j + 2][i] == " ")
					{
						return false;
					}
				}
				if (i - 1 > 0)
				{
					if (gameBoard[j][i - 1] == "A" && gameBoard[j][i - 2] == " ")
					{
						return false;
					}
				}
				if (i + 1 < height - 1)
				{
					if (gameBoard[j][i + 1] == "A" && gameBoard[j][i + 2] == " ")
					{
						return false;
					}
				}
				if (j - 1 > 0 && i - 1 > 0)
				{	
					if (gameBoard[j - 1][i - 1] == "A" && gameBoard[j - 2][i - 2] == " ")
					{
						return false;
					}
				}
				if (j - 1 > 0 && i + 1 < height - 1)
				{
					if (gameBoard[j - 1][i + 1] == "A" && gameBoard[j - 2][i + 2] == " ")
					{
						return false;
					}
				}
				if (j + 1 < width - 1 && i - 1 > 0)
				{
					if (gameBoard[j + 1][i - 1] == "A" && gameBoard[j + 2][i - 2] == " ")
					{
						return false;
					}
				}
				if (j + 1 < width - 1 && i + 1 < height - 1)
				{
					if (gameBoard[j + 1][i + 1] == "A" && gameBoard[j + 2][i + 2] == " ")
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}