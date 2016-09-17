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


void AVLTree::AddNode(int ValorInsertar){
	Node* Nodo = new Node(ValorInsertar);
	Node* RaizTemporal = Raiz;
	int Seguir = 1;

	while(Seguir == 1){
		if ((!(*Raiz).hasLeftSon()) && (!(*Raiz).hasRightSon())){
			if (ValorInsertar > (*Raiz).getValue()){
				Raiz -> setRightSon(Nodo);
				Seguir = 0;
			}else{
				Raiz -> setLeftSon(Nodo);
				Seguir = 0;
			}
		}else{
			if(ValorInsertar > (*RaizTemporal).getValue()){
				if ((*RaizTemporal).hasRightSon()){
					RaizTemporal = RaizTemporal -> getRightSonPointer();
				}else{
					RaizTemporal -> setRightSon(Nodo);
					Nodo -> setParent(RaizTemporal);
					Seguir = 0;
				}
			}else{
				if ((*RaizTemporal).hasLeftSon()){
					RaizTemporal = RaizTemporal -> getLeftSonPointer();
				}else{
					RaizTemporal -> setLeftSon(Nodo);
					Nodo -> setParent(RaizTemporal);
					Seguir = 0;
				}
			}
		}
	}
}

/*void AVLTree::DeleteNode(Node* Nodo){
	Node NodoEliminar = *Nodo;
	bool TieneHijoIzquierdo = NodoEliminar.hasLeftSon();
	bool TieneHijoDerecho = NodoEliminar.hasRightSon();

	if (TieneHijoIzquierdo == false && TieneHijoIzquierdo == false){
		//cuando solo se elimina un nodo que no tiene hijos (caso 1).
		Node HijoIzquierdo = NodoEliminar.getParent().getLeftSon();
		Node HijoDerecho = NodoEliminar.getParent().getRightSon();

		cout << "esto es eliminar y derecha: " << NodoEliminar.Equals(NodoEliminar, HijoDerecho) << endl;
		if (NodoEliminar.Equals(NodoEliminar, HijoIzquierdo)){
			NodoEliminar.getParent().setLeftSon(NULL);
		}else if(NodoEliminar.Equals(NodoEliminar, HijoDerecho)){
			cout << "Entre aqui pero no seteo a NULL porque soy inutil" << endl;
			cout << endl;
			NodoEliminar.getParent().setRightSon(NULL);
		}
	}/*else if (TieneHijoIzquierdo && TieneHijoDerecho == false){
		//cuando se elimina un nodo que tiene hijo izquierdo pero no derecho (caso 2).
		Node HijoIzquierdo = NodoEliminar.getParent().getLeftSon();
		Node HijoDerecho = NodoEliminar.getParent().getRightSon();

		Node HijoDeEliminado = NodoEliminar.getLeftSon();
		Node* SetearHijoDeEliminado = &HijoDeEliminado;

		if (HijoIzquierdo.Equals(HijoIzquierdo, NodoEliminar)){
			NodoEliminar.getParent().setLeftSon(SetearHijoDeEliminado);
			Node SetearPadreTemporal = NodoEliminar.getParent();
			Node* SetearPadre = &SetearPadreTemporal;

			HijoDeEliminado.setParent(SetearPadre);
			NodoEliminar.setRightSon(NULL);
			NodoEliminar.setLeftSon(NULL);
		}else if(HijoDerecho.Equals(HijoDerecho, NodoEliminar)){
			NodoEliminar.getParent().setRightSon(SetearHijoDeEliminado);
			Node SetearPadreTemporal = NodoEliminar.getParent();
			Node* SetearPadre = &SetearPadreTemporal;

			HijoDeEliminado.setParent(SetearPadre);
			NodoEliminar.setRightSon(NULL);
			NodoEliminar.setLeftSon(NULL);
		}
	}else if(TieneHijoIzquierdo == false && TieneHijoDerecho){
		//cuando se elimina un nodo que tiene hijo izquierdo pero no derecho (caso 2).
		Node HijoIzquierdo = NodoEliminar.getParent().getLeftSon();
		Node HijoDerecho = NodoEliminar.getParent().getRightSon();

		Node HijoDeEliminado = NodoEliminar.getRightSon();
		Node* SetearHijoDeEliminado = &HijoDeEliminado;

		if (HijoIzquierdo.Equals(HijoIzquierdo, NodoEliminar)){
			NodoEliminar.getParent().setLeftSon(SetearHijoDeEliminado);
			Node SetearPadreTemporal = NodoEliminar.getParent();
			Node* SetearPadre = &SetearPadreTemporal;

			HijoDeEliminado.setParent(SetearPadre);
			NodoEliminar.setRightSon(NULL);
			NodoEliminar.setLeftSon(NULL);
		}else if(HijoDerecho.Equals(HijoDerecho, NodoEliminar)){
			NodoEliminar.getParent().setRightSon(SetearHijoDeEliminado);
			Node SetearPadreTemporal = NodoEliminar.getParent();
			Node* SetearPadre = &SetearPadreTemporal;

			HijoDeEliminado.setParent(SetearPadre);
			NodoEliminar.setRightSon(NULL);
			NodoEliminar.setLeftSon(NULL);
		}
	}else if(TieneHijoIzquierdo && TieneHijoDerecho){
		//cuando se elimina un nodo que tiene ambos hijos.
		Node NodoTemporal = NodoEliminar.getRightSon();
		Node* HijoDerecho = &NodoTemporal;

		Node* LefterSon = ReturnLefterSon(HijoDerecho);

		if (LefterSon != NULL){
			(*Nodo).setValue((*LefterSon).getValue());

			DeleteNode(LefterSon);
		}
	}
}*/

/*Node* AVLTree::ReturnLefterSon(Node* Nodo){
	Node NodoTemporal = *Nodo;
	if (NodoTemporal.hasLeftSon()){
		NodoTemporal = NodoTemporal.getLeftSon();
		Nodo = &NodoTemporal;
		return ReturnLefterSon(Nodo);
	}

	return Nodo;
}*/

/*string AVLTree::toString()const{
	stringstream ss;
	ss << Raiz.getValue();
	return ss.str();	
}
*/