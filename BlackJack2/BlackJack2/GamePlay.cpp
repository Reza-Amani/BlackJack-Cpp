#include "pch.h"
#include "GamePlay.h"
#include <iostream>
#include <functional>



GamePlay::GamePlay()
{
}

float GamePlay::run(bool echo, bool auto_player, bool use_doubling)
{
	int Dealer_First=0, Dealer_sum=0, Player_pair=0, Player_sum=0, Player_cards_no=0;
	int Dealer_aces = 0, Player_aces = 0;
	int bet_factor = 1;

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
		return 1.5 * bet_factor;	//natural blackjack

	Player_cards_no = 2;
	if (use_doubling && Player_aces==0 && if_doubling(Dealer_First, Player_pair) )
	{	//doubled. only one card will be drawn
		bet_factor = 2;
		player_card = get_card(Player_aces);
		Player_cards_no++;
		if (echo) std::cout << "\r\nDoubled. single card: " << player_card << " ";
		Player_sum += player_card;
		if (Player_sum > 21 && Player_aces > 0)
		{
			Player_aces--;
			Player_sum -= 10;
		}
		if (Player_sum > 21)
			return -1 * bet_factor;
		else if (Player_sum == 21)
			return 1 * bet_factor;
		else if (Player_cards_no >= 5)
			return 1 * bet_factor;
	}
	else
	{
		if (echo) std::cout << "\r\n player cards: ";
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
				return -1 * bet_factor;
			else if (Player_sum == 21)
				return 1 * bet_factor;
			else if (Player_cards_no >= 5)
				return 1 * bet_factor;
		}
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
		return 1 * bet_factor;
	else if (Dealer_sum == 22)
		return 0 * bet_factor;
	else if (Dealer_sum == 21)
		return -1 * bet_factor;
	else if (Dealer_sum > Player_sum)
		return -1 * bet_factor;
	else if (Dealer_sum == Player_sum)
		return 0 * bet_factor;
	else
		return 1 * bet_factor;
}

bool GamePlay::if_doubling(int Dealer_first, int Player_pair)
{	//decides if doubling is suitable or no
	if (Player_pair == 11)
		return true;
	else if (Player_pair == 10 && Dealer_first < 10)
		return true;
	else if (Player_pair == 9 && (Dealer_first == 5 || Dealer_first == 6))
		return true;
	else
		return false;

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

float GamePlay::run_doubled(bool echo, bool auto_player, int _Dealer_First, int _Player_pair)
{
	int Dealer_First = _Dealer_First, Dealer_sum = _Dealer_First;
	int Player_pair = _Player_pair, Player_sum = _Player_pair, Player_cards_no = 2;
	int Dealer_aces = 0, Player_aces = 0;
	if (_Dealer_First == 1)
		Dealer_aces = 1;

	if (echo) std::cout << "Dealer's first: "<< Dealer_First << "\r\n";
	if (echo) std::cout << "Player's first pair: "<< _Player_pair<< "\r\n";
	if (Player_sum == 21)
		return 1.5;	//natural blackjack

	Player_cards_no = 2;
	if (echo) std::cout << "\n player only additional card: ";

	int player_card = get_card(Player_aces);
	Player_cards_no++;
	if (echo) std::cout << player_card << " ";
	Player_sum += player_card;
	if (Player_sum > 21 && Player_aces > 0)
	{
		Player_aces--;
		Player_sum -= 10;
	}
	if (Player_sum > 21)
		return -1;
	else if (Player_sum == 21)
		return 1;

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
	} while (Dealer_sum < 17);

	if (Dealer_sum > 22)
		return 1;
	else if (Dealer_sum == 22)
		return 0;
	else if (Dealer_sum == 21)
		return -1;
	else if (Dealer_sum > Player_sum)
		return -1;
	else if (Dealer_sum == Player_sum)
		return 0;
	else
		return 1;
}
