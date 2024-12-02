#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>

// Class to keep track of game statistics
class Statistics {
private:
    int gamesPlayed;  // Total games played
    int gamesWon;     // Total games won
    int gamesLost;    // Total games lost

public:
    Statistics();  // Constructor to initialize statistics

    void incrementGamesPlayed();  // Increment games played
    void incrementGamesWon();     // Increment games won
    void incrementGamesLost();    // Increment games lost

    void display() const;  // Display statistics
};

#endif
