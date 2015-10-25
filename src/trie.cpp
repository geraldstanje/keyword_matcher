#include "trie.h"

trie::trie() {
    root = create_node();
}

trie::~trie() {
    delete root;
}

node *trie::create_node() {
    node *n = new node;
    return n;
}

bool trie::is_terminal(node *n) {
  if (!n) {
    return false;
  }

  return n->is_end;
}

void trie::add(std::string key) {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        char k = tolower(key[i]) - 'a';

        if (!tmp->next[k]) {
            tmp->next[k] = create_node();
        }

        tmp->is_end = false;
        tmp = tmp->next[k];
    }

    tmp->is_end = true;
}

bool trie::exists(std::string key) {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        char k = tolower(key[i]) - 'a';

        if (tmp->next[k]) {
            tmp = tmp->next[k];
        } else {
            return false; // key not found
        }

        if (is_terminal(tmp)) {
          return true;
        }
    }

    return false;
}