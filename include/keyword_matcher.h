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
    bool load_bag_of_words(const std::string &filename);
    void load_bag_of_words(const std::vector<std::string> &bag_of_words);
    std::vector<unsigned int> match_keywords(const std::string &url);
};

#endif