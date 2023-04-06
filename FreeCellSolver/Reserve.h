#pragma once

#include <vector>
#include "Card.h"

using namespace std;

class Reserve
{
public:
	Reserve();
	~Reserve();

protected:
	vector<Card> cards;
};

