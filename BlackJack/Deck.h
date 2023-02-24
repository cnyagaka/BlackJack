#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> m_cards; // a vector of cards representing the deck
    int m_index; // the index of the next card to be dealt

public:
    Deck();
    void shuffle(); // shuffle the deck
    Card dealCard(); // deal a card from the deck
};

#endif // DECK_H
