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
		void DeleteNode(int ValorEliminar, int NodosTotales, int CasoEspecial);
		Node* ReturnLefterSon(Node*);
		Node* getRootPointer();
		void EstaBalanceado(Node* Nodo, bool Continuar, bool Agregar, int Lado);
		void RSI(Node* Nodo);
		void RSD(Node* Nodo);
		void RSIx2(Node* Nodo);
		void RSDx2(Node* Nodo);
		void Recorrido(Node* Nodo);
		Node* Buscar(int ValorNodo, int NodosTotales);
		string VerArbol(Node* NodoActual, int NodosTotales)const;
		/*string toString()const;*/
};