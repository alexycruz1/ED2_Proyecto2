 #pragma once
#include <vector>

using std::vector;

class treeNode{
	int value;
	treeNode* leftSon;
	treeNode* rightSon;
	treeNode* parentList;
	treeNode* rightBro;
	treeNode* leftBro;

  public: 
	treeNode();
	treeNode(int value);
	treeNode* getLeftSon();
	treeNode* getRightSon();
	void setLeftSon(treeNode*);
	void setRightSon(treeNode*);
	int getValue();
	int setValue(int);
	bool hasRightSon();
	bool hasLeftSon();
	bool hasRightBro();
	bool hasLeftBro();
	bool hasParentList();
	treeNode* getRightBro();
	treeNode* getLeftBro();
	treeNode* getParentList();
	void setRightBro(treeNode*);
	void setLeftBro(treeNode*);
	void setParentList(treeNode*);
};
