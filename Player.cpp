#include "Player.h"
#include <iostream>

using namespace std;


// Initializes the player's name and balance
Player::Player(std::string name, int balance) : name(name), balance(balance) {}

// Adds a card to the player's hand
void Player::addCardToHand(const Card& card) {
    hand.push_back(card);
}

// Clears all cards in the player's hand
void Player::clearHand() {
    hand.clear();
}

// Calculates the total value of the player's hand
// Adjusts the value of Aces to avoid busting
int Player::calculateHandValue() const {
    int total = 0;    // Total value of the hand
    int aceCount = 0; // Count of Aces in the hand

    // Iterate over all cards in the hand
    for (const auto& card : hand) {
        total += card.getValue(); // Add card value to the total
        if (card.getRank() == "Ace") {
            aceCount++; // Count the Ace
        }
    }

    // Adjust Aces from 11 to 1 if total exceeds 21
    while (total > 21 && aceCount > 0) {
        
        total -= 10; // Reduce total value by 10
        
        aceCount--;  // Decrement Ace count
    }

    return total;
}

// Displays the player's hand and its total value
void Player::displayHand() const {
    for (const auto& card : hand) {
        
        cout << card.toString() << ", "; // Display each card
    }
    cout << "Total Value: " << calculateHandValue() << endl; // Display total value
}

// Returns the player's current balance
int Player::getBalance() const {
    
    return balance;
}

// Adjusts the player's balance
void Player::adjustBalance(int amount) {
    
    balance += amount;
}

// Retrieves the first card in the player's hand
Card Player::getFirstCard() const {
    return hand.front();
}

// Initializes the user player with a name and balance
UserPlayer::UserPlayer(std::string name, int balance) : Player(name, balance) {}

// Determines whether the user wants to hit or stay
bool UserPlayer::wantsToHit() const {
    char choice; // User's input choice
    while (true) {
        cout << "Do you want to hit? (y/n): ";
        
        cin >> choice;
        
        if (choice == 'y' || choice == 'n') {
            
            return choice == 'y'; // Return true if user chooses to hit
        }
        cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
    }
}

// Initializes the dealer with a default name and balance
DealerPlayer::DealerPlayer() : Player("Dealer", 0) {}

// Dealer hits if the hand value is less than 17
bool DealerPlayer::wantsToHit() const {
    return calculateHandValue() < 17; // Return true if dealer should hit
}
