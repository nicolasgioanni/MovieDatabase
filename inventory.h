#pragma once
#include "movie.h"
#include <iostream>
using namespace std;

class Inventory {

private:
  struct Node {
    Movie *data;
    Node *left;
    Node *right;
  };
  Node *root;

  // helper functions for inventory
  void helperMakeEmpty(Node *curr);
  bool helperInsert(Movie *insertData, Node *&currNode);
  bool helperRetrieve(const Node *cur, const Movie &target,
                      Movie *&currNode) const;
  void helperDisplay(Node *curr) const;

public:
  // constructor
  Inventory();

  // destructor
  ~Inventory();

  // member functions for inventory
  void display() const;
  bool insert(Movie *insert);
  bool isEmpty() const;
  void makeEmpty();
  bool retrieve(const Movie &target, Movie *&curNode) const;
  void displayGenre() const;
};
