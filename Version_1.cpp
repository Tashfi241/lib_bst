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
        Node(int value) : data(value), weight(1), lchild(nullptr), rchild(nullptr), parent(nullptr) {}      // Inzializzation of objects in Node constructor

    
    //Prototypes
    Node* insertR(int k);            // Insert Recursive
    void inOrder();                 // Inorder Traversal
};

Node* Node:: insertR(int k){                                        // Function Insert Recursive
    if(data == k){
        this->weight++;
        return this;
    }
    if(data > k){
        if(lchild == nullptr){
            lchild = new Node(k);
        } else{
            lchild->insertR(k);
        }
    } else if(data < k){
        if(rchild == nullptr){
            rchild = new Node(k);
        } else{
            rchild->insertR(k);
        }
    }
    return this;
}

void Node::inOrder(){                                                // Function Inorder Traversal
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
    r->insertR(44);
    r->insertR(42);
    r->insertR(38);
    r->insertR(33);
    r->insertR(55);
    r->insertR(52);
    r->insertR(70);

    cout << "THE VALUES OF BST BY INORDER TRAVERSAL: ";
    r->inOrder();
    cout << endl;
    return 0;
}
