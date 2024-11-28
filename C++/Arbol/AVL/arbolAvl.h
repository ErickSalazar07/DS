#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H
#include <vector>
#include <cstdlib>
#include "nodoAvl.h"

template <class T>
class ArbolAVL{
private:
  NodoAVL<T>* root;
  size_t numItems;
protected:
  void deleteTree(NodoAVL<T>*&);
public:
  ArbolAVL();
  ArbolAVL(const T&);
  ArbolAVL(const ArbolAVL&);
  ~ArbolAVL();
  void insert(const T&);
  void pop(const T&);
  void inOrden() const;
  void inOrden(std::vector<T>&);
  void preOrden() const;
  void preOrden(std::vector<T>&);
  void posOrden() const;
  void posOrden(std::vector<T>&);
  void nivelOrden() const;
  void nivelOrden(std::vector<T>&);
  size_t size() const;
  bool find(const T&) const;
  bool empty() const;
  int heigth() const;
  void clear();
  void getRoot() const;
  ArbolAVL<T>& operator = (const ArbolAVL&);
};

#include "arbolAvl.hpp"

#endif // ARBOL_AVL_H
