#include "trie.h"
#include <cassert>

int main() {
  trie t;
  t.add("he");
  t.add("hel");
  t.add("hi");
  assert(t.exists("hello") == true);
}