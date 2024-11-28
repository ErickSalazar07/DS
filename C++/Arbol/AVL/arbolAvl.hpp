#ifndef ARBOL_AVL_HPP
#define ARBOL_AVL_HPP
#include "arbolAvl.h"

template <class T>
ArbolAVL<T>::ArbolAVL(): root(NULL), numItems(0){}

template <class T>
ArbolAVL<T>::ArbolAVL(const T& data): root(new NodoAVL<T>(data)), numItems(1){}

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
  if(this->root->find(data, this->root)) return;
  
  if(!this->root) this->root = new NodoAVL<T>(data);
  else if(this->root->data > data) this->root->insert(data,this->root->izq, this->root);
  else if(this->root->data < data) this->root->insert(data, this->root->der, this->root);
  this->numItems++;
}

template <class T>
void ArbolAVL<T>::pop(const T& data){
  if(!this->root) return;

  if(this->root->data == data){ // Delete root node

  }else if(this->root->data > data) this->root->pop(data, this->root->izq, this->root);
  else if(this->root->data < data) this->root->pop(data, this->root->der, this->root);

  this->numItems--;
}

template <typename T>
void ArbolAVL<T>::inOrden() const{
  if(!this->root) { std::cout<<"\nEl arbol esta vacio, no se puede hacer \"in orden\".\n"; return; }
  std::cout<<"\n\t\t\tIN ORDEN\n\n";
  this->root->inOrden(this->root);
  std::cout.put('\n');
}

template <typename T>
void ArbolAVL<T>::inOrden(std::vector<T>& vec) {
  if(!this->root) {
    std::cerr<<"\nThe tree is empty.\n";
    vec.clear();
    return;
  }
  vec.clear();
  this->root->inOrden(vec,root);
}

template <typename T>
void ArbolAVL<T>::preOrden() const{
  if(!this->root) { std::cout<<"\nEl arbol esta vacio, no se puede hacer \"in orden\".\n"; return; }
  std::cout<<"\n\t\t\tPRE ORDEN\n\n";
  this->root->preOrden(this->root);
  std::cout.put('\n');
}

template <typename T>
void ArbolAVL<T>::preOrden(std::vector<T>& vec) {
  if(!this->root) {
    std::cerr<<"\nThe tree is empty.\n";
    vec.clear();
    return;
  }
  vec.clear();
  this->root->preOrden(vec,root);
}

template <typename T>
void ArbolAVL<T>::posOrden() const{
  if(!this->root) { std::cout<<"\nEl arbol esta vacio, no se puede hacer \"in orden\".\n"; return; }
  std::cout<<"\n\t\t\tPOS ORDEN\n\n";
  this->root->posOrden(this->root);
  std::cout.put('\n');
}

template <typename T>
void ArbolAVL<T>::posOrden(std::vector<T>& vec) {
  if(!this->root) {
    std::cerr<<"\nThe tree is empty.\n";
    vec.clear();
    return;
  }
  vec.clear();
  this->root->posOrden(vec,root);
}

template <typename T>
void ArbolAVL<T>::nivelOrden() const{
  if(!this->root) { std::cout<<"\nEl arbol esta vacio, no se puede hacer \"in orden\".\n"; return; }
  std::cout<<"\n\t\t\tNIVEL ORDEN\n\n";
  this->root->nivelOrden(this->root);
  std::cout.put('\n');
}

template <typename T>
void ArbolAVL<T>::nivelOrden(std::vector<T>& vec) {
  if(!this->root) {
    std::cerr<<"\nThe tree is empty.\n";
    vec.clear();
    return;
  }
  vec.clear();
  this->root->nivelOrden(vec,root);
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

template <class T>
int ArbolAVL<T>::heigth() const{
  if(!this->root) return -1;
  return this->root->heigth();
}

#endif // ARBOL_AVL_HPP