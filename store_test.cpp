/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "business.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;

  ifstream infile1("data4customers.txt");
  if (!infile1) {
    cout << "Error reading customers file)" << endl;
  }
  ifstream infile2("data4movies.txt");
  if (!infile2) {
    cout << "Error reading movies file" << endl;
  }
  ifstream infile3("data4commands.txt");
  if (!infile3) {
    cout << "Error reading commands file" << endl;
  }

  Business movieStore;
  movieStore.createCustomerList(infile1);
  movieStore.createInventory(infile2);
  movieStore.runTransactions(infile3);

  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}