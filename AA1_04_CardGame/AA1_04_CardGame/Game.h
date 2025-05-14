#pragma once
#include "Player.h"
const int MAX_PLAYERS = 8;
const int MIN_PLAYERS = 2;

class Game 
{
private:
	std::vector<Card> v_deck;
	int v_players;
public:
	Game(std::vector<Card> newDeck, int newPlayers);
	Card GetNewCard() const;
	void DiscardCard(const Card card);
	void PrintDiscarded() const;
};

