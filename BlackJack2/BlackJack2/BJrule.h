#pragma once
#include "Card.h"
class BJrule :
	public Irule
{
public:
	int card_value(Suits s, Ranks r);
	BJrule();
	~BJrule();
};

