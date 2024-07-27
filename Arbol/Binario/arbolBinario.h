#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include <cstdlib>
#include "nodoBinario.h"

template <typename T>
class ArbolBin{
private:
  NodoBin<T>* root;
  size_t numItems;
protected:
  void deleteTree(NodoBin<T>*&);
public:
  ArbolBin();
  ArbolBin(const T&);
  ArbolBin(const ArbolBin&);
  ~ArbolBin();
  void insert(const T&);
  void pop(const T&);
  void inOrden() const;
  void inOrden(Queue<T>&);
  void preOrden() const;
  void preOrden(Queue<T>&);
  void posOrden() const;
  void posOrden(Queue<T>&);
  void nivelOrden() const;
  void nivelOrden(Queue<T>&);
  size_t size() const;
  bool find(const T&) const;
  bool empty() const;
  void clear();
  void getRoot() const;
  ArbolBin<T>& operator = (const ArbolBin&);
}; 

#include "arbolBinario.hpp"
#endif