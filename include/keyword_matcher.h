#ifndef KEYWORD_MATCHER_H
#define KEYWORD_MATCHER_H

#include "trie.h"
#include "keyword_matcher.h"
#include <vector>

class keyword_matcher {
  private:
    unsigned int bag_of_words_size;
    trie t; // stores the keyword as a key + index as a value, the index refers to the bag_of_words vector index

  public:
    keyword_matcher();
    void load_bag_of_words(const std::vector<std::string> &list_of_words);
    std::vector<bool> match_keywords(const std::string &url);
};

#endif