#include <iostream>
#include "DeckOfCards.hpp"
#include "Card.hpp"

using namespace std;

int main()
{
    std::cout << "Raj Shah\t\tCIST-004A\n\n";
    bool gameNotOver = true;
    int playerIndex;
    int playerWins = 0;
    int cpuWins = 0;
    DeckOfCards deck;

    while (gameNotOver) {
        deck.shuffle();
        cout << "The current win count is: \nYou: " << playerWins << " Computer: " << cpuWins << "\n\n";
        do {
            cout << "Enter a card number from 0 to 51: ";
            cin >> playerIndex;
        } while (playerIndex > 51 or playerIndex < 0);

        Card * playerCard = deck.getCard(playerIndex);
        Card * cpuCard = deck.getCard(rand() % 52);

        cout << "Your selected card is:  " << playerCard->toString();
        cout << ".\nThe Computer's card is: " << cpuCard->toString() << ".\n";
        if (*playerCard > *cpuCard) {
            cout << "You win this round!\n";
            ++playerWins;
        } 
        else if (*playerCard < *cpuCard) {
            cout << "You lose this round!\n";
            ++cpuWins;
        } 
        else if (*cpuCard == *playerCard) {
            cout << "It's a tie!\n";
        }
        if (cpuWins - playerWins >= 2 or playerWins - cpuWins >= 2) {
            gameNotOver = false;
        }
    }
    if (playerWins > cpuWins) {
        cout << "And you win the Game " << playerWins << " to " << cpuWins << "!";
    }
    else {
        cout << "And the Computer wins the Game " << cpuWins << " to " << playerWins << "!";
    }
}