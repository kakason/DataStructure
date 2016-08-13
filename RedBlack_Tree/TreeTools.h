#ifndef TREETOOLS_H
#define TREETOOLS_H

struct Node {
	int data;
	char color;
	Node* left;
	Node* right;
	Node* parent;
};

#endif