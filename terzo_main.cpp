#include "Node.h"
#include "terzo_refactoring.cpp"
#include <iostream>
using namespace std;

int main() {
    Node* root = new Node(10);
    root->insertI(5);
    root->insertI(15);
    root->insertI(3);
    root->insertI(7);
    root->insertI(13);
    root->insertI(18);

    cout << "THE VALUES OF THE BST BY PREORDER TRAVERSAL: ";
    root->preOrder();
    cout << endl;

    cout << "THE VALUES OF THE BST BY POSTORDER TRAVERSAL: ";
    root->postOrder();
    cout << endl;

    cout << "IS THE TREE A BST? ";
    if (root->isBst()) {
        cout << "YES, IT IS A BST" << endl;
    } else {
        cout << "NO, IT ISN'T A BST" << endl;
    }

    cout << "DELETION NODE 13" << endl;
    root = root->deleteNode(13);

    cout << "THE VALUES OF THE BST BY PREORDER TRAVERSAL AFTER DELETITION ";
    root->preOrder();
    cout << endl;

    cout << "Is the tree still a BST? ";
    if (root->isBst()) {
        cout << "YES, IT IS A BST" << endl;
    } else {
        cout << "NO, IT ISN'T A BST" << endl;
    }

    delete root;
    return 0;
}