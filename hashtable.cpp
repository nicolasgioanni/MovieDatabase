#include "hashtable.h"

HashTable::HashTable() : customersList{} {}

HashTable::~HashTable() { makeEmpty(); }

void HashTable::makeEmpty() {
  for (int i = 0; i < MAX_SIZE; i++) {
    delete customersList[i];
    customersList[i] = nullptr;
  }
}

bool HashTable::insert(Customer *cust) {
  int index = hashValue(cust->getID());

  if (customersList[index] == nullptr) {
    customersList[index] = cust;
    return true;
  }

  for (int i = (index + 1) % MAX_SIZE; i != index; i = (i + 1) % MAX_SIZE) {
    if (customersList[i] == nullptr) {
      customersList[i] = cust;
      return true;
    }
  }

  return false;
}

bool HashTable::retrieve(int id, Customer *&findCust) const {
  int index = hashValue(id);

  if (customersList[index] != nullptr && customersList[index]->getID() == id) {
    findCust = customersList[index];
    return true;
  }

  int tempIndex = (index + 1) % MAX_SIZE;

  for (int i = 0; i < MAX_SIZE; i++) {
    if (customersList[tempIndex] != nullptr &&
        customersList[tempIndex]->getID() == id) {
      findCust = customersList[tempIndex];
      return true;
    }

    tempIndex = (tempIndex + 1) % MAX_SIZE;
  }

  return false;
}

int HashTable::hashValue(int id) { return id % MAX_SIZE; }

void HashTable::display() const {
  for (int i = 0; i < MAX_SIZE; i++) {
    if (customersList[i] != nullptr) {
      customersList[i]->showCustomer();
    }
  }
}
