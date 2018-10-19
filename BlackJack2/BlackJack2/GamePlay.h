#pragma once
#include "Card.h"
#include <functional>
enum result
{
	_LOSE,
	_PUSH,
	_WIN
};
class GamePlay
{
public:
	int DealerFirst, Delaer;
	std::function<int(void)> get_card;
	//func* GetGo_Nogo  --main decides if nogo at any threshold
	//func* int GetCard()  --main decides if rand card or all combinations
	//result,sum@Nogo, sum@firstpair, DealerFirst run();	//main will make 3D array of results and number of occcurances
	GamePlay();
	~GamePlay();
	result run(bool echo, std::function<int(void) > p_get_card);
	void TakeFirstDealerCard(Ranks r);
	void TakeFirstPlayerCards(Ranks r1, Ranks r2);
};

