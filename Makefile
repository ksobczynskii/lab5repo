COMPILER=g++-14


all: main
main: main.o MovieCollection.o
	${COMPILER} main.o MovieCollection.o -o main

main.o: main.cpp
	${COMPILER} -c main.cpp -o main.o

MovieCollection.o: MovieCollection.cpp
	${COMPILER} -c MovieCollection.cpp -o MovieCollection.o
.PHONY: clean all
clean:
	rm test test1 test2 test3 test4 test5 test6 main.o main
