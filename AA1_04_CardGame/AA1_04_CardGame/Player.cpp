#include "Player.h"

void Player::InsertCard(Card card) {
    auto suitOrder = [](const Suit& s) {
        switch (s) {
        case Suit::HEART: return 0;
        case Suit::DIAMOND: return 1;
        case Suit::SPADE: return 2;
        case Suit::CLUB: return 3;
        default: return 4;
        }
        };

    auto it = v_hand.begin();
    while (it != v_hand.end() && suitOrder(it->Card()) <= suitOrder(card.Card())) {
        ++it;
    }
    v_hand.insert(it, card);
}

Card Player::GetCard() const
{

}

Card Player::GetCard(const Suit& suit)
{

}

std::ostream& operator<<(std::ostream& os, const Player& player) 
{

}

void Player::SortCards()
{

}
