#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    int weight = 1;
    Node* lchild;
    Node* rchild;
    Node* parent;
    Node(int value){
        data = value;
        lchild = nullptr;
        rchild = nullptr;
    }
};
Node* insert_recursive(Node* node, int k){
    if(node == nullptr){
        return new Node(k);
    }
    if(node->data == k){
        node->weight++;
    }
    if(node->data > k){
        node->lchild = insert_recursive(node->lchild, k);
    }
    if(node->data < k){
        node->rchild = insert_recursive(node->rchild, k);
    }
    return node;
}
Node* insert_iterative(Node* node, int K){
      Node* newvalue = new Node(K);
      if(node == nullptr){
          return newvalue;
      }
      if(node->data == K){
          node->weight++;
          return node;
      }
      Node* current = node;
      Node* parent = nullptr;
      while(current != nullptr){
          parent = current;
          if(current->data > K){
              current = current->lchild;
          } else if(current->data < K){
              current = current->rchild;
          }
      }
      newvalue->parent = parent;
      if(parent->data > K){
          parent->lchild = newvalue;
      } else if(parent->data < K){
          parent->rchild = newvalue;
      }
      return node;
}
bool search_recursive(Node* node, int K){
    if(node == NULL){
        return false;
    }
    if(node->data == K){
        return true;
    }
    if(node->data > K){
        return search_recursive(node->lchild, K);
    } else{
        return search_recursive(node->rchild, K);
    }
}
bool search_iterative(Node* node, int K){
    while(node != nullptr){
        if(node->data == K){
            return true;
        }
        if(node->data > K){
            node = node->lchild;
        } else{
            node= node->rchild;
        }
    }
    return false;
}
Node* delete_node(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }
    if (value > node->data) {
        node->rchild = delete_node(node->rchild, value);
    } else if (value < node->data) {
        node->lchild = delete_node(node->lchild, value);
    } else {
        if (node->lchild == nullptr && node->rchild == nullptr) {
            delete node;
            return nullptr;
        } else if (node->lchild == nullptr) {
            Node* temp = node->rchild;
            delete node;
            return temp;
        } else if (node->rchild == nullptr) {
            Node* temp = node->lchild;
            delete node;
            return temp;
        }
        Node* successorParent = node;
        Node* successor = node->rchild;
        while (successor->lchild != nullptr) {
            successorParent = successor;
            successor = successor->lchild;
        }
        node->data = successor->data;
        if (successorParent != node) {
            successorParent->lchild = delete_node(successor, successor->data);
        } else {
            successorParent->rchild = delete_node(successor, successor->data);
        }
    }
    return node;
}
bool is_bst(Node* node, int minvalue = INT_MIN, int maxvalue = INT_MAX){
    if(node == NULL){
        return true;
    }
    if(node->data >= maxvalue && node->data <= minvalue){
        return false;
    }
    return is_bst(node->lchild, minvalue, node->data) && is_bst(node->rchild, node->data, maxvalue);
}
void preorder_traversal(Node* node){
    if(node == NULL){
        return;
    }
    cout << node->data << " ";
    preorder_traversal(node->lchild);
    preorder_traversal(node->rchild);
}
void inorder_traversal(Node* node){
    if(node == NULL){
        return;
    }
    inorder_traversal(node->lchild);
    cout << node->data << " ";
    inorder_traversal(node->rchild);
}
void postorder_traversal(Node* node){
    if(node == NULL){
        return;
    }
    postorder_traversal(node->lchild);
    postorder_traversal(node->rchild);
    cout << node->data << " ";
}
int height(Node* node){
    if(node== NULL){
        return 0;
    }
    
    int height_lchild = height(node-> lchild);
    int height_rchild = height(node->rchild);
    
    int max = (height_lchild > height_rchild) ? height_lchild : height_rchild;
    
    return 1 + max;
}
int main(){
    Node* R = new Node(49);
    insert_recursive(R,44);
    insert_recursive(R, 47);
    insert_recursive(R, 76);
    insert_recursive(R, 35);
    insert_recursive(R, 59);
    insert_recursive(R, 88);
    insert_recursive(R, 33);
    insert_recursive(R, 64);
    insert_recursive(R, 55);
    insert_recursive(R, 72);
    insert_recursive(R, 38);
    insert_recursive(R, 41);
    insert_recursive(R, 83);
    insert_recursive(R, 67);
    insert_recursive(R, 50);
    insert_recursive(R, 90);
    
     Node* A = new Node(49);
    insert_iterative(A,44);
    insert_iterative(A, 47);
    insert_iterative(A, 76);
    insert_iterative(A, 35);
    insert_iterative(A, 59);
    insert_iterative(A, 88);
    insert_iterative(A, 33);
    insert_iterative(A, 64);
    insert_iterative(A, 55);
    insert_iterative(A, 72);
    insert_iterative(A, 38);
    insert_iterative(A, 41);
    insert_iterative(A, 83);
    insert_iterative(A, 67);
    insert_iterative(A, 50);
    insert_iterative(A, 90);
    cout << "----------------------" << endl;
    cout << "THE VALUES OF THE BINARY TREE BY PREORDER TRAVERSAL: ";
    preorder_traversal(R);
    cout << endl;
    cout << "----------------------" << endl;
    cout << "THE VALUES OF THE BINARY TREE BY INORDER TRAVERSAL: ";
    inorder_traversal(R);
    cout << endl;
    cout << "----------------------" << endl;
    cout << "THE VALUES OF THE BINARY TREE BY POSTORDER TRAVERSAL: ";
    postorder_traversal(R);
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "------------------------------------------" << endl;
    cout << "THE HEIGHT OF THE BINARY TREE IS: " << height(R) << endl;
    cout << "------------------------------------------" << endl;
    int target1 = 100;
    if(search_recursive(R,target1)){
        cout << "THE TARGET IS IN THE BINARY TREE" << endl;
    } else{
        cout << "THE TARGET ISN'T IN THE BINARY TREE" << endl;
    }
    cout << "------------------------------------------" << endl;
    int target2 = 72;
    if(search_iterative(R,target2)){
        cout << "THE TARGET IS IN THE BINARY TREE" << endl;
    } else{
        cout << "THE TARGET ISN'T IN THE BINARY TREE" << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    if(is_bst(R)){
        cout << "THE IS A BINARY TREE" << endl;
    } else{
        cout << "THE ISN'T A BINARY TREE" << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "----------------------" << endl;
    cout << "THE VALUES OF THE BINARY TREE BY PREORDER TRAVERSAL: ";
    preorder_traversal(A);
    cout << endl;
    return 0;
}


