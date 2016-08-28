#include "MaxHeap.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

int main() {
    // TestInputSize: 10000000
    // Performance:      MyHeap       STL
    // Heap Insertion:   0.170s      1.304s
    // Heap Sort:        6.719s      2.788s

    MaxHeap myheap(10000000);

    //#START--- debug ---
    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;

    t1 = std::chrono::steady_clock::now();
    for (int i = 10000000; i > 0; i--) {
        myheap.insertNode(i);
    }
    t2 = std::chrono::steady_clock::now();
    std::cout << "Heap Insertion: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "\n";
    //-----------------------------------------------------------------------------------------

    t1 = std::chrono::steady_clock::now();
    myheap.heapSort();
    t2 = std::chrono::steady_clock::now();
    std::cout << "Heap Sort: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "\n";
    //-----------------------------------------------------------------------------------------

    std::vector<int> tmp;
    tmp.reserve(10000000);
    t1 = std::chrono::steady_clock::now();
    for (int i = 10000000; i > 0; i--) {
        tmp.push_back(i);
    }
    std::make_heap(tmp.begin(), tmp.end());
    t2 = std::chrono::steady_clock::now();
    std::cout << "Normal Insertion: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "\n";
    //-----------------------------------------------------------------------------------------

    t1 = std::chrono::steady_clock::now();
    sort_heap(tmp.begin(), tmp.end());
    t2 = std::chrono::steady_clock::now();
    std::cout << "STL HeapSort: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "\n";
    //-----------------------------------------------------------------------------------------
    //#END--- debug ---

    return 0;
}
