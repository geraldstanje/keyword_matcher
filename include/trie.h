#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include <string>

class trie {
private:
  node *root;

private:
  node *create_node();
  bool is_terminal(node *n);

public:
  trie();
  ~trie();
  void add(std::string key);
  bool exists(std::string key);
};

#endif