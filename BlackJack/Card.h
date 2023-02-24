#ifndef CARD_H
#define CARD_H

class Card {
private:
    int m_rank; // the rank of the card (1-13)
    int m_suit; // the suit of the card (0-3)

public:
    Card(int rank, int suit);
    int getRank();
    int getSuit();
    int getValue(); // get the value of the card (1-10 or 10)
};

#endif // CARD_H
