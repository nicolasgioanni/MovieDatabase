#include "transaction.h"

// Default constructor
Transaction::Transaction() {}

// Destructor
Transaction::~Transaction() {}

// Show the transaction
void Transaction::display() const {
  cout << mediaType << " " << actionType << ": " << endl;
}

/*
Process the transaction by taking a string, a Movie pointer, and a Customer
pointer as input.
*/
bool Transaction::process([[maybe_unused]] string str,
                          [[maybe_unused]] Movie *mov,
                          [[maybe_unused]] Customer *cus) {
  return false;
}

// getter functions
Movie *Transaction::getMovie() { return item; }
char Transaction::getMovieType() const { return movieType; }
char Transaction::getActionType() const { return actionType; }

// Create a new transaction object
Transaction *Transaction::create() { return new Transaction(); }
