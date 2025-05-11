#pragma once

enum class Suit{HEART, DIAMOND, SPADE, CLUB};

// J = 11, Q = 12, K = 13;

class Card
{
private:
	int v_value;
	Suit v_suit;

public:
	Card() 
	{
		Suit suit = v_suit;
		int value = v_value;
	}
    
	Card(Suit suit, int value) : v_suit(suit), v_value(value)
	{
		bool operator==(const Card& other) const
		{
			return (this->suit == other.suit) && (this->value == other.value);
		}
	}
};

