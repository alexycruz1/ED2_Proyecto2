tree: main.o node.o
	g++ main.o node.o -o tree

main.o: main.cpp node.h
	g++ -c main.cpp

node.o: node.h node.cpp
	g++ -c node.cpp
