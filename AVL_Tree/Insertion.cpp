#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	int height;
	Node* left;
	Node* right;
};

Node* newNode(int);
Node* inSert(Node*, int);
Node* leftRotate(Node*);
Node* rightRotate(Node*);
void preOrder(Node*);
int getBalance(Node*);
int height(Node*);

int main() {
	Node* root = NULL;

	root = inSert(root, 10);
	root = inSert(root, 20);
	root = inSert(root, 30);
	root = inSert(root, 40);
	root = inSert(root, 50);
	root = inSert(root, 25);

	preOrder(root);

	return 0;
}

Node* newNode(int data) {
	Node* tmp = new Node;
	tmp->left = tmp->right = NULL;
	tmp->data = data;
	tmp->height = 0;

	return tmp;
}

Node* inSert(Node* root, int data) {
	/* 1.  Perform the normal BST insertion */
	if (!root)
		return newNode(data);

	if (data < root->data)
		root->left = inSert(root->left, data);
	else
		root->right = inSert(root->right, data);

	/* 2. Update height of this ancestor node */
	root->height = max(height(root->left), height(root->right)) + 1;

	/* 3. Get the balance factor of this ancestor node to check whether
	this node became unbalanced */
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	/*
	               z                                    y
	             /   \                                /   \
	            y     T4      Right Rotate (z)       x     z
	          /   \              --------->        /  \   /  \
	         x     T3                             T1  T2 T3   T4
	       /   \
	     T1    T2
	*/
	if (balance > 1 && data < root->left->data) {
		return rightRotate(root);
	}

	// Left Right Case
	/*
	          z                              z                               x
	         / \                            / \                            /   \
	        y  T4     Left Rotate(y)       x  T4     Right Rotate(z)      y     z
	       / \         --------->         / \          -------->         / \   / \
	      T1  x                          y  T3                         T1  T2 T3  T4
	         / \                        / \
	        T2 T3                      T1 T2
	*/
	if (balance > 1 && data > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	/*
	         z                                       y
	       /   \                                  /    \
	      T1    y           Left Rotate(z)       z      x
	           /  \         ---------->         / \    /  \
	         T2    x                          T1   T2  T3  T4
	              /  \
	             T3   T4
	*/
	if (balance < -1 && data > root->right->data) {
		return leftRotate(root);
	}

	// Right Left Case
	/*
	             z                                 z                                x
	            / \                               / \                             /   \
	          T1   y       Right Rotate (y)      T1   x        Left Rotate(z)    z     y
	              / \          --------->            /  \        -------->      / \   / \
	             x   T4                             T2   y                    T1  T2 T3  T4
	            / \                                     /  \
	          T2   T3                                  T3   T4
	*/
	if (balance < -1 && data < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* leftRotate(Node* z) {
	Node* y = z->right;
	Node* T2 = y->left;

	y->left = z;
	z->right = T2;

	z->height = max(height(z->left), height(z->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

Node* rightRotate(Node* z) {
	Node* y = z->left;
	Node* T3 = y->right;

	y->right = z;
	z->left = T3;

	z->height = max(height(z->left), height(z->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int height(Node* node) {
	if (!node)
		return -1;

	return node->height;
}

int getBalance(Node* node) {
	if (!node)
		return 0;

	return height(node->left) - height(node->right);
}

void preOrder(Node* root) {
	if (root) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
