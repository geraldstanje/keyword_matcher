#include "keyword_matcher.h"
#include <iostream>
#include <fstream>

keyword_matcher::keyword_matcher(): bag_of_words_size(0) {
}

bool keyword_matcher::load_bag_of_words(const std::string &filename) {
    std::ifstream file;
    file.open(filename.c_str(), std::ios::in);

    if(!file.is_open()) {
        std::cerr << "file not found" << '\n';
        return false;
    }

    std::string str;
    std::string file_contents;
    while (std::getline(file, str)) {
        t.insert(str, bag_of_words_size);
        bag_of_words_size++;
    }

    // close file
    file.close();
    return true;
}

void keyword_matcher::load_bag_of_words(const std::vector<std::string> &bag_of_words) {
    if (bag_of_words_size > 0) {
        t.erase();
        bag_of_words_size = 0;
    }

    for (auto i = 0; i < bag_of_words.size(); i++) {
        t.insert(bag_of_words[i], i);
        bag_of_words_size++;
    }
}

std::vector<bool> keyword_matcher::match_keywords(const std::string &url) {
    std::vector<bool> vec(bag_of_words_size, 0);

    for (int start = 0; start < url.size() - 1; start++) {
        for (int len = 1; len <= url.size() - start; len++) {
            unsigned int index = 0;

            if (t.exists(url.substr(start, len), index)) {
                vec[index] = true;
            }
        }
    }

    return vec;
}