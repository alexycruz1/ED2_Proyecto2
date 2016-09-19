#pragma once
#include <string>

using std::string;

class Node{
public:
	int value;
	int level;
	Node* leftSon;
	Node* rightSon;
	Node* parent;
	public:
		Node();
		Node(int value);
		~Node();
		string toString()const;
		int getValue();
		int getLevel();
		Node getLeftSon();
		Node getRightSon();
		Node getParent();
		Node* getParentPointer();
		Node* getLeftSonPointer();
		Node* getRightSonPointer();
		void setParent(Node*);
		void setLeftSon(Node*);
		void setRightSon(Node*);
		void setValue(int);
		void setLevel(int);
		bool Equals(Node, Node);
		bool hasParent();
		bool hasRightSon();
		bool hasLeftSon();
};
