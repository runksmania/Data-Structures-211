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
    string _game_file;

public:
    GuessingGame();
    GuessingGame(string game_file_name);
    ~GuessingGame();
    void beginGame();
    void setGameTree(BinaryGuessTree *new_game_tree);
};

#endif // !GUESSING_GAME_H
