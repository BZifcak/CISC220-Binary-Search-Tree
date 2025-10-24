#include "TNode.hpp"
TNode::TNode(const string sp, const string st, const string inf) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    animal =  new Species(sp,st,inf);
}
TNode::TNode() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    animal = nullptr;
    int height = 1;
}
TNode::~TNode() {
    del(this);
}
void TNode::del(TNode *node){
    if (node->left == nullptr && node->right == nullptr) {
        delete [] node;
        return;
    }
    del(node->left);
    del(node->right);
}
void TNode::printNode(const bool XtraInfo) {
    std::cout<< "This species name is: " << animal->name << "\nIt's status is: " << animal->status << std::endl;
    if (XtraInfo) {
        std::cout<< "It's info is: " << animal->info << std::endl;
    }
}
void TNode::updateStatus(string s) {
    animal->status = s;
}
void TNode::updateHeight() {
    findHeight(this);
}
int TNode::findHeight(TNode *node) {
    if (node == nullptr) {
        return 0;
    }
    height = std::max(findHeight(node->left), findHeight(node->right)) + 1;
    return height;

}

