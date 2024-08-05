#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include <cstdlib>
#include "queue.h"

template <typename T>
Queue<T>::Queue(): numItems(0), bck(NULL), frt(NULL){ }

template <typename T>
Queue<T>::Queue(const T& dato): numItems(1){
  this->bck = this->frt = new Nodo<T>(dato);
}

template <typename T>
Queue<T>::Queue(const Queue<T>& der): frt(NULL), bck(NULL), numItems(der.numItems){
 if(this != &der && der.numItems){
    const Nodo<T>* iterador = der.frt;
    this->frt = this->bck = new Nodo<T>(iterador->dato);
    while(iterador = iterador->sig)
      this->bck = this->bck->sig = new Nodo<T>(iterador->dato);
  }
}

template <typename T>
Queue<T>::~Queue(){
  const Nodo<T>* aux = this->frt;
  while(this->frt){
    this->frt = this->frt->sig;
    delete aux;
    aux = this->frt;
  }
}

template <typename T>
T Queue<T>::front(){
  try{  
    if(!this->frt) throw -1;
    return this->frt->dato;
  }catch(const int& code){
    switch(code){ 
      case -1: std::cerr<<"\a\nTrying to get front element from empty queue\n\n";
    }
    return T();
  }
}

template <typename T>
T Queue<T>::back(){
  try{
    if(!this->bck) throw -1;
    return this->bck->dato;
  }catch(const int& code){
    switch(code){ 
      case -1: std::cerr<<"\a\nTrying to get back element from empty queue\n\n";
    }
    return T();
  }
}

template <typename T>
void Queue<T>::clear(){
  while(this->frt)
    this->pop();
  this->frt = this->bck = NULL;
}

template <typename T>
void Queue<T>::pop(){
  if(this->frt){
    Nodo<T>* aux; 
    if(this->frt == this->bck){
      aux = this->frt;
      this->frt = this->bck = NULL;
    }else{
      aux = this->frt;
      this->frt = this->frt->sig;
    }
    delete aux;
    numItems--;
  }
}

template <typename T>
void Queue<T>::push(const T& dato){
  if(this->frt) this->bck = this->bck->sig = new Nodo<T>(dato);
  else this->frt = this->bck = new Nodo<T>(dato);
  numItems++;
}

template <typename T>
size_t Queue<T>::size() const{
  return this->numItems;
}

template <typename T>
bool Queue<T>::empty() const{
  return this->frt == NULL;
}

template <typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& der){
  if(this != &der){
    this->clear();
    if(!der.numItems) return *this; 

    const Nodo<T>* iterador = der.frt;
    this->frt = this->bck = new Nodo<T>(iterador->dato);
    while(iterador = iterador->sig)
      this->bck = this->bck->sig = new Nodo<T>(iterador->dato);
    this->numItems = der.numItems;
  }
  return *this;
}

#endif // QUEUE_HPP