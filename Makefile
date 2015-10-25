all: main
INCDIR = ./include
SRCDIR = src
OBJS = util.o trie.o keyword_matcher.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -O3 -c $(DEBUG) -std=c++14
LFLAGS = -Wall $(DEBUG)

main: $(OBJS)
	$(CC) $(OBJS) -o main $(LFLAGS)

util.o: $(INCDIR)/util.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/util.cpp

trie.o: $(INCDIR)/node.h $(INCDIR)/util.h $(INCDIR)/trie.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/trie.cpp

main.o: $(INCDIR)/keyword_matcher.h
	$(CC) $(CFLAGS) -I$(INCDIR) main.cpp
	    
keyword_matcher.o: $(INCDIR)/keyword_matcher.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/keyword_matcher.cpp

clean:
	rm -f *.o main