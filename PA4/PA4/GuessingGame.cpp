/*
Assignment: PA
Description: Create a 20 questions style guessing game.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 8 hours.
In completing this program, I received help from the following people:
N/A
*/

#include "GuessingGame.h"
#include <iostream>

using namespace std;

GuessingGame::GuessingGame()
{
    _game_tree = new BinaryGuessTree();
    _game_file = "";
}

GuessingGame::GuessingGame(string game_file_name)
{
    _game_file = game_file_name;
    _game_tree = new BinaryGuessTree(_game_file);
}

GuessingGame::~GuessingGame()
{
    delete _game_tree;
}

void GuessingGame::beginGame()
{
    string play_again = "N";

    cout << "Time to play 20 questions.\nPick a Object, Place, or creature and I'll try to guess it.\n\n";

    do
    {
        string user_answer = "";
        bool game_over = false;

        //Variables to track our current and previous nodes.
        BinaryNode<string> *previous = _game_tree->getRoot();
        BinaryNode<string> *current = previous;

        do
        {
            //Cout the differentiation_question of our current node and get the answer.
            cout << current->getValue() << endl << "Enter (Y)es or (N)o: ";
            getline(cin, user_answer);
            cout << endl;

            if (user_answer == "Y" || user_answer == "y" || user_answer == "Yes" || user_answer == "yes")
            {
                //If there are further questions the guess was correct.
                if (current->isLeaf())
                {
                    game_over = true;
                    cout << "Yay! I got it correct! \nWould you like to play again?\n Enter (Y)es or (N)o: ";
                    getline(cin, play_again);
                    cout << endl;
                }
                else
                {
                    //Yes answers to the previous tree questions are stored on the right.
                    previous = current;
                    current = current->getRightChild();
                }
            }
            else
            {
                //If there are no further questions the guess was incorrect.
                if (current->isLeaf())
                {
                    game_over = true;

                    //Variables to track the user inputs and the tree so the tree can be updated so it can guess the correct answer in the future.
                    string correct_answer = "", differentiation_question = "", question_answer = "", current_question;
                    current_question = current->getValue();

                    cout << "Hmm... Seems that you beat me.\n  Enter the correct answer: ";
                    getline(cin, correct_answer);
                    cout << endl;

                    cout << "Enter a yes or no question that would allow me to differentiate between a " << current_question.substr(8, current_question.size() - 9) << " and a " << correct_answer << ":\n";
                    getline(cin, differentiation_question);
                    cout << endl;

                    //If the user question doesn't have a ? at the end add it.
                    if (differentiation_question[differentiation_question.size() - 1] != '?')
                    {
                        differentiation_question += '?';
                    }

                    cout << "Enter the answer to this question. (Y)es or (N)o: \n";
                    getline(cin, question_answer);
                    cout << endl;

                    BinaryNode<string> *new_answer = new BinaryNode<string>{ "Is it a " + correct_answer + "?" };
                    BinaryNode<string> *new_question = new BinaryNode<string>{ differentiation_question };

                    //If it was a new game previous and current will point to the same object.
                    if (previous == current)
                    {
                        _game_tree->setRoot(new_question);
                    }
                    else 
                    {
                        //If the answer guessed was the left child set previous left child to the differentiation question.
                        if (previous->getLeftChild() == current)
                        {
                            previous->setLeftChild(new_question);
                        }
                        else
                        {
                            previous->setRightChild(new_question);
                        }
                    }

                    //If the answer to the users differentiation question was yes we set the correct answer to the guess on the right, and the incorrect answer to the left.
                    //Otherwise the correct answer goes to the left, and the incorrect answer to the right.
                    if (question_answer == "Y" || question_answer == "y" || question_answer == "Yes" || question_answer == "yes")
                    {
                        new_question->setRightChild(new_answer);
                        new_question->setLeftChild(current);
                    }
                    else
                    {
                        new_question->setRightChild(current);
                        new_question->setLeftChild(new_answer);
                    }

                    cout << "Game Over.\nWould you like to play again?\nEnter (Y)es or (N)o: ";
                    getline(cin, play_again);
                    cout << endl;
                }
                else
                {
                    //No answers to the previous tree questions are stored on the left.
                    previous = current;
                    current = current->getLeftChild();
                }
            }

        } while (!game_over);

    } while (play_again == "Y" || play_again == "y" || play_again == "Yes" || play_again == "yes");


    //If no previous save game file was loaded ask whether to save and for a filename.
    //Else save the tree.
    if (_game_file == "")
    {
        string save_or_not = "";
        cout << "Would you like to save the game?\nEnter (Y)es or (N)o: \n";
        getline(cin, save_or_not);

        if (save_or_not == "no" || save_or_not == "No" || save_or_not == "n" || save_or_not == "N")
        {
            return;
        }

        cout << "Enter a save file name: \n";
        getline(cin, _game_file);
        _game_tree->treeToFile(_game_file);
    }
    else
    {
        _game_tree->treeToFile(_game_file);
    }
    
}

void GuessingGame::setGameTree(BinaryGuessTree *new_game_tree)
{
    if (_game_tree != nullptr)
    {
        delete _game_tree;
    }

    _game_tree = new_game_tree;
}

void GuessingGame::setGameTree(string game_file)
{
    if (_game_tree != nullptr)
    {
        delete _game_tree;
    }

    _game_tree = new BinaryGuessTree(game_file);
}