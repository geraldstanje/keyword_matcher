#include "trie.h"
#include "util.h"
#include <iostream>
#include <cassert>
#include <cstdint>

trie::trie(): size_(0) {
    root_ = create_node();
    iter_ = nullptr;
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
        if (n->next_[i] != nullptr) {
            delete_node(n->next_[i]);
        }
    }

    delete n;
}

void trie::erase() {
    delete_node(root_);
    root_ = nullptr;
    iter_ = nullptr;
    size_ = 0;
}

bool trie::insert(const std::string key, const int16_t value) {
    node *tmp = root_;

    for (uint16_t i = 0; i < key.size(); i++) {
        char k = 0;

        if (!calc_node_index(key[i], k)) {
            return false;
        }

        if (tmp->next_[k] == nullptr) {
            tmp->next_[k] = create_node();
        }

        tmp->is_end_ = false;
        tmp = tmp->next_[k];
    }

    tmp->is_terminal_ = true;
    tmp->is_end_ = true;
    tmp->value_ = value;
    size_++;
    iter_begin();
    return true;
}

void trie::iter_begin() {
    iter_ = root_;
}

bool trie::exists_key(std::string::const_iterator begin, std::string::const_iterator end, int16_t &value) {
    if (iter_ == nullptr) {
        return false;
    }

    for (auto it = begin; it != end; it++) {
        char k = 0;

        if (!calc_node_index(*it, k)) {
            iter_begin();
            return false;
        }

        if (iter_->next_[k] != nullptr) {
            iter_ = iter_->next_[k];
        } else {
            iter_begin();
            return false; // key not found
        }
    }

    if (iter_ == nullptr) {
        iter_begin();
        return false;
    }
    else if (iter_->is_terminal_) {
        value = iter_->value_;
        return true;
    }

    // we found the key in the trie but its not a terminal
    value = -1;
    return true;
}