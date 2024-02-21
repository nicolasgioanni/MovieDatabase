#pragma once

#include "movie.h"
#include <fstream>

class Comedy : public Movie {
public:
  // default constructor
  Comedy();
  // destructor
  ~Comedy();

  // Functions that retrieve data from a file and assign it to comedy movies.
  virtual void setDataItems(std::ifstream &file) override;
  virtual void setTransData(std::ifstream &file) override;

  // overloading operator in comedy class
  virtual bool operator<(const Movie &obj) const override;
  virtual bool operator>(const Movie &obj) const override;
  virtual bool operator==(const Movie &obj) const override;
  virtual bool operator!=(const Movie &obj) const override;

  // Get a pointer to a Movie object.
  virtual Movie *create() override;
};
