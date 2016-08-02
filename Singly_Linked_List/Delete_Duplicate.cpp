/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* pre = head;
    Node* cur = head->next;
    while(cur != NULL){
        if(pre->data == cur->data){
            cur = cur->next;
            delete pre->next;
            pre->next = cur;
        }
        else{
            cur = cur->next;
            pre = pre->next;
        }
    }
    
    return head;
}
