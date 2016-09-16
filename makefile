tree:  B_tree.o treeNode.o main.o node.o AVLTree.o
	g++  main.o node.o B_tree.o treeNode.o AVLTree.o -o tree

main.o: main.cpp node.h treeNode.h B_tree.h AVLTree.h
	g++ -c main.cpp

node.o: node.h node.cpp 
	g++ -c node.cpp

treeNode.o: treeNode.h treeNode.cpp
	g++ -c treeNode.cpp

B_tree.o: treeNode.h B_tree.h B_tree.cpp
	g++ -c B_tree.cpp

AVLTree.o: node.h AVLTree.h AVLTree.cpp
	g++ -c AVLTree.cpp
