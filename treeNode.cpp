#include "treeNode.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;

treeNode::treeNode(){

}
	
treeNode::treeNode(int val){
	value = val;
	parentList = NULL;
	rightSon = NULL;
	leftSon = NULL;
	padre = NULL;
}

treeNode* treeNode::getLeftSon(){
	return leftSon;
}
	
treeNode* treeNode::getRightSon(){
	return rightSon;
}

void treeNode::setLeftSon(treeNode* referencia){
	leftSon = referencia;
}

void treeNode::setRightSon(treeNode* referencia){
	rightSon = referencia;
}

int treeNode::getValue(){
	return value;
}

int treeNode::setValue(int val){
	value = val;
}

bool treeNode::hasRightSon(){
	if(rightSon ==  NULL){
		return false;
	}
	return true;
}

bool treeNode::hasLeftSon(){
	if(leftSon == NULL){
		return false;
	}
	return true;
}

bool treeNode::hasParentList(){
	if(parentList == NULL){
		return false;
	}
	return true;
}

treeNode* treeNode::getParentList(){
	return parentList;
}

void treeNode::setParentList(treeNode*  referencia){
	parentList = referencia;
}

bool treeNode::hasChildren(){
	if(leftSon!=NULL && rightSon!=NULL){
		return true;
	}
	return false;
}

void treeNode::setPadre(treeNode* referencia){
	padre = referencia;
}

treeNode* treeNode::getPadre(){
	return padre;
}
