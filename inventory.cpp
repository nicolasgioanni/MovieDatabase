#include "inventory.h"

// Constructor
Inventory::Inventory() { root = nullptr; }

// Destructor
Inventory::~Inventory() { makeEmpty(); }

// checks if tree empty
bool Inventory::isEmpty() const { return root == nullptr; }

// Delete all nodes in the tree
void Inventory::makeEmpty() {
  helperMakeEmpty(root);
  root = nullptr;
}

// Helper function to delete nodes in the tree
void Inventory::helperMakeEmpty(Node *curr) {
  if (curr == nullptr) {
    return;
  }
  helperMakeEmpty(curr->left);
  helperMakeEmpty(curr->right);
  curr->left = nullptr;
  curr->right = nullptr;
  delete curr->data;
  curr->data = nullptr;
  delete curr;
  curr = nullptr;
}

// Insert a movie into the tree
bool Inventory::insert(Movie *insert) {
  return helperInsert(insert, this->root);
}

bool Inventory::helperInsert(Movie *insertData, Node *&currNode) {
  if (currNode == nullptr) {
    currNode = new Node{insertData, nullptr, nullptr};
    return true;
  }

  if (*insertData == *currNode->data) {
    currNode->data->addStock(insertData->getStock());
    return false;
  }

  return (*insertData < *currNode->data)
             ? helperInsert(insertData, currNode->left)
             : helperInsert(insertData, currNode->right);
}

// Retrieve a movie from the tree
bool Inventory::retrieve(const Movie &target, Movie *&curNode) const {
  curNode = nullptr;
  return helperRetrieve(root, target, curNode);
}

// Helper function to retrieve a movie from the tree
bool Inventory::helperRetrieve(const Node *cur, const Movie &target,
                               Movie *&currNode) const {
  if (cur == nullptr) {
    return false;
  }
  if (*cur->data == target) {
    currNode = cur->data;
    return true;
  }
  return (target < *cur->data) ? helperRetrieve(cur->left, target, currNode)
                               : helperRetrieve(cur->right, target, currNode);
}

// Display all movies in the tree
void Inventory::display() const { helperDisplay(root); }

// Helper function to display all movies in the tree
void Inventory::helperDisplay(Node *curr) const {
  if (curr != nullptr) {
    helperDisplay(curr->left);
    curr->data->display();
    helperDisplay(curr->right);
  }
}

// Display Genre of Inventory Item
void Inventory::displayGenre() const { cout << root->data->getGenre() << endl; }
