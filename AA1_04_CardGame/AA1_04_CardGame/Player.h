#pragma once
#include "Card.h"

class Player 
{
private:
	int v_ID;
	std::vector<Card> v_hand;
public:
	void InsertCard(Card card);
	Card GetCard() const;
	Card GetCard(const Suit& suit);
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	void SortCards();
};

