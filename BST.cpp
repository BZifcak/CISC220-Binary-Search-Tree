#include "BST.hpp"
#include "TNode.hpp"
#include <stdlib.h>
using std::string;

//constructors----------------------------------------------------------------------
// Initialize root pointer and xtra flag
BST::BST(TNode *f, bool x){
    first = f;
    xtra = x;
}
// Initialize root pointer and xtra to false if not provided
BST::BST(TNode *f){
    first = f;
    xtra = false;
}
// Initialize root to nullptr pointer and xtra flag
BST::BST(bool x) {
    first = nullptr;
    xtra = x;
}
//----------------------------------------------------------------------

//Destructor ---------------------------------------------------------------------
// Recursively delete all nodes starting from root
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

/* Return pointer to node with matching name or nullptr if not found.*/
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
Returns new TNode object*/
TNode* BST::insert(string n, string i, string s){
    TNode *node = new TNode(n,i,s);
    insertNode(node, first);
    return node;
}
/*first checks if BST is empty,
then if it can be inserted to the left/right,
then calls itself passing its left child then right child*/
void BST::insertNode(TNode *newNode, TNode *node) {
    if (first == nullptr) { //checks if BST is empty
        first = newNode;
        first->updateHeight();
        return;
    }
    if ((node->animal->name > newNode->animal->name) && node->left == nullptr) { //checks for left insert
        node->left = newNode;
        newNode->parent = node;
        first->updateHeight();
        return;
    }else if  ((node->animal->name < newNode->animal->name) && node->right == nullptr) { // checks for right insert
        node->right = newNode;
        newNode->parent = node;
        first->updateHeight();
        return;
    }
    //recursive calls
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
/* remove helper
 * Currently only handles detaching leaf nodes and assumes non-root parent.
 * Returns detached node or nullptr if not found.
 */
TNode* BST::remove(string n, TNode *node) {
    if (node == nullptr) { //checks base case
        return nullptr;
    }
    if (node->animal->name == n) {
        //handles deletion and redefining parents children
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
    //recursive calls
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
    //discriminate against order
    switch (order) {
        case 0: {
            //preOrder
            node->printNode(xtra);
            printTree(node->left, order);
            printTree(node->right, order);
            break;
        }
        case 1: {
            //inOrder
            printTree(node->left, order);
            node->printNode(xtra);
            printTree(node->right, order);
            break;
        }
        case 2: {
            //postOrder
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
