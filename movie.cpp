#include "movie.h"

// Movie constructor, sets member variables
Movie::Movie() {
  year = 0;
  stock = 0;
  genre = ' ';
  director = "";
  title = "";
}

// destructor
Movie::~Movie() {}

// Displays movie details
void Movie::display() const {
  cout << left << setw(8) << setfill(' ') << "stock:" << left << setw(4)
       << setfill(' ') << stock;
  cout << left << setw(11) << setfill(' ') << "director: " << left << setw(20)
       << setfill(' ') << director;
  cout << left << setw(8) << setfill(' ') << "title: " << left << setw(35)
       << setfill(' ') << title;
  cout << left << setw(6) << setfill(' ') << "year:" << year << " ";
  cout << endl;
}

// Sets the data items of a movie object from a data file
void Movie::setDataItems(ifstream &file) {
  file.ignore();
  getline(file, director, ',');
  file.ignore();
  getline(file, title, ',');
  file.ignore();
  file >> year;
}

// Adds 1 to the movie's stock
void Movie::addStock() { stock++; }

// Reduce 1 to the movie's stock
void Movie::reduceStock() { stock--; }

// Adds more copies of a movie to the inventory
void Movie::addStock(int count) { stock += count; }

// Gets the movie stock
int Movie::getStock() const { return stock; }

//// Gets the movie genre
char Movie::getGenre() const { return genre; }

// Gets the movie year
int Movie::getYear() const { return year; }

// Gets the movie title
string Movie::getTitle() const { return title; }

// Gets the movie director
string Movie::getDirector() const { return director; }
