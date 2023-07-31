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
        root=new TrieNode('\0');
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

    bool searchUtil(TrieNode* root,string word)
    {
       // base
        if (word.length() == 0)
        {
            return  root->isterminal ;
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
        return searchUtil(root,word);
    }
};
int main()
{
    trie* t=new trie();
    t->insertWord("SEXYY");
    t->insertWord("GULLU");
    t->insertWord("JAGGU");
    t->insertWord("KK");
    t->insertWord("DOGI");
    cout<<"Present "<<t->searchWord("KK")<<endl;;
    return 0;
}