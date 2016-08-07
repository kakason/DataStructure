#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	int depth; // Store each node's depth(level)
	Node* left;
	Node* right;
};

Node* newNode(int,int);
void inOrder(Node*);
void constructTree(Node*, int);
void DFS(Node*, int);

int main() {
	// Once u came up with a method to
	// store the input info or to construct
	// the tree, u might find this problem
	// was not difficult to solve :)

	int N, T, K;

	Node* root = newNode(1, 1); // The root node(1)

	cin >> N;
	constructTree(root, N); // Use BFS to construct the tree

	cin >> T;
	while (T--) {
		cin >> K;
		DFS(root, K); // Use DFS to do the swap operations

		inOrder(root); // Print the tree
		cout << "\n";
	}

	return 0;
}

Node* newNode(int data, int depth) {
	Node* tmp = new Node;
	tmp->left = tmp->right = NULL;
	tmp->data = data;
	tmp->depth = depth;

	return tmp;
}

void inOrder(Node* root) {
	if (root) {
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

void constructTree(Node* root, int N) {
	int tmp_left, tmp_right;

	queue<Node*> q;
	q.push(root);
	for (int i = 0; i < N; i++) {
		Node* cur = q.front();
		q.pop();

		cin >> tmp_left >> tmp_right;
		if (tmp_left != -1) {
			cur->left = newNode(tmp_left, cur->depth + 1);
			q.push(cur->left);
		}

		if (tmp_right != -1) {
			cur->right = newNode(tmp_right, cur->depth + 1);
			q.push(cur->right);
		}
	}
}

void DFS(Node* root, int level) {
	if (root) {
		if (root->depth % level == 0) {
			Node* tmp = root->right;
			root->right = root->left;
			root->left = tmp;
		}

		DFS(root->left, level);
		DFS(root->right, level);
	}
}
