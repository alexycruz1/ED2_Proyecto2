tree: node.o AVLTree.o main.o
	g++ ARLVTree.o node.o main.o -o tree

main.o: main.cpp node.h AVLTree.h
	g++ -c main.cpp

node.o: node.h node.cpp
	g++ -c node.cpp

AVLTree.o: AVLTree.h AVLTree.cpp
	g++ -c AVLTree.cpp
