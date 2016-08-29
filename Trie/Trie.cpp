#include "Trie.h"
#include "TreeTools.h"

Trie::Trie() {
    root = getNode();
}

Trie::~Trie() {
    releaseTrie(root);
}

Node* Trie::getNode() {
    Node* tmpNode = new Node;

    tmpNode->count = 0;
    tmpNode->isLeaf = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        tmpNode->children[i] = nullptr;

    return tmpNode;
}

void Trie::insertNode(std::string key) {
    int index;

    Node* cur = root;

    for (int i = 0; i < (int)key.length(); i++) {
        index = key[i] - 'a';

        if (!cur->children[index])
            cur->children[index] = getNode();

        cur = cur->children[index];
        cur->count++;
    }
    cur->isLeaf = true;
}

void Trie::releaseTrie(Node* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i])
            releaseTrie(node->children[i]);

    delete node;
}

bool Trie::search(std::string key) {
    int index;

    Node* cur = root;

    for (int i = 0; i < (int)key.length(); i++) {
        index = key[i] - 'a';

        if (!cur->children[index])
            return false;

        cur = cur->children[index];
    }

    return cur && cur->isLeaf;
}

int Trie::findPrefix(std::string key) {
    int index;

    Node* cur = root;

    for (int i = 0; i < (int)key.length(); i++) {
        index = key[i] - 'a';

        if (!cur->children[index])
            return 0;

        cur = cur->children[index];
    }

    return cur->count;
}

void Trie::insertion(std::string key) {
    insertNode(key);
}

// Insert with conditions that "no string is prefix of another string"
// Return true if the key is valid
// Return false if the key is prefix of another key
bool Trie::insertNoPrefix(std::string key) {
    int index;

    Node* cur = root;

    for (int i = 0; i < (int)key.length(); i++) {
        index = key[i] - 'a';

        // Case 1: Unique key
        if (!cur->children[index]) {
            cur->children[index] = getNode();
        }
        // Case 2-A:
        // e.g. Keys which have already existed {"aa", "ade"} and
        //      we want to insert{"a"}
        else if (cur->children[index] && i == key.length() - 1) {
            return false;
        }
        // Case 2-B:
        // e.g. Keys which have already existed {"a", "ade"} and
        //      we want to insert{"ab"}
        else if (cur->children[index] && cur->children[index]->isLeaf) {
            return false;
        }

        cur = cur->children[index];
        cur->count++;
    }
    cur->isLeaf = true;
}
