#include "BST.hpp"
#include "TNode.hpp"
#include <stdlib.h>
using std::string;

//constructors----------------------------------------------------------------------

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
//----------------------------------------------------------------------

//Destructor ---------------------------------------------------------------------
//Calls helper function so it can run recursively
void BST::deleteSubtree(TNode *node) {
    if (!node) return;
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}

BST::~BST() {
    deleteSubtree(first);
    first = nullptr;
}
//---------------------------------------------------------------------

//Calls helper function so it can run recursively
TNode* BST::find(string n){
    return find(n, first);
}
/*recursively traces the tree in PreOrder traversal,
branching left || right based on if the current name is > or < target name*/
TNode* BST::find(string n, TNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->animal->name == n) {
        return node;
    }
    if (node->animal->name < n) {
        return find(n,node->right);
    } else {
        return find(n,node->left);
    }
}
/*Calls helper function so it can run recursively and passes node created with arguments
Returns new Tnode*/
TNode* BST::insert(string n, string i, string s){
    TNode *node = new TNode(n,i,s);
    insertNode(node, first);
    return node;
}
/*first checks if BST is empty,
then if it can be inserted to the left/right,
then calls itself passing its left child then right child*/
void BST::insertNode(TNode *newNode, TNode *node) {
    if (first == nullptr) {
        first = newNode;
        first->updateHeight();
        return;
    }
    if ((node->animal->name > newNode->animal->name) && node->left == nullptr) {
        node->left = newNode;
        newNode->parent = node;
        first->updateHeight();
        return;
    }else if  ((node->animal->name < newNode->animal->name) && node->right == nullptr) {
        node->right = newNode;
        newNode->parent = node;
        first->updateHeight();
        return;
    }
    if (node->animal->name > newNode->animal->name) {
        insertNode(newNode,node->left);
    }
    else {
        insertNode(newNode,node->right);
    }
}
/*Calls helper function to run recursively*/
TNode* BST::remove(string n) {
    return remove(n,first);
}
/*checks base case,
finds if target node is right or left and removes
otherwise calls itself passing its left child then right child*/
TNode* BST::remove(string n, TNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->animal->name == n) {
        if (node->animal->name < node->parent->animal->name) {
            node->parent->left = nullptr;
            node->parent = nullptr;
            first->updateHeight();
            return node;
        } else {
            node->parent->right = nullptr;
            node->parent = nullptr;
            first->updateHeight();
            return node;
        }
    }
    if (node->animal->name > n) {
        return remove(n,node->left);
    } else {
        return remove(n,node->right);
    }
}
//All print functions call the same recursive helper function with their order as am argument
void BST::printTreePre(){printTree(first, 0);}
void BST::printTreeIO(){printTree(first, 1);}
void BST::printTreePost(){printTree(first, 2);}
/*helper function for all print functions
takes in first node and order [0,1,2] mapping to [pre,in,post] respectively
 */
void BST::printTree(TNode* node, int order) {
    if (!node) {
        return;
    }
    switch (order) {
        case 0: {
            node->printNode(xtra);
            printTree(node->left, order);
            printTree(node->right, order);
            break;
        }
        case 1: {
            printTree(node->left, order);
            node->printNode(xtra);
            printTree(node->right, order);
            break;
        }
        case 2: {
            printTree(node->left, order);
            printTree(node->right, order);
            node->printNode(xtra);
            break;
        }
    }
}
/*assumes node is in tree,
calls TNode update status function
 */
void BST::updateStatus(string name,string status) {
        find(name)->updateStatus(status);
}
