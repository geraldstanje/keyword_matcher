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

bool trie::insert(std::string key, unsigned int value) {
    node *tmp = root;

    for (int i = 0; i < key.size(); i++) {
        char k = 0;

        if (is_alpha(key[i])) {
            k = tolower(key[i]) - 'a';
        } else {
            auto it = special_chars.find(key[i]);
            if (it != special_chars.end()) {
                k = it->second;
            } else {
                return false;
            }
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