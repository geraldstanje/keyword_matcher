#include "keyword_matcher.h"
#include <cassert>
#include <iostream>

void print(std::vector<bool> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
    }
    std::cout << '\n';
}

int main() {
    keyword_matcher m;

    m.load_bag_of_words(std::vector<std::string> {"he", "hel", "hi"});
    auto vec = m.match_keywords("http://hello.com");
    print(vec);
}