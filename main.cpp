#include "trie.h"



int main(int argc, char*argv[]){
    std::ifstream ifs(argv[1]);
    if (!ifs.is_open()) {
    std::cerr << "Error opening file: " << argv[1] << std::endl;
    return 1;
}


    Trie list;

    std::string line;


    // Get the names to be inserted
while(std::getline(ifs, line)){
    std::stringstream ss(line);

    std::string firstName, lastName, phoneNumber;


    while(ss>>firstName>>lastName>>phoneNumber){
        

        list.insert(firstName,lastName,phoneNumber);
    }
}
std::string input;
std::cout << "Enter Name: ";
std::cin >> input;

list.displayContacts(input);
ifs.close();
}
