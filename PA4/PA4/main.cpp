#include <iostream>
#include <string>
#include "GuessingGame.h"

using namespace std;

int main()
{
    GuessingGame *guessing_game = new GuessingGame("game3.txt", false);

    guessing_game->beginGame();

    return 0;
}