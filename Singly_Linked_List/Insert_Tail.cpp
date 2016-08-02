/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data){
    if(head == NULL){
        Node* tmp = new Node;
        tmp->data = data;
        tmp->next = NULL;
        head = tmp;
        return head;
    }

    head->next = Insert(head->next, data);

    return head;
}
