#include "pch.h"
#include "BJrule.h"


BJrule::BJrule()
{
}


BJrule::~BJrule()
{
}

int BJrule::card_value(Suits s, Ranks r)
{
	if (r < _10)
		return r + 2;
	else if (r == _Ace)
		return 11;
	else
		return 10;
}