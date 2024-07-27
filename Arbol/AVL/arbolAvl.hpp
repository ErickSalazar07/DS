#ifndef ARBOL_AVL_HPP
#define ARBOL_AVL_HPP
#include "arbolAvl.h"

template <class T>
ArbolAVL<T>::ArbolAVL(): root(NULL), numItems(0){}

template <class T>
ArbolAVL<T>::ArbolAVL(const T& data): root(data), numItems(1){}

template <class T>
ArbolAVL<T>::ArbolAVL(const ArbolAVL<T>& arbDer){
  
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
  if(!this->raiz) this->raiz = new NodoAVL<T>(data);
  else if(this->raiz > data) this->raiz->insert(data,this->raiz->izq);
  else if(this->raiz < data) this->raiz->insert(data, this->raiz->der);
}

template <class T>
void ArbolAVL<T>::pop(const T& data){
  if(!this->root) return;

  if(this->root->data == data){ // Delete root node

  }else if(this->root->data > data) this->root->pop(data, this->root->izq, this->root);
  else if(this->root->data < data) this->root->pop(data, this->root->der, this->root);

  this->numItems--;
}

template <class T>
void ArbolAVL<T>::inOrden() const{
  if(this->root) this->root->inOrden();
  else std::cout<<"\a\ninOrden(): No hay elementos en el arbol\n\n";
}

template <class T>
void ArbolAVL<T>::preOrden() const{
  if(this->root) this->root->preOrden();
  else std::cout<<"\a\npreOrden(): No hay elementos en el arbol\n\n";
}

template <class T>
void ArbolAVL<T>::posOrden() const{
  if(this->root) this->root->posOrden();
  else std::cout<<"\a\nposOrden(): No hay elementos en el arbol\n\n";
}

template <class T>
void ArbolAVL<T>::nivelOrden() const{
  if(this->root) this->root->nivelOrden();
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
void ArbolAVL<T>::getRoot() const{
  if(!this->root) std::cout<<"\a\nEl arbol no tiene elementos\n\n";
  else std::cout<<"ROOT = "<<this->root->data;
}

#endif // ARBOL_AVL_HPP