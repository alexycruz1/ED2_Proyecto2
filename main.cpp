#include <iostream>
#include "node.h"
#include "B_tree.h"
#include "treeNode.h"
#include "AVLTree.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

using std::stringstream;
using std::vector;
using std::string;
using std::atoi;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

void loadNumbers(vector<int>&);

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
//****************************************************************************************************************************************************	
	

	int size = 0;
	int number = 0;
	int decision = 0;
	bool seguir = true;
	string word = "";
	cout << "---------------------------------------------------" << endl;
	cout << "ingrese el tamaño de su arbol: ";
	cin >> size;
	btree tree(size);
	vector<int> lista;
	int lista2[] = {21,33,77,98,12,6,31,44,28,4,3,99,101,200,14,1};

	while(seguir){
		cout << "*************************************************************************" << endl;
		cout << "1. Para Agregar. " << endl;
		cout << "2. Para Borrar. " << endl;
		cout << "3. Mostrar" << endl;
		cout << "4. Cargar arbol" << endl;
		cout << "5. Cambiar Size" << endl;
		cout << "6 salir" << endl;
		cin >> decision;

		if(decision == 1){
			cout << "Ingrese un numero: ";
			cin >> number;
			tree.insert(number, tree.getRoot());
		}else if(decision == 2){	
			cout << "Ingrese un numero: ";
			cin >> number;
			tree.borrar(number);
		}else if(decision == 3){
			treeNode** root = new treeNode*[1];
			root[0] = tree.getRoot();
			tree.showTree(root, 1);
		}else if(decision == 4){
			//loadNumbers(lista);
			for(int i = 0; i < 16; i++){
				lista.push_back(lista2[i]);
			}
			for(int i = 0; i < 16; i++){
				tree.insert(lista[i], tree.getRoot());
			}

		}else if(decision == 5){
			cout << "Nuevo Size: ";
			cin >>size;
			btree arbol(size);
			lista = tree.getKeys();

			for(int i = 0; i < lista.size(); i++){
				arbol.insert(lista[i],arbol.getRoot());
			}
			tree = arbol;
		}

		decision == 6 ? seguir = false : seguir = true;
	}
	return 0;	
}

void loadNumbers(vector<int>& lista){
	ifstream fentrada;
	fentrada.open("numeros.txt");
    stringstream ss;
    string numero;

    while(!fentrada.fail()){
    	char digito;
    	fentrada >> digito;
    	if(!fentrada.fail()){
    		if(digito == ','){
    			numero = ss.str();
    			ss.str("");
    			int b = atoi(numero.c_str());
    			lista.push_back(b);
    		}else{
    			ss << digito;
    		}
    	}
    }
    fentrada.close();
}

	

