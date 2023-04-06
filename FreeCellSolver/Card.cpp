#include "Card.h"

#include <string>

Card::Card() : suit(Suit::Empty), faceValue(0)
{
}

Card::Card(Suit s, unsigned short value) : suit(s), faceValue(value)
{
}

Card::~Card()
{
}

void Card::setSuit(Suit s)
{
	this->suit = s;
}

Suit Card::getSuit()
{
	return this->suit;
}

void Card::setFaceValue(unsigned short value)
{
	this->faceValue = value;
}

unsigned short Card::getFaceValue()
{
	return this->faceValue;
}

Card::operator std::string() const
{
	string retVal = "";

	if ((faceValue == 0) || (suit == Suit::Empty))
	{
		return " * ";
	}

	switch (faceValue)
	{
	case 1:
		retVal += 'A';
		break;
	case 11:
		retVal += 'J';
		break;
	case 12:
		retVal += 'Q';
		break;
	case 13:
		retVal += 'K';
		break;
	default:
		retVal += std::to_string(faceValue);
		break;
	}

	switch (suit)
	{
	case Suit::Club:
		retVal += "C";
		break;
	case Suit::Diamond:
		retVal += "D";
		break;
	case Suit::Heart:
		retVal += "H";
		break;
	case Suit::Spade:
		retVal += "S";
		break;
	}

	return retVal;
}