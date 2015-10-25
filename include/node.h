#ifndef NODE_H
#define NODE_H

const int ALPHABET_SIZE = 26;

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

#endif