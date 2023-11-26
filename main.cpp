#include trie.h 



int main(int argc, char*argv[]){
    std::ifstream ifs(argv[1]);
    if (!ifs.is_open()) {
    std::cerr << "Error opening file: " << argv[1] << std::endl;
    return 1;
}


    Trie list;

    std::string line;

    // Get the names to be inserted
    std::getline(ifs, line);
    std::stringstream ss(line);

    std::string word;


    while(ss >> word){
        list.insert(word);
    }


fs.close();
}
