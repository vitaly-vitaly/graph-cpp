CFLAGS = -g -Wall 
#-fprofile-arcs -ftest-coverage

all: test

test.o: test.cpp
	g++ $(CFLAGS) -c test.cpp
graph.o: graph.cpp
	g++ $(CFLAGS) -c graph.cpp
test: test.o graph.o
	g++ $(CFLAGS) graph.o test.o -o test

clean: 
	rm -rf *.o test