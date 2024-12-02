#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Statistics.h"

// Represents the main game logic for Blackjack
class Game {
private:
    Player* user;
    Player* dealer;
    Deck<Card> deck;
    int currentBet;
    Statistics stats;
    

    void handleBetting();
    void displayWinner();

public:
    Game(Player* user, Player* dealer);
    void playRound();
    void displayStatistics() const; // Declaration

};

#endif
