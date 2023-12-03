#ifndef TRIE_H 
#define TRIE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <ostream>


class contactInfo{
public:
std::string firstName;
std::string lastName;
std::string phoneNumber;

contactInfo(){
    firstName="";
    lastName="";
    phoneNumber="";
}
 contactInfo(const std::string& first, const std::string& last, const std::string& phone){
    firstName=first;
    lastName=last;
    phoneNumber=phone;
}
};


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
 std::unordered_map<std::string, contactInfo> contacts; //stores in node
      void deleteContactHelper(TrieNode* node, const std::string& contactName); 
      void displayContactsHelper(TrieNode* node, const std::string& prefix) {

   
//SHows all contacts under The prefix example if  A Alex,Alejodro,Alan would appear
    //show contaacts only if prefix matches
    if (!prefix.empty()&& contacts.find(prefix) !=contacts.end()) {
        const contactInfo& contactInfo=contacts[prefix];    
        std::cout << contactInfo.firstName << " " <<  contactInfo.lastName<< std::endl;
        std::cout << contactInfo.phoneNumber << std::endl;
        std::cout<< std::endl;
    }



     

    // Recursively display contacts for child nodes
    for (const auto& entry : node->children) {
        char ch = entry.first;
        TrieNode* child = entry.second;
        std::string childPrefix = prefix + ch;

        displayContactsHelper(child, childPrefix);
    }
    // Private helper function to delete a contact from the Trie

}
 public:
    Trie();
    ~Trie();
    
    void insert(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber);
    void generateDotFile(const std::string& filename);
    void displayContacts(const std::string& prefix);

    void deleteContact(const std::string& command);
    void addContact();

};


#endif // TRIE_t
