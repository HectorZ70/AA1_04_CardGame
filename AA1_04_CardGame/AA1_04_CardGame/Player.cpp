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
    while (it != v_hand.end()) {
        if (suitOrder(it->v_suit) > suitOrder(card.v_suit)) {
            break;
        }
        else if (suitOrder(it->v_suit) == suitOrder(card.v_suit) && it->v_value > card.v_value) {
            break;
        }
        ++it;
    }
    v_hand.insert(it, card);
}

Card Player::GetCard() const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, v_hand.size() - 1);

    int index = dis(gen);
    return v_hand[index];
}

Card Player::GetCard(const Suit& suit)
{
    Card* bestCard = nullptr;

    for (const auto& card : v_hand) {
        if (card.v_suit == suit) {
            if (!bestCard || card.v_value > bestCard->v_value) {
                bestCard = const_cast<Card*>(&card);
            }
        }
    }

    if (!bestCard) {
        throw std::runtime_error("No hay cartas del palo especificado en la mano.");
    }

    return *bestCard;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    std::string suitStr;
    switch (card.v_suit) {
    case Suit::HEART: suitStr = "HEART"; break;
    case Suit::DIAMOND: suitStr = "DIAMOND"; break;
    case Suit::SPADE: suitStr = "SPADE"; break;
    case Suit::CLUB: suitStr = "CLUB"; break;
    default: suitStr = "UNKNOWN"; break;
    }
    os << "(" << suitStr << ", " << card.v_value << ")";
    return os;
}


std::ostream& operator<<(std::ostream& os, const Player& player) 
{
    os << "Player ID: " << player.v_ID << "\nHand: ";
    for (const auto& card : player.v_hand) {
        os << card << " ";
    }
    return os;
}

void Player::SortCards()
{
    auto suitOrder = [](const Suit& s) {
        switch (s) {
        case Suit::HEART: return 0;
        case Suit::DIAMOND: return 1;
        case Suit::SPADE: return 2;
        case Suit::CLUB: return 3;
        default: return 4;
        }
        };

    std::sort(v_hand.begin(), v_hand.end(), [&](const Card& a, const Card& b) {
        int sa = suitOrder(a.v_suit);
        int sb = suitOrder(b.v_suit);
        if (sa != sb) return sa < sb;
        return a.v_value < b.v_value;
        });
}
