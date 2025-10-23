#include "BST.hpp"
#include "TNode.hpp"
#include <stdlib.h>
using std::string;

BST::BST(TNode *f, bool x){
    first = f;
    xtra = x;
}
BST::BST(TNode *f){
    first = f;
    xtra = false;
}
BST::BST(bool x) {
    first = nullptr;
    xtra = x;
}


BST::~BST(){}

TNode* BST::find(string n){
    return find(n, first);
}
TNode* BST::find(string n, TNode *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->animal->name == n) {
        return node;
    }
    if (node->animal->name < n) {
        return find(n,node->left);
    } else {
        return find(n,node->right);
    }
}
TNode* BST::insert(string n, string i, string s){
    TNode *node = new TNode(n,i,s);
    insertNode(node, first);
    return node;
}
void BST::insertNode(TNode *newNode, TNode *node) {
    if (node->animal->name > newNode->animal->name && node->left == nullptr) {
        node->left = newNode;
        newNode->parent = node;
        first->updateHeight();
        return;
    }else if  (node->animal->name > newNode->animal->name && node->left == nullptr) {
        node->left = newNode;
        newNode->parent = node;
        first->updateHeight();
        return;
    }
    if (node->animal->name < newNode->animal->name){insertNode(newNode,node->left);}
    else{insertNode(newNode,node->right);}
}
TNode* BST::remove(string n) {
    remove(n,first);
}
TNode* BST::remove(string n, TNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->animal->name == n) {
        if (node->animal->name < node->parent->animal->name) {
            delete [] node;
            node->parent->left = nullptr;
            first->updateHeight();
            return node;
        } else {
            delete [] node;
            node->parent->right = nullptr;
            first->updateHeight();
            return node;
        }
    }
    if (node->animal->name < n) {
        return remove(n,node->left);
    } else {
        return remove(n,node->right);
    }
}
void BST::printTreePre(){printTree(first, 0);}
void BST::printTreeIO(){printTree(first, 1);}
void BST::printTreePost(){printTree(first, 2);}
void BST::printTree(TNode* node, int order) {
    if (!node) {
        return;
    }
    switch (order) {
        case 0: {
            node->printNode(xtra);
            printTree(node->left, order);
            printTree(node->right, order);
        }
        case 1: {
            printTree(node->left, order);
            node->printNode(xtra);
            printTree(node->right, order);
        }
        case 2: {
            printTree(node->left, order);
            printTree(node->right, order);
            node->printNode(xtra);
        }
    }
}
void BST::updateStatus(string name,string status) {
    find(name)->updateStatus(status);
}
