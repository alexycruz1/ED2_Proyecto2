#include <iostream>
#include "node.h"
#include "B_tree.h"
#include "treeNode.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	btree arbol(3);	
	bool seguir = true;
	int num = 0;
	int dec = 0;

	while(seguir){
		cout<<"Ingrese un numero: " << endl;
		cin >> num;
		arbol.insert(num, arbol.getRoot());
		cout<< "Desea continuar: ";
		cin >> dec;
		
		dec == 1? seguir = true:seguir = false;	
	}
	
	if(arbol.getRoot()->hasLeftSon()){
		cout<< "tiene hijo"<< endl;
	}
	if(arbol.getRoot()->hasRightSon()){
		cout << "tieene otro hijo" << endl;
	}	
	cout << arbol.toString(arbol.getRoot()) << endl;
	return 0;
}
