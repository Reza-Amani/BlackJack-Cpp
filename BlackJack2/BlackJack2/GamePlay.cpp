#include "pch.h"
#include "GamePlay.h"
#include <iostream>
#include <functional>



GamePlay::GamePlay()
{
}

result GamePlay::run(bool echo, std::function<int(void)> p_get_card)
{
	DealerFirst = p_get_card();
	if(echo)
		std::cout << DealerFirst;
	return (result)0;
}

void GamePlay::TakeFirstDealerCard(Ranks r)
{
	DealerFirst = get_card();
}
void TakeFirstPlayerCards(Ranks r1, Ranks r2);


GamePlay::~GamePlay()
{
}
