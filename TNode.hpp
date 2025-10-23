

#ifndef TNode_HPP_
#define TNode_HPP_

#include <iostream>
#include <stdlib.h>
#include "Species.hpp"

using std::string;

class TNode{
	friend class BST;
	friend class Interface;
	TNode *left;
	TNode *right;
	TNode *parent;
	Species *animal;
	int height;
public:
	TNode(const string sp, const string st, const string inf);
	TNode();
	~TNode();
	void del(TNode *node);
	void printNode(const bool XtraInfo);
	void updateStatus(string s);
	void updateHeight();
	int findHeight(TNode *node);
};




#endif /* TNode_HPP_ */
