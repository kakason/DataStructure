/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head){
    Node* pre = NULL;
    Node* cur = head;
    Node* nex;

    while(cur){
        nex = cur->next;
        cur->next = pre;
        cur->prev = nex; // this is the difference between SLL and DLL
        pre = cur;
        cur = nex;
    }
    head = pre;

    return head;
}
