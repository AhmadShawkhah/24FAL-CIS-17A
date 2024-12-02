#include <iostream>
#include "Game.h"

using namespace std;


int main() {
    // Introduction and welcome message
    cout << "Welcome to BlackJack 21!" << endl;
    cout << "--------------------------" << endl;

    // Prompt the player to start or exit the game
    int choice;
    cout << "Enter 1 to start the game or any other key to exit: ";
    cin >> choice;

    // Exit if the player chooses not to start
    if (choice != 1) {
        cout << endl << "Thank you for playing BlackJack 21! Goodbye!" << endl;
        return 0;
    }

    // Prompt the player to input their starting balance
    int startingBalance;
    cout << "Please enter your starting balance: $";
    cin >> startingBalance;

    // Initialize user and dealer players
    UserPlayer user("You", startingBalance);
    DealerPlayer dealer;

    // Create the game object with the user and dealer
    Game game(&user, &dealer);

    // Game loop for multiple rounds
    char playAgain;
    
    do {
        // Play one round of BlackJack
        game.playRound();

        // Ask if they want to play another round
        cout << "Do you want to play another round? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y'); // Continue if the player says 'y'

    // Final balance and game conclusion
    int finalBalance = user.getBalance();
    cout << endl << "Thank you for playing BlackJack 21!" << endl;
    cout << "-----------------------------------" << endl;

    // Evaluate the player's performance
    if (finalBalance > startingBalance) {
        
        cout << "You ended up with $" << finalBalance
             
                << ", earning a profit of $" << (finalBalance - startingBalance) << "." << endl;
    } else if (finalBalance < startingBalance) {
        
        cout << "You ended up with $" << finalBalance
             
                << ", losing $" << (startingBalance - finalBalance) << ". Better luck next time!" << endl;
    } else {
        
        cout << "You broke even with $" << finalBalance << "." << endl;
    }

    // Display the final statistics
    cout << "-----------------------" << endl;
    
    game.displayStatistics();

    return 0;
}
