#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <cstdlib>
#include "stack.h"

template <typename T>
Stack<T>::Stack(): numItems(0), cima(NULL){ }

template <typename T>
Stack<T>::Stack(const T& dato): numItems(1){
  this->cima = new Nodo<T>(dato);
}

template <typename T>
Stack<T>::Stack(const Stack<T>& pDer): cima(NULL), numItems(pDer.numItems){

  if(this != &pDer && pDer.numItems){
    size_t n = pDer.numItems;
    T* arr = new T[n];
    const Nodo<T>* iterador = pDer.cima; 

    for(size_t i = 0; iterador; i++){
      arr[i] = iterador->dato;
      iterador = iterador->sig;
    }
    for(size_t i = n; i > 0; i--)
      this->cima = new Nodo<T>(arr[i-1],this->cima);
    delete[] arr;
  }
}

template <typename T>
Stack<T>::~Stack(){
  Nodo<T>* aux = this->cima;
  while(this->cima){
    this->cima = this->cima->sig;
    delete aux;
    aux = cima;
  }
}

template <typename T>
Stack<T>& Stack<T>::push(const T& dato){
  this->cima = new Nodo<T>(dato,this->cima);
  this->numItems++;
  return *this;
}

template <typename T>
Stack<T>& Stack<T>::clear(){
  while(this->cima)
    this->pop();
  this->cima = NULL;
  return *this;
}

template <typename T>
Stack<T>& Stack<T>::pop(){
  if(!this->cima) return *this;

  Nodo<T>* aux = this->cima;
  this->cima = this->cima->sig;
  this->numItems--;
  delete aux;
  return *this;
}

template <typename T>
T Stack<T>::top() const{
  try{
    if(!this->cima) throw -1;
    return this->cima->dato;
  }catch(const int& code){
    switch(code){ 
      case -1: std::cerr<<"\n\aTrying getting element with stack empty\n\n";
    }
  }
  return T(0);
}

template <typename T>
bool Stack<T>::empty() const{
  return this->cima == NULL;
}

template <typename T>
size_t Stack<T>::size() const{
  return this->numItems;
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& pDer){
  if(this != &pDer){
    this->clear(); // limpia la pila por si existe algun nodo ya existente
    if(!pDer.numItems) return *this;
    size_t n = pDer.numItems; // tamnho de la pila
    T* const arr = new T[n]; //arreglo dinamico para cargar la informacion sin borrarla
    const Nodo<T>* iterador = pDer.cima; // iterador para solo obtener los datos de los nodos de la pila derecha "pDer"

    for(size_t i = 0; iterador != NULL; i++){ //itera sobre la pila hasta que llegue al final "NULL"
      arr[i] = iterador->dato; //primera iteracion guarda el dato de la cima p.ej {1,2,3,4,6,5}  el orden en que deben ser guardado es {5,6,4,3,2,1}
      iterador = iterador->sig;
    }
    for(size_t i = n; i > 0; i--) // itera sobre el arreglo desde la ultima posicion para que se guarde en el orden correcto
      this->cima = new Nodo<T>(arr[i-1],this->cima);
    this->numItems = n;
    delete[] arr; // elimina memoria dinamica 
  }
  return *this; // retorna la referencia del objeto al que se le esta llamando la funcion
}

template <typename T>
T Stack<T>::operator [] (const size_t& j){
  const Nodo<T>* iterador = this->cima;

  for(int i = 0; iterador; i++, iterador = iterador->sig) 
    if(j == i) 
      return iterador->dato;
  return this->cima->dato;
}

#endif // STACK_HPP