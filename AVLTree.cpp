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
}

AVLTree::AVLTree(int Valor){
	this -> Raiz = new Node(Valor);
}

AVLTree::~AVLTree(){
}

Node AVLTree::getRoot(){
	return *Raiz;
}

Node* AVLTree::getRootPointer(){
	return Raiz;
}

void AVLTree::SetRoot(Node* Nodo){
	this -> Raiz = Nodo;
}


void AVLTree::AddNode(int ValorInsertar){
	Node* Nodo = new Node(ValorInsertar);
	Node* RaizTemporal = Raiz;
	int Seguir = 1;

	while(Seguir == 1){
		if ((*Raiz).getValue() != 0){
			if ((!(*Raiz).hasLeftSon()) && (!(*Raiz).hasRightSon())){
				if (ValorInsertar > (*Raiz).getValue()){
					Raiz -> setRightSon(Nodo);
					Nodo -> setParent(Raiz);

					bool Continuar = true, Agregar = true;
					int Lado = 1;
					EstaBalanceado(Raiz, Continuar, Agregar, Lado);
					Seguir = 0;
				}else if(ValorInsertar < (*Raiz).getValue()){
					Raiz -> setLeftSon(Nodo);
					Nodo -> setParent(Raiz);

					bool Continuar = true, Agregar = true;
					int Lado = 0;
					EstaBalanceado(Raiz, Continuar, Agregar, Lado);
					Seguir = 0;
				}
			}else{
				if(ValorInsertar > (*RaizTemporal).getValue()){
					if ((*RaizTemporal).hasRightSon()){
						RaizTemporal = RaizTemporal -> getRightSonPointer();
					}else{
						RaizTemporal -> setRightSon(Nodo);
						Nodo -> setParent(RaizTemporal);

						bool Continuar = true, Agregar = true;
						int Lado = 1;
						EstaBalanceado(RaizTemporal, Continuar, Agregar, Lado);
						Seguir = 0;
					}
				}else{
					if ((*RaizTemporal).hasLeftSon()){
						RaizTemporal = RaizTemporal -> getLeftSonPointer();
					}else{
						RaizTemporal -> setLeftSon(Nodo);
						Nodo -> setParent(RaizTemporal);

						bool Continuar = true, Agregar = true;
						int Lado = 0;
						EstaBalanceado(RaizTemporal, Continuar, Agregar, Lado);
						Seguir = 0;
					}
				}
			}
		}else if((*Raiz).getValue() == 0){
			Raiz = new Node(ValorInsertar);
			Seguir = 0;
		}
	}
}

void AVLTree::DeleteNode(int ValorEliminar, int NodosTotales, int CasoEspecial){
	Node* NodoEliminar = Raiz;
	cout << "Nodo a eliminar: " << (*NodoEliminar).getValue();
	int Revisar = 0;
	int Repetido = 0;

	if (CasoEspecial == 0){
		while(ValorEliminar != (*NodoEliminar).getValue() && (Revisar <= NodosTotales)){
			Revisar++;
			if (ValorEliminar > (*NodoEliminar).getValue()){
				if ((*NodoEliminar).hasRightSon()){
					NodoEliminar = NodoEliminar -> getRightSonPointer();
				}
			}else if(ValorEliminar < (*NodoEliminar).getValue()){
				if((*NodoEliminar).hasLeftSon()){
					NodoEliminar = NodoEliminar -> getLeftSonPointer();	
				}
			}
		}	
	}else{
		while((Revisar < NodosTotales) && (Repetido < 2)){
			Revisar++;
			if (ValorEliminar >= (*NodoEliminar).getValue()){
				if((*NodoEliminar).getValue() == ValorEliminar){
					Repetido++;
				}

				if ((*NodoEliminar).hasRightSon()){
					NodoEliminar = NodoEliminar -> getRightSonPointer();
				}
			}else if(ValorEliminar <= (*NodoEliminar).getValue()){
				if((*NodoEliminar).getValue() == ValorEliminar){
					Repetido++;
				}

				if((*NodoEliminar).hasLeftSon()){
					NodoEliminar = NodoEliminar -> getLeftSonPointer();	
				}
			}
		}	
	}

	bool TieneHijoIzquierdo = (NodoEliminar) -> hasLeftSon();
	bool TieneHijoDerecho = (NodoEliminar) -> hasRightSon();
	if(!TieneHijoIzquierdo && !TieneHijoDerecho){
		//Cuando solo se elimina un nodo que no tiene hijos(Caso1).
		Node* PadreDeEliminado;
		if(NodoEliminar -> hasParent()){
			Node* PadreDeEliminado = NodoEliminar -> getParentPointer();
		}else{
			PadreDeEliminado = NULL;
		}

		if(PadreDeEliminado){
			if (ValorEliminar > (*PadreDeEliminado).getValue()){
				PadreDeEliminado -> setRightSon(NULL);
				NodoEliminar -> setParent(NULL);

				bool Continuar = true, Agregar = false;
				int Lado = 1;
				//EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
			}else{
				PadreDeEliminado -> setLeftSon(NULL);
				NodoEliminar -> setParent(NULL);

				bool Continuar = true, Agregar = false;
				int Lado = 0;
				//EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
			}
		}else{
			Raiz = new Node(0);
		}
	}else if((TieneHijoIzquierdo && !TieneHijoDerecho) || (!TieneHijoIzquierdo && TieneHijoDerecho)){
		//Cuando el nodo a eliminar tiene hijo izquierdo o derecho;
		Node* PadreDeEliminado;
		if(NodoEliminar -> hasParent()){
			PadreDeEliminado = NodoEliminar -> getParentPointer();
		}else{
			PadreDeEliminado = NULL;
		}
		if (TieneHijoIzquierdo && !TieneHijoDerecho && PadreDeEliminado){
			if ((*PadreDeEliminado).getLeftSon().getValue() == ValorEliminar){
				(NodoEliminar -> getLeftSonPointer()) -> setParent(PadreDeEliminado);
				PadreDeEliminado -> setLeftSon(NodoEliminar -> getLeftSonPointer());

				bool Continuar = true, Agregar = false;
				int Lado = 0;
				EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
			}else if((*PadreDeEliminado).getRightSon().getValue() == ValorEliminar){
				(NodoEliminar -> getLeftSonPointer()) ->setParent(PadreDeEliminado);
				PadreDeEliminado -> setRightSon(NodoEliminar -> getLeftSonPointer());

				bool Continuar = true, Agregar = false;
				int Lado = 1;
				EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
			}
		}else if(!TieneHijoIzquierdo && TieneHijoDerecho && PadreDeEliminado){
			Node* PadreDeEliminado = NodoEliminar -> getParentPointer();
			if ((*PadreDeEliminado).getLeftSon().getValue() == ValorEliminar){
				(NodoEliminar -> getRightSonPointer()) -> setParent(PadreDeEliminado);
				PadreDeEliminado -> setLeftSon(NodoEliminar -> getRightSonPointer());

				bool Continuar = true, Agregar = false;
				int Lado = 0;
				EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
			}else if((*PadreDeEliminado).getRightSon().getValue() == ValorEliminar){
				(NodoEliminar -> getRightSonPointer()) -> setParent(PadreDeEliminado);
				PadreDeEliminado -> setRightSon(NodoEliminar -> getRightSonPointer());

				bool Continuar = true, Agregar = false;
				int Lado = 1;
				EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
			}
		}else if(TieneHijoIzquierdo && !TieneHijoDerecho && !PadreDeEliminado){
			PadreDeEliminado = PadreDeEliminado -> getLeftSonPointer();
			PadreDeEliminado -> setParent(NULL);

				bool Continuar = true, Agregar = false;
				int Lado = 0;
				EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
		}else if(!TieneHijoIzquierdo && TieneHijoDerecho && !PadreDeEliminado){
			PadreDeEliminado = PadreDeEliminado -> getRightSonPointer();
			PadreDeEliminado -> setParent(NULL);

				bool Continuar = true, Agregar = false;
				int Lado = 1;
				EstaBalanceado(PadreDeEliminado, Continuar, Agregar, Lado);
		}
	}else if(TieneHijoIzquierdo && TieneHijoDerecho){
		///cuando quiere eliminar un nodo que tiene ambos hijos.
		Node* NuevoNodo = ReturnLefterSon(NodoEliminar -> getRightSonPointer());
		NodoEliminar -> setValue((*NuevoNodo).getValue());

		DeleteNode((*NuevoNodo).getValue(), NodosTotales, 1);
	}
}

Node* AVLTree::ReturnLefterSon(Node* Nodo){
	if (Nodo -> getLeftSonPointer() != NULL){
		Nodo = Nodo -> getLeftSonPointer();
		return ReturnLefterSon(Nodo);
	}
	return Nodo; 
}

void AVLTree::EstaBalanceado(Node* Nodo, bool Continuar, bool Agregar, int Lado){
	//Lado = 1 -> derecho, Lado = 0 -> Izquierdo
	Continuar = true;
	while(Nodo && Continuar){
		if (Agregar == true){
			if (Lado == 0){
				Nodo -> setLevel((Nodo -> getLevel()) - 1);
			}else{
				Nodo -> setLevel((Nodo -> getLevel()) + 1);
			}
		}else{
			if (Lado == 0){
				Nodo -> setLevel((Nodo -> getLevel()) + 1);
			}else{
				Nodo -> setLevel((Nodo -> getLevel()) - 1);
			}
		}

		if (Nodo -> getLevel() == 0){
			Continuar = false;
		}else if(Nodo -> getLevel() == -2){
			if ((Nodo -> getLeftSonPointer()) -> getLevel() == 1){
				RSDx2(Nodo);
			}else{
				RSD(Nodo);
			}

			Continuar = false;
		}else if(Nodo -> getLevel() == 2){
			if ((Nodo -> getRightSonPointer()) -> getLevel() == -1){
				RSIx2(Nodo);
			}else{
				RSI(Nodo);
			}

			Continuar = false;
		}

		if (Nodo -> getParentPointer()){
			if (((Nodo -> getParentPointer()) -> getRightSonPointer()) == Nodo){
				Lado = 1;
			}else{
				Lado = 0;
			}
		}

		Nodo = Nodo -> getParentPointer();
	}
}

void AVLTree::RSI(Node* Nodo){
	Node* Padre = Nodo -> getParentPointer();
	Node* Hijo = Nodo;
	Node* HijoIzquierdo = Hijo -> getRightSonPointer();
	Node* Nieto = HijoIzquierdo -> getLeftSonPointer();

	if(Padre){
		if((Padre -> getRightSonPointer()) == Hijo){
			Padre -> setRightSon(HijoIzquierdo);
		}else{
			Padre -> setLeftSon(HijoIzquierdo);
		}
	}else{
		Raiz = HijoIzquierdo;
	}

	Hijo -> setRightSon(Nieto);
	HijoIzquierdo -> setLeftSon(Hijo);

	Hijo -> setParent(HijoIzquierdo);
	if(Nieto){
		Nieto -> setParent(Hijo);
	}
	HijoIzquierdo -> setParent(Padre);
	Hijo -> setLevel(0);
	HijoIzquierdo -> setLevel(0);
}

void AVLTree::RSD(Node* Nodo){
	Node* Padre = Nodo -> getParentPointer();
	Node* Hijo = Nodo;
	Node* HijoIzquierdo = Hijo -> getLeftSonPointer();
	Node* Nieto = HijoIzquierdo -> getRightSonPointer();

	if(Padre){
		if((Padre -> getRightSonPointer()) == Hijo){
			Padre -> setRightSon(HijoIzquierdo);
		}else{
			Padre -> setLeftSon(HijoIzquierdo);
		}
	}else{
		Raiz = HijoIzquierdo;
	}

	Hijo -> setLeftSon(Nieto);
	HijoIzquierdo -> setRightSon(Hijo);

	Hijo -> setParent(HijoIzquierdo);
	if(Nieto){
		Nieto -> setParent(Hijo);
	}
	HijoIzquierdo -> setParent(Padre);
	Hijo -> setLevel(0);
	HijoIzquierdo -> setLevel(0);
}

void AVLTree::RSDx2(Node* Nodo){
	Node* Hijo = Nodo;
	Node* Padre = Nodo -> getParentPointer();
	Node* HijoIzquierdo = Hijo -> getLeftSonPointer();
	Node* Nieto = HijoIzquierdo -> getRightSonPointer();
	Node* SubIzquierdo = Nieto -> getLeftSonPointer();
	Node* SubDerecho = Nieto -> getRightSonPointer(); 

	if(Padre){
		if((Padre -> getRightSonPointer()) == Nodo){
			Padre -> setRightSon(Nieto);
		}else{
			Padre -> setLeftSon(Nieto);
		}
	}else{
		Raiz = Nieto;
	}

	HijoIzquierdo -> setRightSon(SubIzquierdo);
	Hijo -> setLeftSon(SubDerecho);
	Nieto -> setLeftSon(HijoIzquierdo);
	Nieto -> setRightSon(Hijo);
	
	Nieto -> setParent(Padre);
	Hijo -> setParent(HijoIzquierdo);
	HijoIzquierdo -> setParent(Nieto);

	if(SubIzquierdo){
		SubIzquierdo -> setParent(HijoIzquierdo);
	}

	if(SubDerecho){
		SubDerecho -> setParent(Hijo);
	}

	if((Nieto -> getLevel()) == -1){
		HijoIzquierdo -> setLevel(0);
		Hijo -> setLevel(1);
	}else if((Nieto -> getLevel()) == 0){
		HijoIzquierdo -> setLevel(0);
		Hijo -> setLevel(0);
	}else if((Nieto -> getLevel()) == 1){
		HijoIzquierdo -> setLevel(-1);
		Hijo -> setLevel(0);
	}
}

void AVLTree::RSIx2(Node* Nodo){
	Node* Padre = Nodo -> getParentPointer();
	Node* Hijo = Nodo;
	Node* HijoIzquierdo = Hijo -> getRightSonPointer();
	Node* Nieto = HijoIzquierdo -> getLeftSonPointer();
	Node* SubIzquierdo = Nieto -> getLeftSonPointer();
	Node* SubDerecho = Nieto -> getRightSonPointer(); 
	
	if(Padre){
		if((Padre -> getRightSonPointer()) == Nodo){
			Padre -> setRightSon(Nieto);
		}else{
			Padre -> setLeftSon(Nieto);
		}
	}else{
		Raiz = Nieto;
	}

	HijoIzquierdo -> setLeftSon(SubIzquierdo);
	Hijo -> setRightSon(SubDerecho);
	Nieto -> setLeftSon(Hijo);
	Nieto -> setRightSon(HijoIzquierdo);

	Nieto -> setParent(Padre);
	Hijo -> setParent(HijoIzquierdo);
	HijoIzquierdo -> setParent(Nieto);

	if(SubIzquierdo){
		SubIzquierdo -> setParent(Hijo);
	}

	if(SubDerecho){
		SubDerecho -> setParent(HijoIzquierdo);
	}

	if((Nieto -> getLevel()) == -1){
		HijoIzquierdo -> setLevel(1);
		Hijo -> setLevel(0);
	}else if((Nieto -> getLevel()) == 0){
		HijoIzquierdo -> setLevel(0);
		Hijo -> setLevel(0);
	}else if((Nieto -> getLevel()) == 1){
		HijoIzquierdo -> setLevel(0);
		Hijo -> setLevel(-1);
	}
}

void AVLTree::Recorrido(Node* Nodo){
	if(!Nodo){
		return;
	}else{
		cout << (*Nodo).getValue() << endl;
		Recorrido(Nodo -> getLeftSonPointer());
		Recorrido(Nodo -> getRightSonPointer());
	}
}

Node* AVLTree::BuscarNodo(int valor, int NodosTotales){
	Node* ValorABuscar = Raiz;
	int Revisar = 0;

	while(valor != (*ValorABuscar).getValue() && (Revisar <= NodosTotales)){
		Revisar++;
		if (valor > (*ValorABuscar).getValue()){
			if ((*ValorABuscar).hasRightSon()){
				ValorABuscar = ValorABuscar -> getRightSonPointer();
			}
		}else if(valor < (*ValorABuscar).getValue()){
			if((*ValorABuscar).hasLeftSon()){
				ValorABuscar = ValorABuscar -> getLeftSonPointer();	
			}
		}
	}
	return ValorABuscar -> getParentPointer();
}