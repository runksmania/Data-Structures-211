/*
Assignment: PA
Description: Create a 20 questions style guessing game.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 6 hours.
In completing this program, I received help from the following people:
N/A
*/

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
    void setGameTree(string game_file);
};

#endif // !GUESSING_GAME_H
