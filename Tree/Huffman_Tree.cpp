#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
	int fre;
	char data;
	Node* left;
	Node* right;
};

struct Item {
	int fre;
	char data;
	string secret;
};

void Traversal(Node*, string);
void Encryption(int);
void StoreInput(int);
bool Cmp(Node*, Node*);

vector<Node*> vec;
vector<Item> input;
unordered_map<char, int> id;

int main() {
	int N;
	cout << "How many characters do you want to encode?\n";
	cin >> N;
	cout << "\nPlease enter a space between each characters and its frequency\n";

	StoreInput(N);
	Encryption(N);

	cout << "\n------------Huffman Code----------------\n";
	for (int i = 0; i < N; i++) {
		cout << "Letter: " << input[i].data << " "
			<< "Frequency: " << input[i].fre << " "
			<< "Encryption: " << input[i].secret << "\n\n";
	}

	return 0;
}

void StoreInput(int n) {
	id.clear();
	vec.clear();
	input.clear();
	vec.reserve(n);
	input.reserve(n);

	for (int i = 0; i < n; i++) {
		Node* tmp = new Node;
		cin >> tmp->data >> tmp->fre;
		tmp->left = tmp->right = NULL;
		vec.push_back(tmp);

		Item item;
		item.data = tmp->data;
		item.fre = tmp->fre;
		input.push_back(item);

		id.insert(make_pair(item.data, i));
	}
}

void Traversal(Node* root, string s) {
	if (!root)
		return;

	if (!root->left && !root->right)
		input[id[root->data]].secret = s;

	Traversal(root->left, s + "0");
	Traversal(root->right, s + "1");
}

void Encryption(int n) {
	// Construct the huffman tree
	//
	// After following operations, 
	// vec will only contain the "root" node 
	for (int i = 0; i < n - 1; i++) {
		sort(vec.begin(), vec.end(), Cmp);

		int fre = vec[0]->fre + vec[1]->fre;
		Node* tmp = new Node;
		tmp->fre = fre;
		tmp->data = '\0';
		tmp->left = vec[0];
		tmp->right = vec[1];

		vec.erase(vec.begin());
		vec.erase(vec.begin());
		vec.push_back(tmp);
	}

	// Traverse the tree from the root
	Traversal(vec[0], "");
}

bool Cmp(Node* a, Node* b) {
	return a->fre < b->fre;
}
/*
Sample Input:
9
a 3
b 2
c 1
d 6
e 5
f 2
g 6
h 4
i 3

Sample Output:
( Based on your implementation of huffman tree,
  the answer may be different. )

a: 1101
b: 0111
c: 0110
d: 111
e: 101
f: 1100
g: 00
h: 100
i: 010
*/