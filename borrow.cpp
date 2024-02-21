#include "borrow.h"

Borrow::Borrow() { actionType = 'B'; }

Borrow::~Borrow() {}

// Print the borrowing transaction details to the console
void Borrow::display() const { cout << mediaType << " " << actionType << " "; }

bool Borrow::process(string str, Movie *movie) {
  if (movie == nullptr) {
    return false;
  }
  item = movie;
  mediaType = str;

  if (movie->getStock() <= 0) {
    cout << "Movie: " << movie->getTitle() << " is not in stock." << endl
         << endl;
    return false;
  }
  movie->reduceStock();
  return true;
}

// Create a new instance of the Borrow class
Transaction *Borrow::make() {
  Transaction *newBorrow = new Borrow();
  return newBorrow;
  // return new Borrow();
}
