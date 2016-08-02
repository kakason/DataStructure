/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position){
    if(head == NULL || position == 0){ // empty or in front of the head
        Node* tmp = new Node;
        tmp->data = data;
        tmp->next = head;
        head = tmp;
        return head;
    }

    Node* pre = head;
    for(int i = 1; i < position; i++){
        pre = pre->next;
    }

    Node* cur = new Node;
    cur->data = data;
    cur->next = pre->next;
    pre->next = cur;

    return head;
}
