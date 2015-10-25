#include "trie.h"
#include "util.h"
#include <iostream>

trie::trie(): size_(0) {
    root = create_node();
}

trie::~trie() {
  delete_node(root);
}

unsigned int trie::size() const {
  return size_;
}

node *trie::create_node() {
    node *n = new node;
    return n;
}

void trie::delete_node(node *n) {
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (n->next[i] != nullptr) {
      delete_node(n->next[i]);
    }
  }

  delete n;
}

void trie::insert(std::string key, unsigned int value) {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        char k = tolower(key[i]) - 'a';

        if (tmp->next[k] == nullptr) {
            tmp->next[k] = create_node();
        }

        tmp->is_end = false;
        tmp = tmp->next[k];
    }

    tmp->is_terminal = true;
    tmp->is_end = true;
    tmp->value = value;
    size_++;
}

bool trie::exists(std::string key, unsigned int &value) const {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        if (!is_alpha(key[i])) {
            return false;
        }

        char k = tolower(key[i]) - 'a';

        if (tmp->next[k] != nullptr) {
            tmp = tmp->next[k];
        } else {
            return false; // key not found
        }
    }

    if (tmp != nullptr && tmp->is_terminal) {
        value = tmp->value;
        return true;
    }

    return false;
}