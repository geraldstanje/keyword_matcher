all: keywordMatcher
INCDIR = ./include
SRCDIR = src
OBJS = trie.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -O3 -c $(DEBUG) -std=c++14
LFLAGS = -Wall $(DEBUG)

keywordMatcher: $(OBJS)
	$(CC) $(OBJS) -o keywordMatcher $(LFLAGS)

trie.o: $(INCDIR)/node.h $(INCDIR)/trie.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/trie.cpp

main.o: $(INCDIR)/trie.h
	$(CC) $(CFLAGS) -I$(INCDIR) main.cpp
	    
clean:
	rm -f *.o keywordMatcher