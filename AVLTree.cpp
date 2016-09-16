#include "node.h"
#include "AVLTree.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

AVLTree::AVLTree(Node R){
	Root = R;
}

Node AVLTree::getRoot(){
	return Root;
}

void AVLTree::SetRoot(Node* Nodo){
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

string AVLTree::toString()const{
	stringstream ss;
	ss << Node.getValue();
	return ss.str();	
}