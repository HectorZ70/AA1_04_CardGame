#pragma once
#include "Player.h"
const int MAX_PLAYERS = 8;
const int MIN_PLAYERS = 2;

class Game 
{
private:
	std::vector<Card> v_deck;
	std::vector<Card> v_discarded;
	std::vector<Player> v_playerList;
	int v_players;

	void DealCards();
public:
	Game(std::vector<Card> newDeck, int newPlayers);
	Card DeleteCard();
	Card GetNewCard() const;
	void DiscardCard(const Card card);
	void PrintDiscarded() const;
	void PrintPlayers() const;
};

