#pragma once

#include <string>
#include <vector>

#include "Card.h"

#define MAX_COLUMNS 8
#define MAX_FOUNDATIONS 4
#define MAX_RESERVES 4

using namespace std;

typedef vector <Card> Column;
typedef vector <Card> Foundation;

class Board
{
public:
	Board();
	~Board();

	void LoadBoardFile(string fileName);
	void PrintBoard();

protected:
	vector<Column> columns;
	vector<Card> reserves;
	vector<Foundation> foundations;
};

