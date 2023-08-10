#pragma once
#include <string>

class Card {
public:
	Card(size_t cardSuit, size_t cardFace) {};
	size_t getFaceValue();
	size_t getSuitValue();
	std::string toString();
	bool operator> (const Card&);
	bool operator< (const Card&);
	bool operator== (const Card&);

private:
	int refCount;
	size_t face;
	size_t suit;
	static const std::string faceNames[];
	static const std::string suitNames[];
};