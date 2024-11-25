#include <iostream>
using namespace std;

class Node{
    private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

    public:
    Node(int value) : data(value), weight(1), lchild(nullptr), rchild(nullptr) {}
    
    //prototypes
    Node* insertR(int k);   // prototype for insert recursive
    void inOrder();         // prototype for inorder traversal
};

// Function for inserting numbers inside a node
Node* Node::insertR(int k){                     // Insert Recursive
    if(k == data){
        weight++;
    }
    if(k < data){
        if(lchild == nullptr){
            lchild = new Node(k);
        } else{
            lchild = lchild->insertR(k);
        }
    } else if(k > data){
        if(rchild == nullptr){
            rchild = new Node(k);
        } else{
            rchild = rchild->insertR(k);
        }
    }
    return this;
}

// Function for printing the numbers of bst
void Node::inOrder(){                             // Inorder Traversal
    if(lchild != nullptr){
        lchild->inOrder();
    }
    cout << data << " ";
    if(rchild != nullptr){
        rchild->inOrder();
    }
}

int main(){
    
    Node* r = new Node(49);
    r->insertR(48);
    r->insertR(50);
    r->insertR(55);
    r->insertR(52);
    r->insertR(34);
    r->insertR(40);
    
    cout << "THE NUMBERS OF BST BY INORDER TRAVERSAL: ";
    r->inOrder();
    cout << endl;
    return 0;
}