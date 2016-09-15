#include <iostream>
#include "node.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	int number = 4;
	Node nodo(number);
	Node left(5);
	
	nodo.setLeftSon(&left);
	
	cout << nodo.toString() << endl;
	if(nodo.hasLeftSon() == true){
		cout << "tiene hijo izquierdo" << endl;
	}
	cout << nodo.hasLeftSon() << endl;
	cout << nodo.hasRightSon() << endl;
	cout << nodo.hasParent() << endl;
	return 0;
}
