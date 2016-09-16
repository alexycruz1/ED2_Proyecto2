#pragma once
#include <string>
#include "node.h"

using std::string;

class AVLTree{
	int Valor;
	Node Raiz(int);
	public:
		AVLTree(int);
		Node getRoot();
		/*void SetRoot(Node*);
		void AddNode(Node*, Node*);
		string toString()const;*/
};