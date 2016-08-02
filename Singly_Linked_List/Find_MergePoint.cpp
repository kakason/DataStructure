/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
#include <unordered_map>
int FindMergeNode(Node *headA, Node *headB){
    unordered_map<Node*, int> Merge; // Hash Table

    while(headA){
        Merge.insert(make_pair(headA, Merge.size()));
        headA = headA->next;
    }

    while(headB){
        if(Merge.find(headB) != Merge.end()){
            return headB->data;
        }
        headB = headB->next;
    }

    return 0;
}
