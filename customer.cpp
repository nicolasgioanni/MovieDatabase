#include "customer.h"

// constructor
Customer::Customer() {
  firstName = "";
  lastName = "";
  id = 0;
}

/*
This constructor retrieves customer information from a file, including ID,
last name, and first name. \
*/
Customer::Customer(ifstream &file) {
  file >> id;
  if (file.eof()) {
    return;
  }
  file >> lastName >> firstName;
}

/*
The destructor frees up memory by deleting each Transaction object stored in
the history vector.
*/
Customer::~Customer() {
  for (int i = 0; i < cusHistory.size(); i++) {
    Transaction *temp = cusHistory[i];
    delete temp;
    temp = nullptr;
  }
}

// Adds a new transaction object to the customer's history vector.
void Customer::addHistory(Transaction *tran) { cusHistory.push_back(tran); }

// Show customer's transaction history.
void Customer::showHistory() {
  if (cusHistory.empty()) {
    cout << "Transaction history not available for Customer: " << id << endl
         << endl;
  } else {
    cout << "Transaction History for Customer: " << id << " " << lastName
         << ", " << firstName << endl;

    for (int i = static_cast<int>(cusHistory.size()) - 1; i >= 0; i--) {
      Transaction *temp = cusHistory[i];
      cout << "Action Type: " << temp->getActionType() << "   Movie Title: ";
      cout << temp->getMovie()->getTitle();
      cout << endl;
    }
    cout << endl;
  }
}

// Display customer's basic information: first name, last name, and ID number.
void Customer::showCustomer() const {
  cout << firstName << " " << lastName << " " << id << endl;
}

// Get customer ID
int Customer::getID() const { return id; }

// Get customer first name
string Customer::getFirstName() const { return firstName; }

// Get customer last name
string Customer::getLastName() const { return lastName; }

// This function verifies if the customer ID matches the provided customer
// object.
bool Customer::operator==(const Customer &obj) const { return id == obj.id; }

// This method compares the IDs of two customer objects to determine if they are
// different.
bool Customer::operator!=(const Customer &obj) const { return id != obj.id; }
