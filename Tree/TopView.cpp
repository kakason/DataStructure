#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

struct Item {
	Node* node;
	int hd;
};

map<int, int> m;

Node* newNode(int);
void BFS(Node*, int);
void printTopView(Node*);

int main() {
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << "TopView is \n";
	printTopView(root);

	return 0;
}

Node* newNode(int key) {
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

void BFS(Node* root, int hd) {
	Item* src = new Item;
	src->node = root;
	src->hd = 0;

	queue<Item*> q;
	q.push(src);
	while (!q.empty()) {
		Item* cur = q.front();
		q.pop();

		// If current node's distance is not found
		if (m.find(cur->hd) == m.end()) {
			m.insert(make_pair(cur->hd, cur->node->key));
		}
		// If current node has a left child
		if (cur->node->left) {
			Item* left = new Item;
			left->hd = cur->hd - 1;
			left->node = cur->node->left;
			q.push(left);
		}
		// If current node has a right child
		if (cur->node->right) {
			Item* right = new Item;
			right->hd = cur->hd + 1;
			right->node = cur->node->right;
			q.push(right);
		}
	}
}

void printTopView(Node* root) {
	BFS(root, 0); // Do BFS(or levelOrder traversal) to construct the map

	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		cout << it->second << " ";
	}
}
