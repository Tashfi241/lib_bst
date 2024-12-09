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
    bool searchI(int k);                                                                        // ricerca iterativa di k
    bool searchR(int k);                                                                        // ricerca ricorsiva di k
    Node* insertI(int k);                                                                      // inserimento iterativa di k
    void preOrder();                                                                           // attraversamento in preOrder
    void postOrder();                                                                          // attraversamento in postOrder
    Node* deleteNode(int k);                                                                   // cancellazione del nodo k
    bool isBst(int minvalue = INT_MIN, int maxvalue = INT_MAX);                                // verifica che sia un bst o meno
};


#endif
