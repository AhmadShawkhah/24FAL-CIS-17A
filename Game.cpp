#include "Game.h"
#include <iostream>
#include <limits>

using namespace std;


// Constructor: Initializes the game by setting up players and shuffling the deck
Game::Game(Player* user, Player* dealer)
    : user(user), dealer(dealer), currentBet(0) {
    // Initialize and shuffle the deck
    deck.initializeDeck();
    deck.shuffle();
}

// Displays game statistics (Games Played, Won, and Lost)
void Game::displayStatistics() const {
    stats.display(); // Delegates the display to the Statistics class
}

// Handles the betting logic before each round
void Game::handleBetting() {
    while (true) {
        // Display the user's current balance
        cout << "Your current balance: $" << user->getBalance() << endl;
        cout << "Place your bet ($20, $50, $100) or enter 'E' to exit: ";
        
        std::string input; // Input from the user
        cin >> input;

        if (input == "E" || input == "e") { // Exit condition
            cout << "Exiting the game. Thank you for playing!" << endl;
            
            exit(0); // Graceful program termination
        }

        try {
            currentBet = std::stoi(input); // Convert input to an integer

            // Validate the bet amount
            if (currentBet != 20 && currentBet != 50 && currentBet != 100) {
                
                cout << "Invalid bet. Please enter $20, $50, or $100." << endl;
                
                continue; // Prompt again
            }

            // Check if the user has enough balance for the bet
            if (currentBet > user->getBalance()) {
                
                cout << "You don't have enough balance. Choose a smaller bet or enter 'E' to exit." << endl;
                
                continue; // Prompt again
            }

            // Deduct the bet from the user's balance
            user->adjustBalance(-currentBet);
            
            cout << "You bet $" << currentBet << ". Remaining balance: $" << user->getBalance() << endl << endl;
            
            break; // Exit the loop if the bet is valid

        } catch (...) { // Catch invalid inputs
            cout << "Invalid input. Please enter $20, $50, $100, or 'E' to exit." << endl;
        }
    
    }
}

// Plays a single round of Blackjack
void Game::playRound() {
    handleBetting(); // Start with betting

    // Deal cards to players
    cout << "\n...Giving cards to players...\n\n";
    user->clearHand();
    
    dealer->clearHand();

    // Each player gets two cards initially
    user->addCardToHand(deck.dealCard());
    user->addCardToHand(deck.dealCard());
    dealer->addCardToHand(deck.dealCard());
    dealer->addCardToHand(deck.dealCard());

    // Display user's hand and dealer's first card
    cout << "Your Hand: ";
    
    user->displayHand();
    
    cout << "Dealer's First Card: " << dealer->getFirstCard().toString() << endl;

    // User's turn
    while (user->wantsToHit()) {
        user->addCardToHand(deck.dealCard());
        cout << "Your Hand: ";
        
        user->displayHand();

        if (user->calculateHandValue() > 21) { // Check for bust
            cout << "You busted!" << endl;
            stats.incrementGamesLost(); // Update statistics
            
            return;
        }
    }

    // Dealer's turn
    cout << "\nDealer's Turn:" << endl;
    while (dealer->wantsToHit()) {
        dealer->addCardToHand(deck.dealCard());
    }
    cout << "Dealer's Hand: ";
    dealer->displayHand();

    // Determine the winner
    displayWinner();
}

// Determines the winner and updates statistics
void Game::displayWinner() {
    int userValue = user->calculateHandValue();
    int dealerValue = dealer->calculateHandValue();

    // User busts
    if (userValue > 21) {
        cout << "You busted. Dealer wins!" << endl;
        stats.incrementGamesLost(); // Increment games lost
    }
    // Dealer busts or user has a higher score
    else if (dealerValue > 21 || userValue > dealerValue) {
        cout << "You win!" << endl;
        user->adjustBalance(2 * currentBet); // Double the bet
        stats.incrementGamesWon(); // Increment games won
    }
    // Dealer has a higher score
    else if (userValue < dealerValue) {
        cout << "Dealer wins!" << endl;
        stats.incrementGamesLost(); // Increment games lost
    }
   
    else {
        cout << "It's a tie!" << endl;
        user->adjustBalance(currentBet); // Return the bet
    }

    // Increment games played
    stats.incrementGamesPlayed();
    cout << "\nYour current balance: $" << user->getBalance() << endl;
}
