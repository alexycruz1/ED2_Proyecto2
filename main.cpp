#include <iostream>
#include "node.h"
#include "B_tree.h"
#include "treeNode.h"
#include "AVLTree.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	int NodosTotales = 0;
	AVLTree Arbolito(0);
	NodosTotales++;

	Arbolito.AddNode(9);//-> esta es raiz
	Arbolito.AddNode(3);
	NodosTotales++;
	//Arbolito.AddNode(4);
	NodosTotales++;
	//Arbolito.AddNode(15);
	NodosTotales++;
	//Arbolito.AddNode(11);
	NodosTotales++;
	//Arbolito.AddNode(2);
	NodosTotales++;
	//Arbolito.AddNode(16);
	NodosTotales++;
	//Arbolito.AddNode();
	//Arbolito.AddNode();

	cout << "El valor de la raiz es: " << Arbolito.getRoot().getValue() << endl;
	cout << "El valor del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon()).getValue() << endl;
	//Arbolito.DeleteNode(9, NodosTotales, 0);


	//cout << "El valor de la raiz es: " << Arbolito.getRoot().getValue() << endl;
	//cout << "El valor del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon()).getValue() << endl;
	//cout << "El valor del hijo del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon().getLeftSon()).getValue() << endl;
	//cout << "El valor del hijo del hijo derecho es: " << (Arbolito.getRoot().getLeftSon().getRightSon()).getValue() << endl;

	//cout << "El valor del hijo derecho es: " << (Arbolito.getRoot().getRightSon()).getValue() << endl;
	/*cout << "El valor de la raiz es: " << Arbolito.getRoot().getValue() << endl;

	cout << "El valor del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon()).getValue() << endl;
	cout << "El valor del hijo del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon().getLeftSon()).getValue() << endl;
	//cout << "El valor del hijo del hijo derecho es: " << (Arbolito.getRoot().getLeftSon().getRightSon()).getValue() << endl;

	cout << "El valor del hijo derecho es: " << (Arbolito.getRoot().getRightSon()).getValue() << endl;
	cout << "El valor del hijo del hijo derecho es: " << (Arbolito.getRoot().getRightSon().getRightSon()).getValue() << endl;
	cout << "El valor del hijo del hijo izquierdo es: " << (Arbolito.getRoot().getRightSon().getLeftSon()).getValue() << endl;

	cout << "NUEVOS VALORES: " << endl;

	cout << "El valor de la raiz es: " << Arbolito.getRoot().getValue() << endl;

	cout << "El valor del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon()).getValue() << endl;
	cout << "El valor del hijo del hijo izquierdo es: " << (Arbolito.getRoot().getLeftSon().getLeftSon()).getValue() << endl;
	cout << "El valor del hijo del hijo derecho es: " << (Arbolito.getRoot().getLeftSon().getRightSon()).getValue() << endl;

	cout << "El valor del hijo derecho es: " << (Arbolito.getRoot().getRightSon()).getValue() << endl;
	cout << "El valor del hijo del hijo derecho es: " << (Arbolito.getRoot().getRightSon().getRightSon()).getValue() << endl;
	//cout << "El valor del hijo del hijo izquierdo es: " << (Arbolito.getRoot().getRightSon().getLeftSon()).getValue() << endl;*/

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
	
	seguir = true;
	while(seguir){
		cout << "Que numero desea borrar? " << endl;
		cin>>num;
		arbol.borrar(num);
		cout << "desea contunuar : ";
		cin >> dec;
		dec == 1? seguir = true:seguir = false;
	}	
	arbol.showTree();
	return 0;	
}

	

