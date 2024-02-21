#include "drama.h"

Drama::Drama() {}

Drama::~Drama() {}

// Function to set data items for a Drama object from an input file stream
void Drama::setDataItems(std::ifstream &file) {
  file.ignore();
  file >> stock;
  file.ignore();
  getline(file, director, ',');
  file.ignore();
  getline(file, title, ',');
  file >> year;
}

// Function for setting transaction data from an input file for a Drama object.
void Drama::setTransData(std::ifstream &file) {
  file.ignore();
  getline(file, director, ',');
  file.ignore();
  getline(file, title, ',');
}

// Comparison operator for Drama movies based on director and title
bool Drama::operator<(const Movie &other) const {
  const Drama &dramaMov = static_cast<const Drama &>(other);
  return (director < dramaMov.director) ||
         (director == dramaMov.director && title < dramaMov.title);
}

/*
Comparison operator for Drama movies: Greater than operator based on director
and title
*/
bool Drama::operator>(const Movie &other) const {
  const Drama &dramaMov = static_cast<const Drama &>(other);
  return (director > dramaMov.director) ||
         (director == dramaMov.director && title > dramaMov.title);
}

// Comparison operator for checking equality of Drama movies based on director
// and title
bool Drama::operator==(const Movie &other) const {
  const Drama &dramaMovie = static_cast<const Drama &>(other);
  return (director == dramaMovie.director && title == dramaMovie.title);
}

// Function to check if a Drama object is not equal to another Movie object
bool Drama::operator!=(const Movie &other) const {
  const Drama &dramaMovie = static_cast<const Drama &>(other);
  return !(*this == dramaMovie);
}

Movie *Drama::create() { return new Drama(); }
