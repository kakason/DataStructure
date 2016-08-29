#pragma once
#include "TreeTools.h"
#include <string>
class Trie {
private:
    Node* root;

    Node* getNode();

    void insertNode(std::string);
    void releaseTrie(Node*);

public:
    Trie();
    ~Trie();

    void insertion(std::string);

    bool insertNoPrefix(std::string);
    bool search(std::string);
    int findPrefix(std::string);

};
