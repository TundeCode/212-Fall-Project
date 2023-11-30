#include "trie.h"

// constructor 
Trie::Trie() {
        root = new TrieNode();
    }

// destructor
Trie::~Trie(){}


// insert 

void Trie::insert(const std::string& string){
      TrieNode* current=root;

      for(char ch : string){
        if (current->children.find(ch)==current->children.end()){
            current->children[ch]=new TrieNode();
        }
        current=current->children[ch];
      }
      current->count++;
      current->contacts.push_back(string);
      
}


// display/search

void Trie::displayContacts(const std::string& prefix){
    TrieNode* current = root;
    //count

    std::cout << prefix<<  " - Count: " << root->count << std::endl;

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

    displayContactsHelper(current,prefix);
}
