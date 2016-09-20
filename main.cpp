#include <iostream>
#include <ncurses.h>
#include "node.h"
#include "B_tree.h"
#include "treeNode.h"
#include "AVLTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	int NodosTotales = 0;
	AVLTree Arbolito(0);
	int width, height;
	char salir = '0';
	int pruebas = 0;


	initscr();
	(void)echo();
	char opcion1 = '0';


	while(opcion1 != '3'){
		getmaxyx(curscr, height, width);

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
		
		if(opcion1 == '1'){
			char opcion2 = '1';
			while(opcion2 != '0'){
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
			}
		}else if(opcion1 == '2'){
			char opcion3 = '1';
			while(opcion3 != '0'){
				mvprintw(3,width-100,"ARBOL-B");
			}
		}
		clear();
	}


	//aqui termina la mierda
	getch();
	endwin();
	cout << "EL NUMERO QUE CONVERTISTE ES: " << pruebas << endl;
	Arbolito.Recorrido(Arbolito.getRoot());
	return 0;	
}

	

