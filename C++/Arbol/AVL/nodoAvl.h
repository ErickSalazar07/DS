#ifndef NODO_AVL_H
#define NODO_AVL_H
#include <vector>
#include <cstdlib>

template <class T> class ArbolAVL;
template <class T>
class NodoAVL{
  friend class ArbolAVL<T>;
private:
  T data;
  NodoAVL* izq;
  NodoAVL* der;
  void insert(const T&, NodoAVL*&, NodoAVL* const);
  void pop(const T&, NodoAVL*, NodoAVL*);
  void eraseNode(NodoAVL*, NodoAVL*);
  void inOrden(NodoAVL*); // Recorridos
  void inOrden(std::vector<T>&, NodoAVL*);
  void preOrden(NodoAVL*);
  void preOrden(std::vector<T>&, NodoAVL*);
  void posOrden(NodoAVL*);
  void posOrden(std::vector<T>&, NodoAVL*);
  void nivelOrden(NodoAVL*);
  void nivelOrden(std::vector<T>&, NodoAVL*);
  int heigth(); // is the heigth of some node in the tree
  int heigth(NodoAVL*);
  bool leaf() const;
  bool leaf(const NodoAVL* const) const;
  bool find(const T&, const NodoAVL* const) const;
  int max(const int&, const int&); // Maximo entre dos valores numericos
  void balance(NodoAVL* const, NodoAVL* const);
  NodoAVL* leftRot(NodoAVL* const);
  NodoAVL* rightRot(NodoAVL* const);
  NodoAVL* leftRightRot(NodoAVL* const);
  NodoAVL* rightLeftRot(NodoAVL* const);
protected:
public:
  NodoAVL(const T&, NodoAVL* = NULL, NodoAVL* = NULL);
};

#include "nodoAvl.hpp"

#endif // NODO_AVL_H