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
std::string phoneNumber;
TrieNode(){
    count=0;
}

  


};

class Trie{
private:

 TrieNode* root;
 void print(TrieNode* node, const std::string& prefix){
  if (node==nullptr){
    return;
  }

  if(node->count >0){
    std::cout << prefix<<  " - Count: " << node->count << std::endl;
  }

  for (const auto& child : node->children){
    print(child.second,prefix+child.first);
  }
 }
    public:
    Trie();
    ~Trie();
    void insert(const std::string& word);
      std::pair<bool, int> search(const std::string& word);
      void printList();
    void generateDotFile(const std::string& filename);
};


#endif // TRIE_H