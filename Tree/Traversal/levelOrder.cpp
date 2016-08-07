#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

Node* newNode(int);
void LevelOrder(Node*);

int main() {
	Node *root = newNode(3);
	root->left = newNode(5);
	root->right = newNode(2);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->left->right = newNode(9);
	root->left->left->right->left = newNode(10);
	root->left->left->right->left->left = newNode(11);
	cout << "LevelOrder is \n";

	LevelOrder(root);

	return 0;
}

Node* newNode(int key) {
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

void LevelOrder(Node* root) {
	// Simply just use BFS
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();

		cout << cur->key << " ";

		if (cur->left) {
			q.push(cur->left);
		}

		if (cur->right) {
			q.push(cur->right);
		}
	}
}
