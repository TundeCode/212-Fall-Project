#include "trie.h"

// constructor 
Trie::Trie() {
        root = new TrieNode();
    }

// destructor
Trie::~Trie(){}


// insert 

void Trie::insert(const std::string& word){
      TrieNode* current=root;

      for(char ch : word){
        if (current->children.find(ch)==current->children.end()){
            current->children[ch]=new TrieNode();
        }
        current=current->children[ch];
      }
      current->count++;
}


//search 
std::pair<bool, int> Trie::search(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            return std::make_pair(false, 0);
        }
        current = current->children[ch];
    }
    return std::make_pair(true, current->count);
}

void Trie::displayContacts(const std::string& prefix){
    TrieNode* current = root;

    //pass the trie to node 
    for(char ch:prefix){
        if(current->children.find(ch) == current->children.end()){
            std::cout<<"Contacts Not Found" <<std::endl;
            return;
        }
        current =current->children[ch];
    }
    //SHows all contacts under The prefix example if  A Alex,Alejodro,Alan would appear
    for(const std::string& contact: current->contacts){
        std::cout << contact <<std::endl;
    }
}
