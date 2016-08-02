/*
    Insert Node in a doubly sorted linked list
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node* head, int data){
    Node* tmp = new Node; // the new node being inserted
    tmp->data = data;

    if(!head){ // if the list is empty
        tmp->prev = NULL;
        tmp->next = NULL;

        return tmp;
    }
    
    if(head->data <= data){ // if the node being inserted is larger than current node
        head->next = SortedInsert(head->next, data);
        head->next->prev = head; // prevent the largest data from lost
    }
    else{
        tmp->next = head;
        head->prev = tmp;// prevent the smallest data from lost
        tmp->prev = head->prev;
        head = tmp;
    }

    return head;
}
