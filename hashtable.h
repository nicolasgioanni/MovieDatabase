#pragma once
#include "customer.h"
#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;

class HashTable {
public:
  // default constructor
  HashTable();

  // destructor
  ~HashTable();

  // insert customer into hash table
  bool insert(Customer *cust);

  // display customer details
  void display() const;

  // empty the hashtable
  void makeEmpty();

  // retrieve customer from hash table
  bool retrieve(int id, Customer *&findCust) const;

private:
  Customer *customersList[MAX_SIZE];
  static int hashValue(int id);
};
