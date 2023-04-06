#include "Board.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

Board::Board()
{
	int i = 0;

	for (i = 0; i < MAX_COLUMNS; i++)
		columns.push_back(Column());

	for (i = 0; i < MAX_FOUNDATIONS; i++)
		foundations.push_back(Foundation());

	for (i = 0; i < MAX_RESERVES; i++)
		reserves.push_back(Card());
}

Board::~Board()
{
}

void Board::LoadBoardFile(string fileName)
{
	ifstream boardFile(fileName);
	string currentCardRep;

	if (!boardFile.is_open())
		throw std::string("Could not open file: ") + fileName;

	int currentColumn = 0;
	while (!boardFile.eof())
	{
		boardFile >> currentCardRep;
		transform(currentCardRep.begin(), currentCardRep.end(), currentCardRep.begin(), toupper);

		if ((currentCardRep.length() != 2) && (currentCardRep.length() != 3))
			throw std::string("Found card representation of the wrong length: ") + currentCardRep;

		// get the last character. it should be the suit
		char suitChar = currentCardRep[currentCardRep.length() - 1];
		Suit suit;
		switch (suitChar)
		{
		case 'C':
			suit = Suit::Club;
			break;
		case 'D':
			suit = Suit::Diamond;
			break;
		case 'H':
			suit = Suit::Heart;
			break;
		case 'S':
			suit = Suit::Spade;
			break;
		default:
			throw std::string("Found unknown suit in board file in string: ") + currentCardRep;
			break;
		}

		unsigned short faceValue = 0;
		string valueStr = currentCardRep.substr(0, currentCardRep.length() - 1);
		if (valueStr == "J")
			faceValue = 11;
		else if (valueStr == "Q")
			faceValue = 12;
		else if (valueStr == "K")
			faceValue = 13;
		else if (valueStr == "A")
			faceValue = 1;
		else
		{
			try
			{
				faceValue = std::stoi(valueStr);
			}
			catch (invalid_argument e)
			{
				throw std::string("Found invalid face value of card in string: ") + currentCardRep;
			}
		}

		if ((faceValue < 1) || (faceValue > 13))
			throw std::string("Found invalid face value of card in string: ") + currentCardRep;

		Card card(suit, faceValue);
		this->columns[currentColumn].push_back(card);
		currentColumn++;
		currentColumn %= MAX_COLUMNS;
	}

	boardFile.close();

	// now verify that the right number of cards is on the board
	unsigned short numCards = 0;
	for (auto it = columns.begin(); it != columns.end(); it++)
		numCards += it->size();
	if (numCards < 52)
		throw std::string("Found fewer than 52 cards in file: ") + fileName;
	else if (numCards > 52)
		throw std::string("Found too many cards in file: ") + fileName;

	// verify that each card is on the board somewhere, and that none of the cards are duplicated
	for (int suitIndex = 0; suitIndex < 4; suitIndex++)
	{
		Suit suit = (Suit)suitIndex;

		for (unsigned short valueIndex = 1; valueIndex < 14; valueIndex++)
		{
			Card cardToFind = Card(suit, valueIndex);
			bool foundCard = false;

			for (auto it = columns.begin(); it != columns.end(); it++)
			{
				for (auto cardIt = it->begin(); cardIt != it->end(); cardIt++)
				{
					if ((cardIt->getFaceValue() == cardToFind.getFaceValue()) && (cardIt->getSuit() == cardToFind.getSuit()))
					{
						// check for duplicate
						if (foundCard)
							throw std::string("Found duplicate card: ") + (string)cardToFind;
						foundCard = true;
					}
				}
			}

			if (!foundCard)
				throw std::string("Could not find card: ") + (string)cardToFind;
		}
	}
}

void Board::PrintBoard()
{
	cout << "Reserves:    |";
	for (auto it = reserves.begin(); it != reserves.end(); it++)
		cout << setw(3) << (string)*it << "|";
	cout << endl;

	cout << "Foundations: |";
	for (auto it = reserves.begin(); it != reserves.end(); it++)
		cout << setw(3) << (string)*it << "|";
	cout << endl << endl;

	unsigned int maxRows = 0;
	for (auto it = columns.begin(); it != columns.end(); it++)
	{
		if (it->size() > maxRows) maxRows = it->size();
	}

	cout << "---------------------------------" << endl;
	for (unsigned int i = 0; i < maxRows; i++)
	{
		cout << "|";
		for (auto it = columns.begin(); it != columns.end(); it++)
		{
			if (i < it->size())
				cout << setw(3) << (string)((*it)[i]);
			else
				cout << "   ";
			cout << "|";
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
}