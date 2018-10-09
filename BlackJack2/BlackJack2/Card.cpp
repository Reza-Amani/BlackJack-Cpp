#include "pch.h"
#include "Card.h"


Card::Card(Suits s, Ranks r)
{
	suit = s;
	rank = r;
}

int Card::get_value(Irule& rule)
{
	return rule.card_value(suit, rank);
}


Card::~Card()
{
}




Irule::Irule()
{
}


Irule::~Irule()
{
}

/*int Irule::card_value(Suits s, Ranks r)
{
	return 0;
}
*/