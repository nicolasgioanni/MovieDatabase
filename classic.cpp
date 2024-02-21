#include "classic.h"

// constructor
Classic::Classic() {}

// deconstructor
Classic::~Classic() {}

/*
This method displays the formatted details of a Classic movie object on the
console. It includes information such as the stock, director, title, year,
and month of release. Its purpose is to present the specific details of a
Classic movie to the user.
*/
void Classic::display() const {
  cout << left << setw(8) << setfill(' ') << "stock:" << left << setw(4)
       << setfill(' ') << stock;
  cout << left << setw(11) << setfill(' ') << "director: " << left << setw(20)
       << setfill(' ') << director;
  cout << left << setw(8) << setfill(' ') << "title: " << left << setw(35)
       << setfill(' ') << title;
  cout << left << setw(6) << setfill(' ') << "year:" << year << "  ";
  cout << left << setw(7) << setfill(' ') << "month:" << month << " ";
  cout << endl;
}

/*
This function populates the data members of a Classic movie object by retrieving
the values from a file stream. It retrieves the values for stock, director,
title, actor first name, actor last name, month, and year from the file stream
and assigns them to their corresponding data members.
*/
void Classic::setDataItems(ifstream &file) {
  file.ignore();
  file >> stock;
  file.ignore();
  getline(file >> ws, director, ',');
  file.ignore();
  getline(file >> ws, title, ',');
  file.ignore();
  file >> firstName;
  file.ignore();
  file >> lastName;
  file.ignore();
  file >> month;
  file.ignore();
  file >> year;
}

// Reads Classic movie transaction data from input file, including release date
// and lead actor's names.
void Classic::setTransData(ifstream &file) {
  file >> month >> year >> firstName >> lastName;
}

/*
Compares two Classic movies by release year, actor's first name, and actor's
last name. Returns true if current Classic movie is greater than the
argument, false otherwise.
*/
bool Classic::operator>(const Movie &obj) const {
  const Classic &classicsMov = static_cast<const Classic &>(obj);
  if (year != classicsMov.year) {
    return year > classicsMov.year;
  }
  if (month != classicsMov.month) {
    return month > classicsMov.month;
  }
  if (firstName != classicsMov.firstName) {
    return firstName > classicsMov.firstName;
  }
  if (lastName != classicsMov.lastName) {
    return lastName > classicsMov.lastName;
  }
  return false;
}

/*
Compares two Classic movies by release year, actor's first name, and actor's
last name. Returns true if current Classic movie is smaller than the
argument, false otherwise.
*/
bool Classic::operator<(const Movie &obj) const {
  const Classic &classicsMov = static_cast<const Classic &>(obj);
  if (year != classicsMov.year) {
    return year < classicsMov.year;
  }
  if (month != classicsMov.month) {
    return month < classicsMov.month;
  }
  if (firstName != classicsMov.firstName) {
    return firstName < classicsMov.firstName;
  }
  if (lastName != classicsMov.lastName) {
    return lastName < classicsMov.lastName;
  }
  return false;
}

// Returns true if the Classic movie's year and month match the passed Movie's.
bool Classic::operator==(const Movie &obj) const {
  const Classic &classicsMov = static_cast<const Classic &>(obj);
  return (year == classicsMov.year && month == classicsMov.month);
}

// Returns true if the objects have different year and month values, otherwise
// false.
bool Classic::operator!=(const Movie &obj) const {
  const Classic &classicsMov = static_cast<const Classic &>(obj);
  return !(*this == classicsMov);
}

// Returns a new Classic object as a Movie pointer for dynamic instantiation.
Movie *Classic::create() { return new Classic(); }