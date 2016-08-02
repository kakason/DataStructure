/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position){
    if(head == NULL){
        return head;
    }

    Node* pre = head;

    if(position == 0){
        head = head->next;
        delete pre;
        return head;
    }

    for(int i = 1; i < position; i++){
        pre = pre->next;
    }

    Node* nex = pre->next->next;
    delete pre->next;
    pre->next = nex;

    return head;
}
