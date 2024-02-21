#pragma once
#include "transaction.h"
#include <fstream>
#include <iostream>
using namespace std;

class Customer;
class Return : public Transaction {

public:
  // constructor
  Return();

  // destructor
  ~Return();

  // Show transaction progress
  virtual void display() const override;

  // Provides a pointer to the transaction object.
  virtual Transaction *create() override;

  // Verifying customer transaction progress
  virtual bool process(string mediaName, Movie *movieType);
};
