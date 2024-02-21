#pragma once
#include "movie.h"
#include <fstream>

class Drama : public Movie {
public:
  // Constructor
  Drama();
  // Destructor
  ~Drama();

  // member functions
  void setTransData(std::ifstream &file) override;
  void setDataItems(std::ifstream &file) override;

  // operator overloadings
  bool operator<(const Movie &other) const override;
  bool operator>(const Movie &other) const override;
  bool operator==(const Movie &other) const override;
  bool operator!=(const Movie &other) const override;

  Movie *create() override;
};
