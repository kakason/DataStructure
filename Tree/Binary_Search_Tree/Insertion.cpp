/*
struct Node {
	int key;
	Node *left, *right;
};
*/
// A utility function to create a new BST node
Node* newNode(int key) {
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}
// A utility function to insert a new node with given key
Node* insert(Node* root, int key) {
	if (!root)
		return newNode(key);

	if (key < root->key)
		root->left = insert(root->left, key);

	else if (key > root->key)
		root->right = insert(root->right, key);

	return root;
}
