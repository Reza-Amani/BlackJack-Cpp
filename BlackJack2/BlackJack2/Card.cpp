#include "pch.h"
#include "Card.h"


Card::Card(Suits s, Ranks r)
{
	suit = s;
	rank = r;
//	rule = rule
}

int Card::get_value(Irule& rule)
{
	return 0;//rule.card_value(suit, rank);
}


Card::~Card()
{
}
