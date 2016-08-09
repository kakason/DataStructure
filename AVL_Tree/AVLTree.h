#include "TreeTools.h"
#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree{
private:
  Node* root;

  Node* newNode(int);
  Node* minValueNode(Node*);
  Node* insertNode(Node*, int);
  Node* deleteNode(Node*, int);
  Node* leftRotate(Node*);
  Node* rightRotate(Node*);

  void setRoot(int);
  void releaseTree(Node*);
  void preOrder(Node*);

  int getBalance(Node*);
  int height(Node*);

public:
  AVLTree();
  ~AVLTree();

  void insertion(int);
  void deletion(int);
  void print();

};

#endif
