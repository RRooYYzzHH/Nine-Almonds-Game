/*
This source file implements usageMessage function, which print out how to use my program
*/

#include "stdafx.h"
#include "header.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int usageMessage(const char *programName, string message) {
	cout << "Usage: " << programName << " " << message << " or " << programName << " " << message << " " << "auto_play" << endl;
	return error_command_line;
}