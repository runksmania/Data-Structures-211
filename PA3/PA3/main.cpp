#include <string>
#include <iostream>
#include <fstream>
#include "Trie.h"
using namespace std;

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

//PA #3 Checkin TODO: Implement!
void search(TrieNode *node, vector<string> &words, string current_word, string prefix)
{
    vector<string> matches, matches_to_add;
    TrieNode *current = node;

    for (auto character : prefix)
    {
        current = current->getChild(character);
    }

    vector<TrieNode*> children = current->getChildren();

    if (current != nullptr || current->isWord())
    {
        if (current->isWord())
        {
            matches.push_back(prefix); 
        }

        for (auto child : children)
        {
            matches_to_add = searchHelper(child, prefix);

            for (auto matched : matches_to_add)
            {
                matches.push_back(matched);
            }
        }
    }

    if (matches.size() == 0)
    {
        cout << "No words that start with '" << prefix << "' were found.";
    }

    words = matches;
}

//NOTE: You do not have to modify this function.  Its purpose is to call your checkin code
void pa3CheckinDriver()
{
    TrieNode *root = new TrieNode{};

    //build practice word ('apple')
    root->setChild('a', new TrieNode{ 'a' });
    root->getChild('a')->setChild('p', new TrieNode{ 'p' });
    root->getChild('a')->getChild('p')->setChild('p', new TrieNode{ 'p' });
    root->getChild('a')->getChild('p')->getChild('p')->setChild('l', new TrieNode{ 'l' });
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->setChild('e', new TrieNode{ 'e' });

    //complete word
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->getChild('e')->setChild('$', new TrieNode{ '$' });

    //add branch word ('apples')
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->getChild('e')->setChild('s', new TrieNode{ 's' });

    //complete branch word
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->getChild('e')->getChild('s')->setChild('$', new TrieNode{ '$' });

    //add 2nd practice word ('age')
    root->getChild('a')->setChild('g', new TrieNode{ 'g' });
    root->getChild('a')->getChild('g')->setChild('e', new TrieNode{ 'e' });
    root->getChild('a')->getChild('g')->getChild('e')->setChild('$', new TrieNode{ '$' });

    //search tree
    //EXPECTED: APPLE, APPLES
    vector<string> words{};
    search(root, words, "", "AP");
    for (string word : words)
    {
        cout << word << endl;
    }
}

int main(void)
{
    //Trie dictionary{};

    string line = "complex.txt";

    //PA #3 Checkin hook.  Remove before turning in your final PA3
    cout << "Running checkin driver:\n\n";
    pa3CheckinDriver();
    cout << "\nCheckin driver complete.\n\n";

    //First, prompt the user for a file containing all of the words to look up

    //Next, add all words in the file into the Trie using the addWord() function

    //Then, prompt the user for a list of partial words to look up.  Display all matches 
    //on the screen.

    cout << "Running test search on trie:\n\n";
    Trie *testTrie = new Trie();

    fstream input_file{ line };

    if (input_file.is_open())
    {
        while (input_file.good())
        {
            string word;
            getline(input_file, word);
            testTrie->addWord(word);
        }
    }
    input_file.close();

    vector<string> test = testTrie->search("A");
    int count = 1;

    for (auto word : test)
    {
        cout << count << " " << word << endl;
        count++;
    }

    cout << "\nTest complete.\n";

    delete testTrie;

    return 0;
}