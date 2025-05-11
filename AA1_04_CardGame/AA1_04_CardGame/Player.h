#pragma once
#include <iostream>
#include <stack>
#include "Card.h"

class Player
{
private: 
	std::string v_id;
	std::stack<Card&> v_hand;

public:
	void InsertCard(Card card);
	Card GetCard() const;
	Card GetCard(const Suit& suit);
	bool operator<<();
	void SortCards();
};

