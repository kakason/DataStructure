Node* LCA(Node* root, int n1, int n2) {
	// Just recursively traverse the BST in, if node’s value
	// is greater than both n1 and n2 then our LCA lies in left
	// side of the node, if it’s is smaller than both n1 and n2,
	// then LCA lies on right side. Otherwise root is LCA(assuming
	// that both n1 and n2 are present in BST)
	if (!root)
		return NULL;

	if (root->key < n1 && root->key < n2) {
		return LCA(root->right, n1, n2);
	}
	else if (root->key > n1 && root->key > n2) {
		return LCA(root->left, n1, n2);
	}

	return root;
}
