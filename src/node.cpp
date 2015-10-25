#include "node.h"
#include "util.h"
#include <iostream>
#include <cstdint>

node::node(): value(0), is_terminal(false), is_end(false) {
    for (uint16_t i = 0; i < ALPHABET_SIZE; i++) {
        next[i] = nullptr;
    }
}

bool calc_node_index(const char &key, char &index) {
    if (is_alpha(key)) {
        index = tolower(key) - 'a';
    } else {
        auto it = special_chars.find(key);
        if (it != special_chars.end()) {
            index = it->second;
        } else {
            return false;
        }
    }

    return true;
}