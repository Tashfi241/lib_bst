#include "Node.h"

int main(){
    
    Node* r = new Node(49);
    r->insertI(44);
    r->insertI(45);
    r->insertI(34);
    r->insertI(30);
    r->insertI(50);
    r->insertI(55);
    r->insertI(52);
    r->insertI(70);
    r->insertI(90);
    
    int key1 = 90;
    if(r->searchI(key1)){
        cout << key1 << " is in the bst" << endl;
    } else {
        cout << key1 << " isn't in the bst" << endl; 
    }
    
    int key2 = 100;
    if(r->searchI(key2)){
        cout << key2 << " is in the bst" << endl;
    } else{
        cout << key2 << " isn't in the bst" << endl;
    }
    return 0;
}