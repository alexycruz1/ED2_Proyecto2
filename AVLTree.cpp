#include "node.h"
#include "AVLTree.h"
#include <string>
#include <sstream>
#include <iostream>
#include "typeinfo"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

AVLTree::AVLTree(){
	this -> Raiz = new Node();
}

AVLTree::AVLTree(int Valor){
	this -> Raiz = new Node(Valor);
}

AVLTree::~AVLTree(){
}

Node AVLTree::getRoot(){
	return *Raiz;
}

void AVLTree::SetRoot(Node* Nodo){
	this -> Raiz = Nodo;
}


void AVLTree::AddNode(Node* Nodo, Node* Raiz){
	if(Raiz == NULL){
		Raiz = Nodo;
	}else{
		if ((*Nodo).getValue() <= (*Raiz).getValue()){

			if(!(*Raiz).hasLeftSon()){
				(*Raiz).setLeftSon(Nodo);
			}else{
				Node RaizTemporal = (*Raiz).getLeftSon();
				Raiz = &RaizTemporal;
				AddNode(Nodo, Raiz);
			}
		}else{
			if(!(*Raiz).hasRightSon()){
				(*Raiz).setRightSon(Nodo);
			}else{
				Node RaizTemporal = (*Raiz).getRightSon();
				Raiz = &RaizTemporal;
				AddNode(Nodo, Raiz);
			}
		}
	}
}

void AVLTree::DeleteNode(Node* Nodo){

}

/*string AVLTree::toString()const{
	stringstream ss;
	ss << Raiz.getValue();
	return ss.str();	
}
*/