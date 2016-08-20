#include "Queue.h"
#include <iostream>

int main() {
    Queue myqueue; // my queue object
    
    for (int i = 0; i < 10; i++) {
        myqueue.push(i);
    }
    myqueue.size();
    myqueue.print();
    myqueue.pop();
    myqueue.pop();
    myqueue.print();

    // Testing against memory
    /*
    for (int i = 0; i < 1000000; i++) {
        myqueue.push(i);
    }

    for (int i = 0; i < 1000000; i++) {
        myqueue.pop();
    }
    */
    return 0;
}
