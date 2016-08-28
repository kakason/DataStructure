#pragma once

struct Node {
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* sibling;
};
