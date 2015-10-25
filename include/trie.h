#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include <string>

class trie {
  private:
    node *root;

  private:
    node *create_node();

  public:
    trie();
    ~trie();
    void add(std::string key, unsigned int value);
    bool exists(std::string key, unsigned int &value);
};

#endif