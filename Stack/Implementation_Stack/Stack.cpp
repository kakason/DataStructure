#include <iostream>
#include "Stack.h"

Stack::Stack(int s) {
    maxsize = s;
    thetop = -1;
    arr = new int[maxsize];
}


Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int item) {
    if (thetop + 1 < maxsize) {
        arr[thetop + 1] = item;
        thetop++;
    }
    else
        std::cout << "The stack is full, can't push in anything\n";
}

int Stack::pop() {
    if (thetop >= 0)
        return arr[thetop--];
    else {
        std::cout << "The stack is empty, can't pop out anything\n";
        return -1;
    }
}

void Stack::print() {
    if (thetop < 0)
        std::cout << "The stack is empty, can't print anything\n";
    else {
        std::cout << "From bottom to top: ";
        for (int i = 0; i <= thetop; i++)
            std::cout << arr[i] << " ";

        std::cout << "\n";
    }
}

int Stack::size() {
    return maxsize;
}

int Stack::top() {
    return thetop + 1;
}

int Stack::looktop() {
    if (thetop < 0) {
        std::cout << "The stack is empty\n";
        return -1;
    }
    else
        return arr[thetop];
}
