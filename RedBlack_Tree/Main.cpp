#include <iostream>
#include "RBTree.h"
#include <chrono>

int main() {
    RBTree mytree; // my object

    mytree.insertion(36);
    mytree.insertion(16);
    mytree.insertion(41);
    mytree.insertion(4);
    mytree.insertion(22);
    mytree.insertion(39);
    mytree.insertion(48);
    mytree.insertion(3);
    mytree.insertion(9);
    mytree.insertion(19);
    mytree.insertion(27);
    mytree.insertion(45);
    mytree.insertion(52);
    mytree.insertion(1);
    mytree.insertion(7);
    mytree.insertion(10);
    mytree.insertion(24);
    mytree.insertion(51);
    mytree.insertion(55);

    mytree.deletion(19);
    mytree.deletion(45);
    mytree.deletion(39);
    mytree.deletion(3);
    mytree.deletion(36);
    mytree.deletion(16);
    mytree.deletion(41);

    /*
    //#START --- debug ---
    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;

    t1 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000000; i++) {
        mytree.insertion(i);
    }
    t2 = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << "\n";

    t1 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000000; i++) {
        mytree.deletion(i);
    }
    t2 = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << "\n";
    //#END --- debug ---
    */
    mytree.printOrder();

    return 0;
}
/*
                             48(B)
                       /             \
                    22(B)            52(B)
                  /      \         /      \
               4(R)      24(B)   51(B)    55(B)
              /    \         \
            1(B)   9(B)      27(R)
                  /   \
                7(R)  10(R)
*/
