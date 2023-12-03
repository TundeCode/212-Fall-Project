#include "trie.h"

// constructor 
Trie::Trie() {
        root = new TrieNode();
    }

// destructor
Trie::~Trie(){}


// insert 

void Trie::insert(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber){
      TrieNode* current=root;
std::string Name= firstName+" " +lastName;
      for(char ch : Name){
        if (current->children.find(ch)==current->children.end()){
            current->children[ch]=new TrieNode();
        }
        current=current->children[ch];
      }
      current->count++;
      contacts[Name]=contactInfo(firstName,lastName,phoneNumber);
      
}

  void Trie::addContact() {
        std::string firstName, lastName, phoneNumber;

        std::cout << "Enter first name: ";
        std::cin >> firstName;

        std::cout << "Enter last name: ";
        std::cin >> lastName;

        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;

        insert(firstName, lastName, phoneNumber);
        std::cout << "Contact added successfully.\n";
    }

// display/search

void Trie::displayContacts(const std::string& prefix){
    TrieNode* current = root;
    //count


    //pass the trie to node 
    for(char ch:prefix){
        if(current->children.find(ch) == current->children.end()){
            std::cout<<"Contact Not Found" <<std::endl;
            return;
        }
        current =current->children[ch];
    }
    //SHows all contacts under The prefix example if  A Alex,Alejodro,Alan would appear
    // for(const std::string& contact: current->contacts){
    //     std::cout << contact <<std::endl;
    // }

    displayContactsHelper(current,prefix);
}
