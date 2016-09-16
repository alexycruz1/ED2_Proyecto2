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
		arbol.insert(num);
		cout<< "Desea continuar: ";
		cin >> dec;
		
		dec == 1? seguir = true:seguir = false;	
	}
	
	cout << arbol.toString() << endl;
	return 0;
}
