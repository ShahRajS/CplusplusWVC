#include <iostream>
#include <vector>
#include "Card.hpp"
#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards() {
	for (int i = 0; i < 52; ++i) {
		deck.emplace_back(new Card(i % 4, i % 13));
	}
	size_t indexOfNextCard = 0;
};

void DeckOfCards::shuffle() {
	for (int i = 0; i < 300; ++i) {
		int index1 = (rand() % 52);
		int index2 = (rand() % 52);

		Card* temp = deck[index1];
		deck[index1] = deck[index2];
		deck[index2] = temp;
	}
	return;
}

Card * DeckOfCards::dealCard() {
	return deck[indexOfNextCard++];
}

bool DeckOfCards::moreCards() const{
	return (indexOfNextCard < 52);
}

Card * DeckOfCards::getCard(size_t index) {
	return deck[index];
}