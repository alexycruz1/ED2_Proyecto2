#include "node.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Node::Node(int val){
	value = val;
	parent = NULL;
	leftSon = NULL;
	rightSon = NULL;
}

string Node::toString()const{
	stringstream ss;
	ss << value;
	return ss.str();	
}

int Node::getValue(){
	return value;
}

Node Node::getLeftSon(){
	return *leftSon;
}

Node Node::getRightSon(){
	return *rightSon;
}

Node Node::getParent(){
	return *parent;
}

void Node::setParent(Node* nodo){
	parent = nodo;
}

void Node::setLeftSon(Node* nodo){
	leftSon = nodo;
}

void Node::setRightSon(Node* nodo){
	rightSon = nodo;
}

void Node::setValue(int valor){
	value = valor;
}

bool Node::hasParent(){
	if(parent!=NULL){
		return true;		
	}
	return false;
}

bool Node::hasRightSon(){
	if(rightSon!=NULL){
		return true;
	}
	return false;
}

bool Node::hasLeftSon(){
	if(leftSon!=NULL){
		return true;
	}
	return false;
}
