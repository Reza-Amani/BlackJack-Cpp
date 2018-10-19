#pragma once
#include "Card.h"
#include <functional>
enum result
{
	_LOSE=-1,
	_PUSH,
	_WIN
};
class GamePlay
{
public:
	std::function<int(void)> get_card;
	//func* GetGo_Nogo  --main decides if nogo at any threshold
	//func* int GetCard()  --main decides if rand card or all combinations
	//result,sum@Nogo, sum@firstpair, DealerFirst run();	//main will make 3D array of results and number of occcurances
	GamePlay();
	~GamePlay();
	result run(bool echo, bool auto_player);
	bool Player_decision(bool auto_player, int Dealer_First, int Player_sum, int Player_cards_no);
};

