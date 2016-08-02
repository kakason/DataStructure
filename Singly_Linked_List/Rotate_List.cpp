// This function rotates a linked list counter-clockwise and
// updates the head. The function assumes that k is smaller
// than size of linked list. It doesn't modify the list if
// k is greater than or equal to size
void rotate(struct node* head, int k){
  if(k == 0)
    return;

  struct node* cur = head;

  for(int i = 1;i < k && cur; i++)
    cur = cur->next;

  if(!cur)
    return;

  struct node* kthnode = cur;

  while(cur->next)
    cur = cur->next;

  cur->next = head;
  head = kthnode->next;
  kthnode->next = NULL;

  return;
}
