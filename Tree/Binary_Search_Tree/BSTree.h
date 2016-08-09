#ifndef BSTREE_H  
#define BSTREE_H
#include "TreeTools.h"
#include <map>
#include <vector>

class BSTree {
private:
	Node* root;

	Node* deleteNode(Node*, int);
	Node* insertNode(Node*, int);
	Node* minValueNode(Node*);
	Node* LCA(Node*, int, int);
	Node* newNode(int);

	void findPreSuc(Node*, Node*&, Node*&, int);
	void inOrder(Node*);
	void preOrder(Node*);
	void postOrder(Node*);
	void levelOrder(Node*);
	void verticalOrder();
	void getVerticalOrder(Node*, int, std::map<int, std::vector<int>>&);
	void releaseTree(Node*);

	int maxDepth(Node*);

	bool printAncestors(Node*, int);

public:
	BSTree();
	~BSTree();

	void insertion(int);
	void deletion(int);
	void printOrder();
	void getMaxDepth();
	void getLCA(int, int);
	void getAncestors(int);
};

#endif
