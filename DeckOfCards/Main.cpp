#include <iostream>
#include "Deck.hpp"
#include "Card.hpp"

int main()
{
    std::cout << "Raj Shah\t\tCIST-004A\n\n";
    Deck deck = Deck();
    deck.shuffleTheDeck();

    while(deck.cardsLeft()) {
        Card nextcard = deck.dealOneCard();
        std::cout << nextcard.cardToString() << "\n";
    }
}