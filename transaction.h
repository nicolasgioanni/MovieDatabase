#pragma once
#include "movie.h"
#include <fstream>
#include <iostream>
using namespace std;

// Declaration of the Customer class in advance
class Customer;

class Transaction {
public:
  // default constructor
  Transaction();

  // destructor
  virtual ~Transaction();

  // display the transaction using a virtual function.
  virtual void display() const;

  /*
  Process the transaction using a virtual function, with inputs as a string,
  a Movie pointer, and a Customer pointer.
  */
  virtual bool process(string str, Movie *mov, Customer *cus);

  /*
  This virtual function creates a new transaction and returns a pointer to
  it.
  */
  virtual Transaction *create();

  // getter functions
  char getActionType() const;
  char getMovieType() const;
  Movie *getMovie();

protected:
  // Movie pointer for the transaction
  Movie *item;

  // Movie type character
  char movieType;

  // Character indicating the action type.
  char actionType;

  // Media type of the movie in string format
  string mediaType;
};
