#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int thetop;
    int *arr;
    int maxsize;

public:
    Stack(int);
    ~Stack();

    void push(int);
    void print();

    int pop();
    int size();
    int top();
    int looktop();

};

#endif
