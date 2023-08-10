#include <iostream>
#include <string>
#include "Card.hpp"

const std::string Card::faceNames[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
const std::string Card::suitNames[] = { "Clubs", "Diamonds", "Hearts", "Spades"};

Card::Card(size_t cardSuit, size_t cardFace) {
	Card::refCount = 1;
	Card::face = cardFace;
	Card::suit = cardSuit;
};

size_t Card::getFaceValue() {
	return face;
}

size_t Card::getSuitValue() {
	return suit;
}

std::string Card::toString() {
	return "The " + faceNames[face] + " of " + suitNames[suit];
}

bool Card::operator< (const Card& oppCard) {
	if (face == oppCard.face) {
		return suit < oppCard.suit;
	}
	return face < oppCard.face;
}

bool Card::operator>(const Card& oppCard) {
	if (face == oppCard.face) {
		return suit > oppCard.suit;
	}
	return face > oppCard.face;

}

bool Card::operator==(const Card& oppCard) {
	return (suit == oppCard.suit and face == oppCard.face);
}