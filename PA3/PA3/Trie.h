#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <cctype>
using namespace std;

class Trie
{
private:
    TrieNode * _root = nullptr;

protected:

public:
    Trie()
    {
        _root = new TrieNode{};
    }

    virtual ~Trie()
    {
        deconstructorHelper(_root);
        delete _root;
    }

    void deconstructorHelper(TrieNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        vector<TrieNode*> to_delete = root->getChildren();

        for (auto node : to_delete)
        {
            deconstructorHelper(node);
            delete node;
        }
    }

    //TODO: implement
    void addWord(const string &word)
    {
        TrieNode *current = _root;

        for (auto character : word)
        {

            if (current->getChild(character) == nullptr)
            {
                TrieNode *new_node = new TrieNode(character);
                current->setChild(character, new_node);
                current = new_node;
            }
            else
            {
                current = current->getChild(character);
            }
        }
        current->setChild('$', new TrieNode{ '$' });
    }

    //TODO: implement
    vector<string> search(const string &word)
    {
        vector<string> matches, matches_to_add;
        TrieNode *current = _root;

        for (auto character : word)
        {
            current = current->getChild(character);
        }

        vector<TrieNode*> children = current->getChildren();

        if (current != nullptr || current->isWord())
        {
            if (current->isWord())
            {
                matches.push_back(word);
            }

            for (auto child : children)
            {
                matches_to_add = searchHelper(child, word);

                for (auto matched : matches_to_add)
                {
                    matches.push_back(matched);
                }
            }
        }

        if (matches.size() == 0)
        {
            cout << "No words that start with '" << word << "' were found.";
        }

        return matches;
    }

    vector<string> searchHelper(TrieNode* root, const string &word)
    {
        vector<string> matches, matches_to_add;
        string new_word = word;
        new_word += root->getValue();

        if (root->isWord())
        {
            //cout << new_word << endl;
            matches.push_back(new_word);
        }

        vector<TrieNode*> children = root->getChildren();

        for (auto child : children)
        {
            if (child != root->getChild('$'))
            {
                matches_to_add = searchHelper(child, new_word);

                for (auto matched : matches_to_add)
                {
                    matches.push_back(matched);
                }
            }
        }

        return matches;
    }

    void testRecursionWalker(TrieNode *root)
    {

        if (root == nullptr)
        {
            return;
        }
        else if (root->getValue() == '$')
        {
            cout << endl;
            return;
        }

        vector<TrieNode*> children = root->getChildren();
        cout << root->getValue();

        for (auto child : children)
        {
            testRecursionWalker(child);
        }
    }

    TrieNode* getRoot()
    {
        return _root;
    }
};

#endif // !TRIE_H
