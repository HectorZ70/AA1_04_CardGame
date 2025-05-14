#include "Card.h"

Card::Card(Suit newSuit, int newValue)
{
	v_suit = newSuit;
	v_value = newValue;
}

bool Card::operator==(const Card& other) const
{
	return (this->v_suit == other.v_suit) && (this->v_value == other.v_value);
}

