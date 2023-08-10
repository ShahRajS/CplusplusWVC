#include <iostream>
#include <string>
#include "Card.hpp"

const std::string Card::namesOfFaces[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const std::string Card::namesOfSuits[] = { "Spades", "Diamonds", "Clubs", "Hearts" };

Card::Card(size_t cardSuit, size_t cardFace) {
	Card::face = cardFace;
	Card::suit = cardSuit;
};

size_t Card::getFaceValue() {
	return face;
}

size_t Card::getSuitValue() {
	return suit;
}

std::string Card::cardToString() {
	return namesOfFaces[face] + " of " + namesOfSuits[suit];
}