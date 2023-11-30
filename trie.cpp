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



// print list
void Trie::printList(){
    print(root, "");
}
// dot file

void Trie::generateDotFile(const std::string& filename){
    std::ofstream ofs(filename);
    ofs << "digraph: {"  << std::endl;



    ofs << "}" << std::endl;

    ofs.close();
}