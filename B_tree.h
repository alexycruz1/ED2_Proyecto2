#pragma once
#include "treeNode.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class btree{
	treeNode* root;
	int size;
	vector<int> allKeys;

  public:
	btree();
	btree(int);
	void insert(int, treeNode*);
	string toString(treeNode*);
	treeNode* getRoot();
	void locate(treeNode, treeNode*, int,treeNode);
	bool hasChildren(treeNode*);
	treeNode* getCorrectNode(treeNode*, treeNode, int);
	void showTree(treeNode**, int);
	void setBrothers(treeNode*, treeNode);
	void recorrerPadres(treeNode**, int);
	int getElements(treeNode*);
	treeNode** getChildrenList(treeNode*);
	void borrar(int value);
	void find(treeNode**, int, int,int);
	bool contains(treeNode*, int);
	bool isLeaf(treeNode*);
	void borrarCase1(treeNode*, int);
	void borrarCase2(treeNode**,int,int,int);
	void borrarCase3(treeNode**,int,int,int);
	void borrarCase4(treeNode*, int,int);
	void borrarCase5(treeNode*, int);
	bool isCase1(treeNode*);
	bool isCase2(treeNode**, int, int);
	bool isCase3(treeNode**, int, int);
	bool isCase4(treeNode*, int);
	bool isCase5(treeNode*, int);
	int getBrothers(int,int);
	int findPosition(treeNode*, int, int,int);
	treeNode** getAllChildren(treeNode**, int);
	void reSize(int);
	vector<int> getKeys();
};
