#include "business.h"

// Default constructor
Business::Business() {}

// Destructor
Business::~Business() {}

// Reads customer data from a file and creates a list of customers in a table.
void Business::createCustomerList(ifstream &fileOne) {
  while (true) {
    Customer *create = new Customer(fileOne);

    if (fileOne.eof()) {
      delete create;
      create = nullptr;
      break;
    }
    bool success = table.insert(create);
    if (!success) {
      delete create;
      create = nullptr;
    }
  }
}

// Creates a movie inventory from a file using a factory object.
void Business::createInventory(ifstream &fileTwo) {
  char str = ' ';
  while (!fileTwo.eof()) {
    fileTwo >> str;
    if (fileTwo.eof()) {
      break;
    }
    // Create a movie object using a factory method
    Movie *create = factory.createMovie(str, fileTwo);

    if (create != nullptr) {
      create->setDataItems(fileTwo);

      // Insert the movie into the inventory using the appropriate subscript
      bool success = inventory[MovieFactory::subscript(str)].insert(create);

      if (!success) {
        delete create;
        create = nullptr;
      }
    }
  }
}

// Runs transactions for everything
void Business::runTransactions(ifstream &fileThree) {
  char code1 = ' ';
  char code2 = ' ';
  char code3 = ' ';
  int identifier;
  string type;
  Customer *customerPtr = nullptr;
  Movie *moviePtr = nullptr;
  Movie *retrievedMovie = nullptr;
  bool isTransactionToDelete = false;

  while (!fileThree.eof()) {
    isTransactionToDelete = false;
    fileThree >> code1;

    if (fileThree.eof()) {
      break;
    }

    if (code1 == 'I') {
      displayInventory();
    } else {
      Transaction *transactionPtr = factory.createTransaction(code1, fileThree);
      isTransactionToDelete = true;

      if (transactionPtr != nullptr) {
        fileThree >> identifier;

        if (fileThree.eof()) {
          break;
        }

        if (table.retrieve(identifier, customerPtr)) {
          if (code1 == 'H') {
            transactionPtr->process(type, moviePtr, customerPtr);
          } else {
            fileThree >> code2;
            if (code2 == 'D') {
              fileThree >> code3;
              moviePtr = factory.createMovie(code3, fileThree);
            }
            if (moviePtr != nullptr) {
              moviePtr->setTransData(fileThree);
              bool isMovieFound =
                  inventory[MovieFactory::subscript(code3)].retrieve(
                      *moviePtr, retrievedMovie);

              if (!isMovieFound) {
                cout << "Invalid Movie Request: " << moviePtr->getTitle()
                     << " not found" << endl
                     << endl;
              }

              delete moviePtr;
              moviePtr = nullptr;

              bool isProcessed =
                  transactionPtr->process(type, retrievedMovie, customerPtr);

              if (isMovieFound && isProcessed) {
                customerPtr->addHistory(transactionPtr);
                isTransactionToDelete = false;
              }
            } else {
              cout << "Invalid Movie Genre: " << code3 << " not found" << endl
                   << endl;
            }
          }
        } else {
          cout << "Invalid Customer ID: " << identifier << " not found" << endl
               << endl;
        }

      } else {
        cout << "Invalid Transaction Type: " << code1 << " not found" << endl
             << endl;
      }

      if (isTransactionToDelete) {
        delete transactionPtr;
        transactionPtr = nullptr;
      }
    }
  }
}

// Customer display inventory
void Business::displayInventory() const {
  cout << "----------------------------MovieInventory--------------------------"
          "------";
  cout << "----------------------------" << endl << endl;
  for (int j = MAX_NUM - 1; j >= 0; j--) {
    if (!inventory[j].isEmpty()) {
      inventory[j].display();
      cout << endl;
    }
  }
  cout << "-------------------------------------------------";
  cout << "---------------------" << endl << endl;
}

// Customer display functions
void Business::displayCustomers() const {
  cout << "Current Customers List:" << endl << endl;
  table.display();
}
