#pragma once

#include <vector>
#include "Card.hpp"

class DeckOfCards {
public:
	DeckOfCards();
	void shuffle();
	Card * dealCard();
	Card * getCard(size_t);
	bool moreCards() const;
private:
	std::vector <Card *> deck;
	size_t indexOfNextCard;
};