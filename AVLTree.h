#pragma once
#include <string>
#include "node.h"

using std::string;

class AVLTree{
	Node* Raiz;
	public:
		AVLTree();
		AVLTree(int Valor);
		~AVLTree();
		Node getRoot();
		void SetRoot(Node*);
		void AddNode(int ValorInsertar);
		//void DeleteNode(Node*);
		//Node* ReturnLefterSon(Node*);
		/*string toString()const;*/
};