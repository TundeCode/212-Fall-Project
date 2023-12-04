#include "trie.h"

// constructor 
Trie::Trie() {
        root = new TrieNode();
       
    }

// destructor
Trie::~Trie(){}
//release dynamically allocated memory
void Trie::deleteNode(TrieNode* node){
    for (auto& entry:node ->children){
        deleteNode(entry.second);
        entry.second=nullptr;
    }
    delete node;
}


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
      current->contact=contactInfo(firstName,lastName,phoneNumber);
      
      
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

    if (!firstName.empty() && !lastName.empty()&& !phoneNumber.empty()){
        std::cout << "Contact added successfully.\n";}
        else{
            std::cout << "Invalid input. Please provide all necessary information. \n";}
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
   
    displayContactsHelper(current,prefix);
}


    void Trie::generateDotFile(const std::string& filename){


std::ofstream ofs(filename);

if (!ofs){
    std::cerr << "Error opening File: "<< filename<< std::endl;
    return;
}
ofs << "digraph G {" << std::endl;
 nodeCount=0;
generateDotFileHelper(root,ofs);
ofs << "}" << std:: endl;
ofs.close();
    }