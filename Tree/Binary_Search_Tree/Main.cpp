#include "BSTree.h"
#include <iostream>

int main() {
	BSTree mytree;
	mytree.insertion(12);
	mytree.insertion(10);
	mytree.insertion(20);
	mytree.insertion(9);
	mytree.insertion(11);
	mytree.insertion(10);
	mytree.insertion(12);
	mytree.insertion(12);

	mytree.getMaxDepth();
	mytree.getLCA(9, 20);
	mytree.getAncestors(9);
	mytree.printOrder();

	mytree.deletion(20);
	mytree.getMaxDepth();
	mytree.getLCA(9, 11);
	mytree.getAncestors(9);
	mytree.printOrder();
	
	mytree.deletion(12);
	mytree.getMaxDepth();
	mytree.getLCA(9, 12);
	mytree.getAncestors(9);
	mytree.printOrder();

	mytree.deletion(9);
	mytree.getMaxDepth();
	mytree.getLCA(10, 11);
	mytree.getAncestors(12);
	mytree.printOrder();

	return 0;
}