#pragma once
#include <string>

class Card {
public:
	Card(size_t cardSuit, size_t cardFace);
	size_t getFaceValue();
	size_t getSuitValue();
	std::string cardToString();
private:
	size_t face;
	size_t suit;
	static const std::string namesOfFaces[];
	static const std::string namesOfSuits[];
};