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
	Node NodoEliminar = *Nodo;
	bool TieneHijoIzquierdo = NodoEliminar.hasLeftSon();
	bool TieneHijoDerecho = NodoEliminar.hasRightSon();

	if (TieneHijoIzquierdo == false && TieneHijoIzquierdo == false){
		//cuando solo se elimina un nodo que no tiene hijos (caso 1).
		Node HijoIzquierdo = NodoEliminar.getParent().getLeftSon();
		Node HijoDerecho = NodoEliminar.getParent().getRightSon();

		if (NodoEliminar.Equals(NodoEliminar, HijoIzquierdo)){
			NodoEliminar.getParent().setLeftSon(NULL);
		}else{
			NodoEliminar.getParent().setRightSon(NULL);
		}
	}else if (TieneHijoIzquierdo && TieneHijoDerecho == false){
		//cuando se elimina un nodo que tiene hijo izquierdo pero no derecho (caso 2).
	}else if(TieneHijoIzquierdo == false && TieneHijoDerecho){
		//cuando se elimina un nodo que tiene hijo izquierdo pero no derecho (caso 2).
	}else if(TieneHijoIzquierdo && TieneHijoDerecho){
		//cuando se elimina un nodo que tiene ambos hijos.
	}
}

/*string AVLTree::toString()const{
	stringstream ss;
	ss << Raiz.getValue();
	return ss.str();	
}
*/