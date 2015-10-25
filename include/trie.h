#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include <string>

class trie {
  private:
    node *root;
    unsigned int size_;

  private:
    node *create_node();

  public:
    trie();
    ~trie();
    void delete_node(node *n);
    unsigned int size() const;
    void insert(std::string key, unsigned int value);
    bool exists(std::string key, unsigned int &value) const;
};

#endif