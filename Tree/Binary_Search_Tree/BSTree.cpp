#include "BSTree.h"
#include "TreeTools.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

BSTree::BSTree() {
    //root = new Node();
}

BSTree::~BSTree() {
    releaseTree(root);
}

void BSTree::insertion(int data) {
    if (!root) {
        root = new Node();
        root->data = data;
        root->count = 1;
        root->left = root->right = nullptr;
    }
    else
        root = insertNode(root, data);
}

void BSTree::deletion(int data) {
    root = deleteNode(root, data);
}

void BSTree::getMaxDepth() {
    std::cout << "MaxDepth of the tree: " << maxDepth(root) << "\n";
}

void BSTree::getLCA(int n1, int n2) {
    std::cout << "LCA of " << n1 << " and " << n2 << ": "
        << LCA(root, n1, n2)->data << "\n";
}

void BSTree::getAncestors(int n1) {
    std::cout << "Ancestors of node " << n1 << ": ";
    printAncestors(root, n1);
    std::cout << "\n";
}

void BSTree::printOrder() {
    std::cout << "inOrder: ";
    inOrder(root);
    std::cout << "\npreOrder: ";
    preOrder(root);
    std::cout << "\npostOrder: ";
    postOrder(root);
    std::cout << "\nlevelOrder: ";
    levelOrder(root);
    std::cout << "\nverticalOrder:\n";
    verticalOrder();
    std::cout << "\n";
}

void BSTree::verticalOrder() {
    // Create a map and store vertical order in map using
    // function getverticalOrder()
    std::map<int, std::vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);

    std::map<int, std::vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < (int)it->second.size(); i++)
            std::cout << it->second[i] << " ";
        std::cout << "\n";
    }
}

void BSTree::releaseTree(Node* node) {
    if (node) {
        releaseTree(node->left);
        releaseTree(node->right);
        delete node;
    }
}

Node* BSTree::deleteNode(Node* node, int data) {
    if (!node)
        return node;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    }

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    }

    // If key is same as root's key
    else {
        // If the key is present more than once, simply decrement
        // count and return
        if (node->count > 1) {
            node->count -= 1;
            return node;
        }

        if (!node->left) {
            Node* tmp = node;
            node = node->right;
            delete tmp;
            return node;
        }

        else if (!node->right) {
            Node* tmp = node;
            node = node->left;
            delete tmp;
            return node;
        }

        // node with two children:
        // 1. Get the inorder successor (smallest in the right subtree)
        //    or
        // 2. Get the inorder predecessor (largest in the left subtree)
        Node* tmp = minValueNode(node->right);
        node->data = tmp->data;
        node->right = deleteNode(node->right, tmp->data);
    }

    return node;
}

Node* BSTree::insertNode(Node* node, int data) {
    // If the tree is empty, return a new node
    if (!node)
        return newNode(data);

    // If key already exists in BST, icnrement count and return
    if (data == node->data) {
        node->count += 1;
        return node;
    }

    if (data < node->data)
        node->left = insertNode(node->left, data);

    else if (data > node->data)
        node->right = insertNode(node->right, data);

    return node;
}

Node* BSTree::minValueNode(Node* node) {
    Node* cur = node;

    if (cur->left)
        cur = cur->left;

    return cur;
}

Node* BSTree::LCA(Node* node, int n1, int n2) {
    // Just recursively traverse the BST in, if node��s value
    // is greater than both n1 and n2 then our LCA lies in left
    // side of the node, if it��s is smaller than both n1 and n2,
    // then LCA lies on right side. Otherwise root is LCA(assuming
    // that both n1 and n2 are present in BST)
    if (!node)
        return node;

    if (node->data < n1 && node->data < n2) {
        return LCA(node->right, n1, n2);
    }

    else if (node->data > n1 && node->data > n2) {
        return LCA(node->left, n1, n2);
    }

    return node;
}

Node* BSTree::newNode(int data) {
    Node* tmp = new Node;
    tmp->left = tmp->right = nullptr;
    tmp->data = data;
    tmp->count = 1;

    return tmp;
}

void BSTree::findPreSuc(Node* node, Node*& pre, Node*& suc, int data) {
    if (!node)
        return;

    if (node->data == data) {
        if (node->left) {
            Node* tmp = node->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        if (node->right) {
            Node* tmp = node->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }

        return;
    }

    if (node->data < data) {
        pre = node;
        findPreSuc(node->right, pre, suc, data);
    }

    else if (node->data > data) {
        suc = node;
        findPreSuc(node->left, pre, suc, data);
    }
}

void BSTree::inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        std::cout << node->data << "(" << node->count << ") ";
        inOrder(node->right);
    }
}

void BSTree::preOrder(Node* node) {
    if (node) {
        std::cout << node->data << "(" << node->count << ") ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BSTree::postOrder(Node* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << "(" << node->count << ") ";
    }
}

void BSTree::levelOrder(Node* node) {
    std::queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        std::cout << cur->data << "(" << cur->count << ") ";

        if (cur->left) {
            q.push(cur->left);
        }

        if (cur->right) {
            q.push(cur->right);
        }
    }
}

void BSTree::getVerticalOrder(Node* node, int hd, std::map<int, std::vector<int>> &m) {
    if (!node)
        return;

    m[hd].push_back(node->data);

    getVerticalOrder(node->left, hd - 1, m);
    getVerticalOrder(node->right, hd + 1, m);
}

int BSTree::maxDepth(Node* node) {
    int depth = -1;

    if (node) {
        depth = std::max(maxDepth(node->left), maxDepth(node->right)) + 1;
    }

    return depth;
}

bool BSTree::printAncestors(Node* node, int data) {
    /* If target is present in tree, then prints the ancestors
    and returns true, otherwise returns false. */

    if (!node) {
        return false;
    }

    if (node->data == data)
        return true;

    /* If target is present in either left or right subtree of this node,
    then print this node */
    if (printAncestors(node->left, data) || printAncestors(node->right, data)) {
        std::cout << node->data << " ";
        return true;
    }

    /* Else return false */
    return false;
}
