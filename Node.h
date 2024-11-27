#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node{
    private:
        int data;
        int weight;
        Node* lchild;
        Node* rchild;
        Node* parent;
   
    public:
        Node(int value);
    
    //Prototypes
    bool searchI(int k);                         // Search Iterative
    bool searchR(int k);                         // Search Recursive
    Node* insertI(int k);                        // Insert Iterative
};


#endif