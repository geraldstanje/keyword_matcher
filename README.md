## Keyword Matcher

# About
This app can take in ad-requests, and parse the URL section of the request to 
determine if the URL contains any pre-specific words from a list of words.

To ensure a speedy (sub 10ms) lookup, a trie was implemented.
The keyword matcher needs to be filled with a bag of words, which initializes the trie.

The keyword matcher will return a vector that'll indicate if the keyword is found in the string.

URL string example:
http://edition.cnn.com/2015/10/14/opinions/shirky-xiaomi-chinas-apple/index.html

Keywords can look like:
* Target
* This
* String
* Target-This-String

Keywords can look like:
* Target
* This
* String
* Target-This-String

Before an ad auction happens, there is a "data provider" stage where additional information on the auction 
can be added. As the overall auction is ~150ms, we only have ~10ms to add in this suplemental data to the auction.

Buyers can then target this "has a keyword" segment and make campaigns that only target URLs with ertain words.

# Design
All keywords are stored in a trie, with key = keyword, value = index to the bag of words vector

The trie stores 28 characters: a-z and the following special characters: '-' '_'.
Insertion in the trie as well as lookup will be with lowercase.

There are two options to build the trie:

1. read the keywords (bag of words) from a file
2. read the keywords (bag of words) via command line argument

After the trie is built, the output vector is allocated within keyword_matcher::load_bag_of_words. 

The function keyword_matcher::match_keywords would take a url string and return a vector with the size of the 
bag of words, storing one's and zero's only. A one at index x means the a keyword within the bag of words was found.
The function match_keywords only initializes the output vector to zero, rather than allocating it. <br>
For performance reason the type of the output vector was specified with std::vector< uint16_t>, rather than
std::vector< bool>. If the size of the bag of words would be known at compile time, a bitset could be selected. 
A std::bitset<32> could also be stored in 4 bytes memory. <br>

Example: <br>
trie with 3 words = he,hel,hi <br>
url = http://hello.com

Output:
110
           
The Output of "110" means that keywords (within the bag of words) are found at index 0, and index 1.
The index refers to the bag of words, which is read sequentially.

Index 0...he <br>
Index 1...hel <br>
Index 2...hi <br>

The trie reads each character from the input string exactly once: <br>
current trie node: h <br>
current trie node: t <br>
current trie node: t <br>
current trie node: t <br>
current trie node: p <br>
current trie node: h <br>
current trie node: e <br>
current trie node: l <br>
current trie node: l <br>
current trie node: e <br>
current trie node: l <br>
current trie node: l <br>
current trie node: o <br>
current trie node: c <br>
current trie node: o <br>
current trie node: m <br>

# Usage of the App
./main [-u URL] [-s bag of words string] [-f bag_of_words_file]

Command line arguments:
  * -u ... takes the url string, e.g. -u http://hello.com
  * -f ... takes a path to the bag of words, e.g. -f dataset/vocab.nytimes.txt
  * -s ... takes the bag of words (comma-separated) as a string, e.g. -s he,hel,hi

The app returns a bit vector, indicating if the keyword was found within a bag of words. This format can
be used by a machine learning algorithm.

# Run Unit test and benchmark
The following command runs a valgrind check, to detect memroy leaks and starts a unit test for trie and keyword_matcher.

$ python compile_and_test.py

# TODO:
  * compress the trie by implementing a Suffix Trie
  * yet another idea could be to implement a Ternary Search Tree: http://c.learncodethehardway.org/book/ex47.html
  * add more testing
  * code profiling, in order to further improve the performance of the code