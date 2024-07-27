#ifndef NODO_AVL_HPP
#define NODO_AVL_HPP
#include <iostream>
#include <vector>
#include "../../Queue/queue.h"
#include "nodoAvl.h"

template <typename T>
NodoAVL<T>::NodoAVL(const T& data, const NodoAVL<T>* izq, const NodoAVL<T>* der, const size_t& h): data(data), h(h), izq(izq), der(der){ }

template <typename T>
void NodoAVL<T>::insert(const T& data, NodoAVL<T>*& node){
  if(!node){ node = new NodoAVL<T>(data); return; } 
  else if(node->data > data) this->insert(data, node->izq);
  else if(node->data < data) this->insert(data, node->der);

  // se calcula la altura para la recursividad menos para el nodo que se inserto

  node->h = this->heigth(node);
  this->balance(node);
}

template <typename T>
void NodoAVL<T>::pop(const T& data, NodoAVL<T>* node, NodoAVL<T>* padre){
  if(node->data > data) this->pop(data, node->izq, node);
  else if(node->data < data) this->pop(data, node->der, node);
  else this->eraseNode(node, padre);


}

template <typename T>
void NodoAVL<T>::eraseNode(NodoAVL<T>* nodEliminar, NodoAVL<T>* padre){
  if(nodEliminar->izq && nodEliminar->der){ // Nodo con dos hijos
    
  }else if(nodEliminar->der){ // Nodo con algun hijo

  }else if(nodEliminar->izq){

  }else{ // Nodo hoja

  }
}

template <typename T>
void NodoAVL<T>::inOrden(const NodoAVL<T>* const nodo){
  if(nodo->izq) this->inOrden(nodo->izq);
  std::cout<<nodo->data<<' ';
  if(nodo->der) this->inOrden(nodo->der);
}

template <typename T>
void NodoAVL<T>::inOrden(const std::vector<T>& vec, const NodoAVL<T>* const nodo){
  if(nodo->izq) this->inOrden(vec, nodo->izq);
  vec.push_back(nodo->data);
  if(nodo->der) this->inOrden(vec, nodo->der);
}

template <typename T>
void NodoAVL<T>::preOrden(const NodoAVL<T>* const nodo){
  std::cout<<nodo->data<<' ';
  if(nodo->izq) this->preOrden(nodo->izq);
  if(nodo->der) this->preOrden(nodo->der);
}

template <typename T>
void NodoAVL<T>::preOrden(const std::vector<T>& vec, const NodoAVL<T>* const nodo){
  vec.push_back(nodo->data);
  if(nodo->izq) this->preOrden(vec, nodo->izq);
  if(nodo->der) this->preOrden(vec, nodo->der);
}

template <typename T>
void NodoAVL<T>::posOrden(const NodoAVL<T>* const nodo){
  if(nodo->izq) this->posOrden(nodo->izq);
  if(nodo->der) this->posOrden(nodo->der);
  std::cout<<nodo->data<<' ';
}

template <typename T>
void NodoAVL<T>::posOrden(const std::vector<T>& vec, const NodoAVL<T>* const nodo){
  if(nodo->izq) this->posOrden(vec, nodo->izq);
  if(nodo->der) this->posOrden(vec, nodo->der);
  vec.push_back(nodo->data);
}

template <typename T>
void NodoAVL<T>::nivelOrden(const NodoAVL<T>* const nodo){
  Queue<const NodoAVL<T>* const> buffer(nodo);

  while(!buffer.empty()){
    std::cout<<buffer.front()->data<<' ';
    if(buffer.front()->izq) buffer.push(buffer.front()->izq);
    if(buffer.front()->der) buffer.push(buffer.front()->der);
    buffer.pop();
  }
}

template <typename T>
void NodoAVL<T>::nivelOrden(const std::vector<T>& vec, const NodoAVL<T>* const nodo){
  Queue<const NodoAVL<T>* const> buffer(nodo);

  while(!buffer.empty()){
    vec.push_back(buffer.front()->data);
    if(buffer.front()->izq) buffer.push(buffer.front()->izq);
    if(buffer.front()->der) buffer.push(buffer.front()->der);
    buffer.pop();
  }
}

template <typename T>
int NodoAVL<T>::heigth(){
  if(this->izq && this->der) return this->max(this->heigth(this->izq), this->heigth(this->der));
  else if(this->izq) return 1 + this->heigth(this->izq);
  else if(this->der) return 1 + this->heigth(this->der);
  else return 0;
}

template <typename T>
int NodoAVL<T>::heigth(const NodoAVL<T>* const node){
  if(node->izq && node->der) return max(heigth(node->izq), heigth(node->der));
  else if(node->izq) return 1 + heigth(node->izq);
  else if(node->der) return 1 + heigth(node->der);
  else return 0;
}

template <typename T>
int NodoAVL<T>::max(const int& num1, const int& num2){
  return num1 > num2 ? num1 : num2;
}

template <typename T>
bool NodoAVL<T>::leaf() const{
  return !this->izq && !this->der;
}

template <typename T>
bool NodoAVL<T>::leaf(const NodoAVL<T>* const node) const{
  return !node->izq && !node->der;
}

template <typename T>
bool NodoAVL<T>::find(const T& data, const NodoAVL<T>* const node) const{
  if(node)
    if(node->data < data) return this->find(data, node->der);
    else if(node->data > data) return this->find(data, node->izq);
    else return true;
  return false;
}

template <typename T>
void balance(const NodoAVL<T>* node){
  if(node->izq->h - node->der->h) // implementation of the conditions to know when the node is disbalanced
}

template <typename T>
NodoAVL<T>* NodoAVL<T>::leftRot(const NodoAVL<T>* const node){
  NodoAVL<T>* auxDer = node->der;
  node->der = auxDer->izq;
  auxDer->izq = node;
  return auxDer;
}

template <typename T>
NodoAVL<T>* NodoAVL<T>::rightRot(const NodoAVL<T>* const node){
  NodoAVL<T>* auxIzq = node->izq;
  node->izq = auxIzq->der;
  auxIzq->der = node;
  return auxIzq;
}

template <typename T>
NodoAVL<T>* NodoAVL<T>::rightLeftRot(const NodoAVL<T>* const node){
  return node->izq;
}

template <typename T>
NodoAVL<T>* NodoAVL<T>::leftRightRot(const NodoAVL<T>* const node){
  return node->der;
}

#endif // NODO_AVL_HPP