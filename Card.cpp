#include "Card.h"

// Constructor
Card::Card(std::string rank, std::string suit, int value)
    : rank(rank), suit(suit), value(value) {}

// Getters
std::string Card::getRank() const { return rank; }
std::string Card::getSuit() const { return suit; }
int Card::getValue() const { return value; }

// Returns a string representation of the card
std::string Card::toString() const {
    return rank + " of " + suit;
}

// Overloaded equality operator
bool Card::operator==(const Card& other) const {
    return rank == other.rank && suit == other.suit;
}

// Overloaded less-than operator (by value)
bool Card::operator<(const Card& other) const {
    return value < other.value;
}

// Overloaded greater-than operator (by value)
bool Card::operator>(const Card& other) const {
    return value > other.value;
}
