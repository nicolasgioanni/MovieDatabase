#include "moviefactory.h"

// Constructor for MovieFactory
MovieFactory::MovieFactory() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    keepMovie[i] = nullptr;
    keepTransaction[i] = nullptr;
  }

  // Initialize specific movie types
  keepMovie[2] = new Classic();
  keepMovie[3] = new Drama();
  keepMovie[5] = new Comedy();

  // Initialize specific transaction types
  keepTransaction[1] = new Borrow();
  keepTransaction[7] = new History();
  keepTransaction[17] = new Return();
}

// Destructor for MovieFactory
MovieFactory::~MovieFactory() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    delete keepMovie[i];
    delete keepTransaction[i];
    keepMovie[i] = nullptr;
    keepTransaction[i] = nullptr;
  }
}

// Make a movie using the character and movie file
Movie *MovieFactory::createMovie(char cha, std::ifstream &fileMovie) {
  int subscript = hash(cha);

  if (keepMovie[subscript] == nullptr) {
    std::string temp;
    std::getline(fileMovie, temp, '\n');
    return nullptr;
  }
  return keepMovie[subscript]->create();
}

// Make a transaction using the character and command files
Transaction *MovieFactory::createTransaction(char cha,
                                             std::ifstream &fileCommand) {
  int subscript = hash(cha);
  if (keepTransaction[subscript] != nullptr) {
    return keepTransaction[subscript]->create();
  }
  std::string str;
  std::getline(fileCommand, str, '\n');
  return nullptr;
}

// Subscript for character determined by hash function
int MovieFactory::hash(char ch) { return (ch < 'a') ? (ch - 'A') : 0; }

// Retrieve the character's hash table index
int MovieFactory::subscript(char ch) { return hash(ch); }
