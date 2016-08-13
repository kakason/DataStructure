#include <iostream>
#include "RBTree.h"

int main() {
    RBTree mytree;
    mytree.insertion(7);
    mytree.insertion(3);
    mytree.insertion(18);
    mytree.insertion(10);
    mytree.insertion(22);
    mytree.insertion(8);
    mytree.insertion(11);
    mytree.insertion(26);
    mytree.insertion(2);
    mytree.insertion(6);
    mytree.insertion(13);

    mytree.printOrder();

    return 0;
}
/*
                     10(B)
                 /         \
               7(R)        18(R)
              /    \      /     \
            3(B)   8(B) 11(B)  22(B)
           /   \           \       \
         2(R)  6(R)        13(R)   26(R)
*/