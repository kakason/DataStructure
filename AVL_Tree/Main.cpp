#include "AVLTree.h"
#include <iostream>

int main() {
    AVLTree mytree; // my object

    for (int i = 10; i > 0; i--) {
        mytree.insertion(i);
    }
    
    std::cout << "Pre order traversal of the constructed AVL tree is\n";
    mytree.print();

    mytree.deletion(9);
    std::cout << "\nPre order traversal after deletion is\n";
    mytree.print();

    return 0;
}
