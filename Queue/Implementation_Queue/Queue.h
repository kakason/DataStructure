#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* rear;

    Node* newNode(int);

public:
    Queue();
    ~Queue();

    void push(int);
    void pop();
    void size();
    void print();

};

#endif
