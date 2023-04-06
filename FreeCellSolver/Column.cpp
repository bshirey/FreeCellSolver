#include "Column.h"


Column::Column()
{
}


Column::~Column()
{
}

void Column::addCard(const Card &c)
{
	this->cards.push_back(Card(c));
}

unsigned short Column::getNumCards()
{
	return this->cards.size();
}