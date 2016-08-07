Node* minValueNode(Node* root) {
	Node* cur = root;

	while (cur->left) {
		cur = cur->left;
	}

	return cur;
}

Node* deleteNode(Node* root, int key) {
	// base case
	if (!root)
		return root;
	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	// If the key to be deleted is greater than the root's key,
  // then it lies in right subtree
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	}
	// if key is same as root's key, then This is the node
  // to be deleted
	else {
		// node with only one child or no child
		if (!root->left) {
			Node* tmp = root->right;
			delete root;
			return tmp;
		}

		else if (!root->right) {
			Node* tmp = root->left;
			delete root;
			return tmp;
		}

		// node with two children:
		// 1. Get the inorder successor (smallest in the right subtree)
		//    or
		// 2. Get the inorder predecessor (largest in the left subtree)
		Node* tmp = minValueNode(root->right);
		root->key = tmp->key;
		root->right = deleteNode(root->right, tmp->key);
	}

	return root;
}
