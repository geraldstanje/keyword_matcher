#include "trie.h"
#include "util.h"

trie::trie(): size_(0) {
    root = create_node();
}

trie::~trie() {
    erase();
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

void trie::erase() {
    delete_node(root);
    root = nullptr;
    size_ = 0;
}

bool trie::insert(const std::string key, const unsigned int value) {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        char k = 0;

        if (!calc_node_index(key[i], k)) {
            return false;
        }

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
    return true;
}

bool trie::exists_key(std::string::const_iterator begin, std::string::const_iterator end, unsigned int &value) const {
    node *tmp = root;

    for (auto it = begin; it != end; it++) {
        char k = 0;

        if (!calc_node_index(*it, k)) {
            return false;
        }

        if (tmp->next[k] != nullptr) {
            tmp = tmp->next[k];
        } else {
            return false; // key not found
        }
    }

    if (tmp == nullptr) {
        return false;
    }

    if (tmp->is_terminal) {
        value = tmp->value;
        return true;
    }

    // we found the key in the trie but its not a terminal
    value = -1;
    return true;
}