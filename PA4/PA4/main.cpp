#include <iostream>
#include <string>
#include "GuessingGame.h"

using namespace std;

int main()
{
    GuessingGame *guessing_game = new GuessingGame("game3.txt");

    guessing_game->beginGame();

    delete guessing_game;

    return 0;
}