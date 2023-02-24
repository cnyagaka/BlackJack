#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <vector>
#include "Deck.h"
#include "Player.h"

class BlackJack {
private:
    Deck m_deck; // the deck of cards used in the game
    Player m_player; // the player
    Player m_dealer; // the dealer

public:
    void play(); // play a game of blackjack
    void dealCards(); // deal the initial cards to the player and dealer
    void playerTurn(); // allow the player to take their turn
    void dealerTurn(); // allow the dealer to take their turn
    void showHands(bool showDealerHand); // print the hands of the player and dealer to the console
    void declareWinner(); // determine the winner of the game
};

#endif // BLACKJACK_H
