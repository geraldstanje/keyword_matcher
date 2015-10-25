#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include <string>

class trie {
  private:
    node *root;
    node *iter;
    unsigned int size_;

  private:
    node *create_node();
    void delete_node(node *n);
    void iter_begin();
    void iter_reset();

  public:
    trie();
    ~trie();
    void erase();
    unsigned int size() const;
    bool insert(const std::string key, const int value);
    bool exists_key(std::string::const_iterator begin, std::string::const_iterator end, int &value);
};

#endif