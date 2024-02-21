#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

class Movie {
public:
  // constructor
  Movie();
  // destructor
  virtual ~Movie();

  // Member function for movie
  virtual void display() const;
  virtual void setTransData(ifstream &) = 0;
  virtual void setDataItems(ifstream &file);
  virtual string getTitle() const;
  string getDirector() const;
  int getYear() const;
  int getStock() const;
  char getGenre() const;
  void addStock();
  void reduceStock();
  void addStock(int count);
  virtual Movie *create() = 0;

  // operator overloading
  virtual bool operator<(const Movie &) const = 0;
  virtual bool operator>(const Movie &) const = 0;
  virtual bool operator==(const Movie &) const = 0;
  virtual bool operator!=(const Movie &) const = 0;

protected:
  int stock;
  int year;
  char genre;
  string title;
  string director;
};
