#include <iostream>
#include "Stack.h"

int main() {
    Stack mystack(8); // my stack object which has the size 8

    // do some test

    int i = 8;
    while (mystack.top() < mystack.size()) {
        mystack.push(i);
        i++;
    }
    std::cout << "After the while loop\n";
    mystack.print();

    mystack.push(i);

    int a;
    a = mystack.pop();
    a = mystack.pop();
    mystack.print();

    for (int j = 1; j < 8; j++) {
        a = mystack.pop();
        if(a != -1)
            std::cout << "pop " << a << " out of the stack\n";
    }
    mystack.print();

    mystack.push(30);
    mystack.push(31);
    mystack.print();

    a = mystack.looktop();
    if(a != -1)
        std::cout << "Top Value: " << a << "\n";

    mystack.print();

    return 0;
}
