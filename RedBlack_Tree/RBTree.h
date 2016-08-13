#ifndef RBTREE_H
#define RBTREE_H
#include "TreeTools.h"

class RBTree {
private:
    Node* root;

    Node* insertNode(Node*, Node*);
    Node* leftRotate(Node*);
    Node* rightRotate(Node*);
    Node* newNode(int);

    void insertFix(Node*);
    void inOrder(Node*);
    void levelOrder(Node*);
    void releaseTree(Node*);

public:
    RBTree();
    ~RBTree();

    void insertion(int);
    void printOrder();
};

#endif
