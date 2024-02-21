#include "comedy.h"

// constructor
Comedy::Comedy() {}

// destructor
Comedy::~Comedy() {}

/*
This function reads data from a file stream and assigns values to the stock,
 * director, title, and year attributes of a Comedy movie object.
*/
void Comedy::setDataItems(ifstream &file) {
  file.ignore();
  file >> stock;
  file.ignore();
  getline(file >> ws, director, ',');
  file.ignore();
  getline(file >> ws, title, ',');
  file >> year;
}

/*
This function reads the movie's title and year from the input file stream and
 * sets the transaction data for a Comedy movie object.
*/
void Comedy::setTransData(ifstream &file) {
  file.ignore();
  getline(file >> ws, title, ',');
  file >> year;
}

/*
This code implements the less than operator for the Comedy movie class,
comparing the title and year of the current and another Comedy movie object.
*/
bool Comedy::operator<(const Movie &obj) const {
  const Comedy &comedyMovie = static_cast<const Comedy &>(obj);
  if (title != comedyMovie.title) {
    return title < comedyMovie.title;
  }
  return year < comedyMovie.year;
}

/*
This function checks if the current comedy movie has a higher title and year
than the passed movie.
*/
bool Comedy::operator>(const Movie &obj) const {
  const Comedy &comedyMovie = static_cast<const Comedy &>(obj);
  if (title != comedyMovie.title) {
    return title > comedyMovie.title;
  }
  return year > comedyMovie.year;
}

/*
This method checks if two Comedy movie objects have the same title and
release year, returning true if they do and false if they don't.
*/
bool Comedy::operator==(const Movie &obj) const {
  const Comedy &comedyMovie = static_cast<const Comedy &>(obj);
  return (title == comedyMovie.title && year == comedyMovie.year);
}

/*
This code checks if the Movie object, after casting it to a Comedy object,
is different from the current object using the equal-to operator.
*/
bool Comedy::operator!=(const Movie &obj) const {
  const Comedy &comedyMovie = static_cast<const Comedy &>(obj);
  return !(*this == comedyMovie);
}

/*
Use this method to dynamically create objects at runtime without knowing
their exact type until runtime.
*/
Movie *Comedy::create() { return new Comedy(); }
