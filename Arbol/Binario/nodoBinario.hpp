
#ifndef NODO_BINARIO_HPP
#define NODO_BINARIO_HPP
#include "../../Queue/queue.h" // estructura para el recorrido nivelOrden
#include "nodoBinario.h"

template <typename T>
NodoBin<T>::NodoBin(const T& dato, NodoBin<T>* const izq, NodoBin<T>* const der): dato(dato), izq(izq), der(der){ }

template <typename T>
NodoBin<T>::~NodoBin(){ }

template <typename T>
void NodoBin<T>::insert(const T& dato, NodoBin<T>*& nodo){ 
  if(nodo == NULL) nodo = new NodoBin<T>(dato);
  else if(nodo->dato > dato) insert(dato,nodo->izq);
  else if(nodo->dato < dato) insert(dato, nodo->der);
}

template <typename T>
void NodoBin<T>::pop(const T& dato, NodoBin<T>*& nodo){
  const NodoBin<T>* iterador = nodo;
  const NodoBin<T>* padre = NULL;

  while(iterador)
    if(iterador->dato > dato) {
      padre = iterador;
      iterador = iterador->izq;
    }else if(iterador->dato < dato){ 
      padre = iterador;
      iterador = iterador->der;
    }else
      this->eraseNode(iterador,padre);
}

template <typename T>
void NodoBin<T>::pop(const T& dato, NodoBin<T>* nodo, NodoBin<T>* padre){
  if(nodo)
    if(nodo->dato > dato) this->pop(dato, nodo->izq, nodo);
    else if(nodo->dato < dato) this->pop(dato, nodo->der, nodo);
    else this->eraseNode(nodo, padre);
}

template <typename T>
void NodoBin<T>::inOrden(Queue<T>& cola, const NodoBin<T>* const nodo){
  if(nodo->izq) inOrden(cola, nodo->izq);
  cola.push(nodo->dato);
  if(nodo->der) inOrden(cola, nodo->der);
}

template <typename T>
void NodoBin<T>::inOrden(const NodoBin<T>* const nodo) const{
  if(nodo->izq) inOrden(nodo->izq);
  std::cout<<nodo->dato<<' ';
  if(nodo->der) inOrden(nodo->der);
}

template <typename T>
void NodoBin<T>::preOrden(Queue<T>& cola, const NodoBin<T>* const nodo){
  cola.push(nodo->dato);
  if(nodo->izq) preOrden(cola, nodo->izq);
  if(nodo->der) preOrden(cola, nodo->der);
}

template <typename T>
void NodoBin<T>::preOrden(const NodoBin<T>* const nodo) const{
  std::cout<<nodo->dato<<' ';
  if(nodo->izq) preOrden(nodo->izq);
  if(nodo->der) preOrden(nodo->der);
}

template <typename T>
void NodoBin<T>::posOrden(Queue<T>& cola, const NodoBin<T>* const nodo){
  if(nodo->izq) posOrden(cola, nodo->izq);
  if(nodo->der) posOrden(cola, nodo->der);
  cola.push(nodo->dato);
}

template <typename T>
void NodoBin<T>::posOrden(const NodoBin<T>* const nodo) const{
  if(nodo->izq) posOrden(nodo->izq);
  if(nodo->der) posOrden(nodo->der);
  std::cout<<nodo->dato<<' ';
}

template <typename T>
void NodoBin<T>::nivelOrden(Queue<T>& cola, const NodoBin<T>* const nodo){
  Queue<const NodoBin<T>* const> colaAux(nodo);
  
  while(!colaAux.empty()){
    cola.push(colaAux.front()->dato);
    if(colaAux.front()->izq) colaAux.push(colaAux.front()->izq);
    if(colaAux.front()->der) colaAux.push(colaAux.front()->der);
    colaAux.pop();
  }
}

template <typename T>
void NodoBin<T>::nivelOrden(const NodoBin<T>* const nodo){
  Queue<const NodoBin<T>* const> cola(nodo);

  while(!cola.empty()){
    std::cout<<cola.front()->dato<<' ';
    if(cola.front()->izq) cola.push(cola.front()->izq);
    if(cola.front()->der) cola.push(cola.front()->der);
    cola.pop();
  }
}

template <typename T>
bool NodoBin<T>::leaf() const{
  return !this->izq && !this->der;
}

template <typename T>
bool NodoBin<T>::find(const T& dato, const NodoBin<T>* const nodo) const{
  if(nodo)
    if(dato < nodo->dato) return this->find(dato, nodo->izq);
    else if(dato > nodo->dato) return this->find(dato, nodo->der);
    else return true;
  return false;
}

template <typename T>
void NodoBin<T>::eraseNode(NodoBin<T>* nodEliminar, NodoBin<T>* padre){

  if(nodEliminar->izq && nodEliminar->der){ // case 1. Two childs
    NodoBin<T>* nodRef = nodEliminar;
    padre = nodEliminar;
    nodEliminar = nodEliminar->der;
    while(nodEliminar->izq){ padre = nodEliminar; nodEliminar = nodEliminar->izq; }
    nodRef->dato = nodEliminar->dato;
    padre->der == nodEliminar ? padre->der = nodEliminar->der : padre->izq = nodEliminar->der;
  }else if(nodEliminar->izq) // case 2. Have at most and at least 1 children, either the left one or the right one
    nodEliminar == padre->der ? padre->der = nodEliminar->izq : padre->izq = nodEliminar->izq;
  else if(nodEliminar->der)
    nodEliminar == padre->der ? padre->der = nodEliminar->der : padre->izq = nodEliminar->der;
  else //case 3. Is a leaf node, whether the the conditions weren't entered or evaluated to true, and in the 2 and 3 cases, they both delete the node an setted to NULL
    padre->der == nodEliminar ? padre->der = NULL : padre->izq = NULL;
  nodEliminar->izq = nodEliminar->der = NULL;
  delete nodEliminar;
}

#endif //NODO_BINARIO_HPP