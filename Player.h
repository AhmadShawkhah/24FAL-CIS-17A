#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Player {
protected:
    std::string name;
    int balance;
    std::vector<Card> hand;

public:
    Player(std::string name, int balance);
    virtual ~Player() {}

    virtual bool wantsToHit() const = 0;
    void addCardToHand(const Card& card);
    void clearHand();
    int calculateHandValue() const;
    void displayHand() const;
    int getBalance() const;
    void adjustBalance(int amount);
    Card getFirstCard() const;
};

class UserPlayer : public Player {
public:
    UserPlayer(std::string name, int balance);
    bool wantsToHit() const override;
};

class DealerPlayer : public Player {
public:
    DealerPlayer();
    bool wantsToHit() const override;
};

#endif
