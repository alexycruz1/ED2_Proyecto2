#include "treeNode.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;

treeNode::treeNode(){

}
	
treeNode::treeNode(int val){
	value = val;
	leftBro = NULL;
	rightBro = NULL;
	parentList = NULL;
	rightSon = NULL;
	leftSon = NULL;
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
	
bool treeNode::hasRightBro(){
	if(rightBro == NULL){
		return false;
	}
	return true;
}

bool treeNode::hasLeftBro(){
	if(leftBro == NULL){
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

treeNode* treeNode::getRightBro(){
	return rightBro;
}

treeNode* treeNode::getLeftBro(){
	return leftBro;
}

treeNode* treeNode::getParentList(){
	return parentList;
}

void treeNode::setRightBro(treeNode* referencia){
	rightBro = referencia;
}

void treeNode::setLeftBro(treeNode* referencia){
	leftBro = referencia;
}

void treeNode::setParentList(treeNode*  referencia){
	parentList = referencia;
}

