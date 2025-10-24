#ifndef BST_HPP
#define BST_HPP

#include "TNode.hpp"
#include <stdlib.h>
using std::string;

class BST{
    friend class Interface;
    TNode *first;
    bool xtra;
    public:
    BST(TNode *f, bool x);
    BST(TNode *f);
    BST(bool x);
    void deleteSubtree(TNode *node);
    ~BST();
    TNode *find(string n);
    TNode *find(string n, TNode *node);
    void insertNode(TNode *newNode, TNode *node);
    TNode *insert(string name, string status, string info);
    TNode *remove(string n);
    TNode* remove(string n, TNode *node);
    void printTreePre();
    void printTreeIO();
    void printTreePost();
    void printTree(TNode* node, int order); // the recursive function for all print trees. order denotes print order, [0,1,2] to [pre,in,post] respectively
    void updateStatus(string name,string s);
};

#endif // BST_HPP
