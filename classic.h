#pragma once
#include "movie.h"
#include <fstream>
#include <iostream>
using namespace std;

class Classic : public Movie {
public:
  // default constructor
  Classic();
  // destructor
  ~Classic();

  // virtual methods that display information about a Classic movie
  virtual void display() const;

  // virtual methods that set data items for a Classic movie
  virtual void setDataItems(ifstream &file);

  // virtual methods that set transaction data items for a Classic movie
  virtual void setTransData(ifstream &file);

  // boolean operators that override the base class's operators
  virtual bool operator>(const Movie &obj) const;
  virtual bool operator<(const Movie &obj) const;
  virtual bool operator==(const Movie &obj) const;
  virtual bool operator!=(const Movie &obj) const;

  // Declare a method that returns a pointer to a new Classic movie
  virtual Movie *create();

private:
  string firstName; // actor's first name
  string lastName;  // actor's last name
  int month;        // release month
};