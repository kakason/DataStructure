/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if
the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <unordered_map> // Hash Table
bool has_cycle(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    unordered_map<Node*, int> Vis;
    Vis.clear();

    while(head){
        if(Vis.find(head) == Vis.end()){
            Vis.insert(make_pair(head, Vis.size()));
            head = head->next;
        }
        else{
            return true;
        }
    }

    return false;
}
