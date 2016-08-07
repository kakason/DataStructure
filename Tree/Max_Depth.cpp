
/*The tree node has data, left child and right child
struct node
{
    int data;
    node* left;
    node* right;
};

*/
int height(node * root){
    int maxDepth = -1;

    if(root){
        maxDepth = max(height(root->left),
                       height(root->right))
                       + 1;
    }

    return maxDepth;
}
