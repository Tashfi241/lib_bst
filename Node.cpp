#include <iostream>
#include "Node.h"
#include "Node.cpp"

Node:: Node(int value) : data(value), weight(1), lchild(nullptr), rchild(nullptr), parent(nullptr) {}

bool Node::searchI(int k){
    Node* node = this;
    while(node != nullptr){
        if(node->data == k){
            return true;
        }
        if(node->data > k){
            node = node->lchild;
        } else if(node->data < k){
            node = node->rchild;
        }
    }
    return false;
}

bool Node::searchR(int k){
    Node* node = this;
    if(node == NULL){
        return false;
    }
    if(node->data == k){
        return true;
    }
    if(node->data > k){
        return node->lchild ? node->lchild->searchR(k) : false;
    } else{
        return node->rchild ? node->rchild->searchR(k) : false;
    }
}

Node* Node::insertI(int k){
    Node* newvalue = new Node(k);
    Node* current = this;
    Node* parent = nullptr;
    
    if(current == NULL){
        return newvalue;
    }
    if(current->data == k){
        current->weight++;
        return current;
    }
    while(current != nullptr){
        parent = current;
        if(current->data > k){
            current = current->lchild;
        } else if(current->data < k){
            current = current->rchild;
        }
    }
    newvalue->parent = parent;
    if(parent->data > k){
        parent->lchild = newvalue;
    } else if(parent->data < k){
        parent->rchild = newvalue;
    }
    return current;
}
