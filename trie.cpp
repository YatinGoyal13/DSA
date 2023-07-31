#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *childern[26];
    bool isterminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            childern[i] = NULL;
        }
        isterminal = false;
    }
};

class trie
{
public:
    TrieNode *root;
    trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        // base
        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        int ind = word[0] - 'A';
        TrieNode *child;
        if (root->childern[ind] != NULL)
        {
            // present
            child = root->childern[ind];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->childern[ind] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // base
        if (word.length() == 0)
        {
            return root->isterminal;
        }
        int ind = word[0] - 'A';
        TrieNode *child;
        if (root->childern[ind] != NULL)
        {
            // present
            child = root->childern[ind];
        }
        else
        {
            // absent
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode *root, string word, int index)
    {
        // Base case: If the word is empty, mark the current node as non-terminal
        if (index == word.length())
        {
            if (!root->isterminal)
                return false; // Word doesn't exist in trie, return false
            root->isterminal = false;
            // Check if the current node has any children
            for (int i = 0; i < 26; i++)
            {
                if (root->childern[i] != NULL)
                    return false; // Word is a prefix of another word, return false
            }
            return true; // Word is successfully deleted
        }

        int ind = word[index] - 'A';
        TrieNode *child = root->childern[ind];
        if (child == NULL)
            return false; // Word doesn't exist in trie, return false

        // Recursively delete the remaining part of the word
        bool canDelete = deleteUtil(child, word, index + 1);

        // If canDelete is true, it means that the rest of the word has been deleted
        // and the current node has no other children, so it can be safely deleted
        if (canDelete)
        {
            delete child;
            root->childern[ind] = NULL;
            // Check if the current node is also a terminal node
            for (int i = 0; i < 26; i++)
            {
                if (root->childern[i] != NULL)
                    return false; // Word is a prefix of another word, return false
            }
            return true; // Word is successfully deleted
        }

        return false; // Word doesn't exist in trie, return false
    }

    // Public function to delete a word from the trie
    bool deleteWord(string word)
    {
        return deleteUtil(root, word, 0);
    }
};
int main()
{
    trie *t = new trie();
    t->insertWord("SEXYY");
    t->insertWord("GULLU");
    t->insertWord("JAGGU");
    t->insertWord("KKR");
    t->insertWord("KK");
    t->insertWord("DOGI");
    cout << "Present " << t->searchWord("KK") << endl;
     t->deleteWord("KK");

    cout << "Present " << t->searchWord("KK") << endl;
    cout << "Present " << t->searchWord("KKR") << endl;
    return 0;
}