#pragma once
#include "TreeTools.h"

class BinomialHeap {
private:
    Node* head;

    Node* mergeTree(Node*, Node*);
    Node* unionTree(Node*);
    //Node* bubbleUp(Node*, bool);
    Node* newNode(int);
    Node* search(int);

    void linkTree(Node*, Node*);
    void removeTreeRoot(Node*);
    void insertNode(Node*);
    void deleteNode(Node*);
    void decreaseNode(Node*, int);
    void clearTree();

public:
    BinomialHeap();
    //BinomialHeap(Node*);
    ~BinomialHeap();

    int getMin();

    void insertion(int);
    void deletion(int);
    void extractMin();
    void decreaseKey(int,int);
    //void print();
};

