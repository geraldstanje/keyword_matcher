## Keyword Matcher

This app can take in ad-requests, and parse the URL section of the request to 
determine if the URL contains any pre-specific words from a list of words.

To ensure a speedy (sub 10ms) lookup, a trie was implemented.
The keyword matcher needs to be filled with a bag of words, which initializes the trie.

The keyword matcher will return a vector that'll indicate if the keyword is found in the string.

URL string example:
http://edition.cnn.com/2015/10/14/opinions/shirky-xiaomi-chinas-apple/index.html

Keywords can look like:
Target
This
String
Target-This-String

TODO:
** compress the trie by implemting a Suffix Trie
** yet another idea could be to implement a Ternary Search Tree: http://c.learncodethehardway.org/book/ex47.html