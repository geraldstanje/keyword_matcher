BUILD: all
INCDIR = ./include
SRCDIR = src
OBJS = util.o node.o trie.o keyword_matcher.o main.o
CXX = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG)
cxxflags.all := -Wall -O3 -c $(DEBUG) -std=c++14
cxxflags.benchmark := -Wall -O3 -c $(DEBUG) -std=c++14 -DBENCHMARKING
CXXFLAGS := ${cxxflags.${BUILD}}

all: $(OBJS)
	$(CXX) $(OBJS) -o main $(LFLAGS)
	
bench: $(OBJS)
	$(CXX) $(OBJS) -o main $(LFLAGS)

util.o: $(INCDIR)/util.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $(SRCDIR)/util.cpp

node.o: $(INCDIR)/node.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $(SRCDIR)/node.cpp

trie.o: $(INCDIR)/trie.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $(SRCDIR)/trie.cpp

main.o: $(INCDIR)/keyword_matcher.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) main.cpp
	    
keyword_matcher.o: $(INCDIR)/keyword_matcher.h
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $(SRCDIR)/keyword_matcher.cpp

clean:
	rm -f *.o main; rm -rf main.dSYM