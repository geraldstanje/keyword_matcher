#ifndef NODE_H
#define NODE_H

#include <unordered_map>

const int ALPHABET_SIZE = 28;

class node {
  public:
    unsigned int value;
    node *next[ALPHABET_SIZE];
    bool is_terminal;
    bool is_end;
    node(): value(0), is_terminal(false), is_end(false) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            next[i] = nullptr;
        }
    }
};

const std::unordered_map<char, char> special_chars = {{'_', 26},
    {'-', 27}
};

#endif