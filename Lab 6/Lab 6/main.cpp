#include <iostream>
#include <string>
#include <math.h>
#include "sorting\Sorting.h"
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

int getHeight(BinaryNode<int>* node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else if(node->isLeaf() == true)
    {
        return 0;
    }

    int left_height = getHeight(node->getLeftChild());
    int right_height = getHeight(node->getRightChild());

    if (left_height > right_height)
    {
        return 1 + left_height;
    }
    else
    {
        return 1 + right_height;
    }
}

bool isAvlHelper(BinaryNode<int>* node)
{
    if (node == nullptr)
    {
        return true;
    }
    else
    {
        int left_height = getHeight(node->getLeftChild());
        int right_height = getHeight(node->getRightChild());

        if (abs(left_height - right_height) > 1)
        {
            return false;
        }
        else
        {
            return (isAvlHelper(node->getLeftChild()) && isAvlHelper(node->getRightChild()));
        }
    }
}

bool isAvl(BinarySearchTree<int> *tree)
{
    if (tree == nullptr)
    {
        return true;
    }
    else
    {
        return isAvlHelper(tree->getRoot());
    }
}

BinaryNode<int>* rotateLeft(BinaryNode<int>* original_root)
{
    if (original_root == nullptr)
    {
        return original_root;
    }

    BinaryNode<int>* new_root = original_root->getRightChild();
    original_root->setRightChild(new_root->getLeftChild());
    new_root->setLeftChild(original_root);

    return new_root;
}

bool isFullHelper(BinaryNode<int> *node)
{
    if (node == nullptr)
    {
        return true;
    }
    else if (node->isLeaf())
    {
        return true;
    }

    BinaryNode<int> *left = node->getLeftChild();
    BinaryNode<int> *right = node->getRightChild();

    //If node is not a leaf node and has one nullptr child the tree is not full.
    if (right == nullptr || left == nullptr)
    {
        return false;
    }
    else
    {
        return (isFullHelper(left) && isFullHelper(right));
    }
}

bool isFull(BinarySearchTree<int> *tree)
{
    if (tree == nullptr)
    {
        return true;
    }
    else
    {
        return isFullHelper(tree->getRoot());
    }
}

bool isComplete(BinarySearchTree<int>* tree)
{
    //allows us to perform level-order traversal
    queue<BinaryNode<int>*> to_visit{};

    //kees track of whether or not we've seen a null node yet
    bool has_seen_null = false;

    //prime loop
    to_visit.push(tree->getRoot());

    //begin BFS
    while (to_visit.empty() == false)
    {
        //grab front node from queue
        BinaryNode<int>* front = to_visit.front();
        to_visit.pop();

        if (front == nullptr)
        {
            has_seen_null = true;
        }
        else
        {
            if (has_seen_null == true)
            {
                return false;
            }

            //otherwise, push on children
            to_visit.push(front->getLeftChild());
            to_visit.push(front->getRightChild());
        }
    }

    return has_seen_null;
}

int main(void)
{
    BinarySearchTree<int> tree{};
     
    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: -1)" << endl << endl;

    tree.addElement(10);
    tree.addElement(5);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 1)" << endl << endl;

    tree.addElement(15);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 1)" << endl << endl;

    tree.addElement(12);
    tree.addElement(20);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 2)" << endl << endl;

    tree.addElement(11);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 3)" << endl << endl;

    tree.addElement(13);
    tree.addElement(1);
    tree.addElement(7);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 3)" << endl << endl;


    //Note: this breaks the tree structure because our BST isn't informed of the new root.  Must be done last
    BinaryNode<int>* rotated = rotateLeft(tree.getRoot());
    RecursivePreOrderTraversal<int> traversal{};
    traversal.traverse(rotated);
    cout << endl;
    
    //rotate again just for fun
    rotated = rotateLeft(rotated);
    traversal.traverse(rotated);
    return 0;
}
