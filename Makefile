all: main
INCDIR = ./include
SRCDIR = src
OBJS = util.o node.o trie.o keyword_matcher.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -O3 -c $(DEBUG) -std=c++14
LFLAGS = -Wall $(DEBUG)

main: $(OBJS)
	$(CC) $(OBJS) -o main $(LFLAGS)

util.o: $(INCDIR)/util.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/util.cpp

node.o: $(INCDIR)/node.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/node.cpp

trie.o: $(INCDIR)/trie.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/trie.cpp

main.o: $(INCDIR)/keyword_matcher.h
	$(CC) $(CFLAGS) -I$(INCDIR) main.cpp
	    
keyword_matcher.o: $(INCDIR)/keyword_matcher.h
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCDIR)/keyword_matcher.cpp

clean:
	rm -f *.o main; rm -rf main.dSYM