#pragma once
#include <string>

using std::string;

class Node{
	int value;
	Node* leftSon;
	Node* rightSon;
	Node* parent;

	public:
		Node(int);
		string toString()const;
		int getValue();
		Node getLeftSon();
		Node getRightSon();
		Node getParent();
		void setParent(Node*);
		void setLeftSon(Node*);
		void setRightSon(Node*);
		void setValue(int);
		bool hasParent();
		bool hasRightSon();
		bool hasLeftSon();
		

};
