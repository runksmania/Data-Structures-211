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
#ifndef BINARY_GUESS_TREE_H
#define BINARY_GUESS_TREE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "BinaryNode.h"

using namespace std;

class BinaryGuessTree
{
private:
    BinaryNode<string> *_root = nullptr;

    void treeToVector(BinaryNode<string> *node, vector<string> &tree_vector);
    BinaryNode<string>* treeFromFileHelper(BinaryNode<string>* node, vector<string> &tree_vector, int &count);
    void recursPreOrderTraversalHelper(BinaryNode<string> *node);
    void deconstructorHelper(BinaryNode<string> *node);

public:
    BinaryGuessTree();
    BinaryGuessTree(BinaryNode<string> *node);
    BinaryGuessTree(string prev_tree_file_name);

    ~BinaryGuessTree();
    
    void setRoot(BinaryNode<string> *node);
    BinaryNode<string>* getRoot();
    
    void treeToFile(string output_file_name);
    BinaryNode<string>* treeFromFile(string input_file_name);
    void recursPreOrderTraversal();
};

#endif // !BINARY_GUESS_TREE_H