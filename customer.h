#pragma once
#include "transaction.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Customer {
public:
  // constructor
  Customer();

  explicit Customer(ifstream &file);

  // desctructor
  ~Customer();

  // Customer class member functions
  void
  addHistory(Transaction *tran); // collect the customer transaction activity
  void showCustomer() const;     // display customer info
  void showHistory();            // display customer transaction history
  int getID() const;             // returns customer ID
  string getLastName() const;    // returns first name of the client
  string getFirstName() const;   // returns last name of the client

  // operator overloading for customer class
  bool operator!=(const Customer &obj) const;
  bool operator==(const Customer &obj) const;

private:
  int id;                           // customer unique ID
  string firstName;                 // customer first name
  string lastName;                  // customer last name
  vector<Transaction *> cusHistory; // customer transaction stored
};
