#pragma once

#include "borrow.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "history.h"
#include "movie.h"
#include "return.h"
#include "transaction.h"

#include <fstream>
#include <iostream>

const int MAX_ITEMS = 26;

class MovieFactory {
public:
    // Constructor
    MovieFactory();

    // Destructor
    ~MovieFactory();

    // Member functions of MovieFactory class
    Transaction* createTransaction(char cha, std::ifstream& fileCommand);
    static int subscript(char ch);
    Movie* createMovie(char cha, std::ifstream& fileMovie);

private:
    static int hash(char ch);
    Movie* keepMovie[MAX_ITEMS];             // Keeps track of every movie
    Transaction* keepTransaction[MAX_ITEMS]; // Tracks all the transactions
};
