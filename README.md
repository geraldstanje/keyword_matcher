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

# Design
All keywords are stored in a trie, with key = keyword, value = index to the bag of words vector

At the moment the trie stores 28 characters: a-z and the following special characters: '-' ','
Insertion in the trie as well as lookup will be with lowercase. All other chracters are ignored.

There are two options to build the trie:
1. read the keywords from a file
2. read the ketwords via command line argument

The keyword search returns a vector, which indicates that the keyword was found, if the value is 1

Example:
trie = he,hel,hi
url = http://hello.com

Output:
110

Lookup in the trie (read each character from the input string exactly once):
current trie node: h
current trie node: t
current trie node: t
current trie node: t
current trie node: p
current trie node: h
current trie node: e
current trie node: l
current trie node: l
current trie node: e
current trie node: l
current trie node: l
current trie node: o
current trie node: c
current trie node: o
current trie node: m

# Usage of the App
./main [-u URL] [-t test] [-s bag of words string] [-f bag_of_words_file]

Command line arguments:
  * -t ... runs a predefined test
  * -u ... takes the url string, e.g. -u http://hello.com
  * -f ... takes a path to the bag of words, e.g. -f dataset/vocab.nytimes.txt
  * -s ... takes the bag of words (comma-separated) as a string, e.g. -s he,hel,hi

The app returns a bit vector, indicating if the keyword was found within a bag of words. This format can
be used by a machine learning algorithm.

# Run Basic test and benchmark
python compile_and_test.py

# TODO:
  * compress the trie by implemting a Suffix Trie
  * yet another idea could be to implement a Ternary Search Tree: http://c.learncodethehardway.org/book/ex47.html