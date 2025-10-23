#include "BST.hpp"
#include "TNode.hpp"
#include <stdlib.h>
using std::string;

BST::BST(TNode *f){
    first = f;
    TNode *tmp = first;
    length = 1;
    last = nullptr;
    //finds last
    while(tmp->next != nullptr){
        tmp = tmp->next;
        //updates length for each node 
        length++;
    }
    last = tmp;
}
BST::~BST(){}

BST::TNode *find(string n){
    TNode *tmp = first;
    while (tmp->animal->name != n){
        if(tmp->next == nullptr){
            return NULL;
        }
        tmp = tmp->next;
    }
    return tmp;
}
BST::printNode(TNode *t){
    std::cout<< "This species name is: " << t->animal->name "\nIt's status is: " << t->animal->status <<"\n and its info is: " << t->animal->info << endl;
}
BST::void insert(TNode *newNode){

}
BST::void preOrderPrint();
BST::void inOrderPrint();
BST::void postOrderPrint();
BST::void setStatus(string s);
BST::void removeTNode(string n);