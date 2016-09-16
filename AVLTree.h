#pragma once
#include <string>
#include "node.h"

using std::string;

class AVLTree{
	int Valor;//es para el nodo
	Node Raiz(int);
	public:
		AVLTree(int);
		Node getRoot();//no
		/*void SetRoot(Node*);
		void AddNode(Node*, Node*);
		string toString()const;*/
};