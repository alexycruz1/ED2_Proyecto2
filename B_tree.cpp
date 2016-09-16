#include "treeNode.h"
#include "B_tree.h"
#include <vector>
#include <sstream>

using std::stringstream;
using std::vector;

btree::btree(){

}
	
btree::btree(int number){
	size = number;
	root.reserve(number);
}

void btree::insert(int value){
	treeNode nodo(value);
	root.push_back(nodo);
}

string btree::toString(){
	stringstream ss;
	for(int i = 0; i < root.size(); i++){
		ss << root[i].getValue() << ";";
	}
	ss << "\n";
	return ss.str();
}














