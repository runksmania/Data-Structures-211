/*
Assignment: PA
Description: Create a 20 questions style guessing game.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 8 hours.
In completing this program, I received help from the following people:
N/A
*/

#include "BinaryGuessTree.h"

using namespace std;


BinaryGuessTree::BinaryGuessTree()
{
    _root = new BinaryNode<string>{ "Is it a creature?" };
    _root->setLeftChild(new BinaryNode<string>{ "Is it a place?" });
    _root->setRightChild(new BinaryNode<string>{ "Is it a cat?" });
    _root->getLeftChild()->setRightChild(new BinaryNode<string>{ "Is it a Paris?" });
    _root->getLeftChild()->setLeftChild(new BinaryNode<string>{ "Is it a pizza?" });
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
    deconstructorHelper(_root);
}

void BinaryGuessTree::deconstructorHelper(BinaryNode<string> *node)
{
    //Base Case
    if (node == nullptr)
    {
        return;
    }
    else if(!node->isLeaf())
    {
        //Recursively call children.
        deconstructorHelper(node->getLeftChild());
        deconstructorHelper(node->getRightChild());
    }

    //Delete if leaf node or after its children have been deleted.
    delete node;
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
        //Remove the question portion to only store the answer and add an asterisk to show it is a leaf node.
        //The question portion would be (Is it a ).  I.E.  Is it a dog?
        string leaf_string = "*" + node->getValue().substr(8);
        tree_vector.push_back(leaf_string);
    }
    else
    {
        //If node is not a leaf no change needs to be made, push back its value and recursively call children.
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
        //Vector and call to method to store tree values.
        vector<string> tree_vector;
        treeToVector(_root, tree_vector);

        //Output to the file each tree value.
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
            //If output_file could not be closed there may be data corruption.
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

    //Pointer to be start tree and be returned as _root.
    BinaryNode<string> *start_node = nullptr;

    if (input_file.is_open())
    {
        //Variables to get values from file and hold them in a vector to make tree.
        vector<string> tree_vector;
        string current_line;

        while (input_file.good())
        {
            getline(input_file, current_line);
            tree_vector.push_back(current_line);
        }

        input_file.close();

        //Variable to track where we are in the vector so that the tree can be performed recursively.
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


    //Base Case.  If count == tree_vector.size() we have completed our tree.
    if (count == tree_vector.size())
    {
        return current;
    }
    
    //Second Base Case.  If we have reached an empty node and count != tree_vector.size() we need to create a new node in our tree.
    if (current == nullptr)
    {
        if (tree_vector[count][0] == '*')
        {
            //Leaf nodes need to have a string added due to how they are designated and stored.
            current = new BinaryNode<string>{ "Is it a " + tree_vector[count].substr(1) };
            count++;

            //If leaf node we don't need to progress further, so return back to recursive call.
            return current;
        }
        else
        {
            current = new BinaryNode<string>{ tree_vector[count] };
        }
        count++;
    }
    
    //Set children the return value of recursive call.
    current->setLeftChild(treeFromFileHelper(current->getLeftChild(), tree_vector, count));
    current->setRightChild(treeFromFileHelper(current->getRightChild(), tree_vector, count));
    
    //Return current so the calling method can set _root or children of _root.
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