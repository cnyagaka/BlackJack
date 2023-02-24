#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
private:
    std::vector<Card> m_cards; // a vector of cards in the player's hand

public:
    Player();
    void addCard(Card card); // add a card to the player's hand
    void clearCards(); // remove all cards from the player's hand
    int getScore(); // calculate the player's current score
    bool hasBlackJack(); // check if the player has a blackjack
    bool isBusted(); // check if the player has gone bust
    void showCards(); // print the player's cards to the console
};

#endif // PLAYER_H
