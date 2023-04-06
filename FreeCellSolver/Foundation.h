#pragma once

#include <vector>
#include "Card.h"

using namespace std;

class Foundation
{
public:
	Foundation();
	~Foundation();

protected:
	vector<Card> cards;
};

