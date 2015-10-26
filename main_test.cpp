#include "trie.h"
#include <cassert>
#include <iostream>
#include <vector>

class test_data {
  public:
    std::string key_;
    int16_t value_;
    test_data(std::string key, int16_t value): key_(key), value_(value) {}
};

int main() {
    trie t;

    std::vector<test_data> test_set = {{"hello", 2},
        {"he", 33},
        {"hel", 333},
        {"bi", 3},
        {"help", 1},
        {"bmw", 55},
        {"porsche", 1000}
    };
    int16_t index = 0;

    for (int i = 0; i < test_set.size(); i++) {
        t.insert(test_set[i].key_, test_set[i].value_);
    }

    for (int i = 0; i < test_set.size(); i++) {
        assert(t.exists(test_set[i].key_.begin(), test_set[i].key_.end(), index) == true);
        assert(index == test_set[i].value_);
    }

    assert(t.exists_key(test_set[1].key_.begin(), test_set[1].key_.end(), index) == true);
    assert(index == test_set[1].value_);

    std::string str = "hel";
    assert(t.exists_key(str.begin(), str.end(), index) == false);

    str = "bm";
    assert(t.exists_key(str.begin(), str.end(), index) == true);
    assert(index == -1);

    return 0;
}