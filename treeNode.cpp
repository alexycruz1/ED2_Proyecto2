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
}

vector<treeNode> treeNode::getLeftSon(){
	return leftSon;
}
	
vector<treeNode> treeNode::getRightSon(){
	return rightSon;
}

void treeNode::setLeftSon(vector<treeNode> referencia){
	leftSon = referencia;
}

void treeNode::setRightSon(vector<treeNode> referencia){
	rightSon = referencia;
}

int treeNode::getValue(){
	return value;
}

int treeNode::setValue(int val){
	value = val;
}

bool treeNode::hasRightSon(){
	if(rightSon.size() == 0){
		return false;
	}
	return true;
}

bool treeNode::hasLeftSon(){
	if(leftSon.size() == 0){
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
	if(parentList.size() == 0){
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

vector<treeNode> treeNode::getParentList(){
	return parentList;
}

void treeNode::setRightBro(treeNode* referencia){
	rightBro = referencia;
}

void treeNode::setLeftBro(treeNode* referencia){
	leftBro = referencia;
}

void treeNode::setParentList(vector<treeNode> referencia){
	parentList = referencia;
}

