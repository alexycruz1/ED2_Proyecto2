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
	void locate(treeNode, treeNode*, int);
	bool hasChildren(treeNode*);
};
