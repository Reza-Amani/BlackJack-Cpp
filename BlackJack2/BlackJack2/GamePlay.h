#pragma once
#include "Card.h"
class GamePlay
{
public:
	//func* GetGo_Nogo  --main decides if nogo at any threshold
	//func* int GetCard()  --main decides if rand card or all combinations
	result,sum@Nogo, sum@firstpair, DealerFirst run();	//main will make 3D array of results and number of occcurances
	GamePlay();
	~GamePlay();
	void TakeFirstDealerCard(Ranks r);
	void TakeFirstPlayerCards(Ranks r1, Ranks r2);
};

