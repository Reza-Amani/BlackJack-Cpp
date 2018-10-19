#include "pch.h"
#include "GamePlay.h"
#include <iostream>
#include <functional>



GamePlay::GamePlay()
{
}

result GamePlay::run(bool echo, bool auto_player)
{
	int Dealer_First=0, Dealer_sum=0, Player_pair=0, Player_sum=0;

	if (echo) std::cout << "Dealer's first: ";
	Dealer_First = get_card(); 
	Dealer_sum = Dealer_First;

	if (echo) std::cout << Dealer_First << "\n";

	if (echo) std::cout << "Player's first pair: ";
	int player_card;
	player_card = get_card();
	if (echo) std::cout << player_card << " ";
	Player_pair = player_card;
	player_card = get_card();
	if (echo) std::cout << player_card << "\n";
	Player_pair += player_card;
	Player_sum = Player_pair;

	std::cout << "\n player cards: ";
	while (Player_decision(auto_player, Dealer_First, Player_pair))
	{
		player_card = get_card();
		if (echo) std::cout << player_card << " ";
		Player_sum += player_card;
		if (Player_sum > 21)
			return result::_LOSE;
		else if (Player_sum == 21)
			return result::_WIN;
	}
	return result::_PUSH;
}

bool GamePlay::Player_decision(bool auto_player, int Dealer_First, int Player_pair)
{
	if (auto_player)
	{

	}
	else
	{
		std::cout << "continue?y/n ";
		char c;
		std::cin >> c;
		return c == 'y';
	}
}

GamePlay::~GamePlay()
{
}
