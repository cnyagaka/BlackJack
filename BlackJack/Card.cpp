#include "Card.h"

Card::Card(int rank, int suit)
    : m_rank(rank), m_suit(suit)
{
}

int Card::getRank()
{
    return m_rank;
}

int Card::getSuit()
{
    return m_suit;
}

int Card::getValue()
{
    if (m_rank >= 10) {
        return 10;
    }
    else if (m_rank == 1) {
        return 11;
    }
    else {
        return m_rank;
    }
}