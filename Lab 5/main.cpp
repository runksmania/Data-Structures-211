#include <iostream>
#include <string>
#include "sorting\Sorting.h"
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

void mergeHelper(BinarySearchTree<int>* master_tree, BinaryNode<int>* node)
{

    if (master_tree == nullptr || node == nullptr)
    {
        return;
    }

    //add node's value to the tree
    master_tree->addElement(node->getValue());

    //recursively do the same on node's children
    mergeHelper(master_tree, node->getLeftChild());
    mergeHelper(master_tree, node->getRightChild());
}

//Takes in two roots and determines if the root of root2 is in root 1.
//Returns the root2 value equivalent in root 1 if it exists, or nullptr if it doesn't exist.
BinaryNode<int>* subtreeRootFinder(BinaryNode<int>* root1, BinaryNode<int>* root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return nullptr;
    }
    else if (root1 == nullptr || root2 == nullptr)
    {
        return nullptr;
    }

    BinaryNode<int>* root_to_return = nullptr;

    if (root1->getValue() == root2->getValue())
    {
        root_to_return = root1;
        return root_to_return;
    }
    else if (root2->getValue() < root1->getValue())
    {
        root_to_return = subtreeRootFinder(root1->getLeftChild(), root2);
    }
    else
    {
        root_to_return = subtreeRootFinder(root1->getRightChild(), root2);
    }

    return root_to_return;
}

bool rootsAreIdentical(BinaryNode<int> *root1, BinaryNode<int> *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    else if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }

    return (root1->getValue() == root2->getValue() &&
        rootsAreIdentical(root1->getLeftChild(), root2->getLeftChild()) &&
        rootsAreIdentical(root1->getRightChild(), root2->getRightChild())
        );
}

void mergeTrees()
{
    BinarySearchTree<int> tree1{};
    BinarySearchTree<int> tree2{};
    RandomNumberGenerator rng{};

    for (int i = 0; i < 15; i++)
    {
        tree1.addElement(rng.getRandomNumber(1, 100));
        tree2.addElement(rng.getRandomNumber(1, 100));
    }

    BinaryNode<int>* root1 = tree1.getRoot();
    BinaryNode<int>* root2 = tree2.getRoot();
    BinaryNode<int>* merged = nullptr;

    mergeHelper(&tree1, root2);
    merged = tree1.getRoot();

    //if done correctly, should be in-order
    RecursiveInOrderTraversal<int> traversal{};
    traversal.traverse(merged);

}

void subtreeTest(BinaryNode<int>* tree1, BinaryNode<int>* tree2)
{
    BinaryNode<int> *new_root = subtreeRootFinder(tree1, tree2);

    if (new_root == nullptr)
    {
        cout << "False.\n";
        return;
    }

    if (rootsAreIdentical(new_root, tree2))
    {
        cout << "True.\n";
    }
    else
    {
        cout << "False.\n";
    }

}

BinaryNode<int>* commonAncestorHelper(BinaryNode<int>* tree, int val1, int val2)
{
    if (tree == nullptr)
    {
        return nullptr;
    }

    BinaryNode<int> *root_to_return = nullptr;
    int tree_val = tree->getValue();

    if (val1 < val2)
    {
        if (val1 <= tree_val && val2 >= tree_val)
        {
            if (tree->getLeftChild() == nullptr || tree->getRightChild() == nullptr)
            {
                return nullptr;
            }
            else
            {
                root_to_return = tree;
            }
        }
        else if (val1 < tree_val)
        {
            root_to_return = commonAncestorHelper(tree->getLeftChild(), val1, val2);
        }
        else
        {
            root_to_return = commonAncestorHelper(tree->getRightChild(), val1, val2);
        }
    }
    else
    {
        if (val1 >= tree_val && val2 <= tree_val)
        {
            if (tree->getLeftChild() == nullptr || tree->getRightChild() == nullptr)
            {
                return nullptr;
            }
            else
            {
                root_to_return = tree;
            }
        }
        else if (val1 < tree_val)
        {
            root_to_return = commonAncestorHelper(tree->getLeftChild(), val1, val2);
        }
        else
        {
            root_to_return = commonAncestorHelper(tree->getRightChild(), val1, val2);
        }
    }

    return root_to_return;
}

bool containsElement(BinaryNode<int>* root, int value)
{
    BinaryNode<int> *current = root;
    
    while (current != nullptr)
    {
        if (value == current->getValue())
        {
            return true;
        }
        else if (value < current->getValue())
        {
            current = current->getLeftChild();
        }
        else
        {
            current = current->getRightChild();
        }
    }
    
    return false;
}

void commonAncestor(BinaryNode<int>* tree, int val1, int val2)
{
    //Check to see if values exist in tree.
    if (containsElement(tree, val1) == false || containsElement(tree, val2) == false)
    {
        cout << "NONE.\n";
        return;
    }

    BinaryNode<int>* ancestor = commonAncestorHelper(tree, val1, val2);

    if (ancestor == nullptr)
    {
        cout << "NONE.\n";
    }
    else
    {
        cout << ancestor->getValue() << endl;
    }
}

int main(void)
{
    BinarySearchTree<int> tree1{};
    BinarySearchTree<int> tree2{};

    tree1.addElement(10);
    tree1.addElement(5);
    tree1.addElement(7);
    tree1.addElement(2);
    tree1.addElement(9);
    tree1.addElement(15);
    tree1.addElement(11);
    tree1.addElement(12);
    tree1.addElement(20);
    tree1.addElement(25);
    tree1.addElement(27);
    tree1.addElement(30);

    tree2.addElement(20);
    tree2.addElement(25);
    tree2.addElement(27);
    tree2.addElement(30);

    mergeTrees();
    cout << endl;

    //should be TRUE
    subtreeTest(tree1.getRoot(), tree2.getRoot());

    tree2 = BinarySearchTree<int>{};
    tree2.addElement(5);
    tree2.addElement(9);
    tree2.addElement(27);
    tree2.addElement(25);

    //should be FALSE
    subtreeTest(tree1.getRoot(), tree2.getRoot());

    //should be 5
    commonAncestor(tree1.getRoot(), 5, 7);

    //should be 15
    commonAncestor(tree1.getRoot(), 30, 12);

    //should be "NONE"
    commonAncestor(tree1.getRoot(), 30, 100);
    
    //should be 10.
    commonAncestor(tree1.getRoot(), 9, 11);

    //should be 10.
    commonAncestor(tree1.getRoot(), 11, 9);

    //should be "NONE"
    commonAncestor(tree1.getRoot(), 1, 500);


    return 0;
}
