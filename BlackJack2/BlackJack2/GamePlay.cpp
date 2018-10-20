#include "pch.h"
#include "GamePlay.h"
#include <iostream>
#include <functional>



GamePlay::GamePlay()
{
}

result GamePlay::run(bool echo, bool auto_player)
{
	int Dealer_First=0, Dealer_sum=0, Player_pair=0, Player_sum=0, Player_cards_no=0;
	int Dealer_aces = 0, Player_aces = 0;

	if (echo) std::cout << "Dealer's first: ";
	Dealer_First = get_card(Dealer_aces);
	Dealer_sum = Dealer_First;

	if (echo) std::cout << Dealer_First << "\n";

	if (echo) std::cout << "Player's first pair: ";
	int player_card;
	player_card = get_card(Player_aces);
	if (echo) std::cout << player_card << " ";
	Player_pair = player_card;
	player_card = get_card(Player_aces);
	if (echo) std::cout << player_card << "\n";
	Player_pair += player_card;
	Player_sum = Player_pair;
	if (Player_sum == 21)
		return result::_WIN;

	Player_cards_no = 2;
	if(echo) std::cout << "\n player cards: ";
	while (Player_decision(auto_player, Dealer_First, Player_sum, Player_cards_no))
	{
		player_card = get_card(Player_aces);
		Player_cards_no++;
		if (echo) std::cout << player_card << " ";
		Player_sum += player_card;
		if (Player_sum > 21 && Player_aces > 0)
		{
			Player_aces--;
			Player_sum -= 10;
		}
		if (Player_sum > 21)
			return result::_LOSE;
		else if (Player_sum == 21)
			return result::_WIN;
		else if (Player_cards_no >= 5)
			return result::_WIN;
	}

	if (echo) { std::cout << "\r\n Dealer's turn: "; }

	int Dealer_card;
	do
	{
		Dealer_card = get_card(Dealer_aces);
		if (echo) std::cout << Dealer_card << " ";
		Dealer_sum += Dealer_card;
		if (Dealer_sum > 21 && Dealer_aces > 0)
		{
			Dealer_aces--;
			Dealer_sum -= 10;
		}
	}	while (Dealer_sum < 17);

	if (Dealer_sum > 22)
		return result::_WIN;
	else if (Dealer_sum == 22)
		return result::_PUSH;
	else if (Dealer_sum == 21)
		return result::_LOSE;
	else if (Dealer_sum > Player_sum)
		return result::_LOSE;
	else if (Dealer_sum == Player_sum)
		return result::_PUSH;
	else
		return result::_WIN;
}

bool GamePlay::Player_decision(bool auto_player, int Dealer_First, int Player_sum, int Player_cards_no)
{
	if (auto_player)
	{
		if (Player_sum < 17)
			return true;
		else
			return false;
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
