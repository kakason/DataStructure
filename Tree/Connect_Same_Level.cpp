/*
Connect all the adjacent nodes at the same level in a binary tree.
Structure of the given Binary Tree node is like following.
*/
struct node{
  int data;
  struct node* left;
  struct node* right;
  struct node* nextRight;
}

struct Item {
  Node* node;
  int depth;
};

void connect(struct Node *p) {
    p->nextRight = NULL; // root node

    Item* tmp = new Item;
    tmp->node = p;
    tmp->depth = 0;

    queue<Item*> q;
    q.push(tmp);

    Item* pre = NULL;

    while(!q.empty()) {
        Item* cur = q.front();

        if(cur->node != p) {
            if(pre->depth == cur->depth)
                pre->node->nextRight = cur->node;

            else
                pre->node->nextRight = NULL;
        }

        q.pop();

        if(cur->node->left) {
            Item* tmp = new Item;
            tmp->node = cur->node->left;
            tmp->depth = cur->depth + 1;
            q.push(tmp);
        }

        if(cur->node->right) {
            Item* tmp = new Item;
            tmp->node = cur->node->right;
            tmp->depth = cur->depth + 1;
            q.push(tmp);
        }

        pre = cur;
    }

    pre->node->nextRight = NULL;
}
