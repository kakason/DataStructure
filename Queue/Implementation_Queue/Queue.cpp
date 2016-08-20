#include <iostream>
#include "Queue.h"

Queue::Queue() {
    head = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    while (head) {
        Node* cur = head;
        head = head->next;
        delete cur;
    }
}

Node* Queue::newNode(int data) {
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = nullptr;

    return tmp;
}

void Queue::push(int data) {
    if (!head) {
        rear = newNode(data);
        head = rear;
    }
    else {
        rear->next = newNode(data);
        rear = rear->next;
    }
}

void Queue::pop() {
    if (!head)
        std::cout << "The queue is empty, can't pop out anything\n";

    else if (head == rear) {
        //std::cout << "Pop " << head->data << " out of the queue\n";
        delete head;
        head = rear = nullptr;
    }

    else if (head != rear) {
        Node* cur = head;
        head = head->next;
        //std::cout << cur->data << "\n";
        delete cur;
    }
}

void Queue::size() {
    int ans = 0;
    Node* cur = head;
    while (cur) {
        cur = cur->next;
        ans++;
    }

    std::cout << "The size of the queue is " << ans << "\n";
}

void Queue::print() {
    if(!head)
        std::cout << "The queue is empty, can't print anything\n";

    else {
        std::cout << "The queue contains ";
        Node* cur = head;
        while (cur) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
}
