#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>

class MaxHeap {
private:
    //std::vector<int> arr;
    int *arr;
    int size;
    int capacity;

    void heapify(int,int);

    int parent(int);
    int left(int);
    int right(int);

public:
    MaxHeap(int);
    ~MaxHeap();

    void insertNode(int);
    void deleteMax();
    void displayHeap();
    void heapSort();

    int getMax();
    int heapSize();

};

#endif
