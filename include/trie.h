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
    void delete_node(node *n);

  public:
    trie();
    ~trie();
    void erase();
    unsigned int size() const;
    bool insert(const std::string key, const unsigned int value);
    bool exists(const std::string key, unsigned int &value) const;
};

#endif