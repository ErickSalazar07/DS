#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
#include <cstdlib>
#include "AVLNode.h"

template <typename T>
class AVLTree {
private:
  AVLNode<T>* root;
  size_t numNodes;
protected:
public:
  AVLTree(): root(NULL), numNodes(0) {  }
  AVLTree(const T& data): root(new AVLNode<T>(data)), numNodes(1) {  }
  ~AVLTree() {  }

  T getRoot() { return this->root->getDato(); }
  void inOrden() { 
    if(!this->root) { std::cout<<"\nNo items to do \"in orden\" tour.\n"; return; }
    std::cout<<"\n\t\t\tIN ORDEN\n\n";
    this->root->inOrden(this->root);
    std::cout.put('\n');
  }

  void insert(const T& data) {
    if(!this->root) this->root = new AVLNode<T>(data);
     else if(this->root->dato > data) this->root->insert(data,this->root->izq);
     else if(this->root->dato < data) this->root->insert(data,this->root->der);
    this->numNodes++;
  }
};

#endif // AVL_TREE_H