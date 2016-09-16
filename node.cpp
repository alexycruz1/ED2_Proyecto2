#include "node.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Node::Node(){
}

Node::Node(int val){
	this -> value = val;
	this -> level = 0;//camino desde la raiz a nodo actual
	this -> parent = NULL;
	this -> leftSon = NULL;
	this -> rightSon = NULL;
}

Node::~Node(){
}

string Node::toString()const{
	stringstream ss;
	ss << value;
	return ss.str();	
}

int Node::getValue(){
	return value;
}

int Node::getLevel(){
	return level;
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

void Node::setLevel(int lev){
	level = lev;
}

bool Node::Equals(Node Nodo1, Node Nodo2){
	if ((Nodo1.getValue() == Nodo2.getValue()) && (&Nodo1 == &Nodo2)){
		return true;
	}

	return false;
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
