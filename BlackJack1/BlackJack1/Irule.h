#pragma once
#include "Card.h"

class Irule
{
public:
	virtual int card_value(Card& card)=0;
	Irule();
	~Irule();
};

