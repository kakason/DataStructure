#include "RBTree.h"
#include "TreeTools.h"
#include <iostream>
#include <queue>

void RBTree::insertion(int data) {
    Node* tmp = newNode(data);
    root = insertNode(root,tmp);
    insertFix(tmp);
}

void RBTree::printOrder() {
    std::cout << "inOrder\n";
    inOrder(root);
    std::cout << "\nlevelOrder\n";
    levelOrder(root);
}

// Perform standard BST insertion and make the color of newly inserted nodes as RED
Node* RBTree::insertNode(Node* node, Node* tmp) {
    if (!node)
        return tmp;

    if (tmp->data < node->data) {
        node->left = insertNode(node->left, tmp);
        node->left->parent = node;
    }

    else if (tmp->data > node->data) {
        node->right = insertNode(node->right, tmp);
        node->right->parent = node;
    }

    return node;
}

// The main difference between the rotation of AVLTree and
// RBTree lies in RBTree needs to deal with the parent pointer.
// Hence, it needs more check to make the link between each
// nodes correctly
Node* RBTree::leftRotate(Node* g) {
    Node* p = g->right;

    g->right = p->left;
    // more check
    if (g->right) { 
        g->right->parent = g;
    }

    p->parent = g->parent;
    // more check
    if (!g->parent) { 
        root = p;
    }
    else if (g == g->parent->left) {
        g->parent->left = p;
    }
    else {
        g->parent->right = p;
    }

    p->left = g;
    g->parent = p;

    return p;
}

Node* RBTree::rightRotate(Node* g) {
    Node* p = g->left;

    g->left = p->right;
    // more check
    if (g->left) {
        g->left->parent = g;
    }

    p->parent = g->parent;
    // more check
    if (!p->parent) {
        root = p;
    }
    else if (g == g->parent->left) {
        g->parent->left = p;
    }
    else {
        g->parent->right = p;
    }

    p->right = g;
    g->parent = p;

    return p;
}

Node* RBTree::newNode(int data) {
    Node* tmp = new Node;
    tmp->left = tmp->right = tmp->parent = nullptr;
    tmp->data = data;
    tmp->color = 'R';

    return tmp;
}

// This function fixes violations caused by BST insertion
void RBTree::insertFix(Node* x) {

    while (x != root && x->color == 'R' && x->parent->color == 'R') {
        Node* p = nullptr;
        Node* g = nullptr;
        /*
        p means parent of x
        g means grandparent of x
        u means uncle of x
        */
        p = x->parent;
        g = p->parent;

        /* Case A: 
           Parent of x is left child of Grand-parent of x */
        if (p == g->left) {
            Node* u = g->right;
            /* Case 1:
               The uncle of x is also red
               Only Recoloring required */
            if (u && u->color == 'R') {
                u->color = p->color = 'B';
                g->color = 'R';
                x = g;
            }
            else {
                /* Case 2:
                   x is right child of its parent
                   Left-rotation required */
                if (x == p->right) {
                    p = leftRotate(p);
                    g->left = p;
                }
                /* Case 3:
                   x is left child of its parent
                   Right-rotation required */
                p = rightRotate(g);
                g = p->right;
                std::swap(p->color, g->color);
                x = p;
            }
        }
        /* Case B:
           Parent of x is right child of Grand-parent of x */
        else {
            Node* u = g->left;
            /* Case 1:
               The uncle of x is also red
               Only Recoloring required */
            if (u && u->color == 'R') {
                u->color = p->color = 'B';
                g->color = 'R';
                x = g;
            }
            else {
                /* Case 2:
                   x is left child of its parent
                   Right-rotation required */
                if (x == p->left) {
                    p = rightRotate(p);
                    g->right = p;
                }
                /* Case 3:
                   x is right child of its parent
                   Left-rotation required */
                p = leftRotate(g);
                g = p->left;
                std::swap(g->color, p->color);
                x = p;
            }
        }
    }
    root->color = 'B';
}

void RBTree::inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        std::cout << node->data << "(" << node->color << ") ";
        inOrder(node->right);
    }
}

void RBTree::levelOrder(Node* node){
    std::queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        std::cout << cur->data << "(" << cur->color << ") ";

        if (cur->left) {
            q.push(cur->left);
        }
        
        if (cur->right) {
            q.push(cur->right);
        }
    }
}

void RBTree::releaseTree(Node* node) {
    if (node) {
        releaseTree(node->left);
        releaseTree(node->right);
        delete node;
    }
}

RBTree::RBTree() {
    root = nullptr;
}

RBTree::~RBTree() {
    releaseTree(root);
}

