#ifndef ARBOL_BINARIO_HPP
#define ARBOL_BINARIO_HPP
#include <iostream>
#include <cstdlib>
#include "arbolBinario.h"

template <typename T>
ArbolBin<T>::ArbolBin(): numItems(0), raiz(NULL){ }

template <typename T>
ArbolBin<T>::ArbolBin(const T& data): numItems(1), raiz(data){}

template <typename T>
ArbolBin<T>::ArbolBin(const ArbolBin<T>& arbDer): numItems(0), raiz(NULL){
  if(this != &arbDer && arbDer.raiz){
    Queue<T> cola;
    arbDer.nivelOrden(cola);

    while(!cola.empty()){
      this->raiz->insert(cola.front(), this->raiz);
      this->numItems++;
      cola.pop();
    }
  }
}

template <typename T>
void ArbolBin<T>::clear(){
  if(!this->raiz) return;
  
  this->deleteTree(this->raiz);
  this->numItems = 0;
}

template <typename T>
ArbolBin<T>::~ArbolBin(){
  if(this->raiz)
    this->deleteTree(this->raiz);
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
  this->raiz->insert(dato,this->raiz);
  this->numItems++;
}

template <typename T>
void ArbolBin<T>::pop(const T& dato){

  if(!this->raiz->find(dato , this->raiz)){ std::cerr<<"\n\nThe data: "<<dato<<" wasn't find\n\n"; return;}

  if(dato == this->raiz->dato){ // It searches for the max node in the minimum set of nodes starting at the root node which will be deleted
    NodoBin<T>* iterador = this->raiz;
    if(iterador->izq && iterador->der){
      NodoBin<T>* padre = iterador;
      iterador = iterador->izq;
      while(iterador->der){ padre = iterador; iterador = iterador->der; }
      padre->izq == iterador ? padre->izq = iterador->izq : padre->der = iterador->izq;
      this->raiz->dato = iterador->dato;
    }else if(iterador->der) this->raiz = iterador->der;
    else if(iterador->izq) this->raiz = iterador->izq;
    delete iterador;
  }else if(dato > this->raiz->dato) this->raiz->pop(dato, this->raiz->der, raiz);
  else this->raiz->pop(dato, this->raiz->izq, raiz);
  this->numItems--;
}

template <typename T>
void ArbolBin<T>::inOrden() const{
  if(this->raiz) this->raiz->inOrden(this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::inOrden(Queue<T>& cola){
  if(this->raiz) this->raiz->inOrden(cola, this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::preOrden() const{
  if(this->raiz) this->raiz->preOrden(this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::preOrden(Queue<T>& cola){
  if(this->raiz) this->raiz->preOrden(cola, this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::posOrden() const{
  if(this->raiz) this->raiz->posOrden(this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::posOrden(Queue<T>& cola){
  if(this->raiz) this->raiz->posOrden(cola, this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::nivelOrden() const{
  if(this->raiz) this->raiz->nivelOrden(this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
void ArbolBin<T>::nivelOrden(Queue<T>& cola){
  if(this->raiz) this->raiz->nivelOrden(cola, this->raiz);
  else std::cout<<"El arbol esta vacio\n\n";
}

template <typename T>
ArbolBin<T>& ArbolBin<T>::operator = (const ArbolBin<T>& arbDer){
  if(this != &arbDer){
    this->clear(); 
    if(!arbDer.raiz) return *this;

    Queue<T> cola;
    arbDer.nivelOrden(cola);
    while(!cola.empty()){
      this->raiz->insert(cola.front(), this->raiz);
      cola.pop();
    }
    this->numItems = arbDer.numItems;
  }
  return *this;
}

template <typename T>
bool ArbolBin<T>::find(const T& dato) const{
  return this->raiz && this->raiz->find(dato, this->raiz);
}

template <typename T>
bool ArbolBin<T>::empty() const{
  return this->raiz == NULL;
}

template <typename T>
size_t ArbolBin<T>::size() const{
  return this->numItems;
}

template <typename T>
void ArbolBin<T>::root() const{
  if(!this->raiz){ std::cout<<"\a\nNo hay elementos en el arbol\n\n"; return; }
  std::cout<<"ROOT = "<<this->raiz->dato<<'\n';
}

#endif