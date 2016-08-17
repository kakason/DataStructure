#ifndef TREETOOLS_H
#define TREETOOLS_H

struct Node {
    int data;
    int color;
    Node* left;
    Node* right;
    Node* parent;
};

enum Color { RED, BLACK };

#endif
