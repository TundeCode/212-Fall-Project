# Trie
URI CSC 212 Fall 2023 Term Project

### Group Members:
Ethan Moreta, Tunde Fakolujo, Marvens Sainterlien, Clinton Ijifisoye


### Overview:

A trie is a multiway tree data structure used for storing strings over an alphabet. It is used to store alrge amount of strings. The pattern matching can be done efficiently using tries. The trie shows words like allot, alone, ant, and, are, bat, bad. The idea all strings shring common prefix should come from a common node. The tries are used in spell checking programs.

### Contact List

  * Download `Trie.cpp`, `test.txt`, and `main.cpp` from this repository
  * Open your terminal and compile with G++ using `g++ Trie.cpp main.cpp -o trie`

## Usage: 
  `./trie test.txt` Outputs directly on the terminal.
  * This would be the contact list, this is filled with the names of the contacts you have

### Test File
  * Download `test.txt` from this repository
  * Open your terminal and run with G++ using `./trie test.txt`

After this a prompt opens up and you can choose whether you want to add/delete a contact or search up a contact 
from the test file. To search for the contact all you have to enter is the start of their name and the contact pops up, if multiple people in the contact list have that same letter to begin with it prints out all of their names. If you want to add or delete you have to put in the required information (phone number, name) to delete the contact from the trie strucutre.

### Work Split
|Team Member|     Work Done      |
|--|--|
| E. Moreta |Contributed towards project report and presentation|
| C. Ijifisoye |Contributed towards the code, presentation slides and report|
| M. Sainterlien |Contributed towards code and the report|
| B. Fakolujo |Contributed towards code|
