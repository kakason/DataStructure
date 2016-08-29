#include "Trie.h"
#include <iostream>

int main() {
    Trie mytrie;

    mytrie.insertion("by");
    mytrie.insertion("bye");
    mytrie.insertion("the");
    mytrie.insertion("there");
    mytrie.insertion("their");
    mytrie.insertion("a");
    mytrie.insertion("any");
    mytrie.insertion("answer");
    /*
    std::cout << mytrie.search("b") << "\n";
    std::cout << mytrie.search("by") << "\n";
    std::cout << mytrie.search("bye") << "\n";
    std::cout << mytrie.search("byek") << "\n";

    std::cout << mytrie.findPrefix("b") << "\n";
    std::cout << mytrie.findPrefix("bye") << "\n";

    std::cout << mytrie.findPrefix("t") << "\n";
    std::cout << mytrie.findPrefix("the") << "\n";
    std::cout << mytrie.findPrefix("thereu") << "\n";
    */
    return 0;
}
