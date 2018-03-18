/*
Assignment: PA
Description: Learn how to build a Trie and use it to run an auto complete search.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 6 hours.
In completing this program, I received help from the following people:
Adam Carter
*/

#include <string>
#include <iostream>
#include <fstream>
#include "Trie.h"
using namespace std;


int main(void)
{    
    Trie *dictionary = new Trie{};
    string file_to_open = "";
    string word_to_lookup = "";

    //First, prompt the user for a file containing all of the words to look up
    cout << "Please enter a dictionary file: ";
    getline(cin, file_to_open);

    //Next, add all words in the file into the Trie using the addWord() function
    fstream input_file{ file_to_open };

    if (input_file.is_open())
    {
        while (input_file.good())
        {
            string word;
            getline(input_file, word);
            dictionary->addWord(word);
        }
    }
    input_file.close();

    //Then, prompt the user for a list of partial words to look up.  Display all matches 
    //on the screen.
    cout << "Please enter a partial word to look up. All matches will be output to the screen.\nEnter partial Word: ";
    getline(cin, word_to_lookup);
    
    for (int i = 0; i < word_to_lookup.size(); i++)
    {
        word_to_lookup[i] = toupper(word_to_lookup[i]);
    }

    vector<string> matches = dictionary->search(word_to_lookup);
    int count = 1;

    if (matches.size() != 0)
    {
        cout << "\nMatches:\n";

        for (auto word : matches)
        {
            cout << count << " " << word << endl;
            count++;
        }
    }
    else
    {
        cout << "No words that start with \"" << word_to_lookup << "\" were found.\n";
    }

    delete dictionary;

    return 0;
}