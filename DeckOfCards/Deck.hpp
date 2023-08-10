#pragma once

#include <vector>
#include "Card.hpp"

class Deck {
public:
	Deck();
	void shuffleTheDeck();
	Card dealOneCard();
	bool cardsLeft();
private:
	std::vector <Card> myDeck;
	size_t indexOfNextCard;
};
