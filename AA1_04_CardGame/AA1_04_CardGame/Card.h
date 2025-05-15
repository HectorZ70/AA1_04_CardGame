#pragma once
#include <iostream>
#include <vector>
#include<random>

enum class Suit{HEART, DIAMOND, SPADE, CLUB};

// J = 11, Q = 12, K = 13;

class Card 
{
public:
	Suit v_suit;
	int v_value;
	Card(Suit newSuit, int newValue);
	bool operator==(const Card& other) const;
};

std::ostream& operator<<(std::ostream& os, const Card& card);