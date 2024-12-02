#include "Statistics.h"
#include <iostream>

using namespace std;


// Ensures a fresh start for gamesPlayed, gamesWon, and gamesLost
Statistics::Statistics() : gamesPlayed(0), gamesWon(0), gamesLost(0) {}

// Increment the number of games played

void Statistics::incrementGamesPlayed() {
   
    gamesPlayed++;
}

// Increment the number of games won
// Updates the gamesWon counter when the player wins
void Statistics::incrementGamesWon() {
    gamesWon++;
}

// Increment the number of games lost
// Updates the gamesLost counter when the player loses
void Statistics::incrementGamesLost() {
    gamesLost++;
}

// Display the current statistics of the game

void Statistics::display() const {
    cout << "Game Statistics:" << endl;
    cout << "----------------" << endl;
    cout << "Games Played: " << gamesPlayed << endl;  // Total number of games
    cout << "Games Won: " << gamesWon << endl;      // Total number of wins
    cout << "Games Lost: " << gamesLost << endl;    // Total number of losses
    cout << "----------------" << endl;
}
