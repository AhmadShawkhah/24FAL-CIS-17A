#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>

// A generic deck class using templates for card flexibility
template <typename T>
class Deck {
private:
    std::vector<T> cards;

public:
    void initializeDeck();
    void shuffle();
    T dealCard();
    int getRemainingCards() const;
};

#endif
