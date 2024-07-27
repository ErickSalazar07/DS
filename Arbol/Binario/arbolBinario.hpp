#ifndef ARBOL_BINARIO_HPP
#define ARBOL_BINARIO_HPP
#include <iostream>
#include <cstdlib>
#include "arbolBinario.h"
#include "../../Queue/queue.h"

template <typename T>
ArbolBin<T>::ArbolBin(): numItems(0), root(NULL){ }

template <typename T>
ArbolBin<T>::ArbolBin(const T& data): numItems(1), root(new NodoBin<T>(data)){}

template <typename T>
ArbolBin<T>::ArbolBin(const ArbolBin<T>& arbDer): numItems(arbDer.numItems), root(NULL){ // copy constructor
  if(this != &arbDer && arbDer.root){
    Queue<const NodoBin<T>* const> cola(arbDer.root);

    while(!cola.empty()){ // OrderLevel tour
      this->root->insert(cola.front()->dato, this->root);
      if(cola.front()->izq) cola.push(cola.front()->izq);
      if(cola.front()->der) cola.push(cola.front()->der);
      cola.pop();
    }
  }
}

template <typename T>
void ArbolBin<T>::clear(){
  if(!this->root) return;
  this->deleteTree(this->root);
  this->numItems = 0;
}

template <typename T>
ArbolBin<T>::~ArbolBin(){
  if(this->root)
    this->deleteTree(this->root);
}

template <typename T>
void ArbolBin<T>::deleteTree(NodoBin<T>*& nodo){
  if(nodo){
    if(nodo->der) deleteTree(nodo->der);
    if(nodo->izq) deleteTree(nodo->izq);
    delete nodo;
    nodo = NULL;
  }
}

template <typename T>
void ArbolBin<T>::insert(const T& dato){ // Function that makes recursively the insertion of a new node in the tree
  this->root->insert(dato,this->root);
  this->numItems++;
}

template <typename T>
void ArbolBin<T>::pop(const T& dato){

  if(!this->root->find(dato , this->root)){ std::cerr<<"\n\nThe data: "<<dato<<" wasn't find\n\n"; return;}

  if(dato == this->root->dato){ // It searches for the max node in the minimum set of nodes starting at the getRoot node which will be deleted
    NodoBin<T>* iterador = this->root;
    if(iterador->izq && iterador->der){
      NodoBin<T>* padre = iterador;
      iterador = iterador->izq;
      while(iterador->der){ padre = iterador; iterador = iterador->der; }
      padre->izq == iterador ? padre->izq = iterador->izq : padre->der = iterador->izq;
      this->root->dato = iterador->dato;
    }else if(iterador->der) this->root = iterador->der;
    else if(iterador->izq) this->root = iterador->izq;
    delete iterador;
  }else if(dato > this->root->dato) this->root->pop(dato, this->root->der, root);
  else this->root->pop(dato, this->root->izq, root);
  this->numItems--;
}

template <typename T>
void ArbolBin<T>::inOrden() const{
  if(this->root) this->root->inOrden(this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::inOrden(Queue<T>& cola){
  if(this->root) this->root->inOrden(cola, this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::preOrden() const{
  if(this->root) this->root->preOrden(this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::preOrden(Queue<T>& cola){
  if(this->root) this->root->preOrden(cola, this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::posOrden() const{
  if(this->root) this->root->posOrden(this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::posOrden(Queue<T>& cola){
  if(this->root) this->root->posOrden(cola, this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::nivelOrden() const{
  if(this->root) this->root->nivelOrden(this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::nivelOrden(Queue<T>& cola){
  if(this->root) this->root->nivelOrden(cola, this->root);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
ArbolBin<T>& ArbolBin<T>::operator = (const ArbolBin<T>& arbDer){
  if(this != &arbDer){
    this->clear(); 
    if(!arbDer.root) return *this;
    Queue<const NodoBin<T>* const> cola(arbDer.root);
    
    while(!cola.empty()){
      this->root->insert(cola.front()->dato, this->root);
      if(cola.front()->izq) cola.push(cola.front()->izq);
      if(cola.front()->der) cola.push(cola.front()->der);
      cola.pop();
    }
    this->numItems = arbDer.numItems;
  }
  return *this;
}

template <typename T>
bool ArbolBin<T>::find(const T& dato) const{
  return this->root && this->root->find(dato, this->root);
}

template <typename T>
bool ArbolBin<T>::empty() const{
  return this->root == NULL;
}

template <typename T>
size_t ArbolBin<T>::size() const{
  return this->numItems;
}

template <typename T>
T ArbolBin<T>::getRoot() const{
  try{
    if(!this->root) throw -1;
    return this->root->dato;
  }catch(const int& code){
    switch(code){
      case -1: std::cerr<<"\a\nTrying to get root from empty BST\n\n";
    }
  }
  return T(0);
}

#endif