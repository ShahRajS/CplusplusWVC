#include <iostream>
#include <vector>
#include "Card.hpp"
#include "Deck.hpp"

Deck::Deck() {
	for (int i = 0; i < 52; ++i) {
		myDeck.emplace_back(Card(i % 4, i % 13));
	}
	size_t indexOfNextCard = 0;
};

void Deck::shuffleTheDeck() {
	for (int i = 0; i < 20; ++i) {
		int index1 = (rand() % 52);
		int index2 = (rand() % 52);

		Card temp(0, 0);
		temp = myDeck[index1];

		myDeck[index1] = myDeck[index2];
		myDeck[index2] = temp;
	}
	return;
}

Card Deck::dealOneCard() {
	return myDeck[indexOfNextCard++];
}

bool Deck::cardsLeft() {
	return (indexOfNextCard < 52);
}