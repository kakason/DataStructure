#include "BinomialHeap.h"
#include <queue>
#include <iostream>

#define notExist 1000000000

BinomialHeap::BinomialHeap() {
    head = nullptr;
}

/*BinomialHeap::BinomialHeap(Node* tmp) {
    head = tmp;
}*/

BinomialHeap::~BinomialHeap() {
    clearTree();
}

int BinomialHeap::getMin() {
    if (!head)
        return notExist;

    Node* min = head;
    Node* nex = min->sibling;
    while (nex) {
        if (nex->key < min->key )
            min = nex;
        
        nex = nex->sibling;
    }

    return min->key;
}

void BinomialHeap::insertion(int key) {
    Node* tmpNode = newNode(key);
    insertNode(tmpNode);
}

void BinomialHeap::deletion(int key) {
    Node* result = search(key);
    if (result)
        deleteNode(result);
    else
        std::cout << "Binomial heap doesn't contain " << key << "\n";
}

void BinomialHeap::extractMin() {
    if (!head)
        return;

    Node* min = head;
    Node* minPre = nullptr;
    Node* nex = min->sibling;
    Node* nexPre = min;

    while (nex) {
        if (nex->key < min->key) {
            min = nex;
            minPre = nexPre;
        }
        nexPre = nex;
        nex = nex->sibling;
    }

    if (min == head)
        head = head->sibling;
    else
        minPre->sibling = min->sibling;

    removeTreeRoot(min);
}

void BinomialHeap::decreaseKey(int key, int newkey) {
    Node* target = search(key);
    decreaseNode(target, newkey);
}

// Reduces the specified node¡¦s key and then bubbles 
// it up through its ancestors until the tree meets 
// the conditions of a heap.
void BinomialHeap::decreaseNode(Node* cur, int newKey) {
    cur->key = newKey;
    Node* parent = cur->parent;

    while (parent && parent->key > cur->key) {
        std::swap(parent->key, cur->key);
        cur = parent;
        parent = parent->parent;
    }
}

void BinomialHeap::clearTree() {
    // Current binomial heap is already empty
    // which is caused by deletion
    if (!head)
        return;

    std::queue<Node*> q;
    q.push(head);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (cur->sibling)
            q.push(cur->sibling);

        if (cur->child)
            q.push(cur->child);

        delete cur;
    }
}

/*void BinomialHeap::print() {

}*/

Node* BinomialHeap::unionTree(Node* newHead) {
    if (!newHead)
        return nullptr;

    Node* pre = nullptr;
    Node* cur = newHead;
    Node* nex = cur->sibling;

    while (nex) {
        /* Case 1: Order of cur and nex are not same, we simply move ahead */
        /* Case 2: Order of cur and nex are same and 
                   order of nex->sibling is also same, move ahead */
        if (cur->degree != nex->degree ||
            (nex->sibling && nex->sibling->degree == cur->degree)) {
            pre = cur;
            cur = nex;
        }
        
        /* Case 3: If key of cur is greater than or equal to key
                   of nex, make nex as a child of cur */
        else if (cur->key <= nex->key) {
            cur->sibling = nex->sibling;
            linkTree(cur, nex);
        }

        /* Case 4: If key of cur is smaller than key of nex,
                   make cur as a child of nex */
        else {
            if (!pre)
                newHead = nex;
            else
                pre->sibling = nex;

            linkTree(nex, cur);
            cur = nex;
        }

        nex = cur->sibling;
    }

    return newHead;
}

// Merge the two heaps together by continually linking trees of 
// the same order until no two trees of the same order exist
Node* BinomialHeap::mergeTree(Node* oldHead, Node* newHead) {
    if (!oldHead)
        return newHead;

    else if (!newHead)
        return oldHead;

    else {
        Node* tmpHead;
        Node* oldHeadNext = oldHead;
        Node* newHeadNext = newHead;

        if (oldHead->degree <= newHead->degree) {
            tmpHead = oldHead;
            oldHeadNext = oldHeadNext->sibling;
        }
        else {
            tmpHead = newHead;
            newHeadNext = newHeadNext->sibling;
        }

        Node* tail = tmpHead;

        while (oldHeadNext && newHeadNext) {
            if (oldHeadNext->degree <= newHeadNext->degree) {
                tail->sibling = oldHeadNext;
                oldHeadNext = oldHeadNext->sibling;
            }
            else {
                tail->sibling = newHeadNext;
                newHeadNext = newHeadNext->sibling;
            }

            tail = tail->sibling;
        }

        if (oldHeadNext)
            tail->sibling = oldHeadNext;
        else
            tail->sibling = newHeadNext;

        return tmpHead;
    } 
}

Node* BinomialHeap::newNode(int key) {
    Node* tmp = new Node();
    tmp->key = key;
    tmp->degree = 0;
    tmp->parent = nullptr;
    tmp->child = nullptr;
    tmp->sibling = nullptr;

    return tmp;
}

// Breadth first search
Node* BinomialHeap::search(int key) {
    /*
    Special Case: 
    Binomial heap is empty and you still
    want to delete something
    */
    if (!head)
        return nullptr;

    std::queue<Node*> q;
    q.push(head);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (cur->key == key)
            return cur;

        if (cur->sibling)
            q.push(cur->sibling);

        if (cur->child)
            q.push(cur->child);
    }

    return nullptr;
}

void BinomialHeap::linkTree(Node* minNodeTree, Node* other) {
    other->parent = minNodeTree;
    other->sibling = minNodeTree->child;
    minNodeTree->child = other;
    minNodeTree->degree++;
}

void BinomialHeap::removeTreeRoot(Node* cur) {
    Node* tmpHead = nullptr;
    Node* child = cur->child;
    delete cur;

    // The fragments of the old tree are reversed
    // and linked together to form a new heap
    while (child) {
        Node* nex = child->sibling;
        child->sibling = tmpHead;
        child->parent = nullptr;
        tmpHead = child;
        child = nex;
    }

    //BinomialHeap tmpHeap(tmpHead);

    Node* newHead = mergeTree(head, tmpHead);
    head = unionTree(newHead);
}

void BinomialHeap::insertNode(Node* tmpNode) {
    //BinomialHeap tmpHeap(tmpNode);
    
    Node* newHead = mergeTree(head, tmpNode);
    head = unionTree(newHead);
}

void BinomialHeap::deleteNode(Node* cur) {
    // Pulls the node to the top of the tree,
    // i.e. bubble it up
    Node* parent = cur->parent;
    while (parent) {
        std::swap(cur->key, parent->key);
        cur = parent;
        parent = parent->parent;
    }

    // The node is detached from the rest of the heap and being removed
    if (head == cur)
        head = head->sibling;
    else {
        Node* pre = head;
        while (pre->sibling != cur)
            pre = pre->sibling;

        pre->sibling = cur->sibling;
    }

    removeTreeRoot(cur);
}

