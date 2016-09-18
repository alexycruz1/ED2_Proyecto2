#pragma once
#include "treeNode.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class btree{
	treeNode* root;
	int size;

  public:
	btree();
	btree(int);
	void insert(int, treeNode*);
	string toString(treeNode*);
	treeNode* getRoot();
	void locate(treeNode, treeNode*, int,treeNode);
	bool hasChildren(treeNode*);
	treeNode* getCorrectNode(treeNode*, treeNode, int);
	void showTree();
	void setBrothers(treeNode*, treeNode);
	void recorrerPadres(treeNode**, int);
	int getElements(treeNode*);
	treeNode** getChildrenList(treeNode*);
	void borrar(int value);
	void find(treeNode**, int, int);
	bool contains(treeNode*, int);
	bool isLeaf(treeNode*);
	void borrarCase1(treeNode*, int);
	void borrarCase2(treeNode**,int,int,int);
	void borrarCase3(treeNode**,int,int,int);
	bool isCase1(treeNode*);
	bool isCase2(treeNode**, int, int);
	bool isCase3(treeNode**, int, int);
	int getBrothers(int,int);
	int findPosition(treeNode*, int, int,int);
};
