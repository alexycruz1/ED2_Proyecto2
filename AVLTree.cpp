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

AVLTree::AVLTree(int Valor){
	
	Node Raiz(Valor);
}

Node AVLTree::getRoot(){
	Node nodo(3);
	cout << Raiz.toString() << endl;
	return nodo;
}

/*void AVLTree::SetRoot(Node* Nodo){
	Root = Nodo;
}


void AVLTree::AddNode(Node* Nodo, Node* Raiz){
	if(Raiz == NULL){
		Raiz = Nodo;
	}else{
		if (Nodo.getValue() <= Raiz.getValue()){
			if(Raiz.getLeftSon() == NULL){
				Raiz.setLeftSon(&Nodo);
			}else{
				AddNode(Nodo, Raiz.getLeftSon());
			}
		}else{
			if(Raiz.getRightSon() == NULL){
				Raiz.setRightSon(&Nodo);
			}else{
				AddNode(Nodo, Raiz.getRightSon());
			}
		}
	}
}
*/
string AVLTree::toString()const{
	stringstream ss;
	ss << Node.getValue();
	return ss.str();	
}