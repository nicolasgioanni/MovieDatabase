#include "return.h"

// // Constructor for Return objects, sets the actionType to 'R'
// Return::Return() : Transaction() { actionType = 'R'; }

// Sets the actionType to 'R' in the constructor for Return objects.
Return::Return() { actionType = 'R'; }

// Destructor
Return::~Return() {}

// Shows transaction's media and action types
void Return::display() const { cout << mediaType << " " << actionType << " "; }

// Creates and returns a pointer to a fresh Return object.
Transaction *Return::create() { return new Return(); }

// Handles return transactions: adds returned item to inventory, updates
// customer's history
bool Return::process(string mediaName, Movie *movieType) {
  if (movieType != nullptr) {
    mediaType = mediaName;
    item = movieType;
    item->addStock();
  }
  return true;
}
