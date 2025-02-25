// BlackJack2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Card.h"
#include "BJrule.h"
#include <random>
#include "GamePlay.h"
BJrule bjrule;
int get_rnd_card(int &ace_cnt)
{
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_int_distribution<> dist(0, 12);
	Card card(Suits::_Clubs, (Ranks)dist(mt));
	if (card.get_value(bjrule) == 11)
		ace_cnt++;
	return card.get_value(bjrule);
}
int get_in_card(int &ace_cnt)
{
	int in;
	std::cin >> in;
	if (in == 11)
		ace_cnt++;
	return in;
}
int main()
{
	std::cout << "Hello World!\n";


	GamePlay game;

	int rounds = 0;
	float sum = 0;
	bool echo = false;
	bool Auto = true;
	bool use_doubling = false;
	game.get_card = (Auto) ? get_rnd_card : get_in_card;


	// auto game
	while(rounds++<100000)
	{
		float result=game.run(echo, Auto, use_doubling);
		sum += result;
		if(echo)
			std::cout << "\r\nresult: "<<result << "\r\n";
	}
	std::cout << "\r\n----ave : " << (float)sum/rounds;
	
	
	/*
	//simulation of doubled 
	for (int d = 2; d <= 11; d++)
		for (int p = 4; p <= 16; p++)
		{
			rounds = 0;
			sum = 0;
			while (rounds++ < 100000)
			{
				float result = game.run_doubled(echo, Auto, d, p);
				sum += result;
				if (echo)
					std::cout << "\r\nresult: " << result << "\r\n";
			}
			if (sum >= 0)
				std::cout << "\r\n----ave : " << (float)sum / rounds << " for Dealer: " << d << " and Player pair: " << p;
		}
	*/

	/*	manual game
	char c;
	do
	{
		switch (game.run(true, Auto))
		{
		case result::_LOSE:
			std::cout << "\r\nlost\r\n";
			break;
		case result::_PUSH:
			std::cout << "\r\ndrew\r\n";
			break;
		case result::_WIN:
			std::cout << "\r\nwon\r\n";
			break;
		}
		std::cout << "\r\nnew game?y/n\r\n";
		std::cin >> c;
	} while (c == 'y');
*/
}

//for (int i = 0; i < 60; ++i)
//	std::cout << dist(mt) << "\n";


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
