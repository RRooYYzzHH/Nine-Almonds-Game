// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	// Check the arguments numbers
	const char *programName = argv[command_line_argument::programName];

	if (argc != command_line_argument::expectedArguments && argc != command_line_argument::expectedAutoPlayArguments)
	{
		return usageMessage(programName, "NineAlmonds");
	}

	if (argc == command_line_argument::expectedArguments) 
	{
		if (argv[1] != string("NineAlmonds"))
		{
			return usageMessage(programName, "NineAlmonds");
		}
		NineAlmondsGame nag;
		return nag.play();
	}

	if (argc == command_line_argument::expectedAutoPlayArguments)
	{
		if (argv[1] != string("NineAlmonds") || argv[2] != string("auto_play"))
		{
			return usageMessage(programName, "NineAlmonds");
		}
		NineAlmondsGame nag;
		nag.auto_play();
		return success;
	}
}

