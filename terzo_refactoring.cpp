#include "Node.h"

Node:: Node(int value) : data(value), weight(1), lchild(nullptr), rchild(nullptr), parent(nullptr) {}

void Node::preOrder(){
    cout << data << " ";
    if(lchild != nullptr){
        lchild->preOrder();
    }
    if(rchild != nullptr){
        rchild->preOrder();
    }
}

void Node::postOrder(){
    if(lchild != nullptr){
        lchild->postOrder();
    }
    if(rchild!= nullptr){
        rchild->postOrder();
    }
    cout << data << " ";
}

    bool Node::isBst(int minvalue, int maxvalue){
    if (data <= minvalue || data >= maxvalue) {
        return false;
    }

    bool leftIsBST = (lchild ? lchild->isBst(minvalue, data) : true);

    bool rightIsBST = (rchild ? rchild->isBst(data, maxvalue) : true);

    return leftIsBST && rightIsBST;
}


Node* Node::deleteNode(int k) {
    if (this == nullptr) {
        return nullptr;
    }
    if (k > this->data) {
        this->rchild = this->rchild ? this->rchild->deleteNode(k) : nullptr;
    } else if (k < this->data) {
        this->lchild = this->lchild ? this->lchild->deleteNode(k) : nullptr;
    } else {
        if (this->lchild == nullptr && this->rchild == nullptr) {
            delete this;
            return nullptr;
        } else if (this->lchild == nullptr) {
            Node* temp = this->rchild;
            delete this;
            return temp;
        } else if (this->rchild == nullptr) {
            Node* temp = this->lchild;
            delete this;
            return temp;
        }

        Node* successorParent = this;
        Node* successor = this->rchild;

        while (successor->lchild != nullptr) {
            successorParent = successor;
            successor = successor->lchild;
        }

        this->data = successor->data;

        if (successorParent != this) {
            successorParent->lchild = successor->rchild;
        } else {
            this->rchild = successor->rchild;
        }

        delete successor;
    }

    return this;
}