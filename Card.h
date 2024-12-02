#ifndef CARD_H
#define CARD_H

#include <string>

// Represents a single playing card
class Card {
private:
    std::string rank;
    std::string suit;
    int value;

public:
    Card(std::string rank, std::string suit, int value);

    // Getters
    std::string getRank() const;
    std::string getSuit() const;
    int getValue() const;

    // String representation
    std::string toString() const;

    // Operator overloading for comparison
    bool operator==(const Card& other) const;
    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
};

#endif
