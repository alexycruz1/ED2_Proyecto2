#include <iostream>
#include <ncurses.h>
#include "node.h"
#include "B_tree.h"
#include "treeNode.h"
#include "AVLTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	int width, height;
	char salir = '0';
	int pruebas = 0;
	string size = "";
	char SizeTemp[15];
	vector<int> lista;

	initscr();
	(void)echo();

	getmaxyx(curscr, height, width);

	mvprintw(3,width-100,"Ingrese el tamaño de su Arbol-B: ");
	getnstr(SizeTemp, sizeof(SizeTemp) - 1);
	//sacar la string

	for(int i = 0; i < 16; i++){
		if(SizeTemp[i] != ' '){
			size += SizeTemp[i];
		}
	}
	int sizeArbol = atoi(size.c_str());
	btree tree(sizeArbol);

	char opcion1 = '0';


	while(opcion1 != '3'){
		clear();
		init_pair(1, COLOR_BLUE, COLOR_BLACK);
		init_pair(2, COLOR_RED, COLOR_BLACK);

		attron(COLOR_PAIR(1));
		mvprintw(3,width-100,"DATA-BASE MODELING");

		attron(COLOR_PAIR(2));
		mvprintw(5,width-100,"1.- Arbol AVL");
		mvprintw(6,width-100,"2.- Arbol B");
		mvprintw(7,width-100,"3.- SALIR");

		mvprintw(8,width-100,"Ingrese una opcion: ");
		opcion1 = getch();
		
		if(opcion1 == '1'){//OPCIONES AVL
			char opcion2 = '1';
			while(opcion2 != '0'){
				clear();
				mvprintw(3,width-100,"ARBOL Adelson-Velskii y Landis");
				mvprintw(5,width-100,"1.- Agregar");
				mvprintw(6,width-100,"2.- Eliminar");
				mvprintw(7,width-100,"3.- Buscar");
				mvprintw(8,width-100,"4.- Mostrar");
				mvprintw(11,width-50,"SALIR[0]");
				mvprintw(9,width-100,"Ingrese una opcion: ");
				opcion2 = getch();

				if(opcion2 == '1'){//Agregar AVL
					clear();
					string ValorIngresado = "";
					char ValorIngresadoTemp[15];
					int ValorAgregar;

					mvprintw(3,width-100,"ARBOL Adelson-Velskii y Landis");
					mvprintw(7, width-50, "SALIR [0]");

					mvprintw(5,width-100,"Digite un valor para ingresar al arbol AVL: ");
					getnstr(ValorIngresadoTemp, sizeof(ValorIngresadoTemp) - 1);

					//sacar la string
					for(int i = 0; i < 16; i++){
						if(ValorIngresadoTemp[i] != ' '){
							ValorIngresado += ValorIngresadoTemp[i];
						}
					}

					int ValorAgregarTemp = atoi(ValorIngresado.c_str());
					if(ValorAgregarTemp != 0){
						ValorAgregar = ValorAgregarTemp;
						Arbolito.AddNode(ValorAgregar);
						NodosTotales++;

						pruebas = ValorAgregar;
					}else{
						opcion2 = '0';
					}


					if(opcion2 != '0'){
						mvprintw(6,width-100,"VALOR INGRESADO EXITOSAMENTE!");
						refresh();
						getch();
					}else{
						mvprintw(6,width-100,"Regresaras al menu principal");
						opcion2 = '0';
						getch();
					}
				}else if(opcion2 == '2'){//eliminar AVL
					clear();
					string ValorIngresado = "";
					char ValorIngresadoTemp[15];
					int ValorBorrar;

					mvprintw(3,width-100,"ARBOL Adelson-Velskii y Landis");
					mvprintw(7, width-50, "SALIR [0]");

					mvprintw(5,width-100,"Digite un valor para borrar del arbol AVL: ");
					getnstr(ValorIngresadoTemp, sizeof(ValorIngresadoTemp) - 1);

					//sacar la string
					for(int i = 0; i < 16; i++){
						if(ValorIngresadoTemp[i] != ' '){
							ValorIngresado += ValorIngresadoTemp[i];
						}
					}

					int ValorAgregarTemp = atoi(ValorIngresado.c_str());
					if(ValorAgregarTemp != 0){
						ValorBorrar = ValorAgregarTemp;
						Arbolito.DeleteNode(ValorBorrar, NodosTotales, 0);
						NodosTotales--;
					}else{
						opcion2 = '0';
					}


					if(opcion2 != '0'){
						mvprintw(6,width-100,"VALOR INGRESADO EXITOSAMENTE!");
						refresh();
						getch();
					}else{
						mvprintw(6,width-100,"Regresaras al menu principal");
						opcion2 = '0';
						getch();
					}
				}else if(opcion2 == '3'){//buscar AVL (PENDIENTE)
					clear();
					string ValorIngresado = "";
					char ValorIngresadoTemp[15];
					int ValorBuscar;

					mvprintw(3,width-100,"ARBOL Adelson-Velskii y Landis");
					mvprintw(7, width-50, "SALIR [0]");

					mvprintw(5,width-100,"Digite un valor para buscar en el Arbol-B: ");
					getnstr(ValorIngresadoTemp, sizeof(ValorIngresadoTemp) - 1);

					//sacar la string
					for(int i = 0; i < 16; i++){
						if(ValorIngresadoTemp[i] != ' '){
							ValorIngresado += ValorIngresadoTemp[i];
						}
					}

					int ValorAgregarTemp = atoi(ValorIngresado.c_str());
					if(ValorAgregarTemp != 0){
						ValorBuscar = ValorAgregarTemp;
						Node* PadreBuscado = Arbolito.Buscar(ValorBuscar, NodosTotales);
						mvprintw(5,width-100,"El valor del padre del nodo buscado es: ", "%i", (*PadreBuscado).getValue());
						//mvprintw(5,width-60, "%i", (*PadreBuscado).getValue());
					}else{
						opcion2 = '0';
					}


					if(opcion2 != '0'){
						mvprintw(6,width-100,"VALOR INGRESADO EXITOSAMENTE!");
						refresh();
						getch();
					}else{
						mvprintw(6,width-100,"Regresaras al menu principal");
						opcion2 = '0';
						getch();
					}
				}else if(opcion2 == '4'){//MOSTRAR AVL (PENDIENTE)
					
				}
			}
		}else if(opcion1 == '2'){//OPCIONES ARBOL-B
			char opcion3 = '1';
			while(opcion3 != '0'){
				clear();
				mvprintw(3,width-100,"ARBOL-B");
				mvprintw(5,width-100,"1.- Agregar");
				mvprintw(6,width-100,"2.- Eliminar");
				mvprintw(7,width-100,"3.- Cargar");
				mvprintw(8,width-100,"4.- Mostrar");
				mvprintw(9,width-100,"5.- Cambiar size");
				mvprintw(12,width-50,"SALIR[0]");
				mvprintw(10,width-100,"Ingrese una opcion: ");
				opcion3 = getch();

				if(opcion3 == '1'){//AGREGAR ARBOL-B
					clear();
					string ValorIngresado = "";
					char ValorIngresadoTemp[15];
					int ValorAgregar;

					mvprintw(3,width-100,"ARBOL-B");
					mvprintw(7, width-50, "SALIR [0]");

					mvprintw(5,width-100,"Digite un valor para ingresar al Arbol-B: ");
					getnstr(ValorIngresadoTemp, sizeof(ValorIngresadoTemp) - 1);

					//sacar la string
					for(int i = 0; i < 16; i++){
						if(ValorIngresadoTemp[i] != ' '){
							ValorIngresado += ValorIngresadoTemp[i];
						}
					}

					int ValorAgregarTemp = atoi(ValorIngresado.c_str());
					if(ValorAgregarTemp != 0){
						ValorAgregar = ValorAgregarTemp;
						tree.insert(ValorAgregar, tree.getRoot());
					}else{
						opcion3 = '0';
					}


					if(opcion3 != '0'){
						mvprintw(6,width-100,"VALOR INGRESADO EXITOSAMENTE!");
						refresh();
						getch();
					}else{
						mvprintw(6,width-100,"Regresaras al menu principal");
						opcion3 = '0';
						getch();
					}
				}else if(opcion3 == '2'){//ELIMINAR ARBOL-B
					clear();
					string ValorIngresado = "";
					char ValorIngresadoTemp[15];
					int ValorBorrar;

					mvprintw(3,width-100,"ARBOL-B");
					mvprintw(7, width-50, "SALIR [0]");

					mvprintw(5,width-100,"Digite un valor para borrar del Arbol-B: ");
					getnstr(ValorIngresadoTemp, sizeof(ValorIngresadoTemp) - 1);

					//sacar la string
					for(int i = 0; i < 16; i++){
						if(ValorIngresadoTemp[i] != ' '){
							ValorIngresado += ValorIngresadoTemp[i];
						}
					}

					int ValorAgregarTemp = atoi(ValorIngresado.c_str());
					if(ValorAgregarTemp != 0){
						ValorBorrar = ValorAgregarTemp;
						tree.borrar(ValorBorrar);
					}else{
						opcion3 = '0';
					}


					if(opcion3 != '0'){
						mvprintw(6,width-100,"VALOR INGRESADO EXITOSAMENTE!");
						refresh();
						getch();
					}else{
						mvprintw(6,width-100,"Regresaras al menu principal");
						opcion3 = '0';
						getch();
					}
				}else if(opcion3 == '3'){//CARGAR ARBOL-B (PENDIENTE)

				}else if(opcion3 == '4'){//MOSTRAR ARBOL-B (PENDIENTE)

				}else if(opcion3 == '5'){//CAMBIAR SIZE ARBOL-B
					clear();
					string ValorIngresado = "";
					char ValorIngresadoTemp[15];
					int size;

					mvprintw(3,width-100,"ARBOL-B");
					mvprintw(7, width-50, "SALIR [0]");

					mvprintw(5,width-100,"Digite el nuevo size del Arbol-B: ");
					getnstr(ValorIngresadoTemp, sizeof(ValorIngresadoTemp) - 1);

					//sacar la string
					for(int i = 0; i < 16; i++){
						if(ValorIngresadoTemp[i] != ' '){
							ValorIngresado += ValorIngresadoTemp[i];
						}
					}

					int SizeTemp = atoi(ValorIngresado.c_str());
					if(SizeTemp != 0){
						size = SizeTemp;
						btree arbol(size);
						lista = tree.getKeys();

						for(int i = 0; i < lista.size(); i++){
							arbol.insert(lista[i], arbol.getRoot());
						}

						tree = arbol;
					}else{
						opcion3 = '0';
					}


					if(opcion3 != '0'){
						mvprintw(6,width-100,"VALOR INGRESADO EXITOSAMENTE!");
						refresh();
						getch();
					}else{
						mvprintw(6,width-100,"Regresaras al menu principal");
						opcion3 = '0';
						getch();
					}
				}
			}
		}
		clear();
	}


	//aqui termina la mierda
	getch();
	endwin();
	cout << "EL NUMERO QUE CONVERTISTE ES: " << pruebas << endl;
	Arbolito.Recorrido(Arbolito.getRootPointer());
	return 0;	
}


/*int size = 0;
	int number = 0;
	int decision = 0;
	bool seguir = true;
	string word = "";
	cout << "---------------------------------------------------" << endl;
	cout << "ingrese el tamaño de su arbol: ";
	cin >> size;
	btree tree(size);
	//EL VECTOR Y EL ARREGLO VALEN PIJA
	vector<int> lista;
	int lista2[] = {21,33,77,98,12,6,31,44,28,4,3,99,101,200,14,1};

	//ESTO ESTA EN UN WHILE PERO COMO LO VAS A ACOMODAR A NCURSES, PUES NO SE QUE PUTAS HARAS
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
			//AQUI PEDIS EL NUMERO Y LO MANDAS A INSERTAR AL ARBOL, FIJATE QUE LA FUNCION TAMBIEN RECIBE A LA RAIZ DEL ARBOL
			cout << "Ingrese un numero: ";
			cin >> number;
			tree.insert(number, tree.getRoot());
		}else if(decision == 2){	
			//AQUI BORRAS UN ELEMENTO
			cout << "Ingrese un numero: ";
			cin >> number;
			tree.borrar(number);
		}else if(decision == 3){
			//AQUI MOSTRAS EL ARBOL PERO ME FALTA HACER LA FUNCION
			treeNode** root = new treeNode*[1];
			root[0] = tree.getRoot();
			tree.showTree(root, 1);
		}else if(decision == 4){
			//AQUI CARGAS EL ARCHIVO DE TEXTO PERO ESTO FALLA
			//loadNumbers(lista);
			for(int i = 0; i < 16; i++){
				lista.push_back(lista2[i]);
			}
			for(int i = 0; i < 16; i++){
				tree.insert(lista[i], tree.getRoot());
			}

		}else if(decision == 5){
			//aQUI LE CAMBIAS EL SIZE EL ARBOL EN CASO DE QUE EL USUARIO QUIERA
			cout << "Nuevo Size: ";
			cin >>size;
			btree arbol(size);
			lista = tree.getKeys();

			for(int i = 0; i < lista.size(); i++){
				arbol.insert(lista[i],arbol.getRoot());
			}
			tree = arbol;
		}
		//EN ESTA COSA MERA PIJA SE SALE DEL CICLO
		decision == 6 ? seguir = false : seguir = true;
	}*/


	//ESTA FUNCION ES PARA CARGAR EL ARCHIVO	
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

