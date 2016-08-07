/*
The trick is to write a utility helper function
isBSTUtil that traverses down the tree keeping track of the narrowing min and
max allowed values as it goes, looking at each node only once. The initial values
for min and max should be INT_MIN and INT_MAX — they narrow from there.
*/
#define MAX 1e9
#define MIN -1e9
bool isBSTUtil(Node* root, int min, int max) {
			 if(!root)
					 return true;

			 if(root->data > max || root->data < min)
					 return false;

			 return isBSTUtil(root->left, min, root->data - 1) &&
							isBSTUtil(root->right, root->data + 1, max);
	 }

 bool checkBST(Node* root) {
			 return isBSTUtil(root, MIN, MAX);
 }

/*
Using In-Order Traversal
1) Do In-Order Traversal of the given tree and store the result in a temp array.
2) Check if the temp array is sorted in ascending order, if it is, then the tree
   is BST.
Time Complexity: O(n)

We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can
keep track of previously visited node. If the value of the currently visited
node is less than the previous value, then tree is not BST.
*/
Node* pre = NULL;

bool checkBST(Node* root) {
      if(root){
          if(!checkBST(root->left))
              return false;

          if(pre && root->data <= pre->data)
              return false;

          pre = root;

          return checkBST(root->right);
      }

      return true;
}
