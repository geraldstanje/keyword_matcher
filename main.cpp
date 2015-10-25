#include "keyword_matcher.h"
#include <cassert>
#include <iostream>

void print(std::vector<unsigned int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
    }
    std::cout << '\n';
}

int main() {
    keyword_matcher m;

    m.load_bag_of_words(std::vector<std::string> {"he", "hel", "hi"});
    auto vec1 = m.match_keywords("http://hello.com");
    print(vec1);

    //m.load_bag_of_words("dataset/vocab.nytimes.txt");
    //auto vec2 = m.match_keywords("http://hello.com");

    /*trie t;

    t.insert("he", 2);

    std::string str = "ht";
    unsigned int value = 0;
    bool is_end = false;
    std::cout << t.exists(str.begin(), str.end(), value, is_end) << std::endl;
    std::cout << is_end;*/
}