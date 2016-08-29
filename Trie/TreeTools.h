#pragma once

#define ALPHABET_SIZE 26

struct Node {
    Node* children[ALPHABET_SIZE];
    bool isLeaf;
    int count;
};
