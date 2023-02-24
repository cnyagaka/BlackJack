#include "BlackJack.h"

void BlackJack::play()
{
    std::cout << "Let's play BlackJack!" << std::endl;

    m_deck.shuffle();
    dealCards();

    playerTurn();

    if (!m_player.isBusted()) {
        dealerTurn();
    }

    showHands(true);
    declareWinner();
}

void BlackJack::dealCards()
{
    m_player.clearCards();
    m_dealer.clearCards();

    // deal two cards to the player and two cards to the dealer
    m_player.addCard(m_deck.dealCard());
    m_dealer.addCard(m_deck.dealCard());
    m_player.addCard(m_deck.dealCard());
    m_dealer.addCard(m_deck.dealCard());
}

void BlackJack::playerTurn()
{
    while (true) {
        showHands(false);

        std::cout << "Do you want to hit or stand? (h/s) ";
        char choice;
        std::cin >> choice;

        if (choice == 'h') {
            m_player.addCard(m_deck.dealCard()); // give the player another card
            if (m_player.isBusted()) { // check if the player has gone bust
                break;
            }
        }
        else {
            break; // player has chosen to stand
        }
    }
}
void BlackJack::dealerTurn()
{
    // dealer must hit if their score is less than 17
    while (m_dealer.getScore() < 17) {
        m_dealer.addCard(m_deck.dealCard()); // give the dealer another card
    }
}

void BlackJack::showHands(bool showDealerHand)
{
    // print the player's and dealer's hands to the console
    std::cout << "Player: ";
    m_player.showCards();

    if (showDealerHand) {
        std::cout << "Dealer: ";
        m_dealer.showCards();
    }
    else {
        std::cout << "Dealer: " << m_dealer.getScore() << std::endl; // hide the dealer's second card and print their score
    }
}

void BlackJack::declareWinner()
{
    // determine the winner of the game and print the result to the console
    if (m_player.isBusted()) {
        std::cout << "Player busted. Dealer wins." << std::endl;
    }
    else if (m_dealer.isBusted()) {
        std::cout << "Dealer busted. Player wins." << std::endl;
    }
    else if (m_player.getScore() > m_dealer.getScore()) {
        std::cout << "Player wins." << std::endl;
    }
    else if (m_player.getScore() < m_dealer.getScore()) {
        std::cout << "Dealer wins." << std::endl;
    }
    else {
        std::cout << "It's a tie." << std::endl;
    }
}
