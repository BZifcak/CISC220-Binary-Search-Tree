#include "TNode.hpp"
TNode::TNode(const string sp, const string st, const string inf) {
    left = nullptr;        // left child pointer
    right = nullptr;       // right child pointer
    parent = nullptr;      // parent pointer
    animal = new Species(sp, st, inf); // allocate and store species data
}

// Default constructor: create an empty node with no Species
TNode::TNode() {
    left = nullptr;        // no left child
    right = nullptr;       // no right child
    parent = nullptr;      // no parent
    animal = nullptr;      // no Species data allocated
    int height = 1;        // initialize height for this node
}

// Destructor: attempts to free subtree rooted at this node
TNode::~TNode() {
    del(this);             // call recursive deletion helper on this node
}

/*Recursive helper that deletes the subtree rooted at node
 Traverses to leaves and deletes nodes*/
void TNode::del(TNode *node){
    if (node->left == nullptr && node->right == nullptr) {
        delete [] node;    // delete the node (note: delete[], not delete — see implementation notes)
        return;
    }
    del(node->left);       // delete left subtree
    del(node->right);      // delete right subtree
}

/* Print this node's species. If XtraInfo is true print the info field too.*/
void TNode::printNode(const bool XtraInfo) {
    std::cout << "This species name is: " << animal->name
              << "\nIt's status is: " << animal->status << std::endl;
    if (XtraInfo) {
        std::cout << "It's info is: " << animal->info << std::endl;
    }
}

/* Update the Species status string stored in this node*/
void TNode::updateStatus(string s) {
    animal->status = s;
}

/*Recompute and store the height for this node by calling findHeight on this node*/
void TNode::updateHeight() {
    findHeight(this);
}

/* Compute the height of the subtree rooted at node.
 Returns the height as an int (empty subtree -> 0).
 Also stores the computed value in the node's height member.*/
int TNode::findHeight(TNode *node) {
    if (node == nullptr) {
        return 0;
    }
    height = std::max(findHeight(node->left), findHeight(node->right)) + 1;
    return height;
}
