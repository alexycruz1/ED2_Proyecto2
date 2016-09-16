#include "treeNode.h"
#include "B_tree.h"
#include <vector>
#include <sstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::vector;

btree::btree(){

}
	
btree::btree(int number){
	size = number;
	root = new treeNode[size];
}

void btree::insert(int value, treeNode* current){
	if(!this->hasChildren(current)){
		treeNode nuevo(value);
		locate(nuevo, current, 0);
	}else{

	}	
}

void btree::locate(treeNode nuevo, treeNode* nodo, int pos){
	treeNode temporal(0);
	if(pos <= size-1){
		if(nodo[pos].getValue() == 0){
			nodo[pos] = nuevo;
		}else{
			if(nodo[pos].getValue()<=nuevo.getValue()){
				pos+=1;
				locate(nuevo,nodo,pos);
			}else if(nodo[pos].getValue()>nuevo.getValue()){
				temporal = nodo[pos];
				nodo[pos] = nuevo;
				pos+=1;
				locate(temporal,nodo,pos);
			}
		}
	}else{
		int contador = 0;
		pos = (size+1)/2;
		treeNode* arr = new treeNode[size];
		treeNode* left = new treeNode[size];
		treeNode* right = new treeNode[size];
		nodo[pos].setLeftSon(left);
		nodo[pos].setRightSon(right);
		
		for(int i = 0; i < pos -1; i++){
			left[contador] = nodo[i];
			contador++;	
		}
		
		contador = 0;

		for(int i = pos+1; i<size; i++){
			right[contador] = nodo[i];
			contador++;
		}
		
		root = arr;
		locate(nodo[pos], arr, 0);
	}
}

string btree::toString(treeNode* nodo){
	stringstream ss;
	for(int i = 0; i < size; i++){
		ss << nodo[i].getValue() << ";";
	}
	ss<<"\n";
	return ss.str();
}
		

treeNode* btree::getRoot(){
	return root;
}

bool btree::hasChildren(treeNode* nodo){
	for(int i = 0; i < size; i++){
		if(nodo[i].hasLeftSon()){
			return true;
		}
		if(nodo[i].hasRightSon()){
			return true;
		}
	}
	return false;
}














