#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Game.h"

std::vector<Card> CreateFullDeck() {
    std::vector<Card> deck;
    for (int suit = 0; suit < 4; ++suit) {
        for (int value = 1; value <= 13; ++value) {
            deck.emplace_back(static_cast<Suit>(suit), value);
        }
    }
    return deck;
}

int main() {
    try {
        std::vector<Card> deck = CreateFullDeck();

        int numPlayers;
        std::cout << "Ingrese el número de jugadores (2 a 8): ";
        std::cin >> numPlayers;

        Game game(deck, numPlayers);

        std::cout << "\n=== MANOS INICIALES ===\n";
        game.PrintPlayers();

        std::cout << "\n=== CARTA SIGUIENTE (sin sacarla del mazo) ===\n";
        Card preview = static_cast<const Game&>(game).GetNewCard();  // versión const
        std::cout << preview << "\n";

        std::cout << "\n=== TOMAR Y DESCARTAR 5 CARTAS ===\n";
        for (int i = 0; i < 5; ++i) {
            Card drawn = game.DeleteCard();  // versión no const
            std::cout << "Sacada: " << drawn << "\n";
            game.DiscardCard(drawn);
        }

        std::cout << "\n=== DESCARTES ===\n";
        game.PrintDiscarded();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}