#include <iostream>
#include "node.h"
#include "B_tree.h"
#include "treeNode.h"
#include "AVLTree.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	AVLTree Arbolito(3);
	Node Insertar1(2);
	Node Insertar2(4);
	Node Raiz = (Arbolito.getRoot());

	Arbolito.AddNode(&Insertar1, &Raiz);
	Arbolito.AddNode(&Insertar2, &Raiz);

	cout << "El valor de la raiz es: " << Raiz.getValue() << endl;
	cout << "El valor del hijo izquierdo es: " << Raiz.getLeftSon().getValue() << endl;
	cout << "El valor del hijo derecho es: " << Raiz.getRightSon().getValue() << endl;

	/*btree arbol(3);	
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
	}*/

	return 0;
}
