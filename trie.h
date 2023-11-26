#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

class TrieNode{
public:
int count;
std::unordered_map<char, TrieNode*> children;

TrieNode(){
    count=0;
}

  


};

class Trie{
private:

 TrieNode* root;
    public:
    Trie();
    ~Trie();
    void insert(const std::string& word);
      std::pair<bool, int> search(const std::string& word);
    void generateDotFile(const std::string& filename)
}


#endif // TRIE_H