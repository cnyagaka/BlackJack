#include <iostream>
#include "Player.h"

Player::Player()
{
}

void Player::addCard(Card card)
{
    m_cards.push_back(card);
}

void Player::clearCards()
{
    m_cards.clear();
}

int Player::getScore()
{
    int score = 0;
    int aces = 0;
    for (const auto& card : m_cards) {
        score += card.getValue(); // add the value of the card to the score
        if (card.getRank() == 1) {
            ++aces; // count the number of aces
        }
    }
    // if the score is over 21 and there are aces, treat the aces as 1 instead of 11
    while (score > 21 && aces > 0) {
        score -= 10;
        --aces;
    }
    return score;
}

bool Player::hasBlackJack()
{
    return (m_cards.size() == 2 && getScore() == 21); // check if the player has 2 cards and a score of 21
}

bool Player::isBusted()
{
    return (getScore() > 21); // check if the player's score is over 21
}

void Player::showCards()
{
    for (const auto& card : m_cards) {
        std::cout << " " << card.getRank() << " " << card.getSuit(); // print the rank and suit of each card to the console
    }
    std::cout << std::endl;
}
