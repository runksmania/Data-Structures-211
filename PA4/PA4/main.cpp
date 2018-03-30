/*
Assignment: PA
Description: Create a 20 questions style guessing game.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 6 hours.
In completing this program, I received help from the following people:
N/A
*/

#include <iostream>
#include <string>
#include "GuessingGame.h"

using namespace std;

int main()
{
    GuessingGame *guessing_game;
    string input = "";

    cout << "Would you like to play a new game or load an existing game?\nEnter new or a filename: ";
    getline(cin, input);
    cout << endl;

    if (input == "new" || input == "New")
    {
        guessing_game = new GuessingGame();
    }
    else
    {
        guessing_game = new GuessingGame(input);
    }

    guessing_game->beginGame();

    delete guessing_game;

    return 0;
}