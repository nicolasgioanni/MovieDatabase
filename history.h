#pragma once
#include "hashtable.h"
#include "inventory.h"
#include "transaction.h"
#include <fstream>
#include <iostream>
using namespace std;

class Customer;
class History : public Transaction {
public:
  // constructor
  History();

  // destructor
  ~History();

  // member functions for Customer
  virtual Transaction *create();
  virtual bool process(Customer *cust);
};
