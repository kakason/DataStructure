#include "AVLTree.h"
#include "TreeTools.h"
#include <iostream>
#include <algorithm>

AVLTree::AVLTree() {
	//root = new Node();
}

AVLTree::~AVLTree() {
	releaseTree(root);
}

void AVLTree::insertion(int data) {
	if (!root) {
		root = new Node();
		setRoot(data);
	}
	else
		root = insertNode(root, data);
}

void AVLTree::deletion(int data) {
	root = deleteNode(root, data);
}

void AVLTree::print() {
	preOrder(root);
}

void AVLTree::preOrder(Node* node) {
	if (node) {
		std::cout << node->data << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

Node* AVLTree::newNode(int data){
	Node* tmp = new Node;
	tmp->left = tmp->right = nullptr;
	tmp->data = data;
	tmp->ht = 0;

	return tmp;
}

void AVLTree::setRoot(int data) {
	root->left = root->right = nullptr;
	root->data = data;
	root->ht = 0;
}

Node* AVLTree::minValueNode(Node* node) {
	Node* cur = node;
	
	while (cur->left)
		cur = cur->left;

	return cur;
}

Node* AVLTree::insertNode(Node* node, int data) {
	/* 1.  Perform the normal BST insertion */
	if (!node) {
		return newNode(data);
	}

	if (data < node->data) {
		node->left = insertNode(node->left, data);
	}

	else {
		node->right = insertNode(node->right, data);
	}

	/* 2. Update height of this ancestor node */
	node->ht = std::max(height(node->left), height(node->right)) + 1;

	/* 3. Get the balance factor of this ancestor node to check whether
	this node became unbalanced */
	int balance = getBalance(node);

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
	if (balance > 1 && data < node->left->data) {
		return rightRotate(node);
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
	else if (balance > 1 && data > node->left->data) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
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
	if (balance < -1 && data > node->right->data) {
		return leftRotate(node);
	}

	// Right Left Case
	/*
	             z                                 z                                x
				/ \                               / \                             /   \
			   T1  y       Right Rotate (y)      T1   x        Left Rotate(z)    z     y
			      / \          --------->            /  \        -------->      / \   / \
				 x   T4                             T2   y                    T1  T2 T3  T4
				/ \                                     /  \
			  T2   T3                                  T3   T4
	*/
	else if (balance < -1 && data < node->right->data) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Node* AVLTree::deleteNode(Node* node, int data) {
	// STEP 1: PERFORM STANDARD BST DELETE
	if (!node) {
		return node;
	}
		
	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (data < node->data) {
		node->left = deleteNode(node->left, data);
	}

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (data > node->data) {
		node->right = deleteNode(node->right, data);
	}

	// If key is as same as root's key, then this is the node
	// to be deleted
	else {
		// node with only one child or no child
		if (!node->left) {
			Node* tmp = node;
			node = node->right;
			delete tmp;
		}

		else if(!node->right) {
			Node* tmp = node;
			node = node->left;
			delete tmp;
		}

		else {
			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			Node* tmp = minValueNode(node->right);
			node->data = tmp->data;
			node->right = deleteNode(node->right, tmp->data);
		}
	}

	if (!node) {
		return node;
	}
		
	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	node->ht = std::max(height(node->left), height(node->right)) + 1;

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
	//  this node became unbalanced)
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(node->left) >= 0) {
		return rightRotate(node);
	}

	// Left Right Case
	else if (balance > 1 && getBalance(node->left) < 0) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Right Case
	if (balance < -1 && getBalance(node->right) <= 0) {
		return leftRotate(node);
	}

	// Right Left Case
	else if (balance < -1 && getBalance(node->right) > 0) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Node* AVLTree::leftRotate(Node* z) {
	Node* y = z->right;
	Node* T2 = y->left;

	y->left = z;
	z->right = T2;

	z->ht = std::max(height(z->left), height(z->right)) + 1;
	y->ht = std::max(height(y->left), height(y->right)) + 1;

	return y;
}

Node* AVLTree::rightRotate(Node* z) {
	Node* y = z->left;
	Node* T3 = y->right;

	y->right = z;
	z->left = T3;

	z->ht = std::max(height(z->left), height(z->right)) + 1;
	y->ht = std::max(height(y->left), height(y->right)) + 1;

	return y;
}

void AVLTree::releaseTree(Node* node) {
	if (node) {
		releaseTree(node->left);
		releaseTree(node->right);
		delete node;
	}
}

int AVLTree::getBalance(Node* node) {
	if (!node)
		return 0;

	return height(node->left) - height(node->right);
}

int AVLTree::height(Node* node) {
	if (!node) {
		return -1;
	}
		
	return node->ht;
}
