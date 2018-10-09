#pragma once
#include "Irule.h"

enum Suits
{
	_Heart,
	_Spades,
	_Diamonds,
	_Clubs
};

enum Ranks
{
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
	_10,
	_Jack,
	_Queen,
	_King,
	_Ace
};

class Card
{
	Irule rule();
	Suits suit;
	Ranks rank;
public:
	Card(Suits s, Ranks r);
	int get_value(Irule& rule);
	~Card();
};


