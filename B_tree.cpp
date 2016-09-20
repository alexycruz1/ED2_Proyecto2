#include "treeNode.h"
#include "B_tree.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

btree::btree(){

}
	
btree::btree(int number){
	size = number;
	root = new treeNode[size];
}

void btree::insert(int value, treeNode* current){
	treeNode nuevo(value);
	if(!this->hasChildren(current)){
		locate(nuevo, current, 0,nuevo);
		treeNode** general = new treeNode*[1];
		general[0] = root;
		recorrerPadres(general,1);
		if(std::find(allKeys.begin(), allKeys.end(), value)==allKeys.end()){
			allKeys.push_back(value);
		}
	}else{
		insert(value,this->getCorrectNode(current,nuevo,0));		
	}
}

void btree::reSize(int number){
	size = number;
	root = new treeNode[size];

	for(int i = 0; i < allKeys.size(); i++){
		this->insert(allKeys[i], root);
	}	
}

vector<int> btree::getKeys(){
	return allKeys;
}
void btree::locate(treeNode nuevo, treeNode* nodo, int pos, treeNode extra){
	treeNode temporal(0);
	cout << "colocar: " << nuevo.getValue() << endl;
	//this->toString(nodo);
	if(pos <= size-1){
		if(nodo == root){
			if(nodo[pos].getValue() == 0){
				nodo[pos] = nuevo;
				nodo[pos].setParentList(NULL);
			}else{
				if(nodo[pos].getValue()<=nuevo.getValue()){
					pos+=1;
					locate(nuevo,nodo,pos,extra);
				}else if(nodo[pos].getValue()>nuevo.getValue()){
					temporal = nodo[pos];
					nodo[pos] = nuevo;
					nodo[pos].setParentList(NULL);
					pos+=1;
					extra = temporal;
					locate(temporal,nodo,pos,extra);
				}
			}
		}else{
			if(nodo[pos].getValue() == 0){
				nodo[pos] = nuevo;
				/*for(int i = 0; i < size; i++){
					if(nodo[i].getParentList()!=NULL ){
						cout << "setea padre de: " << nodo[i].getValue()<<endl;
						nodo[pos].setParentList(nodo[i].getParentList());
						i = size;	
					}
				}*/
			
			}else{
				if(nodo[pos].getValue() <= nuevo.getValue()){
					pos+=1;
					locate(nuevo,nodo,pos,extra);
				}else if(nodo[pos].getValue()>nuevo.getValue()){
					temporal = nodo[pos];
					nodo[pos] = nuevo;
					/*if(temporal.getParentList()!=NULL){
						cout << "setea padre de: " << temporal.getValue()<< endl;
						nodo[pos].setParentList(temporal.getParentList());
					}*/
					pos+=1;
					extra = temporal;
					locate(temporal,nodo,pos,extra);
				}	
			}
		}

		if(nodo[pos].hasRightSon() && nodo[pos].hasLeftSon()){
				treeNode* left = nodo[pos].getLeftSon();
				treeNode* right = nodo[pos].getRightSon();

				/*for(int i = 0; i < size; i++){
					left[i].setParentList(nodo);
					right[i].setParentList(nodo);
				}*/
			}
			
	}else{
		int contador = 0;
		pos = (size+1)/2;
		treeNode* arr = new treeNode[size];
		treeNode* left = new treeNode[size];
		treeNode* right = new treeNode[size];
		nodo[pos].setLeftSon(left);
		nodo[pos].setRightSon(right);

		if(nodo == root){
                        root = arr;
                }else{
                        arr = nodo[pos].getParentList();
                }

		
		for(int i = 0; i < pos; i++){
			left[contador] = nodo[i];
			contador++;	
		}
		
		contador = 0;

		for(int i = pos+1; i<size; i++){
			right[contador] = nodo[i];
			contador++;
		}
		right[contador] = extra;
		setBrothers(arr,nodo[pos]);
		locate(nodo[pos], arr, 0,nodo[pos]);
	}

}

void btree::setBrothers(treeNode* nodo, treeNode value){
	int pos = -1;
	int cero = -1;

	for(int i = 0; i< size; i++){
		if(nodo[i].getValue() == 0){
			cero = i;
			i = size;
		}
	}
	for(int i = 0; i< size; i++){
		if(value.getValue() < nodo[i].getValue()){
			pos = i;
			i = size;	
		}
	}
	
	if(pos != -1){
		if(pos == 0){
			nodo[0].setLeftSon(value.getRightSon());
		}else if(pos > 0 && pos < size-1){
			nodo[pos].setLeftSon(value.getRightSon());
                	nodo[pos-1].setRightSon(value.getLeftSon());
		}
	}else if(pos == -1){
		if(cero!=-1){
			nodo[cero-1].setRightSon(value.getLeftSon());
		}else if(cero == -1){
			nodo[size-1].setRightSon(value.getLeftSon());
		}
	}			
}

string btree::toString(treeNode* nodo){
	for(int i = 0; i < size; i++){
		cout << nodo[i].getValue() << ";";
	}	
	return " ";
}
		

treeNode* btree::getRoot(){
	return root;
}

bool btree::hasChildren(treeNode* nodo){
	for(int i = 0; i < size; i++){
		if(nodo[i].hasChildren()){
			if(nodo[i].hasLeftSon()){
				return true;
			}
			if(nodo[i].hasRightSon()){
				return true;
			}
		}
	}
	return false;
}

treeNode* btree::getCorrectNode(treeNode* nodo, treeNode value, int pos){
	//cout << " eligio: ";
	if(pos<size-1){
		if(nodo[pos+1].getValue() == 0){
			if(value.getValue() < nodo[pos].getValue()){
				//this->toString(nodo[pos].getLeftSon()); 
				//cout << endl;
				nodo[pos].getLeftSon()->setParentList(nodo);
				return nodo[pos].getLeftSon();
			}else if(value.getValue() >= nodo[pos].getValue()){
				//this->toString(nodo[pos].getRightSon());
				//cout << endl;
				nodo[pos].getRightSon()->setParentList(nodo);
				return nodo[pos].getRightSon();
			}
		}else{
			if(value.getValue() >= nodo[pos].getValue() && value.getValue() < nodo[pos+1].getValue()){
				//this->toString(nodo[pos].getRightSon());
				//cout << endl;
				nodo[pos].getRightSon()->setParentList(nodo);
				return nodo[pos].getRightSon();
			}else if(value.getValue() < nodo[pos].getValue()){
				//this->toString(nodo[pos].getLeftSon());
				//cout << endl;
				nodo[pos].getLeftSon()->setParentList(nodo);
				return nodo[pos].getLeftSon();
			}else{
					getCorrectNode(nodo,value,pos+1);
					
			}
		}
	}else{
		if(value.getValue() < nodo[pos].getValue()){
			//this->toString(nodo[pos].getLeftSon());
			//cout << endl;
			nodo[pos].getLeftSon()->setParentList(nodo);
			return nodo[pos].getLeftSon();
		}else if(value.getValue() >= nodo[pos].getValue()){
			//this->toString(nodo[pos].getRightSon());
			//cout << endl;
			nodo[pos].getRightSon()->setParentList(nodo);
			return nodo[pos].getRightSon();
		}
	}
}

void btree::showTree(treeNode** lista, int amount){
	int size2 = amount;
	treeNode** listaNueva;

	for(int i = 0; i < amount; i++){
		treeNode* nodo = lista[i];
		size2+=this->getElements(nodo);
		treeNode* left;
		treeNode* right;
		cout << endl;
		this->toString(nodo);
		cout << endl;
		for(int k = 0; k < size; k++){
			if(nodo[k].getValue()!= 0){
				if(nodo[k].hasChildren()){
					left = nodo[k].getLeftSon();
					right = nodo[k].getRightSon();
					this->toString(left);
					cout << " <------ ";
					cout << nodo[k].getValue();
					cout << " ------> ";
					this->toString(right);
					cout << endl;
				}else{
					cout << nodo[k].getValue();
					cout << " --->" << " no tiene hijos" << endl;
				} 
			}	
		}
		cout << "-----------------------------------------------------" << endl;
	}
	cout << "******************************************************" << endl;
	if(this->hasChildren(lista[0])){
		listaNueva = new treeNode*[size2];
		listaNueva = this->getAllChildren(lista, amount);
		showTree(listaNueva, size2);
	}
}

treeNode** btree::getAllChildren(treeNode** padres, int amount){
	int contador = 0;
	contador = amount;
	treeNode** retorno;
	treeNode** temp;
	treeNode* nodo;
	int pos = 0;
	int num = 0;

	for(int i = 0; i < amount, i++;){
		contador += this->getElements(padres[i]);
	}

	retorno = new treeNode*[contador];

	for(int i = 0; i < amount;i++){
		nodo = padres[i];
		num = this->getElements(nodo) + 1;
		temp = new treeNode*[num];
		temp = this->getChildrenList(nodo);

		for(int i = 0; i < num; i++){
			retorno[pos] = temp[i];
			pos++;
		}
	}
	return retorno;
}

void btree::recorrerPadres(treeNode** general, int amount){
	for(int i = 0; i < amount; i++){
		if(this->hasChildren(general[i])){
			treeNode** subGeneral;
			int amount2 = 0;
			amount2 = this->getElements(general[i])+1;
			subGeneral = new treeNode*[amount2];
			subGeneral = this->getChildrenList(general[i]);
			treeNode* padre = general[i];
			for(int k = 0; k < size; k++){
				if(padre[k].getValue()!=0){
					if(padre[k].hasChildren()){
						treeNode* left = padre[k].getLeftSon();
						treeNode* right = padre[k].getRightSon();
						for(int w = 0; w < size; w++){
							left[w].setParentList(general[i]);
							right[w].setParentList(general[i]);
						}
					}
				}
			}
			recorrerPadres(subGeneral,amount2);
		}else{
			return;
		}
	}
}

int btree::getElements(treeNode* nodo){
	int contador = 0;
	for(int i = 0; i < size; i++){
		if(nodo[i].getValue()!=0){
			contador++;
		}
	}
	return contador;
}

treeNode** btree::getChildrenList(treeNode* nodo){
	int amount = this->getElements(nodo);
	treeNode**retorno = new treeNode*[amount+1];
	int contador = 0;
	for(int i = 0; i < amount; i++){
		if(i < amount-1){
			retorno[contador] = nodo[i].getLeftSon();
			contador++;
		}else if(contador == amount-1){
			retorno[contador] = nodo[i].getLeftSon();
			contador++;
			retorno[contador] = nodo[i].getRightSon();
			contador++;
		}
	}
	return retorno;
}

void btree::borrar(int value){
	if(std::find(allKeys.begin(), allKeys.end(), value)!=allKeys.end()){
		treeNode** nodo = new treeNode*[1];
		nodo[0] = root;
		find(nodo,1,value,value);
		allKeys.erase(allKeys.begin() + (std::find(allKeys.begin(), allKeys.end(), value) - allKeys.begin()));
	}else{
		cout << "este numero no existe" << endl;
	}
}

void btree::find(treeNode** general, int amount, int value, int fakeValue){
	for(int i = 0; i < amount; i++){
		treeNode* padre = general[i];
		if(this->hasChildren(general[i])){
			treeNode** subGeneral;
			int amount2 = 0;
			amount2 = this->getElements(padre)+1;
			subGeneral = new treeNode*[amount2];
			subGeneral = this->getChildrenList(padre);
			
			if(this->contains(padre,value)){
				if(this->isCase1(padre)){
					borrarCase1(padre,value);
				}else if(this->isCase2(general,i,amount)){
					borrarCase2(general,i,amount,value);
				}else if(this->isCase3(general,i,amount)){
					borrarCase3(general,i,amount,value);
				}else if(this->isCase4(padre,value)){
					borrarCase4(padre,value,fakeValue);
				}else if(this->isCase5(padre,value)){
					borrarCase5(padre,value);
				}			
			}else{
				find(subGeneral,amount2,value,value);
			}
		}else{
			if(this->contains(padre,value)){
				if(this->isCase1(padre)){
					borrarCase1(padre,value);
				}else if(this->isCase2(general,i,amount)){
					borrarCase2(general,i,amount,value);
				}else if(this->isCase3(general,i,amount)){
					borrarCase3(general,i,amount,value);
				}else if(this->isCase4(padre,value)){
					borrarCase4(padre,value,fakeValue);
				}else if(this->isCase5(padre,value)){
					borrarCase5(padre,value);
				}
			}
		}
	}
}

bool btree::isCase1(treeNode* padre){
	int elements = 0;
	elements = this->getElements(padre);
	cout<< this->toString(padre)<<endl;

	if(elements >1 && this->isLeaf(padre)){
		return true;
	}
	return false;
}

bool btree::isCase2(treeNode** nodo, int pos, int amount){
	int elements = 0;
	elements = this->getElements(nodo[pos]);
	int opciones = 0;

	if(elements == 1){
		if(this->isLeaf(nodo[pos])){
			opciones = this->getBrothers(amount,pos);
			int sizeL = 0;
			int sizeR = 0;

			if(opciones == 1){
				sizeL = this->getElements(nodo[pos-1]);
				sizeR = this->getElements(nodo[pos+1]);

				if(sizeL>1 || sizeR > 1){
					return true;
				}
			}else if(opciones == 2){
				sizeR = this->getElements(nodo[pos+1]);

				if(sizeR > 1){
					return true;
				}
			}else if(opciones == 3){
				sizeL = this->getElements(nodo[pos-1]);

				if(sizeL > 1){
					return true;
				}
			}
		}
	}
	return false;
}

bool btree::isCase3(treeNode** hermanos, int pos, int amount){
	int elements = this->getElements(hermanos[pos]);
	int opcion = 0;

	if(elements == 1){
		if(this->isLeaf(hermanos[pos]) && hermanos[pos]->getParentList()!=NULL){
			opcion = this->getBrothers(amount,pos);
			int sizeL = 0;
			int sizeR = 0;
			int sizePadre = 0;
			sizePadre = this->getElements(hermanos[pos]->getParentList());

			if(sizePadre>1){
				if(opcion == 1){
					sizeL = this->getElements(hermanos[pos-1]);
					sizeR = this->getElements(hermanos[pos+1]);
					if(sizeL == 1 && sizeR == 1){
						return true;
					}
				}else if(opcion == 2){
					sizeR = this->getElements(hermanos[pos+1]);
					if(sizeR == 1){
						return true;
					}
				}else if(opcion == 3){
					sizeL = this->getElements(hermanos[pos-1]);
					if(sizeL == 1){
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool btree::isCase4(treeNode* nodo, int value){
	if(!this->isLeaf(nodo)){
		int sizeP = this->getElements(nodo);
		if(sizeP >= 1){
			treeNode valor;
			treeNode* left;
			treeNode* right;
			int sizeL = 0;
			int sizeR = 0;

			for(int i = 0; i < size; i++){
				if(nodo[i].getValue() == value){
					valor = nodo[i];
				}
			}

			left = valor.getLeftSon();
			right = valor.getRightSon();
			sizeL = this->getElements(left);
			sizeR = this->getElements(right);

			if(sizeL > 1 || sizeR > 1){
				return true;
			}
		}
	}
	return false;
}

bool btree::isCase5(treeNode* nodo, int value){
	if(!this->isLeaf(nodo)){
		int keys = this->getElements(nodo);

		if(keys > 1){
			int position = 0;

			for(int i = 0; i < keys;i++){
				if(nodo[i].getValue() == value){
					position = i;
					i =size;
				}
			}
			treeNode* left = nodo[position].getLeftSon();
			treeNode* right = nodo[position].getRightSon();
			int sizeL = this->getElements(left);
			int sizeR = this->getElements(right);

			if(sizeL == 1 && sizeR == 1){
				return true;
			}
		}
	}
	return false;
}

void btree::borrarCase1(treeNode* padre, int value){
	treeNode* temporal = new treeNode[size];
	int contador = 0;
	for(int i = 0; i < size; i++){
		temporal[i] = padre[i];
	}

	for(int i = 0; i < size; i++){
		if(temporal[i].getValue() == value){
			
		}else{
			padre[contador] = temporal[i];
			contador++;
		}
	}

	for(int i = contador; i < size; i++){
		padre[i].setValue(0);
	}
}

void btree::borrarCase2(treeNode** hermanos, int pos, int amount, int value){
		int kind = 0;
		kind = this->getBrothers(amount, pos);
		int sizeR = 0;
		int sizeL = 0;
		int position = 0;
		treeNode* element;
		treeNode lastElement;
		treeNode* padre;
		treeNode elementPadre;
		if(kind == 1){	
			sizeL = this->getElements(hermanos[pos-1]);
			sizeR = this->getElements(hermanos[pos+1]);

			if(sizeL>1){
				element = hermanos[pos-1];
				lastElement = element[sizeL-1];
				lastElement.setLeftSon(hermanos[pos-1]);
				lastElement.setRightSon(hermanos[pos]);
				padre = lastElement.getParentList();
				position = this->findPosition(padre,value,0,amount-1);
				elementPadre = padre[position];
				elementPadre.setRightSon(NULL);
				elementPadre.setLeftSon(NULL);
				this->borrarCase1(hermanos[pos-1],lastElement.getValue());
				this->borrarCase1(hermanos[pos],value);
				setBrothers(padre,lastElement);
				padre[position] = lastElement;
				insert(elementPadre.getValue(),root);
			}else if(sizeR>1){
				element = hermanos[pos+1];
				lastElement = element[0];
				lastElement.setLeftSon(hermanos[pos]);
				lastElement.setRightSon(hermanos[pos+1]);
				padre = lastElement.getParentList();
				position = this->findPosition(padre,lastElement.getValue(),0,amount-1);
				elementPadre = padre[position];
				elementPadre.setRightSon(NULL);
				elementPadre.setLeftSon(NULL);
				this->borrarCase1(hermanos[pos+1],lastElement.getValue());
				this->borrarCase1(hermanos[pos],value);
				setBrothers(padre,lastElement);
				padre[position] = lastElement;
				insert(elementPadre.getValue(),root);
			}
		}else if(kind == 2){
			sizeR = this->getElements(hermanos[pos+1]);
			element = hermanos[pos+1];
			lastElement = element[0];
			lastElement.setLeftSon(hermanos[pos]);
			lastElement.setRightSon(hermanos[pos+1]);
			padre = lastElement.getParentList();
			position = this->findPosition(padre,lastElement.getValue(),0,amount-1);
			elementPadre = padre[position];
			elementPadre.setRightSon(NULL);
			elementPadre.setLeftSon(NULL);
			this->borrarCase1(hermanos[pos+1],lastElement.getValue());
			this->borrarCase1(hermanos[pos],value);
			setBrothers(padre,lastElement);
			padre[position] = lastElement;
			insert(elementPadre.getValue(),root);
		}else if(kind == 3){
			sizeL = this->getElements(hermanos[pos-1]);
			element = hermanos[pos-1];
			lastElement = element[sizeL-1];
			lastElement.setLeftSon(hermanos[pos-1]);
			lastElement.setRightSon(hermanos[pos]);
			padre = lastElement.getParentList();
			position = this->findPosition(padre,value,0,amount-1);
			elementPadre = padre[position];
			elementPadre.setRightSon(NULL);
			elementPadre.setLeftSon(NULL);
			this->borrarCase1(hermanos[pos-1],lastElement.getValue());
			this->borrarCase1(hermanos[pos],value);
			setBrothers(padre,lastElement);
			padre[position] = lastElement;
			insert(elementPadre.getValue(),root);
		}
}

void btree::borrarCase3(treeNode** hermanos, int pos, int amount, int value){
	int kind = 0; 
	kind = this->getBrothers(amount,pos);
	treeNode* padre;
	padre = hermanos[pos]->getParentList();
	int position = 0;
	treeNode elementPadre;
	treeNode* bro;

	if(kind == 1){
		bro = hermanos[pos+1];
		position = this->findPosition(padre,bro[0].getValue(),0,amount-1);
		elementPadre = padre[position];
		padre[position-1].setRightSon(padre[position].getRightSon());
		padre[position].setLeftSon(NULL);
		padre[position].setRightSon(NULL);
		this->borrarCase1(padre,padre[position].getValue());
		this->borrarCase1(hermanos[pos],value);
		insert(elementPadre.getValue(), root);
	}else if(kind == 2){
		bro = hermanos[pos+1];
		position = this->findPosition(padre,bro[0].getValue(),0,amount-1);
		elementPadre = padre[position];
		padre[position].setLeftSon(NULL);
		padre[position].setRightSon(NULL);
		this->borrarCase1(padre,padre[position].getValue());
		this->borrarCase1(hermanos[pos],value);
		insert(elementPadre.getValue(), root);
	}else if(kind == 3){
		bro = hermanos[pos-1];
		position = this->findPosition(padre,value,0,amount-1);
		elementPadre = padre[position];
		padre[position].setLeftSon(NULL);
		padre[position].setRightSon(NULL);
		this->borrarCase1(padre,padre[position].getValue());
		this->borrarCase1(hermanos[pos],value);
		insert(elementPadre.getValue(), root);
	}
}

void btree::borrarCase4(treeNode* nodo, int valueVerdadero, int valueFalso){
	int position = 0;
	int sizeL = 0;
	int sizeR = 0;
	treeNode cambio;
	treeNode* left;
	treeNode* right;

	for(int i = 0; i < size; i++){
		if(nodo[i].getValue() == valueFalso){
			position = i;
			i = size;
		}
	}

	left = nodo[position].getLeftSon();
	right = nodo[position].getRightSon();
	sizeL = this->getElements(left);
	sizeR = this->getElements(right);
	if(this->isLeaf(left)){
		if(sizeR > 1){
			int value2 = 0;
			value2 = right[0].getValue();
			right[0].setValue(valueVerdadero);
			nodo[position].setValue(value2);
			borrar(valueVerdadero);
		}else if(sizeL > 1){
			int value2 = 0;
			value2 = left[sizeL-1].getValue();

			left[sizeL-1].setValue(valueVerdadero);
			nodo[position].setValue(value2);
			borrar(valueVerdadero);
		}
	}else{
		if(sizeR > 1){
			valueFalso = right[0].getValue();
			borrarCase4(right,valueVerdadero,valueFalso);

		}else if(sizeL > 1){
			valueFalso = left[sizeL-1].getValue();
			borrarCase4(left,valueVerdadero,valueFalso);
		}
	}

}

void btree::borrarCase5(treeNode* nodo, int value){
	int position = 0;

	for(int i = 0; i < size; i++){
		if(nodo[i].getValue() == value){
			position = i;
			i = size;
		}
	}
	cout << "pos: " << position << endl;
	treeNode* right = nodo[position].getRightSon();
	treeNode* left = nodo[position].getLeftSon();
	nodo[position].setValue(left[0].getValue());
	left[0].setValue(right[0].getValue());
	right[0].setValue(value);
	borrar(value);
}

int btree::findPosition(treeNode* padre, int value, int pos, int amount){
	if(pos == amount-1){
		if(value<padre[pos].getValue()){
			return pos-1;
		}else{
			return pos;
		}
	}else{
		if(value < padre[pos].getValue()){
			return pos;
		}else{
			findPosition(padre,value,pos+1,amount);
		}
	}
}

int btree::getBrothers(int amount, int pos){
	if(pos > 0 && pos < amount -1){
		return 1;
	}else if(pos == 0){
		return 2;
	}else if(pos == amount-1){
		return 3;
	}
}

bool btree::contains(treeNode* nodo , int value){
	for(int i = 0; i < size; i++){
		if(nodo[i].getValue() == value){
			return true;
		}
	}
	return false;
}

bool btree::isLeaf(treeNode* nodo){
	if(this->hasChildren(nodo)){
		return false;
	}
	return true;
}






