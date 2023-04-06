// FreeCellSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "Board.h"
#include "Card.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Board startingBoard;

	if (argc != 2)
	{
		cerr << "Usage: FreeCellSolver.exe <boardfile>" << endl;
		return -1;
	}

	try
	{
		startingBoard.LoadBoardFile(std::string((char*)(argv[1])));
	}
	catch (std::string error)
	{
		cerr << "Caught error: " << error << endl;
	}

	startingBoard.PrintBoard();

	return 0;
}

