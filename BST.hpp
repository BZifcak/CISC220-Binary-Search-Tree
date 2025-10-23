#include "TNode.hpp"
#include <stdlib.h>
using std::string;

class BST{
    friend class Interface;
    TNode *first;
    int height;
    public:
    BST(TNode *f);
    ~BST();
    void addNode();
    void preOrderPrint();
    void inOrderPrint();
    void postOrderPrint();
    TNode *findNode(string n);
    void setStatus(string s);
    void removeTNode(string n);
};