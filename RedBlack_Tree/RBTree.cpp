#include "RBTree.h"
#include "TreeTools.h"
#include <iostream>
#include <queue>

RBTree::RBTree() {
    nil = new Node;
    nil->color = BLACK;

    //root = new Node;
    root = nil;
    root->parent = nil;
}

RBTree::~RBTree() {
    releaseTree(root);
    delete nil;
}

void RBTree::insertion(int data) {
    Node* tmp = newNode(data);
    root = insertNode(root, tmp);
    insertFix(tmp);
}

void RBTree::deletion(int data) {
    Node* suc;
    bool isBlack = false;
    root = deleteNode(root, suc, data, isBlack);
    if (isBlack)
        deleteFix(suc);
}

void RBTree::printOrder() {
    std::cout << "inOrder\n";
    inOrder(root);
    std::cout << "\nlevelOrder\n";
    levelOrder(root);
}

// Perform standard BST insertion and make the color of newly inserted nodes as RED
Node* RBTree::insertNode(Node* node, Node* tmp) {
    if (node == nil)
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

Node* RBTree::deleteNode(Node* node, Node* &suc, int data, bool &isBlack) {
    if (node == nil)
        return node;

    if (data < node->data) {
        node->left = deleteNode(node->left, suc, data, isBlack);
        node->left->parent = node; // fix parent pointer even if it is nil
    }

    else if (data > node->data) {
        node->right = deleteNode(node->right, suc, data, isBlack);
        node->right->parent = node; // fix parent pointer even if it is nil
    }

    else {
        // node with only one child or no child
        if (node->left == nil) {
            Node* cur = node;
            node = node->right;
            suc = node; // get successor of node to be deleted

            if (cur->color == BLACK) // check node to be deleted is black or not
                isBlack = true;

            delete cur;
        }

        else if (node->right == nil) {
            Node* cur = node;
            node = node->left;
            suc = node; // get successor of node to be deleted

            if (cur->color == BLACK) // check node to be deleted is black or not
                isBlack = true;

            delete cur;
        }

        else {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* tmp = minValueNode(node->right);
            node->data = tmp->data;
            node->right = deleteNode(node->right, suc, tmp->data, isBlack);
            node->right->parent = node; // fix parent pointer even if it is nil
        }
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
    if (g->right != nil) {
        g->right->parent = g;
    }

    p->parent = g->parent;
    // more check
    if (g->parent == nil) {
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
    if (g->left != nil) {
        g->left->parent = g;
    }

    p->parent = g->parent;
    // more check
    if (p->parent == nil) {
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

Node* RBTree::minValueNode(Node* node) {
    Node* cur = node;

    while (cur->left != nil)
        cur = cur->left;

    return cur;
}

Node* RBTree::newNode(int data) {
    Node* tmp = new Node;
    tmp->left = tmp->right = tmp->parent = nil;
    tmp->data = data;
    tmp->color = RED;

    return tmp;
}

// This function fixes violations caused by BST insertion
void RBTree::insertFix(Node* x) {

    while (x->parent->color == RED) {
        /*
        p means parent of x
        g means grandparent of x
        u means uncle of x
        */
        Node* p = x->parent;
        Node* g = p->parent;

        /* Case A:
           Parent of x is left child of Grand-parent of x */
        if (p == g->left) {
            Node* u = g->right;
            /* Case 1:
               The uncle of x is also red
               Only Recoloring required */
            if (u->color == RED) {
                u->color = p->color = BLACK;
                g->color = RED;
                x = g;
            }
            else {
                /* Case 2:
                   x is right child of its parent
                   Left-rotation required */
                if (x == p->right) {
                    p = leftRotate(p);
                    //g->left = p;
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
            if (u->color == RED) {
                u->color = p->color = BLACK;
                g->color = RED;
                x = g;
            }
            else {
                /* Case 2:
                   x is left child of its parent
                   Right-rotation required */
                if (x == p->left) {
                    p = rightRotate(p);
                    //g->right = p;
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
    root->color = BLACK;
}

void RBTree::deleteFix(Node* cur) {

    while (cur != root && cur->color == BLACK) {
        // Current is leftchild of its parent
        if (cur == cur->parent->left) {
            Node* sibling = cur->parent->right;

            // Case 1: Sibling is red
            if (sibling->color == RED) {
                std::swap(cur->parent->color, sibling->color);
                sibling = leftRotate(cur->parent)->left->right;
            }
            // Case 2: Sibling and its two children are all black
            if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                sibling->color = RED;
                cur = cur->parent;
            }
            // Case 3 & 4: Sibling is black and only one child is black
            else {
                // Case 3: Sibling is black and its left child is red, right child is black
                if (sibling->right->color == BLACK) {
                    std::swap(sibling->color, sibling->left->color);
                    sibling = rightRotate(sibling);
                }
                // Case4: Sibling is black and its right child is red
                sibling->color = cur->parent->color;
                cur->parent->color = sibling->right->color = BLACK;
                cur = leftRotate(cur->parent);
                cur = root;
            }
        }
        // Current is rightchild of its parent
        else {
            Node* sibling = cur->parent->left;

            // Case 1: Sibling is red
            if (sibling->color == RED) {
                std::swap(cur->parent->color, sibling->color);
                sibling = rightRotate(cur->parent)->right->left;
            }
            // Case 2: Sibling and its two children are all black
            if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                sibling->color = RED;
                cur = cur->parent;
            }
            // Case 3 & 4: Sibling is black and only one child is black
            else {
                // Case 3: Sibling is black and its left child is black, right child is red
                if (sibling->left->color == BLACK) {
                    std::swap(sibling->color, sibling->right->color);
                    sibling = leftRotate(sibling);
                }

                // Case4: Sibling is black and its right child is red
                sibling->color = cur->parent->color;
                cur->parent->color = sibling->left->color = BLACK;
                cur = rightRotate(cur->parent);
                cur = root;
            }
        }
    }
    cur->color = BLACK;
}

void RBTree::inOrder(Node* node) {
    if (node != nil) {
        inOrder(node->left);
        std::cout << node->data << "(" << node->color << ") ";
        inOrder(node->right);
    }
}

void RBTree::levelOrder(Node* node) {
    std::queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        std::cout << cur->data << "(" << cur->color << ") ";

        if (cur->left != nil) {
            q.push(cur->left);
        }

        if (cur->right != nil) {
            q.push(cur->right);
        }
    }
}

void RBTree::releaseTree(Node* node) {
    if (node != nil) {
        releaseTree(node->left);
        releaseTree(node->right);
        delete node;
    }
}
