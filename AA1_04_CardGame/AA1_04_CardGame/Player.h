#pragma once
#include "Card.h"
#include <string>

class Player 
{
private:
	int v_ID;
	std::string v_name;
	std::vector<Card> v_hand;
public:
	Player();
	Player(int id, const std::string& name);

	void InsertCard(Card card);
	Card GetCard() const;
	Card GetCard(const Suit& suit);
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	void SortCards();
};

