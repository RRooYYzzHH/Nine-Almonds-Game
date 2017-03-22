/*
We can consider this header file as support file.

First, this header file contains two enumrations, including command_line_argument and return message. And there are totally 5 different messages for our program.

Second, this header file also contains one usageMessage function:
                       usageMessage (handle the usage message)
*/

#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <string>

using namespace std;

enum command_line_argument { programName, fileName, expectedArguments = 2, expectedAutoPlayArguments = 3 };

enum returnMessage
{
	success = 0,
	user_quit = 1,
	no_valid_move_remain = 2,
	error_command_line = 3
};

// Function prototypes
int usageMessage(const char *programName, string message);

#endif#pragma once
