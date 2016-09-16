#pragma once
#include "treeNode.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class btree{
	vector<treeNode> root;
	int size;

  public:
	btree();
	btree(int);
	void insert(int);
	string toString();
};
