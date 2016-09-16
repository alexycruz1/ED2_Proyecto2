#pragma once
#include <string>
#include "node.h"

using std::string;

class AVLTree : public Node{
	Node Root;
	int Valor;
	public:
		AVLTree(Node);
		Node getRoot();
		void SetRoot(Node*);
		void AddNode(Node*, Node*);
		string toString()const;
};