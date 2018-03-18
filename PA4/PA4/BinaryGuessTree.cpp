#include <fstream>
#include <iostream>
#include "BinaryGuessTree.h"

using namespace std;


BinaryGuessTree::BinaryGuessTree()
{
    _root = nullptr;
}

BinaryGuessTree::BinaryGuessTree(BinaryNode<string> *node)
{
    _root = node;
}

BinaryGuessTree::BinaryGuessTree(string prev_tree_file_name)
{
    _root = treeFromFile(prev_tree_file_name);
}

BinaryGuessTree::~BinaryGuessTree()
{
}

void BinaryGuessTree::setRoot(BinaryNode<string> *node)
{
    _root = node;
}

BinaryNode<string>* BinaryGuessTree::getRoot()
{
    return _root;
}

void BinaryGuessTree::treeToVector(BinaryNode<string> *node, vector<string> &tree_vector)
{
    if (node == nullptr)
    {
        return;
    }
    else if (node->isLeaf())
    {
        string leaf_string = "*" + node->getValue().substr(8);
        tree_vector.push_back(leaf_string);
    }
    else
    {
        tree_vector.push_back(node->getValue());
        treeToVector(node->getLeftChild(), tree_vector);
        treeToVector(node->getRightChild(), tree_vector);
    }
}

void BinaryGuessTree::treeToFile(string output_file_name)
{
    cout << "Writing tree to file...\n";

    ofstream output_file{ output_file_name };

    if (output_file.is_open())
    {
        vector<string> tree_vector;
        treeToVector(_root, tree_vector);

        for (auto piece : tree_vector)
        {
            output_file << piece << endl;
        }

        output_file.close();

        if (!output_file.is_open())
        {
            cout << "File written correctly\n";
        }
        else
        {
            cout << "Error writing tree to file.  Please check file name and location.\n";
        }
        
    }
    else
    {
        cout << "Error writing tree to file.  Please check file name and location.\n";
    }
}

BinaryNode<string>* BinaryGuessTree::treeFromFile(string input_file_name)
{
    ifstream input_file{ input_file_name };
    BinaryNode<string> *start_node = nullptr;

    if (input_file.is_open())
    {
        vector<string> tree_vector;
        string current_line;
        while (input_file.good())
        {
            getline(input_file, current_line);
            tree_vector.push_back(current_line);
        }

        int count = 0;

        start_node = treeFromFileHelper(start_node, tree_vector, count);
    }
    else
    {
        cout << "Could not read tree from file.  Please check file name and location.\n";
    }

    return start_node;
}

BinaryNode<string>* BinaryGuessTree::treeFromFileHelper(BinaryNode<string>* node, vector<string> &tree_vector, int &count)
{
    BinaryNode<string> *current = node;

    if (count == tree_vector.size())
    {
        return current;
    }
    else if (current == nullptr)
    {
        if (tree_vector[count][0] == '*')
        {
            current = new BinaryNode<string>{ "Is it a " + tree_vector[count].substr(1) };
            count++;
            return current;
        }
        else
        {
            current = new BinaryNode<string>{ tree_vector[count] };
        }
        count++;
    }
    
    current->setLeftChild(treeFromFileHelper(current->getLeftChild(), tree_vector, count));
    current->setRightChild(treeFromFileHelper(current->getRightChild(), tree_vector, count));
    
    return current;
}

void BinaryGuessTree::recursPreOrderTraversal()
{
    recursPreOrderTraversalHelper(_root);
}

void BinaryGuessTree::recursPreOrderTraversalHelper(BinaryNode<string> *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->getValue() << endl;
    recursPreOrderTraversalHelper(node->getLeftChild());
    recursPreOrderTraversalHelper(node->getRightChild());
}