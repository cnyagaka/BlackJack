#include <algorithm>
#include <random>
#include <chrono>
#include "Deck.h"

Deck::Deck()
{
    // create a deck of 52 cards
    m_cards.reserve(52);
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 1; rank <= 13; ++rank) {
            m_cards.emplace_back(rank, suit);
        }
    }
    m_index = 0;
}

void Deck::shuffle()
{
    // shuffle the deck using the current time as the seed for the random number generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(m_cards.begin(), m_cards.end(), std::default_random_engine(seed));
    m_index = 0;
}

Card Deck::dealCard()
{
    // deal the next card from the deck and increment the index
    return m_cards[m_index++];
}
