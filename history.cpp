#include "history.h"

// Constructor
History::History() {}

// Destructor
History::~History() {}

// Processes the transaction and displays the customer's rental history
bool History::process(Customer *cust) {
  cust->showHistory();
  return true;
}

// Factory method to create a new instance of History
Transaction *History::create() { return new History(); }
