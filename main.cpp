#include <iostream>
#include "node.h"
#include "B_tree.h"
#include "treeNode.h"
#include "AVLTree.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	AVLTree Arbolito(6);

	Arbolito.AddNode(5);
	Arbolito.AddNode(4);
	//Arbolito.AddNode();
	//Arbolito.AddNode();

	cout << "El valor de la raiz es: " << Arbolito.getRoot().getValue() << endl;
	cout << "El valor del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon()).getValue() << endl;
	cout << "El valor del hijo del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon().getLeftSon()).getValue() << endl;
	//cout << "El valor del hijo del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon().getLeftSon().getValue()) << endl;
	/*cout << "El valor del hijo derecho es: " << Raiz.getRightSon().getValue() << endl;
	Node Temporal = Raiz.getRightSon();
	cout << "El valor del hijo de 4 es: " << Temporal.hasRightSon() << endl;
	//cout << "El valor del hijo de 2 es: " << Insertar1.getLeftSon().getValue() << endl;

	cout << endl;
	cout << "ELIMINAR" << endl;
	cout << endl;

	Arbolito.DeleteNode(&Insertar2);

	cout << "El valor de la raiz es: " << Raiz.getValue() << endl;
	cout << "El valor del hijo izquierdo es: " << Raiz.getLeftSon().getValue() << endl;
	cout << "El valor del hijo derecho es: " << Raiz.getRightSon().getValue() << endl;

	if (Raiz.hasRightSon()){
		cout << "Tengo hijo derecho aunque no deberia" << endl;
	}else{
		cout << "No tengo Hijo, asi deberia ser"<< endl;
	}*/

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
