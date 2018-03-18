#include "GuessingGame.h"
#include <iostream>

using namespace std;

GuessingGame::GuessingGame()
{
    _game_tree = nullptr;
}

GuessingGame::GuessingGame(string game_file_name, bool new_file)
{
    if (new_file)
    {
        _game_tree = new BinaryGuessTree("game1.txt");
    }
    else
    {
        _game_tree = new BinaryGuessTree(game_file_name);
    }
}

GuessingGame::~GuessingGame()
{
    delete _game_tree;
}

void GuessingGame::beginGame()
{
    string user_retry = "N", save_file = "";

    do
    {
        string user_input = "";
        bool game_over = false;
        BinaryNode<string> *previous = _game_tree->getRoot();
        BinaryNode<string> *current = previous;

        do
        {
            cout << current->getValue() << endl << "Enter (Y)es or (N)o: ";
            getline(cin, user_input);
            cout << endl;

            if (user_input == "Y" || user_input == "y" || user_input == "Yes" || user_input == "yes")
            {
                if (current->isLeaf())
                {
                    game_over = true;
                    cout << "Yay! I got it correct! \nWould you like to play again?\n Enter (Y)es or (N)o: ";
                    getline(cin, user_retry);
                    cout << endl;
                }
                else
                {
                    previous = current;
                    current = current->getRightChild();
                }
            }
            else
            {
                if (current->isLeaf())
                {
                    game_over = true;
                    string correct_answer = "", question = "", question_answer = "", current_question;
                    current_question = current->getValue();

                    cout << "Hmm... Seems that you beat me.\n  Enter the correct answer: ";
                    getline(cin, correct_answer);
                    cout << endl;

                    cout << "Enter a yes or no question that would allow me to differentiate between a " << current_question.substr(8, current_question.size() - 9) << " and a " << correct_answer << ":\n";
                    getline(cin, question);
                    cout << endl;

                    if (question[question.size() - 1] != '?')
                    {
                        question += '?';
                    }

                    cout << "Enter the answer to this question. (Y)es or (N)o: \n";
                    getline(cin, question_answer);
                    cout << endl;

                    BinaryNode<string> *new_answer = new BinaryNode<string>{"Is it a " + correct_answer + "?"};
                    BinaryNode<string> *new_question = new BinaryNode<string>{ question };
                    
                    if (previous->getLeftChild() == current)
                    {
                        previous->setLeftChild(new_question);
                    }
                    else
                    {
                        previous->setRightChild(new_question);
                    }
                    

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

                    cout << "Game Over.\nWould you like to play again?\n Enter (Y)es or (N)o: ";
                    getline(cin, user_retry);
                    cout << endl;
                }
                else
                {
                    previous = current;
                    current = current->getLeftChild();
                }
            }

        } while (!game_over);

    } while (user_retry == "Y" || user_retry == "y" || user_retry == "Yes" || user_retry == "yes");

    cout << "Enter a save filename: ";
    getline(cin, save_file);
    cout << endl;

    _game_tree->treeToFile(save_file);
}

void GuessingGame::setGameTree(BinaryGuessTree *new_game_tree)
{
    if (_game_tree != nullptr)
    {
        delete _game_tree;
    }

    _game_tree = new_game_tree;
}