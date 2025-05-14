#pragma once
#include <iostream>
#include <vector>

enum class Suit{HEART, DIAMOND, SPADE, CLUB};

// J = 11, Q = 12, K = 13;

class Card 
{
private:
	Suit v_suit;
	int v_value;
public:
	Card(Suit newSuit, int newValue);
	bool operator==(const Card& other) const;
};