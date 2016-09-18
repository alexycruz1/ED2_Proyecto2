 #pragma once
#include <vector>

using std::vector;

class treeNode{
	int value;
	treeNode* padre;
	treeNode* leftSon;
	treeNode* rightSon;
	treeNode* parentList;

  public: 
	treeNode();
	treeNode(int value);
	treeNode* getLeftSon();
	treeNode* getRightSon();
	void setPadre(treeNode*);
	treeNode* getPadre();
	void setLeftSon(treeNode*);
	void setRightSon(treeNode*);
	int getValue();
	int setValue(int);
	bool hasRightSon();
	bool hasLeftSon();
	bool hasParentList();
	treeNode* getParentList();
	void setParentList(treeNode*);
	bool hasChildren();
};
