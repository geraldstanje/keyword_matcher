#include "trie.h"
#include "util.h"
#include <iostream>

trie::trie() {
    root = create_node();
}

trie::~trie() {
    delete root; // todo: delete all nodes in the trie
}

node *trie::create_node() {
    node *n = new node;
    return n;
}

void trie::add(std::string key, unsigned int value) {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        char k = tolower(key[i]) - 'a';

        if (!tmp->next[k]) {
            tmp->next[k] = create_node();
        }

        tmp->is_end = false;
        tmp = tmp->next[k];
    }

    tmp->is_terminal = true;
    tmp->is_end = true;
    tmp->value = value;
}

bool trie::exists(std::string key, unsigned int &value) {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        if (!is_alpha(key[i])) {
            return false;
        }

        char k = tolower(key[i]) - 'a';

        if (tmp->next[k]) {
            tmp = tmp->next[k];
        } else {
            return false; // key not found
        }
    }

    if (tmp && tmp->is_terminal) {
        value = tmp->value;
        return true;
    }

    return false;
}