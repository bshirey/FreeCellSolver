#pragma once

#include <string>

using namespace std;

enum class Suit
{
	Diamond = 0,
	Heart,
	Club,
	Spade,
	Empty
};

class Card
{
public:
	Card();
	Card(Suit s, unsigned short value);
	~Card();

	void setSuit(Suit s);
	Suit getSuit();

	void setFaceValue(unsigned short value);
	unsigned short getFaceValue();

	operator std::string() const;

protected:
	Suit suit;
	unsigned short faceValue; // Ace = 1, Jack = 11, Queen = 12, King = 13
};

