#pragma once

#include <vector>
#include "Card.h"

using namespace std;



class Column
{
public:
	Column();
	~Column();

	void addCard(const Card& c);

	unsigned short getNumCards();

protected:
	vector<Card> cards;
};

