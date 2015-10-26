#include "keyword_matcher.h"
#include "util.h"
#include <cassert>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

class argument_parser {
  public:
    std::string url;
    std::string bag_of_words_path;
    std::vector<std::string> bag_of_words;
    bool test;

    argument_parser(): test(false) {}
    void parse(std::vector<std::string> allArgs) {
        for (uint16_t i = 1; i < allArgs.size(); i++) {
            if (allArgs[i-1] == "-u") { // "http://hello.com"
                url = allArgs[i];
            } else if (allArgs[i-1] == "-f") { // "dataset/vocab.nytimes.txt"
                bag_of_words_path = allArgs[i];
            } else if (allArgs[i-1] == "-s") { // "he,hel,hi"
                split(allArgs[i].begin(), allArgs[i].end(), bag_of_words);
            } else if (allArgs[i] == "-t") { // enable test
                test = true;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::string> allArgs(argv, argv + argc);

    if (allArgs.size() < 2) {
        std::cerr << "usage: "<< allArgs[0] << " [-u URL] [-s bag of words string] [-f bag_of_words_file]\n";
        return -1;
    }

    argument_parser a;
    a.parse(allArgs);

    if (a.test) {
        keyword_matcher m;

        m.load_bag_of_words(std::vector<std::string> {"he", "hel", "hi"});
        auto vec1 = m.match_keywords("http://hello.com");
        print(vec1);

        m.load_bag_of_words("dataset/vocab.nytimes.txt");
        auto vec2 = m.match_keywords("http://hello.com");
        print(vec2);
    } else if (!a.url.empty()) {
        keyword_matcher m;
        if (!a.bag_of_words_path.empty()) {
            m.load_bag_of_words(a.bag_of_words_path);
        } else if (!a.bag_of_words.empty()) {
            m.load_bag_of_words(a.bag_of_words);
        }
        auto vec = m.match_keywords(a.url);
        print(vec);
    }
}