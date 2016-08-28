#include "MaxHeap.h"
#include <vector>
#include <iostream>

#define NotExist -1e9

MaxHeap::MaxHeap(int c) {
    capacity = c;
    //arr.reserve(capacity);
    size = 0;
    arr = new int[capacity];
}

MaxHeap::~MaxHeap() {
    delete[] arr;
}

// i means the index, s means the size
void MaxHeap::heapify(int i, int s) {
    int l = left(i);
    int r = right(i);
    int maxIndex = i;

    if (l < s && arr[l] > arr[maxIndex])
        maxIndex = l;
    if (r < s && arr[r] > arr[maxIndex])
        maxIndex = r;

    if (maxIndex != i) {
        std::swap(arr[i], arr[maxIndex]);
        heapify(maxIndex, s);
    }
}

int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

int MaxHeap::left(int i) {
    return i * 2 + 1;
}

int MaxHeap::right(int i) {
    return i * 2 + 2;
}

void MaxHeap::insertNode(int data) {
    if (size == capacity) {
        std::cout << "Overflow: Heap is full\n";
        return;
    }

    arr[size++] = data;
    //arr.push_back(data);
    int i = size - 1;

    // Fix the max heap property if it is violated
    while (i != 0 && arr[parent(i)] < arr[i]) {
        std::swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void MaxHeap::deleteMax() {
    if (size == 0)
        std::cout << "The heap is empty, u can't delete anything\n";

    std::swap(arr[0], arr[--size]);
    //arr.pop_back();
    heapify(0, size);
}

void MaxHeap::heapSort() {
    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(0, i);
    }
}

void MaxHeap::displayHeap() {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

int MaxHeap::getMax() {
    if (size == 0)
        return NotExist;
    else
        return arr[0];
}

int MaxHeap::heapSize() {
    return size;
}
