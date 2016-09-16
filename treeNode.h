 #pragma once
#include <vector>

using std::vector;

class treeNode{
	int value;
	vector<treeNode> leftSon;
	vector<treeNode> rightSon;
	vector<treeNode> parentList;
	treeNode* rightBro;
	treeNode* leftBro;

  public: 
	treeNode();
	treeNode(int value);
	vector<treeNode> getLeftSon();
	vector<treeNode> getRightSon();
	void setLeftSon(vector<treeNode>);
	void setRightSon(vector<treeNode>);
	int getValue();
	int setValue(int);
	bool hasRightSon();
	bool hasLeftSon();
	bool hasRightBro();
	bool hasLeftBro();
	bool hasParentList();
	treeNode* getRightBro();
	treeNode* getLeftBro();
	vector<treeNode> getParentList();
	void setRightBro(treeNode*);
	void setLeftBro(treeNode*);
	void setParentList(vector<treeNode>);
};
