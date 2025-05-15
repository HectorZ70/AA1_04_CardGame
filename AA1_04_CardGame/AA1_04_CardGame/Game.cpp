#include "Game.h"

Game::Game(std::vector<Card> newDeck, int newPlayers)
{
	v_deck = newDeck;
	v_players = newPlayers;

	std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));

	std::vector<std::string> nombres = { "Ana", "Luis", "Eva", "Carlos", "Nora", "Tomas", "Marta", "Jorge" };
	std::shuffle(nombres.begin(), nombres.end(), rng);
	if (newPlayers < MIN_PLAYERS || newPlayers > MAX_PLAYERS)

		throw std::invalid_argument("Número de jugadores inválido.");
	for (int i = 0; i < v_players; ++i) {
		Player p(i + 1, nombres[i]);
		v_playerList.push_back(p);
	}
	std::shuffle(v_deck.begin(), v_deck.end(), rng);

	DealCards();
}

void Game::DealCards()
{
	for (int i = 0; i < 10; ++i) {
		for (auto& player : v_playerList) {
			if (!v_deck.empty()) {
				Card card = v_deck.back();
				v_deck.pop_back();
				player.InsertCard(card);  // Ya inserta ordenado
			}
		}
	}
}

Card Game::DeleteCard()
{
	if (v_deck.empty())
		throw std::runtime_error("No hay más cartas en el mazo.");

	Card card = v_deck.back();
	v_deck.pop_back();   // Elimina
	return card;
}

Card Game::GetNewCard() const 
{
	if (v_deck.empty())
		throw std::runtime_error("No hay más cartas en el mazo.");

	return v_deck.back(); // Solo muestra
}

void Game::DiscardCard(const Card card)
{
	v_discarded.push_back(card);
}

void Game::PrintDiscarded() const 
{
	if (v_discarded.empty()) {
		std::cout << "No hay cartas descartadas." << std::endl;
	}
	else {
		std::cout << "Última carta descartada: " << v_discarded.back() << std::endl;
	}
}

void Game::PrintPlayers() const {
	for (const auto& player : v_playerList) {
		std::cout << player << std::endl;
	}
}