/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head){
    // Iterative Method
    Node* pre = NULL;
    Node* cur = head;
    Node* nex;

    while(cur != NULL){
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    head = pre;

    return head;

    // Recursive Method
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rest = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}
