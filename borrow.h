#include "transaction.h"
#include <fstream>
#include <iostream>
#pragma once

using namespace std;

class Customer;
class Borrow : public Transaction {
public:
  // Default constructor
  Borrow();

  // Destructor
  ~Borrow();

  // Function to display the borrow information
  virtual void display() const;

  // process the borrow transaction
  virtual bool process(string str, Movie *movie);

  // Create a pointer to a Borrow object
  virtual Transaction *make();
};
