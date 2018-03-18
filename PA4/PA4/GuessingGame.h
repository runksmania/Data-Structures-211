#pragma once
#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H

#include <string>
#include "BinaryGuessTree.h"

using namespace std;

class GuessingGame
{
private:
    BinaryGuessTree *_game_tree;

public:
    GuessingGame();
    GuessingGame(string game_file_name, bool new_file);
    ~GuessingGame();
    void beginGame();
    void setGameTree(BinaryGuessTree *new_game_tree);
};

#endif // !GUESSING_GAME_H
