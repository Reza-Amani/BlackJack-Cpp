#pragma once
#include "Card.h"
#include <functional>
class GamePlay
{
public:
	std::function<int(int&)> get_card;
	//func* GetGo_Nogo  --main decides if nogo at any threshold
	//func* int GetCard()  --main decides if rand card or all combinations
	//result,sum@Nogo, sum@firstpair, DealerFirst run();	//main will make 3D array of results and number of occcurances
	GamePlay();
	~GamePlay();
	bool if_doubling(int Dealer_first, int Player_pair);	//decides if doubling is suitable or no
	float run(bool echo, bool auto_player, bool use_doubling);
	float run_doubled(bool echo, bool auto_player, int Dealer_First, int Player_pair);	//run after first pair, continue only for 1 hit, to determine if doubling was a good idea (return >0?)
	bool Player_decision(bool auto_player, int Dealer_First, int Player_sum, int Player_cards_no);
};

