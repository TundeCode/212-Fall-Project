#include "trie.h"
#include <climits>
#include <cctype>
int main(int argc, char* argv[]) {
    Trie list;

    if (argc > 1) {
        std::ifstream ifs(argv[1]);
        if (!ifs.is_open()) {
            return 1;
        }

        std::string line;
        while (std::getline(ifs, line)) {
            std::stringstream ss(line);
            std::string firstName, lastName, phoneNumber;

            if (std::getline(ss, firstName, ' ') && std::getline(ss, lastName, '-') && ss >> phoneNumber) {
                list.insert(firstName, lastName, phoneNumber);
            }
        }
        ifs.close();
    }

    bool running = true;
    while (running) {
        char choice;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Search Contacts" << std::endl;;
        std::cout << "3. Exit" << std::endl;;
        std::cout << "Choose One Option above:" << std::endl;;
        while(!(std::cin >> choice)|| !isdigit(choice)){
            std::cout << "Invalid choice, Please try again:"<< std::endl;
            std::cin.clear(); // clear error flag
            std::cin.ignore(INT_MAX, '\n');
        }

        switch (choice) {
            case '1':
                list.addContact();
                break;
            case '2': {
                std::string input;
                std::cout << "Enter Name or Letter: ";
                std::cin >> input;
                list.displayContacts(input);
                break;
            }
            case '3':
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;;
        }
    }

    return 0;
}
