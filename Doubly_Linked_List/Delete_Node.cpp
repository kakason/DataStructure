/*
  struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
/* Function to delete a node in a Doubly Linked List.*/
void deleteNode(Node* head, Node* del){
  /* base case */
  if(!head || !del)
    return;

  /* If node to be deleted is head node */
  if(head == del)
    head = del->next;

  /* Change next only if node to be deleted is NOT the last node */
  if(!del->next)
    del->next->prev = del->prev;

  /* Change prev only if node to be deleted is NOT the first node */
  if(!del->prev)
    del->prev->next = del->next;

  /* Finally, free the memory occupied by del*/
  delete(del);
  return;
}
