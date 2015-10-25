#include "trie.h"
#include "util.h"
#include <iostream>
#include <cassert>
#include <cstdint>

trie::trie(): size_(0) {
    root = create_node();
    iter = nullptr;
}

trie::~trie() {
    erase();
}

uint16_t trie::size() const {
    return size_;
}

node *trie::create_node() {
    node *n = new node;
    return n;
}

void trie::delete_node(node *n) {
    for (uint16_t i = 0; i < ALPHABET_SIZE; i++) {
        if (n->next[i] != nullptr) {
            delete_node(n->next[i]);
        }
    }

    delete n;
}

void trie::erase() {
    delete_node(root);
    root = nullptr;
    iter = nullptr;
    size_ = 0;
}

bool trie::insert(const std::string key, const int16_t value) {
    node *tmp = root;

    for (uint16_t i = 0; i < key.size(); i++) {
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
    iter_begin();
    return true;
}

void trie::iter_begin() {
    iter = root;
}

bool trie::exists_key(std::string::const_iterator begin, std::string::const_iterator end, int16_t &value) {
    if (iter == nullptr) {
        return false;
    }

    for (auto it = begin; it != end; it++) {
        char k = 0;

        if (!calc_node_index(*it, k)) {
            iter_begin();
            return false;
        }

        if (iter->next[k] != nullptr) {
            iter = iter->next[k];
        } else {
            iter_begin();
            return false; // key not found
        }
    }

    if (iter == nullptr) {
        iter_begin();
        return false;
    }

    if (iter->is_terminal) {
        value = iter->value;
        return true;
    }

    // we found the key in the trie but its not a terminal
    value = -1;
    return true;
}