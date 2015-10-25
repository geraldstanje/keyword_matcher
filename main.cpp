#include "keyword_matcher.h"
#include <cassert>
#include <iostream>
#include <cstdint>

void print(std::vector<uint16_t> &vec) {
    for (uint16_t i = 0; i < vec.size(); i++) {
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
    //print(vec2);
}