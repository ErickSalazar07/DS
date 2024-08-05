#ifndef ARBOL_AVL_HPP
#define ARBOL_AVL_HPP
#include "arbolAvl.h"
#include <queue>

template <class T>
ArbolAVL<T>::ArbolAVL(): root(NULL), numItems(0){}

template <class T>
ArbolAVL<T>::ArbolAVL(const T& data): root(new NodoAVL<T>(data)), numItems(1){}

template <class T>
ArbolAVL<T>::ArbolAVL(const ArbolAVL<T>& arbDer){
  if(this != &arbDer && arbDer.numItems){
    std::queue<NodoAVL<T>*> cola;
    cola.push(arbDer.root);
    while(!cola.empty()){
      this->insert(cola.front()->data);
      if(cola.front()->izq) cola.push(cola.front()->izq);
      if(cola.front()->der) cola.push(cola.front()->der);
      cola.pop();
    }
  }
}

template <class T>
void ArbolAVL<T>::deleteTree(NodoAVL<T>*& node){
  if(node->izq) deleteTree(node->izq);
  if(node->der) deleteTree(node->der);
  delete node;
  node = NULL;
}

template <class T>
ArbolAVL<T>::~ArbolAVL(){
  if(this->root) this->deleteTree(this->root); 
}

template <class T>
void ArbolAVL<T>::clear(){
  if(this->root) this->deleteTree(this->root);
  this->numItems = 0;
}

template <class T>
void ArbolAVL<T>::insert(const T& data){
  if(this->root->find(data, this->root)) return;
  
  if(!this->root) this->root = new NodoAVL<T>(data);
  else if(this->root->data > data) this->root->insert(data,this->root->izq, this->root);
  else if(this->root->data < data) this->root->insert(data, this->root->der, this->root);
  this->numItems++;
}

template <class T>
void ArbolAVL<T>::pop(const T& data){
  if(!this->root){ std::cerr<<"\n\aThe root is NULL. Enter data\n\n"; return;}
  if(!this->root->find(data, this->root)){ std::cerr<<"\n\aThe data "<<data<<" is not in the tree\n\n"; return;}

  if(this->root->data == data){ // Delete root node

  }else if(this->root->data > data) this->root->pop(data, this->root->izq, this->root);
  else if(this->root->data < data) this->root->pop(data, this->root->der, this->root);

  this->numItems--;
}

template <class T>
void ArbolAVL<T>::inOrden() const{
  if(this->root) this->root->inOrden(this->root);
  else std::cout<<"\a\ninOrden(): No hay elementos en el arbol\n\n";
}

template <class T>
void ArbolAVL<T>::preOrden() const{
  if(this->root) this->root->preOrden(this->root);
  else std::cout<<"\a\npreOrden(): No hay elementos en el arbol\n\n";
}

template <class T>
void ArbolAVL<T>::posOrden() const{
  if(this->root) this->root->posOrden(this->root);
  else std::cout<<"\a\nposOrden(): No hay elementos en el arbol\n\n";
}

template <class T>
void ArbolAVL<T>::nivelOrden() const{
  if(this->root) this->root->nivelOrden(this->root);
  else std::cout<<"\a\nnivelOrden(): No hay elementos en el arbol\n\n";
}

template <class T>
size_t ArbolAVL<T>::size() const{
  return this->numItems;
}

template <class T>
bool ArbolAVL<T>::find(const T& data) const{
  return this->root->find(data, this->root);
}

template <class T>
bool ArbolAVL<T>::empty() const{
  return this->root == NULL;
}

template <class T>
T ArbolAVL<T>::getRoot() const{
  try{
    if(!this->root) throw -1;
    return this->root->data;
  }catch(const int& code){
    switch(code){
      case -1: std::cerr<<"\a\nEl arbol no tiene elementos\n\n"; break;
    }
    return T();
  }
}

template <class T>
int ArbolAVL<T>::heigth() const{
  if(!this->root) return -1;
  return this->root->heigth();
}

#endif // ARBOL_AVL_HPP