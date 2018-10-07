#include "stdafx.h"
#include "Card.h"


Card::Card(Suits s, Ranks r)
{
	suit = s;
	rank = r;
	rule = rule
}

int Card::get_value(Irule& rule)
{
	return rule.card_value(this);
}


Card::~Card()
{
}
