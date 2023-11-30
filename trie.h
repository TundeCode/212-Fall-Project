#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <ostream>
class TrieNode{
public:
int count;
std::unordered_map<char, TrieNode*> children;
std::vector<std::string> contacts; //stores in node

TrieNode(){
    count=0;
}

  


};

class Trie{
private:
 TrieNode* root;
   void displayContactsHelper(TrieNode* node, const std::string& prefix) {
    // Display count at the current level
    std::cout << prefix << " - Count: " << node->count << std::endl;

    // Show all contacts under the prefix
    for (const std::string& contact : node->contacts) {
        std::cout << contact << std::endl;
    }

    // Recursively display contacts for child nodes
    for (const auto& entry : node->children) {
        char ch = entry.first;
        TrieNode* child = entry.second;
        std::string childPrefix = prefix + ch;
        displayContactsHelper(child, childPrefix);
    }
}
 public:
    Trie();
    ~Trie();
    void insert(const std::string& word);
    void generateDotFile(const std::string& filename);
    void displayContacts(const std::string& prefix);
};


#endif // TRIE_H