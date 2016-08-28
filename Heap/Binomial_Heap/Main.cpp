#include "BinomialHeap.h"
#include <iostream>

#define notExist 1e9

int main() {
    BinomialHeap myheap;
    
    for (int i = 1000000; i >= 1; i--)
        myheap.insertion(i);

    for (int i = 1; i <= 500000; i++)
        myheap.deletion(i);
    
    for (int i = 500001; i <= 700000; i++)
        myheap.extractMin();

    // The min value should be 700001
    std::cout << myheap.getMin() << "\n"; 

    myheap.decreaseKey(850000, 700000);
    // The min value should be 700000
    std::cout << myheap.getMin() << "\n";

    return 0;
}