#include "Deck.h"
#include "Card.h"
#include <random>
#include <algorithm>

template <typename T>
void Deck<T>::initializeDeck() {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"}; // Array of possible suits
    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"}; // Array of possible ranks

    cards.clear(); // Ensure the deck starts empty
    for (const auto& suit : suits) { // Iterate through all suits
        for (const auto& rank : ranks) { // Iterate through all ranks
            int value = (rank == "Ace") ? 11 : // Assign a value of 11 for Aces
                        (rank == "King" || rank == "Queen" || rank == "Jack") ? 10 :
                        std::stoi(rank); // Convert numeric ranks to integer values
            cards.emplace_back(rank, suit, value);
        }
    }
}

// Shuffles the deck
template <typename T>
void Deck<T>::shuffle() {
    std::random_device rd; 
    std::mt19937 g(rd()); // 
    std::shuffle(cards.begin(), cards.end(), g); // Shuffle the deck using the random engine
}

// Deals a card from the top of the deck
// Removes and returns the last card in the deck (LIFO order).
template <typename T>
T Deck<T>::dealCard() {
    T card = cards.back(); 
    cards.pop_back(); // Remove the card from the deck
    return card; // Return the dealt card
}

// This method provides the current size of the deck, allowing for runtime checks of deck depletion.
template <typename T>
int Deck<T>::getRemainingCards() const {
    return cards.size(); // Return the size of the deck
}

// This tells the compiler to generate the templated methods for Deck<Card>.
template class Deck<Card>;

