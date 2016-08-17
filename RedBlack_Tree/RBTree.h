#ifndef RBTREE_H
#define RBTREE_H
#include "TreeTools.h"

class RBTree {
private:
    Node* root;
    Node* nil;

    Node* insertNode(Node*, Node*);
    Node* deleteNode(Node*, Node*&, int, bool&);
    Node* leftRotate(Node*);
    Node* rightRotate(Node*);
    Node* minValueNode(Node*);
    Node* newNode(int);

    void insertFix(Node*);
    void deleteFix(Node*);
    void inOrder(Node*);
    void levelOrder(Node*);
    void releaseTree(Node*);

public:
    RBTree();
    ~RBTree();

    void insertion(int);
    void deletion(int);
    void printOrder();
};

#endif
