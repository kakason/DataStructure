#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

Node* newNode(int);
void getVerticalOrder(Node*, int);
void printVerticalOrder(Node*);

map<int, vector<int>> m;

int main() {
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->right = newNode(7);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	cout << "Vertical order traversal is \n";
	printVerticalOrder(root);

	return 0;
}

Node* newNode(int key) {
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

void getVerticalOrder(Node* root, int hd) {
	if (!root)
		return;

	m[hd].push_back(root->key);
	getVerticalOrder(root->left, hd - 1); // left tree
	getVerticalOrder(root->right, hd + 1); // right tree
}

void printVerticalOrder(Node* root) {
	int hd = 0;

	getVerticalOrder(root, hd);

	map<int, vector<int>>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		for (int i = 0; i < it->second.size(); ++i)
			cout << it->second[i] << " ";
		cout << "\n";
	}
}
